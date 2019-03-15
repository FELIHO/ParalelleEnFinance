#include "Basket.hpp"
#include "MonteCarlo.hpp"

#include <iostream>
#include <string>
#include "jlparser/parser.hpp"
#include <ctime>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv)
{
  int numprocs, myid;
  MPI_Init(&argc,&argv);
  MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank (MPI_COMM_WORLD, &myid);
  double T, r, strike;
  PnlVect *spot, *sigma;
  string type;
  int size;
  size_t n_samples;
  int nbTimeSteps;
  double rho;


  // Initializing Variables to contain the test results
  double correct_price = 13.627;
  double sd = 0.025;
  //double payoff = 0;
  double prix;
  double ic;

  char const *infile = "../../data/basket.dat";
  Param *P = new Parser(infile);

  P->extract("option type", type);
  P->extract("maturity", T);
  P->extract("option size", size);
  P->extract("timestep number", nbTimeSteps);

  //PnlMat *path = pnl_mat_create(nbTimeSteps + 1, size);
  PnlVect *weights = pnl_vect_create(size);

  P->extract("spot", spot, size);
  P->extract("volatility", sigma, size);
  P->extract("interest rate", r);
  P->extract("strike", strike);
  P->extract("sample number", n_samples);
  P->extract("correlation", rho);
  P->extract("payoff coefficients", weights, size);

/* ######################################################################## */
/* ######################################################################## */

  // TEST BODY
  // #########

  // Initializing Option
  Basket *test_Basket = new Basket(T, nbTimeSteps, size, strike, weights);

  // Initializing Random Number Generator
  PnlRng* pnlRng = pnl_rng_create(PNL_RNG_MERSENNE);
  pnl_rng_sseed(pnlRng, time(NULL));
  RandomGen* rng = new PnlRand(pnlRng);

  BlackScholesModel *bs_model = new BlackScholesModel(size, r, rho, sigma, spot);
  // bs_model->asset(path, T, nbTimeSteps, rng); // Simulating the path from spot t=0 only
  // payoff = test_Basket->payoff(path);

  MonteCarlo *mc_pricer = new MonteCarlo(bs_model, test_Basket, rng, 1, n_samples);
  mc_pricer->price(prix, ic, numprocs, myid);


  cout << endl << "### Testing the Pricer for " << "basket.dat" << " file input ###" << endl << endl;
  cout << "#######################################################" << endl;


  cout << "True Price = " << 13.627 << endl;
  cout << "True Confidence Interval = " << 0.025*1.96*2 << endl;

  cout << "#######################################################"<< endl << endl;

     // cout << "Option Payoff = " << payoff << endl;
  cout << "Price = " << prix << endl;
  cout << "Confidence Interval = " << ic << endl;

  cout << "#######################################################" << endl;






/* ######################################################################## */
/* ######################################################################## */

  // FREEING DYNAMICALLY ALLOCATED VARIABLES
  // #######################################

  delete(bs_model);
  delete P;
  delete(test_Basket);

  // TEST PASS VERIFICATION
  // ######################

  assert(correct_price >= prix - ic);
  assert(correct_price <= prix + ic);
  assert(prix >= correct_price - sd*2);
  assert(prix <= correct_price + sd*2);

  cout << "# [test_basket TEST PASSED SUCCESSFULLY] #" << endl << endl;


  /*int myid = -1;
  MPI_Comm_rank (MPI_COMM_WORLD, &myid);
  if (myid == 0) {
    MPI_Finalize();
  }
  */


}
