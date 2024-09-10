#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return pow(x, 3) - x - 2;
}

double metodo_da_bissecao(double (*f)(double), double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("O método da bisseção falhou.\n");
        return -1;
    }

    double ponto_medio;
    while ((b - a) / 2.0 > tol) {
        ponto_medio = (a + b) / 2.0;
        if (f(ponto_medio) == 0) {
            return ponto_medio;
        } else if (f(a) * f(ponto_medio) < 0) {
            b = ponto_medio;
        } else {
            a = ponto_medio;
        }
    }

    return (a + b) / 2.0;
}

int main() {
    double a = 1;
    double b = 2;
    double tolerancia = 1e-5;

    double raiz = metodo_da_bissecao(funcao, a, b, tolerancia);
    if (raiz != -1) {
        printf("A raiz encontrada é: %lf\n", raiz);
    }

    return 0;
}