#include <stdio.h>

//7. Criar um programa em C que converta a temperatura de Celsius para Fahrenheit. Solicite ao usuário a temperatura em Celsius e exiba o resultado em Fahrenheit. Pesquise e escreva, como comentário, a regra de conversão usada.

int main ()
{
  float Celsius, Fahrenheit;

  printf ("Escreva a temperatura em Graus Celsius: ");
  scanf ("%f", &Celsius);

  Fahrenheit = Celsius * 1.8 + 32;

  printf ("A temperatura em Fahrenheit e: %.2f", Fahrenheit);

  return 0;
}