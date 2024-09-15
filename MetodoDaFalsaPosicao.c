#include <stdio.h>
#include <math.h>

// Definição da função cuja raiz queremos encontrar
double funcao(double x)
{
    return pow(x, 3) - (9 * x) + 5;
}

// Implementação do método da falsa posição
double metodo_da_falsa_posicao(double (*f)(double), double a, double b, double tol)
{
    if (f(a) * f(b) >= 0)
    {
        printf("O método da falsa posição falhou.\n");
        return -1;
    }

    double ponto = a;
    while (fabs(f(ponto)) > tol)
    {
        ponto = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
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
    double a, b;
    double tolerancia = 1e-2;
    printf("Insira o valor de a: ");
    scanf("%lf", &a);
    printf("Insira o valor de b: ");
    scanf("%lf", &b);
    double raiz = metodo_da_falsa_posicao(funcao, a, b, tolerancia);
    if (raiz != -1)
    {
        printf("A raiz encontrada e: %lf\n", raiz);
        printf("sendo a: %lf\n", a);
        printf("Sendo b: %lf\n", b);
    }
    return 0;
}