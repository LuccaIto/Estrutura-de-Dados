#include <stdio.h>
#include <stdlib.h>

//estrutura da celula
typedef struct Celula{
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct LDE{
    Celula *primeiro;
    int qtd;
} LDE;

LDE *criar_lista(){
    LDE *lista = malloc(sizeof(LDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

Celula *criar_celula(int valor){
    Celula *novo =  malloc(sizeof(Celula));
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}

//funcao INSERIR
void Inserir(LDE *lista, int valor){
    Celula *novo = criar_celula(valor);
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor < novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL){
        lista->primeiro = novo;
        //novo->proximo = atual;
    }
    else{
        anterior->proximo = novo;
        //novo->proximo = atual;
    }
    novo->proximo = atual;

    //adiciona mais uma posicao na lista(LDE);
    lista->qtd++;
}

//funcao REMOVER
void Remover(LDE *lista, int valor){

}

void mostrar(LDE *lista){
    Celula *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf(" \n");
}

int main(){
    LDE *lista = criar_lista();
    Inserir(lista, 5);
    mostrar(lista);
    Inserir(lista,3);
    mostrar(lista);
    Inserir(lista, 8);
    mostrar(lista);
    Inserir(lista, 6);
    mostrar(lista);

    return 0;
}


