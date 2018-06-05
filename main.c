#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float derivada(float X0){ //função que calcula a derivada F'(x) e^x + 1 de forma numérica
   float  X, amplitude = 0.00001, fx, fx0, resultado;
    X = amplitude+X0;
    fx = pow(M_E,X) + X - 3;
    fx0 = pow(M_E,X0) + X0 - 3;
    resultado = (fx - fx0)/amplitude;
    return(resultado);
}
float funcao(float X){ //função que calcula a função F(x) e^x + x - 3
    float resultado;
    resultado = pow(M_E,X) + X - 3;
    return(resultado);
}
float modulo(float X){ //função que faz modulo de X
    if (X < 0) X = X * -1;
    return (X);
}
int main()
{
    int quant=0;
    float Xk, X_atual, X_anterior,  erro, result_erro;

    printf("Digite o chute inicial 'Xk': ");
    scanf("%f", &Xk);
    printf("Digite o erro(criterio de parada): ");
    scanf("%f", &erro);

    printf("\n");

    do
    {
    quant ++;

    if (quant != 1) X_anterior = X_atual;
    else X_anterior = Xk;

    X_atual = X_anterior -(funcao(X_anterior)/derivada(X_anterior));

    result_erro = X_atual - X_anterior;

    printf("X%d = %f, erro = %f\n", quant, X_atual, modulo(result_erro));

    }
    while (modulo(result_erro) > erro);

    printf("\nNumero total de iteracoes = %d\nresultado final = %f\nerro = %f", quant, X_atual, modulo(result_erro));

    return 0;
}
