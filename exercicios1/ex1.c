#include <stdio.h>

//1. Faça um programa que leia um número inteiro e imprima o seu antecessor e o seu sucessor.
int main ()
{
  int Numero, Antecessor, Sucessor;

  printf ("Digite um numero inteiro: ");
  scanf ("%d", &Numero);
  
  Antecessor = Numero -1;
  Sucessor = Numero +1;
  
  printf ("Antecessor: %d \nSucessor: %d ", Antecessor, Sucessor);
  
  return 0;
}
