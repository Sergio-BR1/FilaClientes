#include <iostream>
#include <stdlib.h>
#include <time.h>

struct cliente {
	std::string nome;
	int senha;
};

void insere(int &inicio, int &fim, cliente *fila) {
	int prov;
	int senha;
	prov = (fim+1)%20;
	if (prov != inicio) {
		fim = prov;
		senha = rand()%10000;
		std::cout << "Insira o nome do cliente" << std::endl;
		std::cin.ignore();
		std::getline(std::cin,fila[fim].nome);
		fila[fim].senha = senha;
		std::cout << "Senha: " << senha << std::endl;
		if (inicio == -1)
			inicio = 0;
	}
	else 
		std::cout << "Fila cheia" << std::endl;
}

void remove (int &inicio, int &fim, cliente *fila) {
	if (inicio != -1) {
		std::cout << "Cliente: " << fila[inicio].nome << " Senha: " <<  fila[inicio].senha << std::endl;
		if (inicio == fim) inicio = fim = -1;
		else inicio = (inicio+1)%20;

	}
	else std::cout << "A fila está vazia" << std::endl;
}

int main() {
  cliente fila[20];
	bool encerra = false;
	int inicio = -1;
	int fim = -1;
	int escolha;
	char continuar;

	srand((unsigned)time(NULL));

	while (!encerra) {
		std::cout << "Digite 1 para incluir cliente na fila e 2 para exibir o próximo a ser atendido: ";
		std::cin >> escolha;
		if (escolha == 1) {
			insere(inicio, fim, fila);	
		}
		else 
			remove(inicio, fim, fila);

		std::cout << "Deseja continuar? [S/N]" << std::endl;
		std::cin >> continuar;
		if(continuar == 'N' || continuar == 'n')
			encerra = true;
	}

	
}