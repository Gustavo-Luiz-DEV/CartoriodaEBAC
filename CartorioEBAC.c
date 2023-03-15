#include <stdio.h> // Biblioteca de comunic��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloc��o de espa�o na mem�ria
#include <locale.h> //Biblioteca de texto por regi�o
#include <string.h> //Strings

//Fun��es de op��es
int registro()
{
	setlocale(LC_ALL,"Portuguese");
	
	printf("\t\t\tRegistro de nomes!\n");
	
	//Dados
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//CPF
	
	printf("Digite o seu CPF: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w");
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // Escreve o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome do usu�rio ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file," Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o sobrenome do usu�rio ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file," Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo do usu�rio ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, " Cargo: ");
	fprintf(file,cargo);
	fclose(file);
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[50];
	char conteudo[200];
	
	
	printf("\t\t\tConsultar nomes\n");
	
	printf("Digite o CPF do usu�rio: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Arquivo n�o localizado!");
	}
	
	while (fgets(conteudo,200, file) != NULL) // enquanto procurar o conte�do no arqu�vo, e n�o for nulo
	{
		printf("\n\t\t\tinforma��es do usu�rio!\n\n");
		printf("\t%s",conteudo);
		printf("\n\n");
	}
	 system("pause");	
}

int deletar()
{
	//idioma
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("\t\t\tDeletar nomes!\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nusu�rio n�o encontrado\n");
	}
	
	else
	{
		//remove o usu�rio
		remove(cpf);
		printf("\nUsu�rio deletado com sucesso!\n");
	}
	
	system("pause");
}

//Programa Principal
int main()
{
	//Variavel de Op��o e Loop
	int opcao = 0;
	int loop = 0;
	
	// Idioma do texto
	setlocale(LC_ALL,"Portuguese");
	
	for (loop = 1; loop = 1;)
	{
		system("cls");
		
		//T�tulo
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t     Cart�rio da Ebac\n");
		printf("\t\t\t-------------------------\n");
		
		//Op��es
		printf("\t\t\t( 1 ) - Registrar Usu�rio\n");
		printf("\t\t\t( 2 ) - Consultar Usu�rio\n");
		printf("\t\t\t( 3 ) - Deletar Usu�rio\n");
		printf("\t\t\t( 4 ) - Sair do sistema\n");
		
		//Escolha
		printf("Escolha Uma op��o: ");
		scanf("%d", &opcao);
		
		//Op��o escolhida
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("\t\t A op��o %s n�o est� dispon�vel tente novamente!\n",opcao);
			system("pause");
			break;
			
		}
	}
}
