#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h>//bliblioteca de aloca�ao de espa�o em memoria 
#include <locale.h>//biblioteca de aloca�oes de texto por regiao 
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//Fun��o responasavel por cadastrar os usu�rios no sistema
{
	//inicio da  cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da  cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");// Abrir o arquivo e o "w" significa escrever
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,nome);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//%s refere-se a string
	
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,cargo);//"," pra dar a virgula
	fclose(file);// fecho o arquivo
	
	system("pause");// Sereve para pausar o arquivo
	
}

int consulta()//Fun��o responasavel por consultar os usu�rios no sistema
{
    setlocale(LC_ALL, "portuguese");//definindo a linguagem	
	//inicio da  cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da  cria��o de vari�veis/string
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;// cria o arquivo
	file = fopen(cpf, "r");//Abrir o arquivo e o "r" significa ler o arquivo
	
	if(file == NULL)//if == NULL siguinifica que se o usuario n�o cadastrou essa informa��o no sistema 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio" );//coletando informa��o do usu�rio
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n");//\n serve pra dar espa�o 
	}
	
	system("pause");// Sereve para pausar o arquivo
	
	
}

int deletar()//Fun��o responasavel por deletar os usu�rios no sistema
{
	//inicio da  cria��o de vari�veis/string
     char cpf[40];
     
     printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o do usu�rio
     scanf("%s",cpf);//%s refere-se a string
     
     remove(cpf);//serve para deletar do sistema 
     
     FILE *file;// cria o arquivo
     file = fopen(cpf,"r");//Abrir o arquivo e o "r" significa ler o arquivo
     
     if(file == NULL)//if == NULL siguinifica que se o usuario n�o cadastrou essa informa��o no sistema 
     {
     	printf("O usu�rio n�o se encontra no sistema!.\n");//coletando informa��o do usu�rio
     	system("pause");// Sereve para pausar o arquivo
	 }
}

int main()
{
	  int opcao=0;//Definindo as vari�veis
	  int x=1;
	 
	  for(x=1;x=1;)
{
	
	  system("cls");//responsavel por limpar a tela  
	
	 setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	 printf("###cart�rio da EBAC###\n\n");//inicio do menu 
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1- Resgistrar nomes\n");
     printf("\t2- Consultar nomes\n");
     printf("\t3- Deletar nomes\n\n");
	 printf("Opcao:");//Fim do menu
   
     scanf("%d", &opcao);//amarzenado a escolha do usu�rio
    
     system("cls");
    
    
	 switch(opcao)//inicio da sele��o do menu
	 {
	 	case 1:
	 	registro();//chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
	    deletar();
        break;
        
		default:
        printf("Essa op��o n�o esta disponivel!\n");
	    system("pause");
		break;	
		}
}//final da sele��o do menu
} 


