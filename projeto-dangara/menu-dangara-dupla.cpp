#include <stdio.h>
#include <stdlib.h>
#include "dangara_dupla.h"

int main(){

	int op=-9;
	
	dangara *inicio = cria_ponteiro();
while(op!=6){
	printf("\n;;;;;;;;;;;;;;;;;;\n");
	printf("DANGARA----->DUPLA\n");
	printf(";;;;;;;;;;;;;;;;;;\n");
	printf("\ninforme o que deseja:\n");
	printf("1-cadastar\n2-consultar todos os cadastros\n3-consultar um cadastro especifico\n4-remover um cadastro\n5-imprimir em ordem inversa:\n6-sair:\n");
	scanf("%i",&op);
	//estrutura switch
	switch(op){
		case 1:{
			cadastrar(inicio);
			break;		
		}//case1
		case 2:{
			consultar(inicio);
			break;
		}//case2
		case 3:{
			consultar_especifico(inicio);
			break;
		}//cas3
		case 4:{
			remover(inicio);
			break;
		}//case4
		case 5:{
			imprimir_ordem(inicio);
			break;
		}
		case 6:{
			printf("\nfim do programa: ");
			break;
		}//case6
			
	}//switch	
}//while
	
	system("pause");
}//msain

