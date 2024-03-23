#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void printarResultado(float resultado) {
    if (!isnan(resultado)) {
        printf("Resultado: %.2f\n", resultado);
    } else {
        printf("Erro! Divisão por zero.\n");
    }
}


void printarDivisaobyzero() {
    printf("Erro! Divisão por zero.\n");
}


float *PrimerioESegundoNum() {
    float *num = malloc(sizeof(float) * 2);
    if (num == NULL) {
        printf("Erro: não foi possível alocar memória para armazenar os números.\n");
        return NULL; 
    }

    int validNums = 0;

    do {
        printf("Digite o primeiro número: ");
        if (scanf("%f", &num[0]) != 1) {
            printf("Erro: entrada inválida para o primeiro número.\n");
            while (getchar() != '\n');
        } else {
            validNums++;
        }
    } while (!validNums);

    validNums = 0;

    do {
        printf("Digite o segundo número: ");
        if (scanf("%f", &num[1]) != 1) {
            printf("Erro: entrada inválida para o segundo número.\n");
            while (getchar() != '\n');
        } else {
            validNums++;
        }
    } while (!validNums);

    return num;
}


float divisao(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        return NAN;
    }
}


float multiplicacao(float num1, float num2){

    return num1 * num2;
}


float subtracao(float num1, float num2){

    return num1 - num2;
}


float soma(float num1, float num2){
    
    return num1 + num2;
}

char EscolherOperador(){
    char operador;
    int valido = 0;
    
    do {
        printf("Digite a operação (+, -, *, /): ");
        scanf(" %c", &operador);
        if (operador == '+' || operador == '-' || operador == '*' || operador == '/')
            valido = 1;
        else
            printf("Operador inválido. Por favor, tente novamente.\n");
        while (getchar() != '\n');
    } while (!valido);
    
    return operador;
}


int menu() {
    char operador;
    float resultado, num1, num2;
    operador = EscolherOperador();
    float *numeros = PrimerioESegundoNum();
    if (numeros != NULL) {
        num1 = numeros[0]; 
        num2 = numeros[1]; 
        free(numeros); 
    } else {
        return 1;
    }


    switch (operador) {
        case '+':
            resultado = soma(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = multiplicacao(num1, num2);
            break;
        case '/':
            resultado = divisao(num1, num2);
            break;
    }
    printarResultado(resultado);
    return 1;
}


int main() {
    menu();
    return 0;
}
