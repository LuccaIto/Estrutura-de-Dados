// PILHA ESTATICA
#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proxima;
    int valor;
} Celula;

typedef struct{
    Celula *topo;
    int qtde;
} Pilha;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proxima = NULL;
    nova->valor = valor;
    //return nova;
}

void push(Pilha *pilha, int valor){
    Celula *nova = criar_celula(valor);

    if(pilha->qtde > 0){
        nova->proxima = pilha->topo;
        pilha->topo->anterior = nova;
    }
    pilha->topo = nova;
    pilha->qtde++;
}

int pop(Pilha *pilha){
    if(pilha->qtde == 0){
        return -1;
    }
    int valor = pilha->topo->valor;
    Celula *aux = pilha->topo;
    if(pilha->qtde == 1){
        pilha->topo = NULL;
    } 
    if(pilha->qtde > 1){
        pilha->topo = pilha->topo->proxima;
        pilha->topo->anterior = NULL;
    }
    pilha->qtde--;
    free(aux);
    return valor;
}

void mostrar(Pilha *pilha){
    Celula *atual = pilha->topo;
    printf("TOPO --> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proxima;
    }
    printf("<-- BASE\n");
}

int main(){
    Pilha pilha;
    pilha.qtde = 0;
    pilha.topo = NULL;
    push(&pilha, 8);
    mostrar(&pilha);
    pop(&pilha);
    mostrar(&pilha);
    push(&pilha, 5);
    mostrar(&pilha);
    push(&pilha, 8);
    mostrar(&pilha);
    push(&pilha, 8);
    mostrar(&pilha);
    push(&pilha, 8);
    mostrar(&pilha);
    pop(&pilha);
    mostrar(&pilha);
  

    return 0;
}
