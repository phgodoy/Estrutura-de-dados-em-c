#include<stdio.h>
#include<conio.h>

int opcao, linha, coluna, i, j, sala1[5][10], sala2[6][11], sala3[8][9], pessoas,resp, resp2[500];
int cont=0,op=1,cont_meiaa=0,cont_meiab=0,cont_meiac=0,cont_inta=0,cont_intb=0,cont_intc=0,m=0,t=0;

float preco1, preco2, preco3, precototal,fat_a=0,fat_b=0,fat_c=0;



main(){ 
	
	printf("Informe o preco da Sala A: ");
	scanf("%f",&preco1);
	printf("Informe o preco da Sala B: ");
	scanf("%f",&preco2);
	printf("Informe o preco da Sala C: ");
	scanf("%f",&preco3);
	
	for(i=0;i<5;i++){
 		for(j=0;j<10;j++){
 			sala1[i][j] = 0;
		 }
	}
	
	for(i=0;i<6;i++){
 		for(j=0;j<11;j++){
 			sala2[i][j] = 0;
		}
	}
	
	for(i=0;i<8;i++){
 		for(j=0;j<9;j++){
 			sala1[i][j] = 0;
		}
	}
	do{
	
	printf("Informe qual sala deseja ver: \n");
	printf("1 - Sala A\n");
	printf("2 - Sala B\n");
	printf("3 - Sala C\n");
	printf("4 - Sair\n");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
		
		for(i=0;i<5;i++){
 			for(j=0;j<10;j++){
 				printf("|%d|",sala1[i][j]);
		 	}
		printf("\n");
		}
		
		do{
			printf("Escolheu a Sala A\n");
			printf("O Preco e: %.2f\n",preco1);
			printf("Informe quantas pessoas irao ver o filme: ");
			scanf("%d", &pessoas);
			cont=pessoas+cont;
			
			for(i=1;i<=pessoas;i++){
				printf("Informe\n");
				printf("1-Meia\n");
				printf("2-Inteira\n");
				scanf("%d",&resp2[i]);
				
				if(resp2[i]==1){
					precototal=precototal+(preco1/2);
					fat_a = fat_a +(preco1/2);
					cont_meiaa++;
					m ++;
				}else if(resp2[i]==2){
					precototal=precototal+preco1;
					fat_a = fat_a +preco1;
					cont_inta++;
					t ++;
					
				}else{
					printf("Nao existe essa opcao");
				}
				
				printf("Informe a Linha(Limite=5): ");
				scanf("%d", &linha);
				printf("\nInforme a Coluna(Limite=10): ");
				scanf("%d", &coluna);
				if(sala1[linha-1][coluna-1]==1)
				{
					printf("\nEsse lugar ja esta ocupado");
				}else{
					sala1[linha-1][coluna-1]=1;
				}
			}
			
			for(i=0;i<5;i++){
				printf("\n");
 				for(j=0;j<10;j++){
 					printf("|%d|",sala1[i][j]);
		 		}
			}
			
		printf("\nDeseja Continuar:(1=Sim/2=Nao/3=refazer venda): \n");
		scanf("%d",&resp);
		if(resp==3){	
		for(i=0;i<5;i++){
 		for(j=0;j<10;j++){
 			sala1[i][j] = 0;
		 }
	}		cont = cont - pessoas;
				for(i=1;i<=pessoas;i++){
			
				
				if(resp2[i]==1){
					precototal=precototal-(preco1/2);
					fat_a = fat_a -(preco1/2);
					cont_meiaa--;
					m --;
				}else if(resp2[i]==2){
					precototal=precototal-preco1;
					fat_a = fat_a -preco1;
					cont_inta--;
					t --;
					
				}
		}
		}//if
		else{
		}
		}while(resp==1 or resp==3);
			break;
	case 2:{
		for(i=0;i<6;i++){
 			for(j=0;j<11;j++){
 				printf("|%d|",sala2[i][j]);
			}
			printf("\n");
		}
		do{
			printf("\n");
			printf("Escolheu a Sala B\n");
			printf("O Preco e: %.2f\n",preco2);
			printf("Informe quantas pessoas irao ver o filme: ");
			scanf("%d", &pessoas);
			cont=pessoas+cont;
			
			for(i=1;i<=pessoas;i++){
				
				printf("Informe\n");
				printf("1-Meia\n");
				printf("2-Inteira\n");
				scanf("%d",&resp2[i]);
				
				if(resp2[i]==1){
					precototal=precototal+(preco2/2);
					cont_meiab++;
					m++;
					fat_b = fat_b +(preco2/2);
				}else if(resp2[i]==2){
					precototal=precototal+preco2;
					cont_intb++;
					t++;
					fat_b = fat_b+preco2;
				}else{
					printf("Nao existe essa opcao");
				}
				
				printf("Informe a Linha(Limite=6): ");
				scanf("%d", &linha);
				printf("\nInforme a Coluna(Limite=11): ");
				scanf("%d", &coluna);
				if(sala2[linha-1][coluna-1]==1){
					printf("\nEsse lugar ja esta ocupado");
				}else{
					sala2[linha-1][coluna-1]=1;
				}
				
			}
			for(i=0;i<6;i++){
				printf("\n");
 				for(j=0;j<11;j++){
	 				printf("|%d|",sala2[i][j]);
			 	}
			}
			printf("\nDeseja Continuar:(1=Sim/2=Nao/3=refazer venda): \n");
			scanf("%d",&resp);
				if(resp==3){	
		for(i=0;i<6;i++){
 		for(j=0;j<11;j++){
 			sala2[i][j] = 0;
		 }
	}	cont = cont - pessoas;
				for(i=1;i<=pessoas;i++){
			
				
				if(resp2[i]==1){
					precototal=precototal-(preco2/2);
					fat_b = fat_b -(preco2/2);
					cont_meiaa--;
					m --;
				}else if(resp2[i]==2){
					precototal=precototal-preco2;
					fat_b = fat_b -preco2;
					cont_intb--;
					t --;
					
				}
		}
		}//if
		else{
		}
			}while(resp==1 or resp==3);
			break;
		}
	
		case 3:{
			for(i=0;i<8;i++){
 				for(j=0;j<9;j++){
 					printf("|%d|",sala3[i][j]);
			 	}
			printf("\n");
		 	}
		 	
		 	do{
				printf("Escolheu a Sala C\n");
				printf("O Preco e: %.2f\n",preco3);
				printf("Informe quantas pessoas irao ver o filme: ");
				scanf("%d", &pessoas);
				cont=pessoas+cont;
				
				for(i=1;i<=pessoas;i++){
					
					printf("Informe\n");
					printf("1-Meia\n");
					printf("2-Inteira\n");
					scanf("%d",&resp2[i]);
				
					if(resp2[i]==1){
						precototal=precototal+(preco3/2);
						cont_meiac++;
						m++;
						fat_c = fat_c +(preco3/2);
					}else if(resp2[i]==2){
						precototal=precototal+preco3;
						cont_intc++;
						t++;
						fat_c = fat_c + preco3;
					}else{
						printf("Nao existe essa opcao");
					}
					
					printf("Informe a Linha(Limite=8): ");
					scanf("%d", &linha);
					printf("\nInforme a Coluna(Limite=9): ");
					scanf("%d", &coluna);
					if(sala3[linha-1][coluna-1]==1){
						printf("\nEsse lugar ja esta ocupado");
					}else{
						sala3[linha-1][coluna-1]=1;
					}
					
				}
				
				for(i=0;i<8;i++){
					printf("\n");
	 				for(j=0;j<9;j++){
 						printf("|%d|",sala3[i][j]);
					}
				}
				printf("\nDeseja Continuar:(1=Sim/2=Nao/3=refazer venda): \n");
				scanf("%d",&resp);
				if(resp==3){	
		for(i=0;i<8;i++){
 		for(j=0;j<9;j++){
 			sala3[i][j] = 0;
		 }
	}	cont= cont - pessoas;
				for(i=1;i<=pessoas;i++){
			
				
				if(resp2[i]==1){
					precototal=precototal-(preco3/2);
					fat_c = fat_c -(preco3/2);
					cont_meiac--;
					m --;
				}else if(resp2[i]==2){
					precototal=precototal-preco3;
					fat_c = fat_c -preco3;
					cont_intc--;
					t --;
					
				}
		}
		}//if
		else{
		}
			}while(resp==1 or resp==3);
			break;
		}
	
		case 4:
		printf("FIM DO PROGRAMA! ");
		printf("\n%d ingresos inteiros na sala A",cont_inta);
		printf("\n%d  meia entrada na sala A",cont_meiaa);
		printf("\nR$%.2f faturamento da sala A",fat_a);
		printf("\nsobraram %d lugares",(50 - (cont_inta +cont_meiaa)));
		printf("\n");
		
		printf("\n%d ingresos inteiros na sala B",cont_intb);
		printf("\n%d meia entrada na sala B",cont_meiab);
		printf("\nR$%.2f faturamento da sala B",fat_b);
		printf("\nsobraram %d lugares",(66 - (cont_intb +cont_meiab)));
		printf("\n");
		
		printf("\n%d ingresos inteiros na sala C",cont_intc);
		printf("\n%d meia entrada na sala C",cont_meiac);
		printf("\nR$%.2f faturamento da sala C",fat_c);
		printf("\nsobraram %d lugares",(72 - (cont_intc +cont_meiac)));
		printf("\n");
		
		printf("\n%d ingresos inteiros no total",t);
		printf("\n%d meia entrada no total ",m);
		printf("\n");
		
		printf("\nForam %d Pessoas",cont);
		printf("\nForam R$%.2f faturamento no total\n",precototal);
		printf("\nsobraram %d lugares no total",(188 - (cont_inta +cont_meiaa + cont_intb +cont_meiab +cont_intc +cont_meiac )));
		
		op=2;
		
	//case4
	break;
	default:{
		
		printf("Nao existe essa opcao");
	
		break;
	}
}//shitch

	}while(op!=2);
	
}//menu
