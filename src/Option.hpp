#pragma once

#ifndef OPTION_HPP
#define OPTION_HPP

/* 
 * \file Option.hpp
 * \brief Superclasse Abstraite Option
 * \author arahouy jmarian benhamoa letaillc
 * \date 18/09/2018
 *
 */

#include "pnl/pnl_vector.h"
#include "pnl/pnl_matrix.h"

#include <iostream>
#include <stdio.h>



/*! \class Option abstraite
 * \brief Option Abstraite
 */
class Option
{
public:
  /*!
   * double T_ : Maturité de l'option
   */
    double T_; /// maturité
  /*!
   * nbTimeSteps_ : nombre de dates de constatation des cours du sous-jacent
   */
    int nbTimeSteps_; /// nombre de pas de temps de discrétisation
  /*!
   * size_ : nombre d'actifs sous-jacents
   */
    int size_; /// dimension du modèle, redondant avec BlackScholesModel::size_

    /**
     * \brief Calcule la valeur du payoff sur la trajectoire
     *
     * @param[in] path est une matrice de taille (N+1) x d
     * contenant une trajectoire du modèle telle que créée
     * par la fonction asset.
     * @return phi(trajectoire)
     */
    virtual double payoff(const PnlMat *path) = 0;

/* ######################################################################## */
/* ######################################################################## */

  /*!
   *  \brief Destructeur virtuel de la classe mère Option
   */
    virtual ~Option() {};

    virtual Option* clone() = 0;

};


#endif
