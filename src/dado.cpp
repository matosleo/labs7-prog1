/**
 * @file	dado.cpp
 * @brief	Implementação dos métodos da classe Dado em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#include <random>
#include "dado.h"

Dado::Dado():rd(), gen(rd()), dis(1, 6) {
	m_valor = std::round(dis(gen));
}

Dado::~Dado(){}

/**
  * @brief 		Funcao que seleciona um valor aleatório entre 1 a 6
  * @details   
  * @params
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Dado::jogar() {
	m_valor = std::round(dis(gen));
}

/**
  * @brief 		Funcao que retorna o valor da face atual do dado
  * @details   
  * @params
  * @return		Um valor de 1 a 6
  * @sa 		https://github.com/matosleo
*/
int 
Dado::getValor() {
	return m_valor;
}