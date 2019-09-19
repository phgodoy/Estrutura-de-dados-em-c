int v[6], m[2][3], cont_par=0,cont_impar=0;

void vetor(){
	int i =  0;
	while(i<6)
	{
		printf("\nv[%i] = ",i+1);
		scanf("%i",&v[i]);
		i++;
	}
}

void imprime_vetor(){
	int i = 0;
	printf("\n:vetor:");
	do{
		printf("\n v[%i] ",v[i]);
		i++;
	}while(i<6);
}

void imprime_inverso(){
	int i = 5;
	printf("\n:inverso:");
	do{
		printf("\n v[%i] ",v[i]);
		i--;
	}while(i>0);
}

void conta_par(){
	int i;
	for(i=0;i<6;i++){
		if(v[i]%2==0)
			cont_par++;
	}
	printf("\n Numeros pares: %d",cont_par);		
}

void conta_impar(){
	int i;
	for(i=0;i<6;i++){
		if(v[i]%2!=0)
			cont_impar++;					
	}
	printf("\n Numeros imares: %d",cont_impar);
}

void imprime_conta_par(){
	int i;
	printf("\n Pares = ");
	for(i=0;i<6;i++){
		if(v[i]%2==0)
			printf("v[%i],",v[i]);
	}		
}

void imprime_conta_impar(){
	int i;
	printf("\n Impares = ");
	for(i=0;i<6;i++){
		if(v[i]%2!=0)
			printf("  v[%i] ",v[i]);
	}	
}

void cria_matriz(){
	int i,j,k = 0 ;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			m[i][j] = v[k];
			k++;
		}
	}
}

void imprime_matriz(){
	int i,j;
	printf("\n");
	for(i=0;i<2;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf(" [%d] ",m[i][j]);
		}
	}
}

void imprime_diagonal(){
	int i=0,j=0,k = 0;
	printf(" \ndiagonais: ");
	while(k<2){
		printf(" [%d] ",m[i][j]);
		i++;
		j++;
		k++;
	}
}
void imprime_diagonalopostas(){
	int i=0,j=2,k = 0;
	printf(" \ndiagonais-opostas: ");
	while(k<2){
		printf(" [%d] ",m[i][j]);
		i++;
		j--;
		k++;
}		
}

