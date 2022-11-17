#pragma once

struct Node {
    int dado;
    Node* proxNode;
};


//Definicao da classe lista
class Fila {
    //Definicao de membros privados
private:
    Node* inicio;
    Node* fim;
    int qtdElementos;
    int tamanhoMax;

public:
    Fila(int capacidade); // Construtor
    ~Fila(); // Destrutor

    int mostraQtdElementos();
    bool filaVazia();
    bool filaCheia();

    /* Adiciona um elemento no fim da fila */
    void enqueue(int dado);

    /* Retorna o elemento que está no ínicio da fila, e o remove*/
    int  dequeue();
};