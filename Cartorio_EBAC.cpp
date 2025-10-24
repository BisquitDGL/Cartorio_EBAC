#include <stdio.h> //Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h> //Biblioteca de Aloca��o de Espa�o em Mem�ria
#include <locale.h> //Biblioteca de Aloca��es de Texto por Regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//In�cio da cria��o de vari�veis/strings
	char arquivo[60];
	char cpf[60];
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no Banco de Dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta ()//Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[60];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. N�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	
}


int deletar()//Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[60];
	
	printf("Digitar o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	
	else
	{
	remove(cpf);
	
	printf("O usu�rio foi deletado do sistema!\n");
	}
	
	system("pause");
}


int main()
{
	int opcao=0; //Definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		
		printf ("### Cart�rio da EBAC ### \n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("Op��o:"); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");//Respons�vel por limpar a tela
		{
			
			switch(opcao)//In�cio da sele��o do menu
			{
				case 1: 
				registro();//Chamada de fun��es
				break;
				
				case 2: 
				consulta();
				break;
				
				case 3: 
				deletar();
				break;
				
				default:
				printf("Op��o n�o dispon�vel!\n");
				system("pause");
				break;
				
			}	
		}
	}
}
