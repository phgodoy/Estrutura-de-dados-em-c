#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct pneu{
	int codigo,aro,qtd;
	//float compra,lucro,revenda;
	struct pneu*prox;
};
typedef struct pneu produlto;

 struct pneu *cria_ponteiro(void)
 {
	produlto *inicio=(produlto*)malloc(sizeof(produlto));
	if(!inicio)
	{
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
	}
	
	return inicio;

}

void cadastrar(produlto *inicio)
{

	produlto *nova=(produlto*)malloc(sizeof(produlto));
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
	}
	else
	{
		produlto *temp;
		temp=inicio;
		while(temp->prox !=NULL)
		{
			temp=temp->prox;
		}
			
		temp->prox=nova;		
	}
}

void consultar(produlto *inicio)
{
	produlto *temp;
	temp=inicio;
	while(temp->prox !=NULL)
	{
		temp=temp->prox;
		printf("\ncodigo %i teve o lucro de %.2f na compra de %i pneus de aro %i",temp->codigo,temp->lucro,temp->qtd,temp->aro);
	}
}

void consultar_especifico(produlto *inicio)
{
	int consulta;
	printf("informe o codigo que deseja consultar");
	scanf("%i",&consulta);
	produlto *temp;
	temp=inicio;
	while(temp!=NULL)
	{
		if(temp->codigo==consulta)
		{	
			printf("\ncodigo %i teve o lucro de %.2f na compra de %i pneus de aro %i",temp->codigo,temp->lucro,temp->qtd,temp->aro);
			break;
		}
		else
		{
			temp=temp->prox;
		}
	}
}

void remover(produlto *inicio)
{
	int item;	
	produlto *temp;
	produlto *aux;			
	temp=inicio->prox;
	aux=inicio;
	printf("\ninforme um item para remover: ");
	scanf("%i",&item);
	while(temp->codigo!=item)
	{
		temp=temp->prox;
		aux=aux->prox;
	}
	aux->prox=temp->prox;
	free(temp);
}
void imprimir_ordem(produlto *inicio)
{
	produlto *temp;
	produlto *aux;
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

