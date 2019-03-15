
//#include "BlackScholesModel.hpp"
//#include "MonteCarlo.hpp"
#include "HedgePortfolio.cpp"
#include "jlparser/parser.hpp"
//#include "Option.hpp"
#include "Basket.hpp"
#include "Performance.hpp"
#include "Asian.hpp"
#include <ctime>
#include <mpi.h>
using namespace std;

int main(int argc,char **argv){
  int numprocs, myid;
  MPI_Init(&argc,&argv);
  MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank (MPI_COMM_WORLD, &myid);
  // Argument managment
  const char *argument = argv[1];

  double precision;
  const char *file;
  string c = "-c";
  PnlMat *past;
  const char* char_c = c.c_str();

  file = argv[1];
  if (argc > 2)
  { // the -c option isn't given
    const char *precisionChar = argv[2];
    precision = atof(precisionChar);
  }

  // Variables
  double T, r, strike;
  PnlVect *spot, *sigma;
  string type;
  int size;
  size_t n_samples;
  int nbTimeSteps;
  double rho, fdStep;

  // Initializing Variables to contain the test results
  double sd;
  //double payoff = 0;
  double prix;
  double ic;
  int nbSamples;

  Param *P = new Parser(file);

  P->extract("option type", type);
  P->extract("maturity", T);
  P->extract("option size", size);
  P->extract("timestep number", nbTimeSteps);

  // Matrix
  PnlMat *path = pnl_mat_create(nbTimeSteps + 1, size);
  PnlVect *weights = pnl_vect_create(size);

  P->extract("spot", spot, size);
  P->extract("volatility", sigma, size);
  P->extract("interest rate", r);
  P->extract("sample number", n_samples);
  P->extract("correlation", rho);
  P->extract("payoff coefficients", weights, size);
  //P->extract("fd step", fdStep);
  fdStep = 0.1;

  // Initializing Option
  Option *opt;

  if (type =="basket")
  {
    P->extract("strike", strike);
    opt = new Basket(T,nbTimeSteps,size,strike,weights);
  }
  else if ( type == "asian")
  {
    P->extract("strike", strike);
    opt = new Asian(T,nbTimeSteps,size,strike,weights);
  }
  else if ( type == "performance")
  {
    opt = new Performance(T,nbTimeSteps,size,weights);
  }
  else
  {
    cout << "Invalid option type parsed" << endl;
  }

  // Initializing Random Number Generator
  PnlRng* pnlRng = pnl_rng_create(PNL_RNG_MERSENNE);
  pnl_rng_sseed(pnlRng, time(NULL));
  RandomGen* rng = new PnlRand(pnlRng);

  //BlackScholesModel *bs_model = new BlackScholesModel(size, r, rho, sigma, spot);
  BlackScholesModel *bs_model;

  bs_model = new BlackScholesModel(size, r, rho, sigma, spot);


  MonteCarlo *mc_pricer = new MonteCarlo(bs_model, opt, rng, fdStep, n_samples);

  if (strcmp(argument, char_c)) // option -c not given
  {

    float time;
    double t0,tf;

    t0 = MPI_Wtime();

    //mc_pricer->price(prix,ic);

    // Variables temporaires
    PnlVect *delta = pnl_vect_create_from_scalar(size,0.0);
    past = pnl_mat_create_from_scalar(1,size,pnl_vect_get(spot,0));

    if (argc > 2) {
      mc_pricer->price(prix, nbSamples, precision, numprocs, myid);
    } else {
      mc_pricer->price(prix, ic, numprocs, myid);
    }


    tf = MPI_Wtime() ;
    if (myid == 0) {
      time = (double) (tf - t0);
      cout << endl;

      cout << "#####################" << endl;
      cout << "# NOMBRE DE TIRAGES #   =   " << ((argc > 2) ? nbSamples : n_samples) << endl;
      cout << "#####################" << endl << endl;


      cout << "##########################" << endl;
      cout << "# PRIX DE L'OPTION À t=0 #   =   "<< prix << endl;
      cout << "##########################" << endl << endl;

      cout << "###########################" << endl;
      cout << "# INTERVALLE DE CONFIANCE #   =   "<< ((argc > 2) ? precision : ic) << endl;
      cout << "###########################" << endl << endl;

      cout << "#####################" << endl;
      cout << "# TEMPS D'EXECUTION #   =   " << time << endl;
      cout << "#####################" << endl << endl;

      pnl_vect_free(&delta);

    }

  }


  pnl_mat_free(&past);
  pnl_mat_free(&path);
  pnl_vect_free(&spot);
  pnl_vect_free(&sigma);
  pnl_vect_free(&weights);
  delete P;
  delete(rng);
  delete mc_pricer;
  delete bs_model;
  delete opt;
  MPI_Finalize();
  return 0;

}
