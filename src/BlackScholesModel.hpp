
#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

/*
 * \file BlackScholesModel.hpp
 * \brief Model de BlackScholes
 * \author arahouy jmarian benhamoa letaillc
 * \date 18/09/2018
 *
 */


#include "pnl/pnl_random.h"
#include "pnl/pnl_vector.h"
#include "pnl/pnl_matrix.h"

#include <math.h>
#include <assert.h>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <stdexcept>

#include "RandomGen.hpp"
#include "FakeRnd.hpp"
#include "PnlRand.hpp"

/** \class BlackScholesModel
 * \brief Modèle de Black Scholes
 */
class BlackScholesModel
{
public:

/**
 * int size_ : nombre d'actifs du modèle
 */
  int size_;

/**
 * double r_ : taux d'intérêt
 */
  double r_;

/**
 *  double rho_ : paramètre de corrélation
 */
  double rho_;

/**
 *  PnlVect *sigma_ : vecteur de volatilités
 */
  PnlVect *sigma_;

/**
 *  PnlVect *spot_ : valeurs initiales des sous-jacents
 */
  PnlVect *spot_;

/**
 *  PnlVect *trend_ : tendance du marche
 */
  PnlVect *trend_;

/**
 *  PnlMat* choleskyFactor : récipient de la factorisation de Cholesky
 */
  PnlMat* choleskyFactor;

    /**
     * \brief Constructeur de la classe BlackScholesModel
     *
     * @param[in] size_ nombre d'actifs du modèle
     * @param[in] r_ taux d'intérêt
     * @param[in] rho_ paramètre de corrélation
     * @param[in] sigma_ vecteur de volatilités
     * @param[in] spot_ valeurs initiales des sous-jacents
     */
    BlackScholesModel(int size, double r, double rho, PnlVect *sigma, PnlVect *spot, PnlVect *trend_);
    BlackScholesModel(int size, double r, double rho, PnlVect *sigma, PnlVect *spot);

    // // Constructor without arguments, only for testing purposes
    // BlackScholesModel();

    // // Constructor par copie
    BlackScholesModel(const BlackScholesModel &BlackScholesModelACopier);


    // Destructor
    ~BlackScholesModel();


    /**
     * \brief Génère une trajectoire du modèle et la stocke dans path
     *
     * @param[out] path contient une trajectoire du modèle.
     * C'est une matrice de taille (nbTimeSteps+1) x d
     * @param[in] T  maturité
     * @param[in] nbTimeSteps nombre de dates de constatation
     */
    void asset(PnlMat *path, double T, int nbTimeSteps, RandomGen *rng);

    /**
     * Calcule une trajectoire du sous-jacent connaissant le
     * passé jusqu' à la date t
     *
     * @param[out] path  contient une trajectoire du sous-jacent
     * donnée jusqu'à l'instant t par la matrice past
     * @param[in] t date jusqu'à laquelle on connait la trajectoire.
     * t n'est pas forcément une date de discrétisation
     * @param[in] nbTimeSteps nombre de pas de constatation
     * @param[in] T date jusqu'à laquelle on simule la trajectoire
     * @param[in] past trajectoire réalisée jusqu'a la date t
     */
    void asset(PnlMat *path, double t, double T, int nbTimeSteps, RandomGen *rng, const PnlMat *past);

    /**
     * Shift d'une trajectoire du sous-jacent
     *
     * @param[in]  path contient en input la trajectoire
     * du sous-jacent
     * @param[out] shift_path contient la trajectoire path
     * dont la composante d a été shiftée par (1+h)
     * à partir de la date t.
     * @param[in] t date à partir de laquelle on shift
     * @param[in] h pas de différences finies
     * @param[in] d indice du sous-jacent à shifter
     * @param[in] timestep pas de constatation du sous-jacent
     */
    void shiftAsset(PnlMat *shift_path, const PnlMat *path, int d, double h, double t, double timestep);

   /**
    * Concatène deux PnlMat 
    * @param[out] res matrice résultat de la concaténation
    * @param[in] mat1 1ere matrice à concaténer
    * @param[in] mat2 1ere matrice à concaténer
    *
    */  
    void concatenationMatrice(PnlMat* res,const PnlMat *mat1, const PnlMat *mat2);


   /**
    * Simule les cours des sous-jacents selon le modèle de Black-Scholes
    *
    * @param[out] path matrice contenant les données des cours S_t
    * @param[in] timestep pas de constatation
    * @param[in] nbTimeSteps nombre de pas de constatation
    * @param[in] rng Générateur de nombre aléatoire
    * @param[in] r vecteur des taux d'intérêts des sous-jacents
    */
    void simulateAsset(PnlMat *path, double timestep, int nbTimeSteps, RandomGen *rng, PnlVect* r);

    /**
     * Génère une trajectoire du modèle selon la probabilité risque neutre et la stocke dans market
     *
     * @param[out] market contient une trajectoire du modèle.
     * C'est une matrice de taille (nbTimeSteps+1) x d
     * @param[in] trend tendance du marché
     * C'est un vecteur de taille nombre d'actifs
     * @param[in] T  maturité
     * @param[in] H nombre de dates d'observation
     */
    void simul_market(PnlMat* market, double T, int H, RandomGen *rng);

};
#endif
