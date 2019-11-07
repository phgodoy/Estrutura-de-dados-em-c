 //Bibliotecas 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#include "funcoes-ordenaçao.h"




//Funcao principal

int main(){
	contato  *topo = cria_ponteiro();
	
	color_graphic();
	
	while(op!=666){
		printf("\n********ORDENACAO******");
		printf("\n1-inserir");
		printf("\n2-imprimir");
		printf("\n3-consultar");
		printf("\n4-bubble sort");
		printf("\n5-selection sort");
		printf("\n6-quick sort");
		printf("\n7-sair");
		printf("\n************************");
		printf("\ninforme a opcao\n: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:{
			
				load();
				inserir(topo);
				break;
			}
			case 2:{
				load();
				eh_vazia(topo);
				imprimir(topo);
				break;
			}
			case 3:{
				load();
				eh_vazia(topo);
				consultar(topo);
				break;
			}
			case 4:{
				load();
				editar_contato(topo);
				break;
			}
			case 5:{
				load();
				remover_contato(topo);
				break;
			}
			case 6:{
				load();
				eh_vazia(topo);
				imprimir_inverso(topo);
				break;
			}
			case 7:{
				exit();
				sair();	
				break;
			}
			default:{
				clear();
				printf("\n********ORDENACAO******");
				printf("\n1-inserir");
				printf("\n2-imprimir");
				printf("\n3-consultar");
				printf("\n4-bubble sort");
				printf("\n5-selection sort");
				printf("\n6-quick sort");
				printf("\n7-sair");
				printf("\n************************");
				op_invalida();
				break;
			}
		}	
	}
}
