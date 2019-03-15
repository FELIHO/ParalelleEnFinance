#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP


/*
 * \file MonteCarlo.hpp
 * \brief Méthode de MonteCarlo
 * \author arahouy jmarian benhamoa letaillc
 * \date 18/09/2018
 *
 */

#include "Option.hpp"
#include "BlackScholesModel.hpp"
#include <mpi.h>


/** \class MonteCarlo
 * \brief Méthode de MonteCarlo
 */
class MonteCarlo
{
public:
  /**
   * pointeur vers le modèle
   */
    BlackScholesModel *mod_;
  /**
   * pointeur sur l'option
   */
    Option *opt_;
  /**
   * pointeur sur le générateur
   */
    RandomGen *rng_;
  /**
   * pas de différence finie
   */
    double fdStep_;
  /**
   * nombre de tirages Monte Carlo
   */
    int nbSamples_;

  /**
   * Constructeur de la classe MonteCarlo
   *
   * @param[in] mod Modèle de BlackScholes employé pour pricer
   * @param[in] opt Option à pricer
   * @param[in] rng Générateur de nombres aléatoires
   * @param[in] fdStep pas de différence finie
   * @param[in] nbSamples nombre de tirages Monte Carlo
   */
    MonteCarlo(BlackScholesModel *mod, Option *opt, RandomGen *rng, double fdStep, int nbSamples);

    /**
     * Constructeur par Copie de la classe MonteCarlo
     *
     * @param[in] MonteCarloACopier Objet MonteCarlo à copier
     */
    MonteCarlo(const MonteCarlo &MonteCarloACopier);

    /**
     * Destructeur de la classe MonteCarlo
     */
    ~MonteCarlo();

    /**
     * Calcule le prix de l'option à la date 0
     *
     * @param[out] prix valeur de l'estimateur Monte Carlo
     * @param[out] ic largeur de l'intervalle de confiance
     */
    void price(double &prix, double &ic);

    /**
     * Calcule le prix de l'option à la date 0
     *
     * @param[out] prix valeur de l'estimateur Monte Carlo
     * @param[out] ic largeur de l'intervalle de confiance
     */
    void price(double &prix, double &ic, int numprocs, int myid);


    /**
     * Calcule le prix de l'option à la date 0
     *
     * @param[out] prix valeur de l'estimateur Monte Carlo
     * @param[out] ic largeur de l'intervalle de confiance
     */
    void price(double &prix, int &nbSamples, double ic, int numprocs, int myid);

    /**
     * Calcule le prix de l'option à la date t
     *
     * @param[in]  past contient la trajectoire du sous-jacent
     * jusqu'à l'instant t
     * @param[in] t date à laquelle le calcul est fait
     * @param[out] prix contient le prix
     * @param[out] ic contient la largeur de l'intervalle
     * de confiance sur le calcul du prix
     */
    void price(const PnlMat *past, double t, double &prix, double &ic);

    void priceMaster(int nbMasterIteration, int numprocs, double &sommePayoff,
                     double &sommePayoffCarre, PnlMat* pathCourant, RandomGen* rngRand,
                     int proc, int tagCarre, int tag, MPI_Status status);

    void priceSlave(int nbSlaveIteration, PnlMat* pathCourant,
                                RandomGen* rngRand, int master, int tagCarre, int tag);

    /**
     * Calcule le delta de l'option à la date t
     *
     * @param[in] past contient la trajectoire du sous-jacent
     * jusqu'à l'instant t
     * @param[in] t date à laquelle le calcul est fait
     * @param[out] delta contient le vecteur de delta
     * de confiance sur le calcul du delta
     */
    void delta(const PnlMat *past, double t, PnlVect *delta);
    void delta2(const PnlMat *past, double t, PnlVect *delta, PnlVect *ic_delta);
};

#endif
