//Estruturaa da agenda

struct agenda{
	char  nome[40];
	char  email[40];
	int   idade;
	char   telefone[40];
};
struct agenda contato[5];

//Variaveis golbais
FILE *pont_arq; //ponteiro de arquivo
char resp = 'S';
int  op=-7;
int  i=0;
int  cont=0;

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
int cria_arq(){
	pont_arq = fopen("agenda_texto.txt","w"); 
	if(pont_arq == NULL)
  {
  	printf("Erro na abertura do arquivo!");
  	return 1;
  }
  
}


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
}

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
