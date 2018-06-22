/**
 * @file	jogo.h
 * @brief	Implementação da classe Jogo em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "jogador.h"
#include <entradaInvalida.h>

#define QTD_DADOS 2

class Jogo {

private:
	static int m_qtd_jogadores; /**< Quantidade de jogadores que irão jogar. */
	int m_meta_pontos; /**< Um valor que será a meta de pontos a ser atingdo no jogo. */
	int m_rodada; /**< Um valor numérico que representa a rodada atual. */
	Dado m_saco_dados[QTD_DADOS]; /**< Uma lista do tipo dados que guarda os dados a serem lançados no jogo. */
	Jogador* m_vencedor = nullptr; /**< Carrega o endereço na memória do vencedor do jogo. */
	bool temVencedor; /**< FALSO representando que não há vencedor ainda no jogo e VERDADEIRO representando que há um vencedor. */

public:
	Jogo(int quant);
	~Jogo();

	static int getQtdJogadores();
	static void setQtdJogadores(int);

	void swap(Jogador&, Jogador&);
	void sort(Jogador*);
	void addJogadores(Jogador*);
	void imprimeRegra();
	int lancarDados();
	int verificaAtivos(Jogador*);
	void jogarRodada(Jogador*);
	void placarDaRodada(Jogador*);
	void exibeVencedor(Jogador*);
	void run();
};


#endif
