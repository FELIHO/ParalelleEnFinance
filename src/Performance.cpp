
#include "Performance.hpp"

using namespace std;


Performance::Performance(double T, int nbTimeSteps, int size, PnlVect *weights)
{
  weights_ = pnl_vect_copy(weights);
  T_ = T;
  nbTimeSteps_ = nbTimeSteps;
  size_ = size;
}


Performance::Performance(const Performance& source) 
{
  weights_ = pnl_vect_copy(source.weights_);
  T_ = source.T_;
  nbTimeSteps_ = source.nbTimeSteps_;
  size_ = source.size_;
}

Performance* Performance::clone()
{
  return (new Performance(*this));
}

Performance::~Performance()
{
  pnl_vect_free(&weights_);
}


double Performance::payoff(const PnlMat *path){

  double res = 1.0;
  double perf = 0.0;

  // Creating two vectors to contain two consecutive rows of the 'path' matrix
  PnlVect *spot_date_i;
  PnlVect *spot_date_i_1;

  spot_date_i = pnl_vect_create(size_);
  spot_date_i_1 = pnl_vect_create(size_);

  for (unsigned int i=0 ; i < nbTimeSteps_ ; i++)
  {
    // Charging the rows
    pnl_mat_get_row(spot_date_i_1, path, i);
    pnl_mat_get_row(spot_date_i, path, i+1);
    // Debug
    /*
    cout << endl << "Printing spot_date_i_1 :" << endl;
    cout << "########################" << endl;
    pnl_vect_print(spot_date_i_1);
    cout << "########################" << endl;
    cout << endl << "Printing spot_date_i :" << endl;
    pnl_vect_print(spot_date_i);
    cout << "########################" << endl << endl;
    */

    perf = ( pnl_vect_scalar_prod(weights_, spot_date_i) / pnl_vect_scalar_prod(weights_, spot_date_i_1) ) - 1;

    if (perf >= 0)
    {
    res += perf;
    }

  }

  // Deleting spot_date
  pnl_vect_free(&spot_date_i);
  pnl_vect_free(&spot_date_i_1);

  return res;

}
