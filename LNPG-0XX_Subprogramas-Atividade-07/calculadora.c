#include <stdio.h>
#include <stdlib.h>


void printarResultado(float resultado);


void printarDivisaobyzero() {
    printf("Erro! Divisão por zero.\n");
}


void divisao(float num1, float num2) {
    if (num2 != 0) {
        float resultado = num1 / num2;
        printarResultado(resultado);
    } else {
        printarDivisaobyzero();
    }
}


float *PrimerioESegundoNum() {
    float *num = malloc(sizeof(float) * 2);
    if (num == NULL) {
        printf("Erro: não foi possível alocar memória para armazenar os números.\n");
        return NULL; 
    }


    printf("Digite o primeiro número: ");
    scanf("%f", &num[0]);
    printf("Digite o segundo número: ");
    scanf("%f", &num[1]);

    return num;
}


void multiplicacao(float num1, float num2) {
    float resultado;
    resultado = num1 * num2;
    printarResultado(resultado);
}


void subtracao(float num1, float num2) {
    float resultado;
    resultado = num1 - num2;
    printarResultado(resultado);
}


void printarResultado(float resultado) {
    printf("Resultado: %.2f\n", resultado);
}


void soma(float num1, float num2) {
    float resultado;
    resultado = num1 + num2;
    printarResultado(resultado);
}


int menu() {
    char operador;
    float num1, num2;
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operador); 
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
            soma(num1, num2);
            break;
        case '-':
            subtracao(num1, num2);
            break;
        case '*':
            multiplicacao(num1, num2);
            break;
        case '/':
            divisao(num1, num2);
            break;
        default:
            printf("Operador inválido.\n");
            return 0;
    }
    return 1;
}


int main() {
    menu();
    return 0;
}
