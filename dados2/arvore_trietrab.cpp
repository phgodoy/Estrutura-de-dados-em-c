#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_ALFABETO 26

struct Node
{
	struct Node *filho[TAM_ALFABETO];
	bool fimDePalavra;
};


struct Node *criaNo(void)
{
	struct Node *No = NULL;
	No = (struct Node *)malloc(sizeof(struct Node));
	if (No)
	{
		int i;
		No->fimDePalavra = false;
		for (i = 0; i < TAM_ALFABETO; i++)
			No->filho[i] = NULL;
	}
	return No;
}

void insere(struct Node *raiz,  char *chave)
{
	int nivel;
	int tamanho = strlen(chave);
	int i;
	struct Node *p = raiz;
	for (nivel = 0; nivel < tamanho; nivel++)
	{
		i = ((int)chave[nivel] - (int)'a');
		if (!p->filho[i])
			p->filho[i] = criaNo();

		p = p->filho[i];
	}
	p->fimDePalavra = true;
}

bool busca(struct Node *raiz,  char *chave)
{
	int nivel;
	int tamanho = strlen(chave);
	int i;
	struct Node *p = raiz;
	for (nivel = 0; nivel < tamanho; nivel++)
	{
		i = ((int)chave[nivel] - (int)'a');
		if (!p->filho[i])
			return false;
		p = p->filho[i];
	}
	return (p != NULL && p->fimDePalavra);
}




int main()
{
	int op = -9;
	struct Node *raiz = criaNo();
	char mensagem[][21] = {"Nao Existe na Arvore", "Existe na Arvore"};
	char chave[10];
	char buscar[10];
	char remove[10];
	int i;
	while(op!=4){
		
		printf("1)Inserir\n2)Buscar\n3)Excluir\n4)Sair\n");
		scanf("%d",&op);
		
		switch(op){
			
			case 1:{
				while(true) {
				printf("Digite um valor para inserir na arvore: ");
				scanf("%s",&chave[i]);				
				insere(raiz,chave);	
				i++;
				break;
				}
				break;
			}
			
			case 2:{
				printf("Informe o que quer buscar: ");
				scanf("%s",&buscar);
				for(i = 0; i < (sizeof(buscar)/sizeof(buscar[i])); i++)
					printf("%s ===> %s\n", buscar, mensagem[busca(raiz,buscar)] );	
				break;
			}
			case 3:{
			
				 
				break;
			}
			case 4:{
				
				printf("FIM DO PROGRAMA: ");
				break;
			}
		}
	}
	/*
	printf ("TESTES\n==============\n\n");
	char chaves[][18] = {"aba", "a", "abacate", "abacaxi", "abracadabra",
					"banir", "banana", "banco","bandeira"};
	char mensagem[][21] = {"Nao Existe na Arvore", "Existe na Arvore"};
	struct Node *raiz = criaNo();
    int i;
	for (i = 0; i < (sizeof(chaves)/sizeof(chaves[0])); i++)
		insere(raiz, chaves[i]);
	char s[][20]= {"abobora","a","bandeira","banco","xuxu","bouceta","biscoito","banir"};
    for (i = 0; i < (sizeof(s)/sizeof(s[0])); i++)
	printf("%s ===> %s\n", s[i], mensagem[busca(raiz, s[i])] );
	return 0;
	*/
}

