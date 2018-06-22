/**
 * @file	jogo.cpp
 * @brief	Implementação dos métodos da classe Jogo em C++
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

#include "jogo.h"

using namespace std;

int Jogo::m_qtd_jogadores = 0;

Jogo::Jogo(int quant) {
	m_qtd_jogadores = quant;
	m_meta_pontos = 0;
	m_rodada = 1;
	temVencedor = false;
}

Jogo::~Jogo() {}

/**
  * @brief 		Pega a quantidade de jogadores participantes
  * @details   
  * @params		
  * @return		Retorna um valor inteiro positivo
  * @sa 		https://github.com/matosleo
*/
int 
Jogo::getQtdJogadores(){
	return m_qtd_jogadores;
}

/**
  * @brief 		Altera a quantidade de jogadores na partida
  * @details   
  * @params		Um valor inteiro positivo
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogo::setQtdJogadores(int quant){
	if(quant > 0) {
		m_qtd_jogadores = quant;
	}
}

/**
  * @brief 		Funcao que troca os objetos de posição
  * @details   	 
  * @params		Objeto do tipo Jogador
  * @params		Objeto do tipo Jogador
  * @return		Sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogo::swap(Jogador& x, Jogador& y)
{
    Jogador aux = x;
    x = y;
    y = aux;
}

/**
  * @brief 		Funcao Bubble Sort que ordena os objetos
  * @details   Faz uma ordenação decrescente com bubble sort para classificar a
  *colocação dos jogadores em relação aos pontos acumulados por eles 
  * @params
  * @return		Sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogo::sort(Jogador* lista)
{
	bool mudou = true;
	int fim  = m_qtd_jogadores - 1;
	while(mudou)
	{
		mudou = false;
		for(int j = 0; j < fim; j++)
		{
			if(lista[j].getPontos() < lista[j + 1].getPontos())
			{
				swap(lista[j], lista[j + 1]);
				mudou = true;
			}
		}
		fim -= 1;
	}
}

/**
  * @brief 		Adiciona jogadores a lista de jogadores do jogo
  * @details   
  * @params		Recebe uma lista do tipo Jogador
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void
Jogo::addJogadores(Jogador* lista){
	Jogador j;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		std::cout << "Digite o nome do jogador " << i+1 <<std::endl;
		std::cin >> j;
		lista[i] = j;
	}
}

/**
  * @brief 		Imprime na tela as regras do jogo
  * @details   
  * @params		
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void
Jogo::imprimeRegra() {
	std::cout << std::endl
	<< "**************************** REGRAS DO JOGO ****************************\n"
	<< "\n"
	<< "   O objetivo é tentar atingir através de sucessivos lances de dados,\n"
	<< " a quantidade de pontos estabelecida como meta no início do jogo.\n"
	<< "   A cada rodada os jogadores lançam os dados, acumulam pontos e\n"
	<< " somam no seu placar.\n"
	<< "   Os jogadores podem escolher passar a vez\n"
	<< "   Se todos passarem a vez, o jogo termina. Aquele com o placar\n"
	<< " mais próximo da meta será o vencedor\n"
	<< "\n"
	<< "**************************************************************************\n"
	<< std::endl;
}

/**
  * @brief 		Permite o jogador lançar os dados
  * @details   
  * @params		Recebe uma lista de jogadores participantes
  * @return		Um valor que é a soma das faces dos dados lançados
  * @sa 		https://github.com/matosleo
*/
int
Jogo::lancarDados() {
	int pontosDados = 0;
	for(int i = 0; i < QTD_DADOS; i++) {
		m_saco_dados[i].jogar();
		pontosDados += m_saco_dados[i].getValor();
	}
	return pontosDados;
}

/**
  * @brief 		Verifica os jogadores com status de ativo
  * @details   
  * @params		Recebe uma lista de jogadores participantes
  * @return		Retorna um valor inteiro da quantidade de jogadores com o status ativo
  * @sa 		https://github.com/matosleo
*/
int
Jogo::verificaAtivos(Jogador* lista) {
	int contAtivos = 0;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		if(lista[i].getStatus() == 1) {
			contAtivos++;
		}
	}
	return contAtivos;
}

