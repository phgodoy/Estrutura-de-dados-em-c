//Estruturaa da agenda

struct agenda{
	char  nome[40];
	char  email[40];
	int   idade;
	char   telefone[40];
	struct agenda *prox;
	struct agenda *ant;
};
typedef struct agenda contato;

//Funcoes graficas 

void clear(){
	system("cls");
}
 
void load(){
	char ascii = 178;
	
	clear();

	printf("***********CARREGANDO***********");
	printf("\n");
	for(int i = 0;i<32;i++){
		printf("%c%",ascii);
		Sleep(50);
	}
	clear();
}

void exit(){
	char ascii = 178;
	
	clear();	
	printf("***********SAINDO***********");
	printf("\n");
	for(int i = 0;i<28;i++){
		printf("%c%",ascii);
		Sleep(50);
	}
	clear();
}

void color_graphic(){
	system("color A");
}

//Variaveis golbais
FILE *pont_arq; //ponteiro de arquivo
char resp = 'S';
int  op=-7;
int  i=0;
int  cont=0;

//Funcoes pora ponteiro

bool eh_vazia(contato *inicio){
	if(inicio->prox==NULL){
		printf("\nlista vazia\n");
		return true;
		
	}
}

 contato *cria_ponteiro(void){
		contato *p=(contato*)malloc(sizeof(contato));
	if(!p)
	{
		printf("erro");
	}
	else
	{
		p->nome[0] = NULL;
		p->idade = NULL;
		p->email[0] = NULL;
		p->telefone[0] = NULL;
		p->prox = NULL;
		p->ant = NULL;
		
	}
	
	return p;
};


void inserir(contato *inicio){
		contato *nova = cria_ponteiro();
		printf("\ninforme o nome: ");
		fflush(stdin);
		gets(nova->nome);
		printf("\ninforme a idade: ");
		scanf("%d",&nova->idade);
		printf("\ninforme o e-mail: ");
		fflush(stdin);
		gets(nova->email);
		printf("\ninforme o telefone:");
		fflush(stdin);
		gets(nova->telefone);
		
		if(inicio->prox==NULL)
	{
		inicio->prox=nova;
		inicio->ant = nova;
		nova->prox = inicio;
		nova->ant=inicio;
			
	}
	else
	{
		contato *temp;
		temp=inicio;
		while(temp->prox !=inicio)
		{
			temp=temp->prox;
		}
			
		temp->prox=nova;
		nova->prox = inicio;
		nova->ant=temp;	
		inicio->ant = nova;	
	}					
}

void inserir_inicio(contato *inicio){
		contato *nova = cria_ponteiro();
		printf("\ninforme o nome: ");
		fflush(stdin);
		gets(nova->nome);
		printf("\ninforme a idade: ");
		scanf("%d",&nova->idade);
		printf("\ninforme o e-mail: ");
		fflush(stdin);
		gets(nova->email);
		printf("\ninforme o telefone:");
		fflush(stdin);
		gets(nova->telefone);
		
	nova->prox = inicio->prox;
	nova->ant = inicio;
	inicio->prox = nova;
	
						
}


void imprimir(contato *inicio){
	contato *temp;
	temp = inicio;
	printf("***********LISTA***********");
	while(temp->prox !=inicio){
		    temp = temp->prox;
			printf("\nnome: %s ",temp->nome);
			printf("\nidade: %d", temp->idade);
			printf("\ne-mail: %s",temp->email);
			printf("\ntelefone: %s",temp->telefone);
			printf("\n");
		}
	printf("***************************\n");
}

void consultar(contato *inicio){
	char consulta[30];
	printf("\ninforme o nome do contaro: ");
	fflush(stdin);
	gets(consulta);
	clear();
	contato *temp;
	temp=inicio;
	while(temp!=NULL)
	{
		if(strcmp(consulta,temp->nome)==0)
		{	
			printf("\nnome: %s ",temp->nome);
			printf("\nidade: %d", temp->idade);
			printf("\ne-mail: %s",temp->email);
			printf("\ntelefone: %s",temp->telefone);
			printf("\n");
			temp=temp->prox;
		}
		else
		{
			temp=temp->prox;
		}
	}
	
}

