
#include "Asian.hpp"

using namespace std;


Asian::Asian(double T, int nbTimeSteps, int size, double strike, PnlVect *weights)
{
  weights_ = pnl_vect_copy(weights);
  T_ = T;
  nbTimeSteps_ = nbTimeSteps;
  size_ = size;
  strike_ = strike;
}


Asian::Asian(const Asian& source) 
{
  weights_ = pnl_vect_copy(source.weights_);
  T_ = source.T_;
  nbTimeSteps_ = source.nbTimeSteps_;
  size_ = source.size_;
  strike_ = source.strike_;
}

Asian* Asian::clone()
{
  return (new Asian(*this));
}

Asian::~Asian()
{
  pnl_vect_free(&weights_);
}


double Asian::payoff(const PnlMat *path){

  double res = 0.0;

  // Creating a vector to contain the rows of the 'path' matrix
  PnlVect *spot_date;
  spot_date = pnl_vect_create(size_);

  for (unsigned int i=0 ; i <= nbTimeSteps_; i++)
  {
    // Charging the i row
    pnl_mat_get_row(spot_date, path, i);
    res += pnl_vect_scalar_prod(weights_, spot_date);
  }
  res = res/(nbTimeSteps_ + 1);
  res = res - strike_;

  // Deleting spot_date
  pnl_vect_free(&spot_date);

  if (res >= 0)
  {
    return res;
  }
  else
  {
    return 0.0;
  }

}
