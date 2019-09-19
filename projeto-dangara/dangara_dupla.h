#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct id{
	int codigo,aro,qtd;
	float compra,lucro,revenda;
	struct id *prox;
	struct id *ant;
};
typedef struct id dangara;


 struct id *cria_ponteiro(void){
	dangara *inicio=(dangara*)malloc(sizeof(dangara));
	if(!inicio){
		printf("erro");
	}
	else
	{
		inicio->aro=NULL;
		inicio->codigo=NULL;
		inicio->compra=NULL;
		inicio->lucro=NULL;
		inicio->revenda=NULL;
		inicio->qtd=NULL;
		inicio->prox=NULL;
		inicio->ant=NULL;
	}
	
	return inicio;

}

void cadastrar(dangara *inicio){
	dangara *nova=(dangara*)malloc(sizeof(dangara));
	if(!nova)
	{
		printf("erro");
	}
	else
	{
		nova->codigo=NULL;
		nova->compra=NULL;
		nova->lucro=NULL;
		nova->revenda=NULL;
		nova->qtd=NULL;
		nova->prox=NULL;
		nova->ant=NULL;
	}
	printf("\ninforme o codigo do cadastro: ");
	scanf("%i",&nova->codigo);
	printf("\ninforme o aro do pneu: ");
	scanf("%i",&nova->aro);
	printf("\ninforme a quantidade de pneus: ");
	scanf("%i",&nova->qtd);
	printf("\ninforme o valor de compra: ");
	scanf("%f",&nova->compra);
	printf("\ninforme o valor de revenda: ");
	scanf("%f",&nova->revenda);
	nova->lucro=nova->revenda-nova->compra;
	if(inicio->prox==NULL)
	{
		inicio->prox=nova;
		nova->ant=inicio;
		nova->prox=NULL;			
	}
	else
	{
		dangara *temp;
		temp=inicio;
		while(temp->prox !=NULL)
		{		
			temp=temp->prox;		
		}
		nova->ant = temp;
		temp->prox=nova;		
	}
			
}

void consultar(dangara *inicio){
	dangara *temp;
	temp=inicio;
	while(temp->prox !=NULL)
	{
		temp=temp->prox;
		printf("\ncodigo %i teve o lucro de %.2f na compra de %i pneus de aro %i",temp->codigo,temp->lucro,temp->qtd,temp->aro);
	}
}
void consultar_especifico(dangara *inicio){
	int consulta;
	printf("informe o codigo que deseja consultar");
	scanf("%i",&consulta);
	dangara *temp;
	temp=inicio;
	while(temp!=NULL)
	{
		if(temp->codigo==consulta)
		{	//break;
			printf("\ncodigo %i teve o lucro de %.2f na compra de %i pneus de aro %i",temp->codigo,temp->lucro,temp->qtd,temp->aro);
			break;
		}
		else
		{
			temp=temp->prox;
		}
	}
}

void remover(dangara *inicio){
	int item;	
	dangara *temp;
	dangara *aux;			
	temp=inicio->prox;
	aux=inicio;
	printf("\ninforme um item para remover: ");
	scanf("%i",&item);
	while(temp->codigo!=item){
		temp=temp->prox;
		aux=aux->prox;
		}
	aux->prox=temp->prox;
	free(temp);
}


imprimir_ordem(dangara *inicio){
	dangara *temp;
	dangara *aux;
	temp=inicio;
	while(temp->prox!=NULL)
	{
		temp=temp->prox;
	}
	while(temp!=inicio)
	{
		aux=inicio;
				
		while(aux->prox!=temp)
		{
			aux=aux->prox;
		}
		if(temp!=inicio)
		{
			printf("\ncodigo %i teve o lucro de %.2f na compra de %i pneus de aro %i",temp->codigo,temp->lucro,temp->qtd,temp->aro);
		}
		temp=aux;
	}
					 
}
