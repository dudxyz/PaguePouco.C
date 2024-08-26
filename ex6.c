#include <stdio.h>

//6. Escrever programa em C para solicitar ao usuário um número e exibir a tabuada (de multiplicação) desse número até 10.

int main ()
{
  int Numero;

  printf ("Digite um numero: ");
  scanf ("%d", &Numero);

  printf ("A Tabuada de %d e:\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", 
  Numero, Numero*1, Numero*2, Numero*3, Numero *4, Numero*5, Numero*6, 
  Numero*7, Numero*8, Numero*9, Numero*10);
  
  return 0;
}