/**
  * @brief 		Executa a rodada
  * @details   	Este método faz com que os jogadores lancem os dados ou esperem, verifica se
  *há vencedor e todas as condiçẽos de término do jogo
  * @params		Recebe uma lista de jogadores participantes
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void
Jogo::jogarRodada(Jogador* lista) {
	int opcao, flagContadora = 0;
	bool venceu = false, valido = false;
	
	for(int i = 0; i < m_qtd_jogadores; i++) {
		if(!venceu) {
			if(lista[i].getStatus() == 1) {
				do {
					std::cout << lista[i].getNome() << " voce tem " << lista[i].getPontos() << " pontos, deseja lançar os dados?\n"
					<< " 1 - Lançar dados\n"
					<< " 2 - Esperar\n"
					<< "\n"
					<< "opcao: ";

					do
					{
						std::cin >> opcao;
						try {
							if(opcao <= 0)
							{
								throw EntradaInvalida();
							}

							valido = true;
						} catch (EntradaInvalida &ex){
							cerr << ex.what() << " Digite novamente: " << endl;
							cin.clear();
							cin.ignore(100, '\n');
						}
					}while(valido == false);

					switch(opcao) {
						case 1:
						{
							int pontos = lancarDados();
							lista[i].setPontos(pontos);
							std::cout << "Voce somou " << lista[i].getPontos() << " pontos nesse lance\n"
							<< std::endl;
							flagContadora++;
							valido = true;
							break;
						}

						case 2:
						{
							std::cout << lista[i].getNome() << " passou a vez!\n" << std::endl;
							valido = true;
							break;
						}

						default:
						{
							std::cout << std::endl << "!ERRO!\n"
							<< "Digite uma opção válida\n" << std::endl;
							break;
						}
					}
				}while(!valido);

			}

			if(lista[i].getStatus() == 1 && lista[i].getPontos() > m_meta_pontos) {
				std::cout << std::endl << "Que pena. Seus pontos passaram do valor da meta\n"
				<< "Voce foi desclassificado.\n" << std::endl;
				lista[i].setStatus(0);
			}

			if(lista[i].getPontos() == m_meta_pontos) {
				m_vencedor = &lista[i];
				temVencedor = true;
				venceu = true;
			}

			if(verificaAtivos(lista) == 1) {
				for(int i = 0; i < m_qtd_jogadores; i++) {
					if(lista[i].getStatus() == 1) {
						m_vencedor = &lista[i];
					}
				}
				venceu = true;
				temVencedor = true;
			}
		}
	}
	if(flagContadora == 0) {
		int maiorPonto = 0;
		for(int i = 0; i < m_qtd_jogadores; i++) {
			if(lista[i].getStatus() == 1) {
				if(lista[i].getPontos() > maiorPonto) {
					maiorPonto = lista[i].getPontos();
					m_vencedor = &lista[i];
				}
			}
		}
		temVencedor = true;
	}		
}

/**
  * @brief 		Exibe o placar da rodada atual
  * @details   
  * @params		Recebe uma lista de jogadores participantes
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void 
Jogo::placarDaRodada(Jogador* lista) {
	Jogador *tmp = new Jogador [m_qtd_jogadores];
	for(int i = 0; i < m_qtd_jogadores; i++) {
		tmp[i] = lista[i];
	}

	sort(tmp);
	std::cout << std::endl << "        PLACAR DA RODADA" << std::endl;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		std::cout << i+1 <<"º " << tmp[i];
	}
	std::cout << std::endl;
}

/**
  * @brief 		Exibe o jogador vencedor do jogo
  * @details   
  * @params		Recebe um ponteiro para o endereço do jogador vencedor
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void
Jogo::exibeVencedor(Jogador* vencedor) {
	std::cout << std::endl << "O GRANDE VENCEDOR FOI " << vencedor->getNome() 
			<< ", COM " << vencedor->getPontos() 
			<< " PONTOS" << std::endl;
}

/**
  * @brief 		Função que executa o jogo
  * @details 	A função exibe um menu, cria uma lista de objetos Jogador, executa as funções
  * que criam as rodadas e mostra o placar e também que exibe o vencedor 
  * @params		
  * @return		sem retorno
  * @sa 		https://github.com/matosleo
*/
void
Jogo::run() {
		int opcao;

	do {
		bool valido = false;
		std::cout << std::endl
		<< " 1 - Jogar\n"
		<< " 2 - Regras do jogo\n"
		<< " 3 - Sair\n"
		<< "\n"
		<< " Opção: ";

		do
		{
			std::cin >> opcao;
			try {
				if(opcao <= 0)
				{
					throw EntradaInvalida();
				}

				valido = true;
			} catch (EntradaInvalida &ex){
				cerr << ex.what() << " Digite novamente: " << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		}while(valido == false);

		switch(opcao) {
			case 1:
			{
				Jogador *lista_jogadores = new Jogador [m_qtd_jogadores];
				addJogadores(lista_jogadores);
				int quantMeta;
				std::cout << "Quantos pontos será a meta a ser atingida na partida? ";

				valido = false;
				do
				{
					std::cin >> quantMeta;
					try {
						if(quantMeta <= 0)
						{
							throw EntradaInvalida();
						}

						valido = true;
					} catch (EntradaInvalida &ex){
						cerr << ex.what() << " Digite novamente: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
				}while(valido == false);

				m_meta_pontos = quantMeta;

				while(!temVencedor) {
					std::cout << "------------------- Rodada " << m_rodada << " -------------------" << std::endl;
					jogarRodada(lista_jogadores);
					placarDaRodada(lista_jogadores);
					m_rodada++;
				}
				std::cout << "---------------------------- FIM DE JOGO ----------------------------" << std::endl;
				exibeVencedor(m_vencedor);
				opcao = 0;
				break;
			}
			
			case 2:
			{
				imprimeRegra();
				break;			
			}

			case 3:
			{
				std::cout << std::endl <<  "Até logo!" << std::endl;
				break;
			}

			default:
			{
				std::cout << std::endl << "!ERRO!\n"
				<< "Digite uma opção válida"
				<< std::endl;
				break;
			}
		}

	} while(opcao != 3);
}