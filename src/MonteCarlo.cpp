
#include "MonteCarlo.hpp"
using namespace std;


MonteCarlo::MonteCarlo(BlackScholesModel *mod, Option *opt, RandomGen *rng, double fdStep, int nbSamples)
{
  mod_ = new BlackScholesModel(*mod);
  opt_ = opt->clone();
  rng_ =  rng->clone();
  fdStep_ = fdStep;
  nbSamples_ = nbSamples;
}

MonteCarlo::MonteCarlo(const MonteCarlo &MonteCarloACopier){
  mod_ = new BlackScholesModel(*MonteCarloACopier.mod_);
  opt_ = MonteCarloACopier.opt_->clone();
  rng_ =  MonteCarloACopier.rng_->clone();
  fdStep_ = MonteCarloACopier.fdStep_;
  nbSamples_ = MonteCarloACopier.nbSamples_;
}

MonteCarlo::~MonteCarlo() {
  delete(mod_);
  delete(opt_);
  delete(rng_);
}


void MonteCarlo::price(double &prix, double &ic)
{
  double payoff;
  double sommePayoff = 0;
  double sommePayoffCarre = 0;
  PnlMat *pathCourant = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);

  for (int i = 0; i < nbSamples_; i++) {
    mod_->asset(pathCourant, opt_->T_, opt_->nbTimeSteps_, rng_);
    payoff = opt_->payoff(pathCourant);
    sommePayoff += payoff;
    sommePayoffCarre += payoff*payoff;
  }
  double moyennePayoff = sommePayoff/nbSamples_;
  double moyennePayoffCarre = sommePayoffCarre/nbSamples_;

  double ksiCarreM = exp(-2*mod_->r_*opt_->T_)*(moyennePayoffCarre-moyennePayoff*moyennePayoff);
  ic = 1.96*sqrt(ksiCarreM/nbSamples_)*2;
  prix = exp(-mod_->r_*opt_->T_)*moyennePayoff;

  pnl_mat_free(&pathCourant);

}



void MonteCarlo::price(double &prix, double &ic, int numprocs, int myid)
{


  double sommePayoff = 0;
  double sommePayoffCarre = 0;
  // int size, rank, proc;
  int proc;
  MPI_Status status; // Add
  int master = 0; // Add
  int tag = 123; // Add
  int tagCarre = 236;



  PnlMat *pathCourant = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);
  PnlRng *rng;
  cout << "Mon id  = " << myid << endl;
  rng = pnl_rng_dcmt_create_id(myid, 1234);
  pnl_rng_sseed(rng, 0);
  RandomGen* rngRand = new PnlRand(rng);


  /* Thread master */
  if (myid == 0) {
    priceMaster(nbSamples_/numprocs + nbSamples_%numprocs, numprocs, sommePayoff, sommePayoffCarre, pathCourant, rngRand, proc, tagCarre, tag, status);
    /* Compute endpoint data */
    double moyennePayoff = sommePayoff/nbSamples_;
    double moyennePayoffCarre = sommePayoffCarre/nbSamples_;

    double ksiCarreM = exp(-2*mod_->r_*opt_->T_)*(moyennePayoffCarre-moyennePayoff*moyennePayoff);
    ic = 1.96*sqrt(ksiCarreM/nbSamples_)*2;
    prix = exp(-mod_->r_*opt_->T_)*moyennePayoff;
  }

  // Thread slave
  else { /* envoyer la réponse au maître */
      priceSlave(nbSamples_/numprocs, pathCourant, rngRand, master, tagCarre, tag);

    }

    pnl_mat_free(&pathCourant);
    pnl_rng_free(&rng);

}

void MonteCarlo::priceMaster(int nbMasterIteration, int numprocs, double &sommePayoff,
                             double &sommePayoffCarre, PnlMat* pathCourant, RandomGen* rngRand,
                             int proc, int tagCarre, int tag, MPI_Status status){
  double mypayoff;
  double theirPayoffCarre;
  double theirPayoff;
  /* Calcul de la participation du maître */
  for (int i = 0; i < nbMasterIteration; i++) {
    mod_->asset(pathCourant, opt_->T_, opt_->nbTimeSteps_, rngRand);
    mypayoff = opt_->payoff(pathCourant);
    sommePayoff += mypayoff;
    sommePayoffCarre += mypayoff * mypayoff;
  }

  /* Recevoir la réponse de j */
  for(proc = 1; proc < numprocs; proc++) {
    MPI_Recv(&theirPayoff, 1, MPI_DOUBLE, proc, tag, MPI_COMM_WORLD, &status);
    sommePayoff += theirPayoff;
    MPI_Recv(&theirPayoffCarre,1,MPI_DOUBLE,proc,tagCarre,MPI_COMM_WORLD, &status);
    sommePayoffCarre += theirPayoffCarre;

  }

}

