#include <stdio.h>
#include <stdlib.h>

#define CAP 10

typedef struct{
    int dados[CAP];
    int head;
    int tail;
    int qtd;
} Fila;

Fila *criar_fila(){
    Fila *nova = malloc(sizeof(Fila));
    nova->head = 0;
    nova->tail = 0;
    nova->qtd = 0;
    return nova;
}

int is_full(Fila *fila){
    return fila->qtd == CAP;
}

int is_empty(Fila *fila){
    return fila->qtd == 0;
}

int enqueue(Fila *fila, int valor){
    if(is_full(fila)){
        return 0;
    }
    fila->dados[fila->tail % CAP] = valor;
    fila->tail++;
    fila->qtd++;
    return 1;
}

int dequeue(Fila *fila){
    if(is_empty(fila)){
        return -1;
    }
    int valor = fila->dados[fila->head % CAP];
    fila->head++;
    fila->qtd--;
    return valor;
}

void mostrar_fila(Fila *fila){
    printf("HEAD -> ");
    for(int i = fila->head ; i < fila->tail ; i++){
        printf("%d ", fila->dados[i % CAP]);
    }
    printf("<- TAIL\n");
}

int main(){
    Fila *fila = criar_fila();
    enqueue(fila, 8);
    enqueue(fila, 3);
    enqueue(fila, 5);
    mostrar_fila(fila);
    printf("VAlor removido: %d\n", dequeue(fila));
    printf("VAlor removido: %d\n", dequeue(fila));
    printf("VAlor removido: %d\n", dequeue(fila));
    printf("VAlor removido: %d\n", dequeue(fila));
    mostrar_fila(fila);

    return 0;
}