#include<stdio.h>//bibliotecade comunicaçao com o usuario
#include<stdlib.h>//biblioteca de alocaçao de espaço em momoria
#include<locale.h>//bibliteca de alocaçao de texto por regiao
#include<string.h>//biblioteca responsavel por cuidar das strings

int registrar()// função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis, strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis, strings
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",cpf); //"%s" refere-se as string
	strcpy(arquivo, cpf); //reponsavel por copiar os valores das strings
	
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informação do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!.\n\n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	printf("###Cartorio da EBAC###\n\n"); //inicio do menu
	printf("escolha a opçao desejada do menu:\n\n");
	printf("\t1: registrar nomes\n");
	printf("\t2: consutar nomes\n");
	printf("\t3: deletar nomes\n");
	printf("\t4: sair do sistema\n\n");
	printf("opcao:"); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//responsavel por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registrar();//chamada de funções
			break;
			
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema.\n");
			return 0;
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção do menu
			
	}	
}
