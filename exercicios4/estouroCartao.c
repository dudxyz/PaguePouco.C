// JK evitar "estouro" de cartão de crédito

#include <stdio.h>

void ValidaCompra(float *L, int NumerodaCompra){
  float D;
  printf("Debito: ");
  scanf("%f",&D);

  if (*L - D >= 0){
  printf("Compra %d possivel! \n", NumerodaCompra);
  *L = *L - D;}
  else
  printf("Esta compra \"estourarah\" o cartao! \n");
  printf("Limite restante: %.2f \n\n",*L);}

int main(){
  float Limite;
  int NumerodaCompra = 1;
  printf("Limite do cartao: ");
  scanf("%f",&Limite);
      while (Limite>0)
    ValidaCompra(&Limite, NumerodaCompra++);
  printf("Seu limite de compras acabou!");
    return 0;
}
