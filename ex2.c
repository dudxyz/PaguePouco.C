#include <stdio.h>

//2. Para a manutenção da saúde é indispensável que as pessoas mantenham o peso ideal e, assim, evitem a obesidade. Escrever programa para ler: peso atual, peso ideal e perda mensal; e exibir em quantos dias a pessoa alcançará o peso ideal.
int main ()
{
  float PesoAtual, PesoIdeal, PerdaMensal, PesoPerder, QuantidadeMeses, QuantidadeDias;
  
  printf ("Digite o peso atual, o peso ideal e sua perca mensal: ");
  scanf ("%f%f%f", &PesoAtual, &PesoIdeal, &PerdaMensal);
  
  PesoPerder = PesoAtual - PesoIdeal;
  QuantidadeMeses = PesoPerder / PerdaMensal;
  QuantidadeDias = QuantidadeMeses * 30;
  
  printf ("Falta %.0f dias para voce atingir seu peso ideal.", QuantidadeDias);
  
  return 0;
}
