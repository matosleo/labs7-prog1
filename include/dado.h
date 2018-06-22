/**
 * @file	dado.h
 * @brief	Implementação da classe Dado em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#ifndef DADO_H
#define DADO_H

#include <random>

class Dado {
	private:
		int m_valor; /**< Valor de uma das faces do dado quando esta se encontra virada para cima. */
		std::random_device rd; /**< Dispositivo usado para a geração de números randômicos. */ 
		std::default_random_engine gen; /**< Máquina de geração de números randômicos. */
		std::uniform_int_distribution<> dis; /**< Define a distribuição a ser usado no sorteio dos valores randômicos, neste caso, uma distribuição uniforme, pois representa melhor cada valor de um dado real. */
	public:
		Dado();
		~Dado();

		void jogar();
		int getValor();
};

#endif