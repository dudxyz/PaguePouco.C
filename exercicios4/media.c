#include <stdio.h>

int main()
{
    float Nota1, Nota2, Nota3, Nota4, Media, NovaMedia;
    char Resposta;
  
    do {
    system ("cls");

    printf("Digite a primeira nota: ");
    scanf("%f", &Nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &Nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &Nota3);

    Media = (Nota1 + Nota2 + Nota3) / 3;

    if (Media > 7)
        printf("Aluno aprovado.");
    else if (Media <=3)
        printf("Aluno reprovado.");
        else
        printf("Digite a quarta nota: ");
        scanf("%f", &Nota4);

        NovaMedia = (Nota1 + Nota2 + Nota3 + Nota4) / 4;

            if (NovaMedia > 5)
                printf("Aluno aprovado.\n");
            else 
                printf("Aluno reprovado.\n");

    printf("Deseja verificar a situacao de outro aluno?\n");
    scanf(" %c", &Resposta);}
    while (Resposta == 'S' || Resposta == 's');

    return 0;
}
