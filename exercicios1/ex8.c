#include <stdio.h>

//8. Escrever um programa em C para calcular a área de um retângulo. O usuário deve fornecer o comprimento e a largura desse.

int main ()
{
  float Comprimento, Largura, Area;

  printf ("Digite o comprimento: ");
  scanf ("%f", &Comprimento);

  printf ("Digite a largura: ");
  scanf ("%f", &Largura);

  Area = Comprimento * Largura;

  printf ("A area do retangulo e: %.2f", Area);

  return 0;
}