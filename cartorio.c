#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao=0;
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser registrado:"); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //abre o aquivo e "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma vírgula 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser registrado: "); //coletando informações do usuário
	scanf("%s",nome); //criando a string responsável por armazear o dado "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,nome); //adiciona os dados ao arquivo, neste caso o "nome"
	fclose(file); //fecha o aquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser registrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //criando a string responsável por armazear o dado "sobrenome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,sobrenome); //adiciona os dados ao arquivo, neste caso o "sobrenome"
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser registrado: "); //coletando informações do usuário
	scanf("%s",cargo); //criando a string responsável por armazear o dado "cargo"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,cargo); //adiciona os dados ao arquivo, neste caso o "cargo"
	fclose(file); //fecha o arquivo
	
	printf("Usuário resgistrado com sucesso.\n\n");
	
	printf(" Deseja registrar um novo usuário? \n"); //opção para registrar novo usuário ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	
	while (1) //repetir enquanto não cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //início da seleção
			case 1:
			registrar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa opção não está disponível.\n\n");
			printf("Deseja registrar um novo usuário? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - Não\n");
			break;
		} //fim da seleção
	} //fim da repetição
	
	system("pause"); //pausa a execução do programa
}

int consultar() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início de criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //criando a string responsável por armazear o dado "cpf"
	
	FILE*file; //cria um arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" significa leitura (read)
	
	if(file == NULL) //condicional: se o arquivo for nulo executar o seguinte
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n\n"); //informa impossibilidade de abrir o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repetição: enquanto o conteúdo for diferente de nulo
	{
		printf("\nEssas são as informações do usuário: "); //transmite ao usuário os dados consultados
		printf("%s", conteudo); 
		printf("\n\n");
	}
		
	printf("Deseja consultar um novo usuário? \n"); //opção para consultar novo usuário ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	
	while (1) //repetir enquanto não cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //início da seleção
			case 1:
			consultar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa opção não está disponível.\n\n");
			printf("Deseja consultar um novo usuário? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - Não\n");
			break;
		} //fim da seleção
	} //fim da repetição
	
	system("pause"); //pausa a execução do programa
}

int deletar()
{
	//início da criação de variáveis/string
	char cpf[40];
	int opcao=0;
	//final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: \n");//coletando informações do usuário
	scanf("%s",cpf);//criando a string responsável por armazear o dado "cpf"
	
	FILE *file;
	file = fopen(cpf,"r"); //abre e ler o aquivo
	
	if(file == NULL) //condição: se o arquivo não existir
	{
		printf("O usuário não se encontra no sistema.\n\n");
		system("pause");
	} else {		//condição: caso contrário
		fclose(file); //é necessário fechar o aquivo antes de deletá-lo
		remove(cpf); //exclui o arquivo
		printf("Usuário deletado com sucesso.\n\n");
	}
	
	printf("Deseja deletar um novo usuário? \n"); //opção para deletar novo usuário ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	
	while (1) //repetir enquanto não cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //início da seleção
			case 1:
			deletar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa opção não está disponível.\n\n");
			printf("Deseja deletar um novo usuário? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - Não\n");
			break;
		} //fim da seleção
	} //fim da repetição
	
	system("pause"); //pausa a execução do programa
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao); //Armazenando as informações
	
		system("cls"); //Limpa a tela
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível.\n");
			system("pause");
			break;
		}//Fim da seleção
	
	}
}
