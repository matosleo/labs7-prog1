/**
 * @file	jogador.cpp
 * @brief	Implementação dos métodos da classe Jogador em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#include "jogador.h"


Jogador::Jogador() {
	m_status = ativo;
	m_total_pontos = 0;
}

Jogador::~Jogador(){}

std::string
Jogador::getNome() {
	return m_nome;
}

/**
  * @brief 		Funcao que retorna o valor de pontos acumulador
  * @details   
  * @params
  * @return		O total de pontos acumulados pelo jogador
  * @sa 		https://github.com/matosleo
*/
int
Jogador::getPontos() {
	return m_total_pontos;
}

/**
  * @brief 		Funcao que permite incrementar valores para os pontos do jogador
  * @details   
  * @params
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogador::setPontos(int pontos) {
	m_total_pontos += pontos;
}

/**
  * @brief 		Funcao que retorna o status atual do jogador
  * @details   
  * @params
  * @return		Um valor entre 0 e 1
  * @sa 		https://github.com/matosleo
*/
int
Jogador::getStatus() {
	return m_status;
}

/**
  * @brief 		Funcao que permite alterar o status atual do jogador
  * @details   
  * @params
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogador::setStatus(int s) {
	m_status = s;
}

/**
  * @brief 		Operador sobrecarregado de atribuicao
  * @details   
  * @params
  * @return		ponteiro para o próprio objeto que invocou o método
  * @sa 		https://github.com/matosleo
*/
Jogador& 
Jogador::operator=(Jogador const &j) {
	m_status = j.m_status;
	m_nome = j.m_nome;
	m_total_pontos = j.m_total_pontos;
	return *this;
}

/**
  * @brief 		Imprime o objeto criado pela classe Jogador
  * @details   
  * @params		Recebe um objeto ostream, passado por referência
  * @params		Recebe um objeto da classe Jogador
  * @return		Uma referencia para um objeto ostream
  * @sa 		https://github.com/matosleo
*/
std::ostream& 
operator<< (std::ostream &o, Jogador const j) {
	o << std::setw(12) << std::left << j.m_nome << " | " << j.m_total_pontos << " pontos" << std::endl;
	return o;
}

/**
  * @brief 		Lê um objeto criado pela classe Jogador
  * @details   
  * @params		Recebe um objeto istream, passado por referência
  * @params		Recebe um objeto da classe Jogador
  * @return		Uma referencia para um objeto ostream, por referência
  * @sa 		https://github.com/matosleo
*/
std::istream& 
operator>>(std::istream &i, Jogador &j) {	
	i >> j.m_nome;
	return i;
}
