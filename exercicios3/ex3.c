#include <stdio.h>
#include <math.h>

int main ()
{
  float Nota1, Nota2, Nota3, CalculoNota;
  printf("Qual a nota 1 do aluno? ");
  scanf("%f", &Nota1);
  
  printf("Qual a nota 2 do aluno? ");
  scanf("%f", &Nota2);
  
  printf("Qual a nota 3 do aluno? ");
  scanf("%f", &Nota3);
  
  CalculoNota = (Nota1 + Nota2*2 + Nota3*3)/3;
  
  if (CalculoNota >= 7)
    printf("Aluno aprovado.");
  else
    if (CalculoNota < 7 && CalculoNota >= 5)
        printf("Aluno em recuperação.");
    else
        printf("Aluno reprovado.");
        
  return 0;
}
