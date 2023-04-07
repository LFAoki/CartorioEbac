#include <stdio.h> //bilbioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cnio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	int opcaoCargo=0;
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��a do usu�rio
	scanf("%s", cpf); //* %s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por  copiar os valores da strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //este comando com "w" cria o arquivo e escreve (w de write)
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //salvo o valor da vari�vel
	fprintf(file,", ");
	fclose(file); //fecha o arquivo
		
	printf("Digite o nome a ser cadastrado: "); //coletando o nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //inserindo o nome no arquivo
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fprintf(file," ");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //inserindo o sobrenome no arquivo
	fprintf(file,sobrenome);
	fprintf(file,", ");
	fclose(file);
	
	printf("Selecione o cargo a ser cadastrado:\n\n"); //menu de sele��o de cargo
	printf("1 - Aluno\n");
	printf("2 - Monitor\n");
	printf("3 - Professor\n");
	printf("4 - Diretor\n");
	printf("Op��o: ");
	scanf("%d",&opcaoCargo);
	
	switch(opcaoCargo) //decis�o de cargo
	{
		case 1:
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: Aluno\n");
		fclose(file);
		break;
		
		case 2:
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: Monitor\n");
		fclose(file);
		break;
		
		case 3:
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: Professor\n");
		fclose(file);
		break;
		
		case 4:
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: Diretor\n");
		fclose(file);
		break;
				
		default:
		printf("Op��o inv�lida!\n");
		system("pause");
		break;
			
	}
	
	system("pause");
}

int consulta() //fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale (LC_ALL, "Portuguese"); //defini��o de linguagem
	char cpf[40]; // cria��o de vari�veis
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando usu�rio para consulta
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrindo o arquivo indicado
	
	if(file == NULL) //caso arquivo n�o exista
	{
		printf("Usu�rio n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //mostrar dados consultados
	{
		printf("Essas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar usu�rios no sistema
{
	setlocale (LC_ALL, "Portuguese"); //defini��o de linguagem
	char cpf[40]; //cria��o de vari�veis e strings
	char conteudo[200];
	int confirma=0;
	
	printf("Digite o CPF a ser deletado: "); //coletando usu�rio a ser deletado
	scanf("%s",cpf);
	
	
	
	FILE *file; //abrindo arquivo do usu�rio indicado
	file = fopen(cpf,"r"); //"r" para leitura do arquivo (read)
	
	if(file == NULL) //caso arquivo n�o seja encontrado
	{
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
	}
	else //caso arquivo seja encontrado
	{
		while(fgets(conteudo, 200, file) !=NULL) //exibindo dados a serem deletados
		{
			printf("Essas s�o as informa��es do usu�rio: \n\n");
			printf("%s\n", conteudo);
			fclose(file);
		}
	
		printf("Deletar?\n\n1 - Sim\n2 - N�o\n\n"); //confirma��o para deletar
		printf("Op��o: ");
		scanf("%d",&confirma);
		
		switch(confirma) //in�cio da decis�o
		{
		case 1:
			remove(cpf); //deletar o arquivo
			printf("O usu�rio foi deletado.\n\n");
			system("pause");
			break;
		
		case 2:
			printf("O usu�rio N�O foi deletado.\n\n");
			system("pause");
			break;
			
		default:
			printf("Esta op��o n�o existe.\n\n");
			system("pause");
			break;
		} //fim da decis�o
		
		
	}
	
	fclose(file);
}



int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;) //repeti��o da escolha no menu
	{
		
		system("cls");
		
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("===== Sistema de Usu�rios da EBAC =====\n\n"); //in�cio do menu
		printf("Selecione a op��o desejada:\n\n");
		printf("\t1 - Cadastrar usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Deletar usu�rio\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //final do menu
	
		scanf("%d",&opcao); //armazenando escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) //inicio da decisao
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o inv�lida!\n");
			system("pause");
			break;
		} //final da decisao
	
	
	}
	
}
