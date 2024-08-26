#include <stdio.h>

//5. Escrever programa em C para solicitar ao usuário a distância que ele pretende correr e sua velocidade média esperada. Exibir o tempo estimado de exercício (corrida).
int main ()
{
 float Distancia, VelocidadeMedia, TempoEstimado; 

 printf ("Qual a distancia em metros que pretende percorrer?");
 scanf ("%f", &Distancia);

 printf ("Qual a sua velocidade media esperada (em m/s)?");
 scanf ("%f", &VelocidadeMedia);

 TempoEstimado = Distancia / VelocidadeMedia;

 printf ("O tempo estimado da sua corrida e: %.2f segundos", TempoEstimado);

 return 0;
}