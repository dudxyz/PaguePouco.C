// Exercício 01.
#include <stdio.h>
#include <math.h>

int main() 
{
    int Inscritos;
    printf ("Qual e o numero de inscritos? ");
    scanf ("%d", &Inscritos);
    if (Inscritos <= 11 || Inscritos%11==0)
        printf("Todos os %d passageiros vao de Kombi.", Inscritos);
    else 
        printf("Viagens de Kombi: %d.\nPassagens de coletivo: %d.", Inscritos/11, Inscritos % 11);
    return 0;
}
