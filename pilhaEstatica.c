// PILHA ESTATICA
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct{
    int valores[LEN];
    int topo;
    int qtde;
} Pilha;

void push(Pilha *pilha, int valor){
    if(pilha->qtde == LEN){
        return;
    }
    pilha->valores[pilha->topo] = valor;
    pilha->topo++;
    pilha->qtde++;
}

int pop(Pilha *pilha){
    if(pilha->qtde == 0){
        return -1;
    }
    pilha->qtde--;
    pilha->topo--;
    return pilha->valores[pilha->topo];
}

void mostrar(Pilha *pilha){
    printf("TOPO --> ");
    for(int i = pilha->topo - 1 ; i >= 0 ; i--){
        printf("%d ", pilha->valores[i]);
    }
    printf("<-- BASE\n");
}

int main(){
    Pilha pilha;
    pilha.qtde = 0;
    pilha.topo = 0;
    push(&pilha, 8);
    mostrar(&pilha);
    push(&pilha, 5);
    mostrar(&pilha);
    push(&pilha, 9);
    mostrar(&pilha);
    pop(&pilha);
    mostrar(&pilha);
    pop(&pilha);
    mostrar(&pilha);
    pop(&pilha);
    mostrar(&pilha);
    push(&pilha, 5);
    mostrar(&pilha);
    push(&pilha, 99);
    mostrar(&pilha);

    return 0;
}
