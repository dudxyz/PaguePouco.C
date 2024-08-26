#include <stdio.h>

//3. Periodicamente as crianças brasileiras devem tomar vacinas que as protegem de diversas doenças. Escreva um programa para ler o ano em que a criança toma a primeira dose e a periodicidade (intervalo em anos) da vacina e exibir em que outros anos a criança deve tomar as próximas doses da vacina, sabendo que são quatro doses ao total.
int main ()
{
 int PrimeiraDose, SegundaDose, TerceiraDose, QuartaDose, Periodicidade;
 printf ("Digite o ano em que tomou a primeira dose da vacina:", PrimeiraDose);
 scanf ("%d", &PrimeiraDose);
 printf ("Digite a periodicidade em anos da vacina:", Periodicidade);
 scanf ("%d", &Periodicidade); 
 SegundaDose = PrimeiraDose + Periodicidade;
 TerceiraDose = SegundaDose + Periodicidade;
 QuartaDose = TerceiraDose + Periodicidade;
 printf ("Próximas Doses:\n%d\n%d\n%d", SegundaDose, TerceiraDose, QuartaDose);
 return 0;
}