#include "Fila.h"
#include <stddef.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Fila::Fila(int capacidade)
{
	inicio = fim = NULL;
	qtdElementos = 0;
	tamanhoMax = capacidade;
}

Fila::~Fila()
{
	while (filaVazia() == false)
	{
		dequeue();
	}
	inicio = fim = NULL;
	tamanhoMax = 0;
}

int Fila::mostraQtdElementos()
{
	return qtdElementos;
}

bool Fila::filaVazia()
{
	return (qtdElementos == 0);
}

bool Fila::filaCheia()
{
	return (qtdElementos == tamanhoMax);
}

void Fila::enqueue(int dado)
{
	if (filaCheia()) {
		cout << "A fila esta cheia! Que triste" << endl;
		return;
	}

	Node* temp = new Node;
	temp->dado = dado;
	temp->proxNode = NULL;

	if (filaVazia())
	{
		inicio = fim = temp;
	}
	else
	{
		fim->proxNode = temp;
		fim = temp;
	}

	qtdElementos++;
}

int Fila::dequeue()
{
	if (filaVazia()) {
		throw invalid_argument("Fila Vazia Exception");
	}

	int dado = inicio->dado;

	Node* temp = inicio;
	inicio = inicio->proxNode;
	delete temp;

	// Fila está vazia, limpar ponteiro do fim também.
	if (inicio == NULL)
		fim = NULL;

	qtdElementos--;

	return dado;
}