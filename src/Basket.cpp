
#include "Basket.hpp"

using namespace std;

Basket::Basket(double T, int nbTimeSteps, int size, double strike, PnlVect *weights)
{
  weights_ = pnl_vect_copy(weights);
  T_ = T;
  nbTimeSteps_ = nbTimeSteps;
  size_ = size;
  strike_ = strike;
}

Basket::Basket(const Basket& source) 
{
  weights_ = pnl_vect_copy(source.weights_);
  T_ = source.T_;
  nbTimeSteps_ = source.nbTimeSteps_;
  size_ = source.size_;
  strike_ = source.strike_;
}

Basket* Basket::clone()
{
  return (new Basket(*this));
}

Basket::~Basket()
{

  pnl_vect_free(&weights_);

}


double Basket::payoff(const PnlMat *path)
// /!\ Works for the specific case of K<0 (Put basket option)
{
  double res = 0.0;

  // For a Call basket sign=+1, for a Put basket sign=-1
  double sign = 1;
  if (strike_ < 0)
  {
    cout << "Strike < 0" << endl;
    sign = -1;
  }

  // Creating a vector to contain the final row of the 'path' matrix
  PnlVect *last_date;
  last_date = pnl_vect_create(size_);

  // Debug
  //cout << "size of the Basket currently used to compute payoff = " << size_ << endl;

  // Charging the last row
  pnl_mat_get_row(last_date, path, nbTimeSteps_);
  // Debug
  //cout << "Printing the vector containing last date stock prices :" << endl;
  //pnl_vect_print(last_date);
  //cout << "Printing the vector containing the weights of each underlying asset :" << endl;
  //pnl_vect_print(weights_);
  //cout << "double result of scalar product of weight and last_date = " << pnl_vect_scalar_prod(weights_, last_date);

  res = (sign * pnl_vect_scalar_prod(weights_, last_date)) - strike_;

  // Deleting last_date
  pnl_vect_free(&last_date);

  if (res >= 0)
  {
    return res;
  }
  else
  {
    return 0.0;
  }

}
