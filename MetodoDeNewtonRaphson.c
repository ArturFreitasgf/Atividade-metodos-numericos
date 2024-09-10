#include <stdio.h>
#include <math.h>

// Definição da função cuja raiz queremos encontrar
double funcao(double x) {
    return pow(x, 3) - (9*x) + 5;
}

// Definição da derivada da função
double derivada_funcao(double x) {
    return 3 * pow(x, 2) - 9;
}

// Implementação do método de Newton-Raphson
double metodo_de_newton_raphson(double (*f)(double), double (*df)(double), double x0, double tol, int max_iter) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double dfx = df(x);
        if (fabs(dfx) < tol) {
            printf("Derivada muito pequena.\n");
            return -1;
        }
        double x1 = x - fx / dfx;
        if (fabs(x1 - x) < tol) {
            return x1;
        }
        x = x1;
    }
    printf("Número máximo de iterações atingido.\n");
    return -1;
}

int main() {
    double x0 = 0.75; // Chute inicial
    double tolerancia = 1e-2;
    int max_iter = 1000;
    double raiz = metodo_de_newton_raphson(funcao, derivada_funcao, x0, tolerancia, max_iter);
    if (raiz != -1) {
        printf("A raiz encontrada é: %lf\n", raiz);
    }
    return 0;
}