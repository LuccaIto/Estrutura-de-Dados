#include <stdio.h>

#define LEN 100

typedef struct {
	char data[LEN];
	int head;
	int tail;
	int qtde;
} Queue;

void enqueue(Queue *queue, char caracter) {
    // implementar
    if(queue->qtde == LEN){
        return;
    }
    queue->data[queue->tail++] = caracter;
    queue->qtde++;
}

char dequeue(Queue *queue) {
    // implementar
    if(queue->qtde == 0){
        return -1;
    }
    char valor = queue->data[queue->head++];
    queue->qtde--;
    return valor;
}

void show(Queue *queue) {
    // implementar
    //printf("HEAD -> ");
    for(int i = queue->head ; i < queue->tail ; i++){
        printf("%c ", queue->data[i]);
    }
    //printf("<- TAIL\n");
    printf("\n");
}

void start_queue(Queue *queue) {
    // implementar
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(void) {
    char s[LEN];
    fgets(s, sizeof(s), stdin);
    Queue queue;
    Queue queue_2;
    char var;

    
    start_queue(&queue);

    for (int i = 0; s[i] != '\0'; i++) {
        enqueue(&queue, s[i]);
    }
        
    // implementar

    int x = queue.qtde;
    for(int i = 0 ; i < x ; i++){
        var = dequeue(&queue);
        
        if(var == '('){
            enqueue(&queue_2, var);
        }
        else if(var == ')'){
            dequeue(&queue_2);
        }
        
    }

    if(queue_2.qtde == 0){
        printf("correto");
    }
    else{
        printf("incorreto");
    }

    



    return 0;
}
