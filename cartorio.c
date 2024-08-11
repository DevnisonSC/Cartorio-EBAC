#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao=0;
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser registrado:"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //abre o aquivo e "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma v�rgula 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser registrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //criando a string respons�vel por armazear o dado "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,nome); //adiciona os dados ao arquivo, neste caso o "nome"
	fclose(file); //fecha o aquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser registrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //criando a string respons�vel por armazear o dado "sobrenome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,sobrenome); //adiciona os dados ao arquivo, neste caso o "sobrenome"
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file, ","); //adiciona os dados ao arquivo, neste caso uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser registrado: "); //coletando informa��es do usu�rio
	scanf("%s",cargo); //criando a string respons�vel por armazear o dado "cargo"
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa adicionar dados ao aquivo
	fprintf(file,cargo); //adiciona os dados ao arquivo, neste caso o "cargo"
	fclose(file); //fecha o arquivo
	
	printf("Usu�rio resgistrado com sucesso.\n\n");
	
	printf(" Deseja registrar um novo usu�rio? \n"); //op��o para registrar novo usu�rio ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n");
	
	while (1) //repetir enquanto n�o cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //in�cio da sele��o
			case 1:
			registrar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n\n");
			printf("Deseja registrar um novo usu�rio? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - N�o\n");
			break;
		} //fim da sele��o
	} //fim da repeti��o
	
	system("pause"); //pausa a execu��o do programa
}

int consultar() //fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio de cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //criando a string respons�vel por armazear o dado "cpf"
	
	FILE*file; //cria um arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" significa leitura (read)
	
	if(file == NULL) //condicional: se o arquivo for nulo executar o seguinte
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n\n"); //informa impossibilidade de abrir o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repeti��o: enquanto o conte�do for diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //transmite ao usu�rio os dados consultados
		printf("%s", conteudo); 
		printf("\n\n");
	}
		
	printf("Deseja consultar um novo usu�rio? \n"); //op��o para consultar novo usu�rio ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n");
	
	while (1) //repetir enquanto n�o cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //in�cio da sele��o
			case 1:
			consultar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n\n");
			printf("Deseja consultar um novo usu�rio? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - N�o\n");
			break;
		} //fim da sele��o
	} //fim da repeti��o
	
	system("pause"); //pausa a execu��o do programa
}

int deletar()
{
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	int opcao=0;
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");//coletando informa��es do usu�rio
	scanf("%s",cpf);//criando a string respons�vel por armazear o dado "cpf"
	
	FILE *file;
	file = fopen(cpf,"r"); //abre e ler o aquivo
	
	if(file == NULL) //condi��o: se o arquivo n�o existir
	{
		printf("O usu�rio n�o se encontra no sistema.\n\n");
		system("pause");
	} else {		//condi��o: caso contr�rio
		fclose(file); //� necess�rio fechar o aquivo antes de delet�-lo
		remove(cpf); //exclui o arquivo
		printf("Usu�rio deletado com sucesso.\n\n");
	}
	
	printf("Deseja deletar um novo usu�rio? \n"); //op��o para deletar novo usu�rio ou voltar ao menu principal
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n");
	
	while (1) //repetir enquanto n�o cair em algum dos casos
	{ 
		scanf("%d", &opcao); //armazena a escolha
		
		switch(opcao){ //in�cio da sele��o
			case 1:
			deletar();
			break;
		
			case 2:
			main();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n\n");
			printf("Deseja deletar um novo usu�rio? \n");
			printf("\t1 - Sim\n");
			printf("\t2 - N�o\n");
			break;
		} //fim da sele��o
	} //fim da repeti��o
	
	system("pause"); //pausa a execu��o do programa
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao); //Armazenando as informa��es
	
		system("cls"); //Limpa a tela
	
		switch(opcao) //inicio da sele��o
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
			printf("Essa op��o n�o est� dispon�vel.\n");
			system("pause");
			break;
		}//Fim da sele��o
	
	}
}
