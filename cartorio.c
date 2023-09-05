#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h>//bliblioteca de alocaçao de espaço em memoria 
#include <locale.h>//biblioteca de alocaçoes de texto por regiao 
#include <string.h>//biblioteca responsável por cuidar das string

int registro()//Função responasavel por cadastrar os usuários no sistema
{
	//inicio da  criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da  criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");// Abrir o arquivo e o "w" significa escrever
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,nome);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome);// salvo o valor da variavel
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,",");//"," pra dar a virgula 
	fclose(file);// fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//%s refere-se a string
	
	
	file = fopen(arquivo, "a");// Abrir o arquivo e o "a" significa atualizar
	fprintf(file,cargo);//"," pra dar a virgula
	fclose(file);// fecho o arquivo
	
	system("pause");// Sereve para pausar o arquivo
	
}

int consulta()//Função responasavel por consultar os usuários no sistema
{
    setlocale(LC_ALL, "portuguese");//definindo a linguagem	
	//inicio da  criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da  criação de variáveis/string
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;// cria o arquivo
	file = fopen(cpf, "r");//Abrir o arquivo e o "r" significa ler o arquivo
	
	if(file == NULL)//if == NULL siguinifica que se o usuario não cadastrou essa informação no sistema 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário" );//coletando informação do usuário
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n");//\n serve pra dar espaço 
	}
	
	system("pause");// Sereve para pausar o arquivo
	
	
}

int deletar()//Função responasavel por deletar os usuários no sistema
{
	//inicio da  criação de variáveis/string
     char cpf[40];
     
     printf("Digite o CPF do usuário a ser deletado: ");//coletando informação do usuário
     scanf("%s",cpf);//%s refere-se a string
     
     remove(cpf);//serve para deletar do sistema 
     
     FILE *file;// cria o arquivo
     file = fopen(cpf,"r");//Abrir o arquivo e o "r" significa ler o arquivo
     
     if(file == NULL)//if == NULL siguinifica que se o usuario não cadastrou essa informação no sistema 
     {
     	printf("O usuário não se encontra no sistema!.\n");//coletando informação do usuário
     	system("pause");// Sereve para pausar o arquivo
	 }
}

int main()
{
	  int opcao=0;//Definindo as variáveis
	  int x=1;
	 
	  for(x=1;x=1;)
{
	
	  system("cls");//responsavel por limpar a tela  
	
	 setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	 printf("###cartório da EBAC###\n\n");//inicio do menu 
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1- Resgistrar nomes\n");
     printf("\t2- Consultar nomes\n");
     printf("\t3- Deletar nomes\n\n");
	 printf("Opcao:");//Fim do menu
   
     scanf("%d", &opcao);//amarzenado a escolha do usuário
    
     system("cls");
    
    
	 switch(opcao)//inicio da seleção do menu
	 {
	 	case 1:
	 	registro();//chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
	    deletar();
        break;
        
		default:
        printf("Essa opção não esta disponivel!\n");
	    system("pause");
		break;	
		}
}//final da seleção do menu
} 


