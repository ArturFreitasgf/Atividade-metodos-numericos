#include <stdio.h>
#include <math.h>

// Função constante que representa a carga máxima suportada pela coluna
double funcao(double x)
{
    double A = 0.09;     // Área da seção transversal (m^2)
    double fc = 25e6;    // Resistência à compressão do concreto (Pa)
    return x - (A * fc); // f(x) = x - P
}

// Derivada da função
double derivada_funcao(double x)
{
    return 1; // Derivada de x é 1
}

// Método de Newton-Raphson
double metodo_de_newton_raphson(double (*f)(double), double (*df)(double), double x0, double tol, int max_iter, int *interacoes)
{
    double x = x0;
    *interacoes = 0; // Inicializando a contagem de iterações

    for (int i = 0; i < max_iter; i++)
    {
        double fx = f(x);
        double dfx = df(x);
        (*interacoes)++;
        if (fabs(dfx) < tol)
        {
            printf("Derivada muito pequena.\n");
            return -1;
        }
        double x1 = x - fx / dfx;
        if (fabs(x1 - x) < tol)
        {
            return x1;
        }
        x = x1;
    }

    printf("Número máximo de iterações atingido.\n");
    return -1;
}

int main()
{
    double x0 = 2e6; // Chute inicial para a carga
    double tolerancia = 1e-5;
    int max_iter = 1000;
    int interacoes;

    double raiz = metodo_de_newton_raphson(funcao, derivada_funcao, x0, tolerancia, max_iter, &interacoes);
    if (raiz != -1)
    {
        printf("A carga máxima suportada é: %lf N\n", raiz);
        printf("Número de iterações: %d\n", interacoes);
    }

    return 0;
}