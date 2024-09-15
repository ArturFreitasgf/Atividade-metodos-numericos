#include <stdio.h>
#include <math.h>

// Função constante que representa a carga máxima suportada pela coluna
double funcao(double x)
{
    double A = 0.09;     // Área da seção transversal (m^2)
    double fc = 25e6;    // Resistência à compressão do concreto (Pa)
    return x - (A * fc); // f(x) = x - P
}

// Método da Falsa Posição
double metodo_da_falsa_posicao(double (*f)(double), double a, double b, double tol, int *interacoes)
{
    if (f(a) * f(b) >= 0)
    {
        printf("O método da falsa posição falhou.\n");
        return -1;
    }

    double ponto = a;
    *interacoes = 0; // Inicializando a contagem de iterações

    while (fabs(f(ponto)) > tol)
    {
        ponto = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
        (*interacoes)++;
        if (f(ponto) == 0)
        {
            return ponto;
        }
        else if (f(a) * f(ponto) < 0)
        {
            b = ponto;
        }
        else
        {
            a = ponto;
        }
    }

    return ponto;
}

int main()
{
    double a = 0;   // Limite inferior para a carga
    double b = 5e6; // Limite superior para a carga
    double tolerancia = 1e-5;
    int interacoes;

    double raiz = metodo_da_falsa_posicao(funcao, a, b, tolerancia, &interacoes);
    if (raiz != -1)
    {
        printf("A carga máxima suportada é: %lf N\n", raiz);
        printf("Número de iterações: %d\n", interacoes);
    }

    return 0;
}  