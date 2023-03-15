#include <stdio.h> // Biblioteca de comunicção com o usuário
#include <stdlib.h> // Biblioteca de alocção de espaço na memória
#include <locale.h> //Biblioteca de texto por região
#include <string.h> //Strings

//Funções de opções
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
	fprintf(file,cpf); // Escreve o valor da variável
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome do usuário ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file," Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o sobrenome do usuário ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file," Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo do usuário ");
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
	
	printf("Digite o CPF do usuário: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Arquivo não localizado!");
	}
	
	while (fgets(conteudo,200, file) != NULL) // enquanto procurar o conteúdo no arquívo, e não for nulo
	{
		printf("\n\t\t\tinformações do usuário!\n\n");
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
		printf("\nusuário não encontrado\n");
	}
	
	else
	{
		//remove o usuário
		remove(cpf);
		printf("\nUsuário deletado com sucesso!\n");
	}
	
	system("pause");
}

//Programa Principal
int main()
{
	//Variavel de Opção e Loop
	int opcao = 0;
	int loop = 0;
	
	// Idioma do texto
	setlocale(LC_ALL,"Portuguese");
	
	for (loop = 1; loop = 1;)
	{
		system("cls");
		
		//Título
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t     Cartório da Ebac\n");
		printf("\t\t\t-------------------------\n");
		
		//Opções
		printf("\t\t\t( 1 ) - Registrar Usuário\n");
		printf("\t\t\t( 2 ) - Consultar Usuário\n");
		printf("\t\t\t( 3 ) - Deletar Usuário\n");
		printf("\t\t\t( 4 ) - Sair do sistema\n");
		
		//Escolha
		printf("Escolha Uma opção: ");
		scanf("%d", &opcao);
		
		//Opção escolhida
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
			printf("\t\t A opção %s não está disponível tente novamente!\n",opcao);
			system("pause");
			break;
			
		}
	}
}
