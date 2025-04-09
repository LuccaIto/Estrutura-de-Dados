#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    int qtd;
    Celula *head;
    Celula *tail;
} Fila;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

Fila *criar_fila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtd = 0;
    return fila;
}

void enqueue(Fila *fila, int valor){
    Celula *nova = criar_celula(valor);
    if(fila->qtd == 0){
       // fila->tail = nova;
        fila->head = nova;
       // fila->qtd++;
    }
    else{
        fila->tail->proximo = nova;
        nova->anterior = fila->tail;
       // fila->tail = nova;        tem em ambos entao joga pra fora das condicoes..
       // fila->qtd++;
    }
    fila->tail = nova;
    fila->qtd++;
}

int dequeue(Fila *fila){
    if(fila->qtd == 0){
        return -1;
    }

    int valor = fila->head->valor;
    Celula *aux = fila->head;

    if(fila->qtd == 1){
        //int valor = fila->head->valor;
        //Celula *aux = fila->head;             apresenam a mesma logica em if e else e portanto pode se colocar fora (porem antes do codigo)
        fila->head = NULL;
        fila->tail = NULL;
        //fila->qtd--;
        //free(aux);
        //return valor;                 apresenam a mesma logica em if e else e portanto pode se colocar fora 

    }
    else{
        //int valor = fila->head->valor; 
        //Celula *aux = fila->head;
        fila->head->proximo->anterior = NULL;
        fila->head = fila->head->proximo;
        //fila->qtd--;
        //free(aux);
        //return valor;
    }
    fila->qtd--;
    free(aux);
    return valor;
}

void mostrar(Fila *fila){
    Celula *atual = fila->head;
    printf("HEAD -> ");
    while(atual != NULL){
        printf("%d , ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- TAIL");
    printf("\n");
}

int main(){
    Fila *fila = criar_fila();
    enqueue(fila, 5);
    mostrar(fila);
    enqueue(fila, 2);
    mostrar(fila);
    enqueue(fila, 3);
    mostrar(fila);
    printf("Valor removido: %d\n", dequeue(fila));
    mostrar(fila);
    printf("Valor removido: %d\n", dequeue(fila));
    mostrar(fila);
    printf("Valor removido: %d\n", dequeue(fila));
    mostrar(fila);
    printf("Valor removido: %d\n", dequeue(fila));
    mostrar(fila);


    return 0;
}