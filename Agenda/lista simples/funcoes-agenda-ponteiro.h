//Estruturaa da agenda

struct agenda{
	char  nome[40];
	char  email[40];
	int   idade;
	char   telefone[40];
	struct agenda *prox;
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

//variaveis por ponteiro

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
	}
	else
	{
		contato *temp;
		temp=inicio;
		while(temp->prox !=NULL)
		{
			temp=temp->prox;
		}
			
		temp->prox=nova;		
	}					
}

void imprimir(contato *inicio){
	contato *temp;
	temp = inicio;
	printf("***********LISTA***********");
	while(temp->prox !=NULL){
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
			break;
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
	printf("\ninforme o nome do contaro que deseja remover: ");
	fflush(stdin);
	gets(consulta);
	clear();
	contato *temp;
	contato *aux;
	temp=inicio->prox;
	aux=inicio;
	while(temp!=NULL)
	{	
		if(strcmp(consulta,temp->nome)==0)
		{
			aux->prox=temp->prox;
			free(temp);
		}
		temp=temp->prox;
		aux=aux->prox;
	}
	
}

void imprimir_inverso(contato *inicio){
	contato *temp;
	contato *aux;
	temp = inicio->prox;
          
	while(temp->prox != NULL){
		temp = temp->prox;
	}   

	printf("***********LISTA***********");
	while(temp !=inicio){
			aux  = inicio;  
		while(aux->prox!=temp){
			aux = aux->prox;
		}
		
			printf("\nnome: %s ",temp->nome);
			printf("\nidade: %d", temp->idade);
			printf("\ne-mail: %s",temp->email);
			printf("\ntelefone: %s",temp->telefone);
			printf("\n");
			temp = aux;
		}
	printf("***************************\n");
	
}

//Variaveis golbais
FILE *pont_arq; //ponteiro de arquivo
char resp = 'S';
int  op=-7;
int  i=0;
int  cont=0;


//Funcoes do sistema
bool eh_vazia(){
	if(cont ==0){
		printf("\nlista vazia!!");
		return true;
	}
	else{
		return false;
	}
}


/*
void inserir(){
	int x ;
	i=cont;
	
	cria_arq();
	
	do{
		if(i>=5){
			printf("\nagenda lotada... ");
			break;
		}
		printf("\ninforme o nome: ");
		fflush(stdin);
		gets(contato[i].nome);
		fprintf(pont_arq, "\nnome:%s", contato[i].nome);
		printf("\ninforme a idade: ");
		scanf("%d",&contato[i].idade);
		fprintf(pont_arq, "\nidade:%d", contato[i].idade);
		printf("\ninforme o e-mail: ");
		fflush(stdin);
		gets(contato[i].email);
		fprintf(pont_arq, "\nemail:%s", contato[i].email);
		printf("\ninforme o telefone:");
		fflush(stdin);
		gets(contato[i].telefone);
		fprintf(pont_arq, "\ntelefone:%s\n", contato[i].telefone);
	
		i+=1;
		cont+=1;
		while(toupper(resp)!='N'){
			printf("\ndeseja continuar<s/n>:\n ");
			resp = getch();
			clear();
			while(!(toupper(resp)=='S'|| toupper(resp)=='N')){
				printf("comando nao reconhecido!\n ");
				printf("\ndeseja continuar<s/n>:\n ");
				resp = getch();
				clear();
			}
		}
		
	
	}while(toupper(resp)!='N');
	
}
*/
/*
void imprimir(){
	if(!eh_vazia()){
		i=0;
		char continua ='x';
		printf("***********LISTA***********");
		while(i<cont or contato[i].idade!=0){
			printf("\nnome: %s ",contato[i].nome);
			printf("\nidade: %d", contato[i].idade);
			printf("\ne-mail: %s",contato[i].email);
			printf("\ntelefone: %s",contato[i].telefone);
			printf("\n");
			i+=1;
		}
		printf("***************************\n");
		do{
			printf("Precione qualquer tecla para continuar . . .");
			continua=getch();
			clear();
			break;	
		}while(continua!=NULL);
	}	
}*/
/*
void consultar(){
	if(!eh_vazia()){	
		i=0;
		char pesquisa[30];
		char continua ='x';
		printf("\ninforme o nome do contaro: ");
		fflush(stdin);
		gets(pesquisa);
		clear();
		printf("***********CONSULTA***********");
		while(i<cont or contato[i].idade!=0){
		
			if(strcmp(pesquisa,contato[i].nome)==0){
				printf("\nnome: %s ",contato[i].nome);
				printf("\nidade: %d", contato[i].idade);
				printf("\ne-mail: %s",contato[i].email);
				printf("\ntelefone: %s\n",contato[i].telefone);
			}			
			i+=1;
		}
		if(i==cont){
			if(strcmp(pesquisa,contato[i].nome)!=0){
				printf("\n contano nao existe!\n ");
			}
		}
		printf("\n******************************\n");
		do{
			printf("Precione qualquer tecla para continuar . . .");
			continua=getch();
			clear();
			break;
		}while(continua!=NULL);
	}
}
*/
/*
void editar_contato(){
	if(!eh_vazia()){
			i=0;
	
		char edita[30];
		printf("\ninforme o nome do contaro que deseja editar: ");
		fflush(stdin);
		gets(edita);	
		printf("***********EDICAO***********");
		while(i<cont){
			if(strcmp(edita,contato[i].nome)==0){
				printf("\ninforme o nome: ");
				fflush(stdin);
				gets(contato[i].nome);
				fprintf(pont_arq, "\nnome:%s", contato[i].nome);
				printf("\ninforme a idade: ");
				scanf("%d",&contato[i].idade);
				fprintf(pont_arq, "\nidade:%d", contato[i].idade);
				printf("\ninforme o e-mail: ");
				fflush(stdin);
				gets(contato[i].email);
				fprintf(pont_arq, "\nemail:%s", contato[i].email);
				printf("\ninforme o telefone:");
				fflush(stdin);
				gets(contato[i].telefone);
				fprintf(pont_arq, "\ntelefone:%s\n", contato[i].telefone);
			}
					
			i+=1;
		}
		printf("\n***************************\n");
		char continua = 'x';
	
		do{
			printf(":edicao bem sucedida, precione qualquer tecla para continuar . . .");
			continua=getch();
			clear();
			break;
		}while(continua!=NULL);
	}	
}

void remover_contato(){
	if(!eh_vazia()){
			i=0;
		char remove[30];
		char continua = 'x';
		printf("\ninforme o nome do contaro que deseja remover: ");
		fflush(stdin);
		gets(remove);
		while(i<cont){
			if(strcmp(remove,contato[i].nome)==0){
				strcpy(contato[i].nome, "\0" );
			
				contato[i].idade = NULL;
				
				strcpy(contato[i].email, "\0" );
				//malloc(sizeof(contato[i].email));
				strcpy(contato[i].telefone, "\0" );
				//free(contato[i].telefone);
			}			
			i+=1;
		}
		printf("***********REMOCAO***********");
		printf("\ncontato removido");
		printf("\n***************************\n");
		do{
			printf(":Precione qualquer tecla para continuar . . .");
			continua=getch();
			clear();
			break;
		}while(continua!=NULL);
	}	
}
*/
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
