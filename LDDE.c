#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct Lista{
    Celula *primeiro;
    int qtd;
} LDDE;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

LDDE *criar_lista(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor < nova->valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL){
        lista->primeiro = nova;
        
        if(atual != NULL){
            nova->proximo = atual;
            atual-> anterior = nova;
        }
    }
    else if(atual == NULL){
        anterior->proximo = nova;
        nova->anterior = anterior;
    }
    else{
        anterior->proximo = nova;
        nova->anterior = anterior;
        atual->anterior = nova;
        nova->proximo = atual;
    }
    lista->qtd++;
    
}

void mostrar(LDDE *Lista){
    Celula *atual = Lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    LDDE *lista = criar_lista();
    inserir(lista, 12);
    mostrar(lista);
    inserir(lista, 8);
    mostrar(lista);
    inserir(lista, 18);
    mostrar(lista);
    inserir(lista, 16);
    mostrar(lista);
}