void editar_contato(contato *inicio){
		char edita[30];
		printf("\ninforme o nome do contaro que deseja editar: ");
		fflush(stdin);
		gets(edita);
		clear();
		contato *temp;
		temp = inicio;
		
			
		printf("***********EDICAO***********");
		while(temp!=NULL){
			if(strcmp(edita,temp->nome)==0){
				printf("\ninforme o nome: ");
				fflush(stdin);
				gets(temp->nome);
				printf("\ninforme a idade: ");
				scanf("%d",&temp->idade);
				printf("\ninforme o e-mail: ");
				fflush(stdin);
				gets(temp->email);
				printf("\ninforme o telefone:");
				fflush(stdin);
				gets(temp->telefone);
				break;
			} 
			else{
				temp = temp->prox;
			}
		}	
}


void remover_contato(contato *inicio){
	char consulta[30];
	int qtd = 0;
	printf("\ninforme o nome do contaro que deseja remover: ");
	fflush(stdin);
	gets(consulta);
	clear();
	contato *temp;
	contato *aux;
	temp=inicio->prox;
	aux=inicio;
	while(temp!=inicio){
		if(strcmp(consulta,temp->nome)==0)
		{	
			qtd +=1;
		}	
		temp = temp->prox;
	}
	if(qtd == 0){
		printf("\ncontato nao existe\n");
	
	}
	else if(qtd==1){
		temp=inicio->prox;
		aux=inicio;
		while(temp!=inicio)
		{	
			if(strcmp(consulta,temp->nome)==0)
			{
				aux->prox=temp->prox;
				aux->ant = temp->ant;
				free(temp);
			}
			temp=temp->prox;
			aux=aux->prox;
		}
	}
	else{
		temp=inicio->prox;
		aux=inicio;
		while(temp!=inicio)
		{
			if(strcmp(consulta,temp->nome)==0)
			{	
				printf("\nnome: %s ",temp->nome);
				printf("\nidade: %d", temp->idade);
				printf("\ne-mail: %s",temp->email);
				printf("\ntelefone: %s",temp->telefone);
				printf("\n");
				temp=temp->prox;
			}
			else
			{
				temp=temp->prox;
			}
		}
		temp=inicio->prox;
		aux=inicio;
		printf("informe o telefone do contaro que deseja remover: ");
		fflush(stdin);
		gets(consulta);
		clear();
		while(temp!=NULL)
		{	
			if(strcmp(consulta,temp->telefone)==0)
			{
				aux->prox=temp->prox;
				aux->ant = temp->ant;
				free(temp);
			}
			temp=temp->prox;
			aux=aux->prox;
		}
		
	}
	
	
	
}

void imprimir_inverso(contato *inicio){
	contato *temp;
	contato *aux;
	temp = inicio->ant;
          


	printf("***********LISTA***********");
	while(temp !=inicio){
		 
	
		
			printf("\nnome: %s ",temp->nome);
			printf("\nidade: %d", temp->idade);
			printf("\ne-mail: %s",temp->email);
			printf("\ntelefone: %s",temp->telefone);
			printf("\n");
			temp = temp->ant;
		}
	printf("***************************\n");
	
}

void sair(){
	//fecha o arquivo
	fclose(pont_arq);
	printf("***************************\n");
	printf("      FIM DO PROGRAMA ");
	printf("\n***************************\n");
	Sleep(500);
	op = 666;
	system("pause");
}

void op_invalida(){
	char continua = 'x';
	printf("\ninforme uma  opcao valida de 1 - 6\n ");
	do{
		printf(":Precione qualquer tecla para continuar . . .");
		continua=getch();
		clear();
		break;
	}while(continua!=NULL);
		
}
