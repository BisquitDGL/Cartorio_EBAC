#include <stdio.h> //Biblioteca de Comunicação com o Usuário
#include <stdlib.h> //Biblioteca de Alocação de Espaço em Memória
#include <locale.h> //Biblioteca de Alocações de Texto por Região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro()//Função responsável por cadastrar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//Início da criação de variáveis/strings
	char arquivo[60];
	char cpf[60];
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no Banco de Dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
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

int consulta ()//Função responsável por consultar os usuários no sistema
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
		printf("Não foi possível abrir o arquivo. Não localizado!\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	
}


int deletar()//Função responsável por deletar os usuários no sistema
{
	char cpf[60];
	
	printf("Digitar o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	else
	{
	remove(cpf);
	
	printf("O usuário foi deletado do sistema!\n");
	}
	
	system("pause");
}


int main()
{
	int opcao=0; //Definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		
		printf ("### Cartório da EBAC ### \n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("Opção:"); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");//Responsável por limpar a tela
		{
			
			switch(opcao)//Início da seleção do menu
			{
				case 1: 
				registro();//Chamada de funções
				break;
				
				case 2: 
				consulta();
				break;
				
				case 3: 
				deletar();
				break;
				
				default:
				printf("Opção não disponível!\n");
				system("pause");
				break;
				
			}	
		}
	}
}