void MonteCarlo::priceSlave(int nbSlaveIteration, PnlMat* pathCourant, RandomGen* rngRand, int master, int tagCarre, int tag) {
  double theirPayoffCarre = 0;
  double theirPayoff = 0;
  double mypayoff;

  for (int i = 0; i < nbSlaveIteration; i++) {
    mod_->asset(pathCourant, opt_->T_, opt_->nbTimeSteps_, rngRand);
    mypayoff = opt_->payoff(pathCourant);
    theirPayoff += mypayoff;
    theirPayoffCarre += mypayoff * mypayoff;
  }
  MPI_Send(&theirPayoff, 1, MPI_DOUBLE, master, tag, MPI_COMM_WORLD);
  MPI_Send(&theirPayoffCarre, 1, MPI_DOUBLE, master, tagCarre, MPI_COMM_WORLD);
}



void MonteCarlo::price(double &prix, int &nbSamples, double ic, int numprocs, int myid)
{


  double sommePayoff = 0;
  double sommePayoffCarre = 0;
  nbSamples = 0;
  double icCurrent;
  // int size, rank, proc;
  int proc;
  MPI_Status status; // Add
  int master = 0; // Add
  int tag = 123; // Add
  int tagCarre = 236;


  double mypayoff;
  double theirPayoffCarre;
  double theirPayoff;
  double moyennePayoff;
  double moyennePayoffCarre;
  double ksiCarreM;
  PnlMat *pathCourant = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);
  PnlRng *rng;
  cout << "Mon id  = " << myid << endl;
  rng = pnl_rng_dcmt_create_id(myid, 1234);
  pnl_rng_sseed(rng, 0);
  RandomGen* rngRand = new PnlRand(rng);
  bool mustContinue = true;

  do {

  /* Thread master */
  if (myid == 0) {
      priceMaster(1, numprocs, sommePayoff, sommePayoffCarre, pathCourant, rngRand, proc, tagCarre, tag, status);
      nbSamples += numprocs;
      /* Compute endpoint data */

      moyennePayoff = sommePayoff/nbSamples;
      moyennePayoffCarre = sommePayoffCarre/nbSamples;


      ksiCarreM = exp(-2*mod_->r_*opt_->T_)*(moyennePayoffCarre-moyennePayoff*moyennePayoff);
      icCurrent = 1.96*sqrt(ksiCarreM/nbSamples)*2;
      prix = exp(-mod_->r_*opt_->T_)*moyennePayoff;
	  cout < numprocs << endl;

      for(proc = 1; proc < numprocs; ++proc){
        MPI_Send(&icCurrent, 1, MPI_DOUBLE, proc, 3, MPI_COMM_WORLD);
      }


    }

    else { /* envoyer la réponse au maître */
        priceSlave(1, pathCourant, rngRand, master, tagCarre, tag);
        MPI_Recv(&icCurrent, 1, MPI_DOUBLE, 0, 3, MPI_COMM_WORLD, &status);
      }
	  

	MPI_Barrier(MPI_COMM_WORLD);
	
    
  } while (icCurrent > ic) ;

  pnl_mat_free(&pathCourant);
  pnl_rng_free(&rng);


}







void MonteCarlo::price(const PnlMat *past, double t, double &prix, double &ic)
{
  double payoff;
  double sommePayoff = 0;
  double sommePayoffCarre = 0;
  PnlMat *pathCourant = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);

  for (int i = 0; i < nbSamples_; i++) {
    mod_->asset(pathCourant, t, opt_->T_, opt_->nbTimeSteps_, rng_, past);
    payoff = opt_->payoff(pathCourant);
    sommePayoff += payoff;
    sommePayoffCarre += payoff*payoff;
  }
  double moyennePayoff = sommePayoff/nbSamples_;
  double moyennePayoffCarre = sommePayoffCarre/nbSamples_;

  double ksiCarreM = exp(-2*mod_->r_*opt_->T_)*(moyennePayoffCarre-moyennePayoff*moyennePayoff);

  ic = 1.96*sqrt(ksiCarreM/nbSamples_)*2;

  prix = exp(-mod_->r_*(opt_->T_-t))*moyennePayoff;

  pnl_mat_free(&pathCourant);
}

