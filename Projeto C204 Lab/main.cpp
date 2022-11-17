#include <iostream>
#include <bits/stdc++.h>
#include "Grafo.h"

using namespace std;

int main()
{
	int V = 6;
	const bool eh_digrafo = true;
	int i = 0, quantrota = 0, estacorigem = 0, estadestino = 0, custodaviagem = 0 ;

	cout << "Entre com a quantidade de estacoes: " << endl;
	cin >> V;


	Grafo G(eh_digrafo, V);

	cout << endl << "Entre com a quantidade de rotas: " << endl;
	cin >> quantrota;

	while(i < quantrota)
	{
		cout << endl << i << ") " << "Percurso da estacao ate a parada" << endl;

		cout << "Inserir a estacao de Origem: ";
		cin >> estacorigem;

		cout << "Inserir a estacao de destino: ";
		cin >> estadestino;

		cout << "Custo da viagem: ";
		cin >> custodaviagem;
		i++;

		G.insereAresta(estacorigem, estadestino, custodaviagem);
	}

//	G.mostraArestas(); //imprime lista de adjacencia
	int dist[V];
	int pai[V];
	int origem = 0;
	G.dijkstra(origem, dist, pai, V);

	cout << "Menor custo da garagem (" << origem << " - Origem) ate as demais estacoes\n" << endl;
	for (size_t v = 0; v < V; v++)
	{
		cout << "Da estacao 0 ate a estacao " << v << " temos um custo de = " << dist[v] << endl;
	}

	return 0;
}
