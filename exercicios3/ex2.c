#include <stdio.h>
#include <math.h>

int main ()
{
  int Gatos;
  printf("Quantos gatos foram capturados? ");
  scanf("%d", &Gatos);
  if (Gatos <= 4)
    printf("Todos os veterinários trabalharam na castração, em conjunto.");
  else 
    printf("Gatos que serão castrados pelos veterinarios experientes: %d.\nGatos que serão castrados pelo veterinário recem-formado: %d.", Gatos/4, Gatos%4);
  return 0;
}
