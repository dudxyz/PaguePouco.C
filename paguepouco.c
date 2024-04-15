#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

//melhoria 1: implementada a função de recuperar registros apagados
//melhoria 2: implementada a função de exibir as informações para evitar redundancias no codigo

struct TpFarma{
	char Nome[21];
	float Preco;
	int QEstoque;
  int Ativo; //-1 p inativo, 1 p ativo
  };
  
typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;
  
FILE *ArqFarma;

long int Tamanho=21*sizeof(char)+sizeof(float)+sizeof(int);

//função implementada
void ExibirInformacoes(TpFARMA Farmaco){
  printf("Nome: %s\n",Farmaco.Nome);
  printf("Valor: %f\n",Farmaco.Preco);
  printf("Estoque: %d\n",Farmaco.QEstoque);
}

void Incluir() {
  char R;
    do{
    int FarmaExistente = 0;
    TpFARMA AuxFarma; //auxiliar temporario para leitura dos registros
    //system("cls");
    printf("*** inclusao ***\n\n");
    printf("Nome: ");
    scanf("%s",AuxFarma.Nome);

    fseek(ArqFarma, 0, 0);
      while (fread(&RgFarma,sizeof(RgFarma), 1, ArqFarma)){
        if (strcmp(AuxFarma.Nome, RgFarma.Nome)==0 && RgFarma.Ativo != -1)
        FarmaExistente=1;}
    
    if(FarmaExistente){
      printf("Esse farmaco ja existe no registro.\n\n");
    }else{  
      strcpy(RgFarma.Nome, AuxFarma.Nome);
      printf("Preco: ");
      scanf("%f",&RgFarma.Preco);
      printf("Estoque: ");
      scanf("%d",&RgFarma.QEstoque);
      fseek(ArqFarma,0,2);
      fwrite(&RgFarma,sizeof(RgFarma),1,ArqFarma);}
    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);}
  while (R!='N');
  return;}

long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/sizeof(RgFarma);
	return R;}

void Excluir() {
  if (TArquivo() != 0) {
    fclose(ArqFarma);
    ArqFarma = fopen("Farmacos.dat", "r+b");

    printf("*** exclusao ***\n\n");
    printf("Qual farmaco deseja excluir? ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    int Achou = 0;
    long int Posicao = 0;
    do {
      fread(&RgFarma, sizeof(RgFarma), 1, ArqFarma);
      if (strcmp(RgFarma.Nome, Farmaco) == 0) {
        Achou = 1;
        Posicao = ftell(ArqFarma) - sizeof(RgFarma);
        break;
      }
    } while (!feof(ArqFarma));

    if (Achou == 0) {
      printf("Registro inexistente!");
    } else {
      fseek(ArqFarma, Posicao, 0);
      // Marca o registro como excluído alterando o primeiro caractere do nome
      RgFarma.Ativo = -1;
      fwrite(&RgFarma, sizeof(RgFarma), 1, ArqFarma);
      printf(">>> Exclusao efetuada com sucesso! <<<\n");
    }
    fclose(ArqFarma);
    ArqFarma = fopen("Farmacos.dat", "a+b");
  } else {
    printf("Arquivo Vazio. Nao existem dados para excluir.");
  }
}

//função: Recupera registros implementada (melhoria)
void RecuperarRegistro() {
  if (TArquivo() != 0) {
    fclose(ArqFarma);
    ArqFarma = fopen("Farmacos.dat", "r+b");

    char RecuperaFarmaco[21];
    printf("Digite o nome do farmaco apagado que deseja recuperar: ");
    scanf("%s", RecuperaFarmaco);
    getchar();

    int Achou = 0;
    while (fread(&RgFarma, sizeof(RgFarma), 1, ArqFarma)) {
      if (strcmp(RgFarma.Nome, RecuperaFarmaco) == 0 && RgFarma.Ativo == -1) {
        Achou = 1;
        RgFarma.Ativo = 1; // marca como ativo
        fseek(ArqFarma, -sizeof(RgFarma), SEEK_CUR); // move para trás um registro
        fwrite(&RgFarma, sizeof(RgFarma), 1, ArqFarma);
        printf("Registro recuperado com sucesso!\n");
        break;
      }
    }

    if (Achou != 1) {
      printf("Registro nao encontrado!\n");
    }

    fclose(ArqFarma);
    ArqFarma = fopen("Farmacos.dat", "a+b");

  } else {
    printf("Arquivo vazio. Não existem dados a recuperar.");
  }
}


void Alterar(){
  if (TArquivo()!=0){
    fclose(ArqFarma); //modo a + b
    ArqFarma=fopen("Farmacos.dat","r+b");
    //system("cls");
    printf("*** alterar ***\n\n");  
    fseek(ArqFarma,0,0);
    printf("Qual farmaco? ");
    char Farmaco[21];
    scanf("%s",Farmaco);
    int Achou=0;
    do {
	    fread(&RgFarma,sizeof(RgFarma),1,ArqFarma);
	    if (strcmp(RgFarma.Nome,Farmaco)==0){
	      Achou=1;	
	      ExibirInformacoes(RgFarma);}} //funcao nova implementada
    while (!feof(ArqFarma) && (Achou==0));
    if (Achou==0)
      printf("Registro inexistente!"); 
    else{
      printf("Qual o novo preco? \n"); 
      scanf("%f",&RgFarma.Preco);
      printf("Qual a nova quantidade? \n");
      scanf("%d",&RgFarma.QEstoque);
      fseek(ArqFarma,-sizeof(RgFarma),1);
      fwrite(&RgFarma,sizeof(RgFarma),1,ArqFarma);
      printf(">>> Alteracao efetuada com sucesso! <<<\n");}
      //system("pause");
    fclose(ArqFarma);
    ArqFarma=fopen("Farmacos.dat","a+b");}
  else{
    printf("Arquivo Vazio.  Nao existem dados a alterar.");}
    //system("pause");
  return;}

void Consultar(){
  //system("cls");
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[21];
  scanf("%s",Farmaco);
  int Achou=0;
  do{
	  fread(&RgFarma,sizeof(RgFarma),1,ArqFarma);
	  if (strcmp(RgFarma.Nome,Farmaco)==0){
	    Achou=1;	
	    ExibirInformacoes(RgFarma);}} //funcao nova implementada
  while (!feof(ArqFarma) && (Achou==0));
  if (Achou==0)
    printf("Registro inexistente!");  
  //system("pause");
  return;}

void LTodos() {
  printf("*** lista todos ***\n\n");
  fseek(ArqFarma, 0, 0);

  while (fread(&RgFarma, sizeof(RgFarma), 1, ArqFarma)) {
    // Verifica se o registro não está marcado como excluído
    if (RgFarma.Ativo != -1) {
      ExibirInformacoes(RgFarma); //funcao nova implementada
      printf("***\n\n");
    }
  }
  fseek(ArqFarma, 0, 2);
}

int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
	  //system("cls");
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("R - Recuperar registro \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break; 
      case 'E': Excluir(); break; 
      case 'A': Alterar(); break; 
      case 'C': Consultar(); break; 
      case 'T': LTodos(); break;
      case 'R': RecuperarRegistro(); break;}} //adicionado novo case para função recuperar registro
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}
