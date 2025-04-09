#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  struct Cell *anterior;
  struct Cell *proximo;
  char valor;
} Cell;

typedef struct {
  Cell *top;
  int qtde;
} Stack;

Cell *start_cell(char valor) {
  Cell *nova = malloc(sizeof(Cell));
  nova->anterior = NULL;
  nova->proximo = NULL;
  nova->valor = valor;
  return nova;
}

Stack *start_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->qtde = 0;
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, char valor) {
  Cell *nova = start_cell(valor);
  if (stack->qtde != 0) {
    nova->proximo = stack->top;
    stack->top->anterior = nova;
  }
  stack->top = nova;
  stack->qtde++;
}

char pop(Stack *stack) {
  if (stack->qtde > 0) {
    char valor = stack->top->valor;
    Cell *top = stack->top;
    stack->top = stack->top->proximo;
    if (stack->top != NULL)
      stack->top->anterior = NULL;
    stack->qtde--;
    free(top);
    return valor;
  } else {
    return 'x';
  }
}

int main(void) {
    Stack *stack = start_stack();
  
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    int ctd_parenteses = 0;
    int ctd_conchetes = 0;
    int ctd_chaves = 0;

    int correto = 1;

    for(int i = 0 ; expr[i] != '\0'; i++){
        char c = expr[i];
        if(c == '('){
            push(stack, c);
            ctd_parenteses++;
        }
        if(c == ')'){
            if(pop(stack) != '('){
                correto = 0;
                break;
            }
            ctd_parenteses--;
        }
        if(c == '['){
            push(stack, c);
            ctd_conchetes++;
            if(ctd_parenteses > 0){
                correto = 0;
                break;
            }
        }
        if(c == ']'){
            if(pop(stack) != '['){
                correto = 0;
                break;
            }
            ctd_conchetes--;
        }
        if(c == '{'){
            push(stack,c);
            ctd_chaves++;
            if(ctd_conchetes > 0){
                correto = 0;
                break;
            }
        }
        if(c == '}'){
            if(pop(stack) != '{'){
                correto = 0;
                break;
            }
            ctd_chaves--;
        }      
    }
    if(correto){
        printf("correto");
    }else{
        printf("incorreto");
    }


    return 0;
}

//{[(9+7)÷(2÷3)]+[(5∗3)−(1÷6)]}

//{([9+7]÷[2÷3])+([5∗3]−[1÷6])}

//[{(9+7)÷(2÷3)}+{(5∗3)−(1÷6)}]