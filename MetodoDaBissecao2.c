#include <stdio.h>
#include <math.h>

// Função constante que representa a carga máxima suportada pela coluna
double funcao(double x)
{
    double A = 0.09;     // Área da seção transversal (m^2)
    double fc = 25e6;    // Resistência à compressão do concreto (Pa)
    return x - (A * fc); // f(x) = x - P
}

// Método da Bissecção
double metodo_da_bissecao(double (*f)(double), double a, double b, double tol, int *interacoes)
{
    if (f(a) * f(b) >= 0)
    {
        printf("O método da bisseção falhou.\n");
        return -1;
    }

    double ponto_medio;
    *interacoes = 0; // Inicializando a contagem de iterações

    while ((b - a) / 2.0 > tol)
    {
        ponto_medio = (a + b) / 2.0;
        (*interacoes)++;
        if (f(ponto_medio) == 0)
        {
            return ponto_medio;
        }
        else if (f(a) * f(ponto_medio) < 0)
        {
            b = ponto_medio;
        }
        else
        {
            a = ponto_medio;
        }
    }

    return (a + b) / 2.0;
}

int main()
{
    double a = 0;   // Limite inferior para a carga
    double b = 5e6; // Limite superior para a carga
    double tolerancia = 1e-5;
    int interacoes;

    double raiz = metodo_da_bissecao(funcao, a, b, tolerancia, &interacoes);
    if (raiz != -1)
    {
        printf("A carga máxima suportada é: %lf N\n", raiz);
        printf("Número de interações: %d\n", interacoes);
    }

    return 0;
}