void MonteCarlo::delta(const PnlMat *past, double t, PnlVect *delta) {
  pnl_vect_resize(delta, opt_->size_);
  PnlMat *path = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);
  PnlMat *shift_path_plus = pnl_mat_new();
  PnlMat *shift_path_minus = pnl_mat_new();

  double timestep = opt_->T_/opt_->nbTimeSteps_;
  double Diff = 0;
  PnlVect *vectDiff = pnl_vect_create(opt_->size_);

  for (int i = 0; i < nbSamples_; i++){
    mod_->asset(path, t, opt_->T_, opt_->nbTimeSteps_, rng_, past);
    for (int d = 0; d<opt_->size_; d++) {
      mod_->shiftAsset(shift_path_plus, path, d, fdStep_ , t, timestep);
      mod_->shiftAsset(shift_path_minus, path, d, -fdStep_, t, timestep);
      Diff = opt_->payoff(shift_path_plus) - opt_->payoff(shift_path_minus);
      pnl_vect_set(vectDiff,d,Diff);

    }
    pnl_vect_plus_vect(delta, vectDiff);

  }


  double scal = exp(-mod_->r_*(opt_->T_-t))/(2*nbSamples_*fdStep_);
  pnl_vect_mult_scalar(delta, scal);
  int nbRowsPast = past->m;
  PnlVect* s_t = pnl_vect_new();
  pnl_mat_get_row(s_t, past , nbRowsPast-1);
  pnl_vect_div_vect_term(delta,s_t); // Division par s_t


  pnl_vect_free(&s_t);
  pnl_vect_free(&vectDiff);

  pnl_mat_free(&path);
  pnl_mat_free(&shift_path_plus);
  pnl_mat_free(&shift_path_minus);
  pnl_vect_free(&vectDiff);
}

void MonteCarlo::delta2(const PnlMat *past, double t, PnlVect *delta, PnlVect *ic_delta) {
  pnl_vect_resize(delta, opt_->size_);
  pnl_vect_resize(ic_delta, opt_->size_);
  PnlMat *path = pnl_mat_create(opt_->nbTimeSteps_+1, opt_->size_);
  PnlMat *shift_path_plus = pnl_mat_new();
  PnlMat *shift_path_minus = pnl_mat_new();

  PnlVect *delta_carre = pnl_vect_create_from_scalar(opt_->size_,0);
  PnlVect *delta_2 = pnl_vect_create_from_scalar(opt_->size_,0);

  double timestep = opt_->T_/opt_->nbTimeSteps_;
  double Diff = 0;
  PnlVect *vectDiff = pnl_vect_create_from_scalar(opt_->size_,0);
  PnlVect *vectDiffCarre = pnl_vect_create_from_scalar(opt_->size_,0);

  for (int i = 0; i < nbSamples_; i++){
    mod_->asset(path, t, opt_->T_, opt_->nbTimeSteps_, rng_, past);
    for (int d = 0; d<opt_->size_; d++) {
      mod_->shiftAsset(shift_path_plus, path, d, fdStep_ , t, timestep);
      mod_->shiftAsset(shift_path_minus, path, d, -fdStep_, t, timestep);
      Diff = opt_->payoff(shift_path_plus) - opt_->payoff(shift_path_minus);
      pnl_vect_set(vectDiff, d, Diff);

      pnl_vect_set(vectDiffCarre, d, Diff*Diff);
    }
    pnl_vect_plus_vect(delta, vectDiff);

    pnl_vect_plus_vect(delta_carre, vectDiffCarre); // moyenne des carres
  }
  double exp_ = exp(-mod_->r_*(opt_->T_-t));
  // calcul delta
  double denominateur = 2*fdStep_;
  int nbRowsPast = past->m;
  PnlVect* s_t = pnl_vect_new();
  pnl_mat_get_row(s_t, past , nbRowsPast-1);

  pnl_vect_div_scalar(delta, denominateur);
  pnl_vect_div_scalar(delta, nbSamples_);
  pnl_vect_div_vect_term(delta,s_t); // Division par s_t
  //pause delta
  // calcul ic_delta
  pnl_vect_div_scalar(delta_carre, denominateur*denominateur);
  pnl_vect_div_vect_term(delta_carre,s_t);
  pnl_vect_div_vect_term(delta_carre,s_t);
  pnl_vect_div_scalar(delta_carre, nbSamples_);

  pnl_vect_plus_vect(delta_2,delta);
  pnl_vect_mult_vect_term(delta_2, delta);

  pnl_vect_plus_vect(ic_delta, delta_carre);
  pnl_vect_minus_vect(ic_delta, delta_2);

  pnl_vect_map_inplace(ic_delta, sqrt);
  pnl_vect_mult_scalar(ic_delta,2*1.96*exp_);

  //fin delta
  pnl_vect_mult_scalar(delta,exp_);


  pnl_vect_free(&s_t);
  pnl_vect_free(&vectDiff);
  pnl_vect_free(&vectDiffCarre);
  pnl_vect_free(&delta_2);
  pnl_vect_free(&delta_carre);
  pnl_mat_free(&path);
  pnl_mat_free(&shift_path_plus);
  pnl_mat_free(&shift_path_minus);
}
