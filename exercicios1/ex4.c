#include <stdio.h>

//4. Escrever programa em C para solicitar um valor monetário em reais, o câmbio real - dólar, e exiba o valor em dólar.
int main ()
{
  float Reais, Dolar;
  printf ("Insira o valor em reais:", Reais);
  scanf ("%f", &Reais);
  Dolar = Reais / 4.94;
  printf ("%.2f US Dolars", Dolar);
  return 0;
}