/**
 * @file	main.cpp
 * @brief	aquivo main que executa o jogo
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#include <iostream>
#include "jogo.h"
#include "entradaInvalida.h"

using namespace std;

int main(int argc, char const *argv[]) {

	int quant;
	bool valido = true;
	std::cout << "Quantos jogadores irão participar do jogo? ";
	
	std::cin >> quant;

	try {
		if(quant <= 0) 
		{
			throw EntradaInvalida();
		}
	} catch (EntradaInvalida &ex){
		cerr << ex.what() << " O jogo foi encerrado... " << endl;
		valido = false;
	}

	if(valido)
	{
		Jogo::setQtdJogadores(quant);

		Jogo jogo(Jogo::getQtdJogadores());
		jogo.run();
	}

	return 0;
}