/**
 * @file	jogador.h
 * @brief	Implementação da classe Jogador em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <iomanip>
#include "dado.h"


enum Status {exlcuido, ativo};

class Jogador {

private:
	int m_status; /**< Representa o status do jogador: 0 para 'excluido' e 1 para 'ativo'. */
	std::string m_nome; /**< Nome do jogador. */
	int m_total_pontos; /**< Os pontos que o jogador irá acumular durante o jogo. */

public:
	Jogador();
	~Jogador();

	std::string getNome();
	int getPontos();
	void setPontos(int);
	int getStatus();
	void setStatus(int);

	Jogador& operator=(Jogador const &j);
	friend std::ostream& operator<< (std::ostream &o, Jogador const j);
	friend std::istream& operator>>(std::istream &i, Jogador &j);
};

#endif