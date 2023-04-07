#include <stdio.h> //bilbioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro() //função responsável por cadastrar os usuários no sistema
{
	//inícnio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	int opcaoCargo=0;
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informaçõa do usuário
	scanf("%s", cpf); //* %s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por  copiar os valores da strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //este comando com "w" cria o arquivo e escreve (w de write)
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //salvo o valor da variável
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
	
	printf("Selecione o cargo a ser cadastrado:\n\n"); //menu de seleção de cargo
	printf("1 - Aluno\n");
	printf("2 - Monitor\n");
	printf("3 - Professor\n");
	printf("4 - Diretor\n");
	printf("Opção: ");
	scanf("%d",&opcaoCargo);
	
	switch(opcaoCargo) //decisão de cargo
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
		printf("Opção inválida!\n");
		system("pause");
		break;
			
	}
	
	system("pause");
}

int consulta() //função responsável por consultar usuários no sistema
{
	setlocale (LC_ALL, "Portuguese"); //definição de linguagem
	char cpf[40]; // criação de variáveis
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando usuário para consulta
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrindo o arquivo indicado
	
	if(file == NULL) //caso arquivo não exista
	{
		printf("Usuário não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //mostrar dados consultados
	{
		printf("Essas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar() //função responsável por deletar usuários no sistema
{
	setlocale (LC_ALL, "Portuguese"); //definição de linguagem
	char cpf[40]; //criação de variáveis e strings
	char conteudo[200];
	int confirma=0;
	
	printf("Digite o CPF a ser deletado: "); //coletando usuário a ser deletado
	scanf("%s",cpf);
	
	
	
	FILE *file; //abrindo arquivo do usuário indicado
	file = fopen(cpf,"r"); //"r" para leitura do arquivo (read)
	
	if(file == NULL) //caso arquivo não seja encontrado
	{
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	else //caso arquivo seja encontrado
	{
		while(fgets(conteudo, 200, file) !=NULL) //exibindo dados a serem deletados
		{
			printf("Essas são as informações do usuário: \n\n");
			printf("%s\n", conteudo);
			fclose(file);
		}
	
		printf("Deletar?\n\n1 - Sim\n2 - Não\n\n"); //confirmação para deletar
		printf("Opção: ");
		scanf("%d",&confirma);
		
		switch(confirma) //início da decisão
		{
		case 1:
			remove(cpf); //deletar o arquivo
			printf("O usuário foi deletado.\n\n");
			system("pause");
			break;
		
		case 2:
			printf("O usuário NÃO foi deletado.\n\n");
			system("pause");
			break;
			
		default:
			printf("Esta opção não existe.\n\n");
			system("pause");
			break;
		} //fim da decisão
		
		
	}
	
	fclose(file);
}



int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;) //repetição da escolha no menu
	{
		
		system("cls");
		
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("===== Sistema de Usuários da EBAC =====\n\n"); //início do menu
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 - Cadastrar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Deletar usuário\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //final do menu
	
		scanf("%d",&opcao); //armazenando escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) //inicio da decisao
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Opção inválida!\n");
			system("pause");
			break;
		} //final da decisao
	
	
	}
	
}
