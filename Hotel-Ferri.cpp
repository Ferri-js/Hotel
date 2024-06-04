/*FLLM - 
nomes
função de criar matriz
função pra alterar a matriz
criar 3 structs - endereço hospede e apartamento
menu
*/

#include <stdio.h>

typedef struct endereco{
    char ender[40];
    char muncic[20];
    char UF[3];
    char cep[10];
}typeEnder;

typedef struct hospede{
    char cpf[14];
    char nome[40];
    char telefone[15];
    int idade;
    typeEnder endereco;
    float valorHospedagem;
}typeHospede;

typedef struct apartamento{
    char situacao;
    typeHospede hospede;
}typeApto;

typeApto Hotel[20][14];

main(){
	char tab[20][30];
	int i, j;
	
	for(i = 0; i < 20; i++){
		for(j = 0; j < 30; j++)
			tab[i][j] = '.';
	}
		
	do{
		printf("\t");
		
		for(j=0; j < 30; j++)
			printf("%2d ", j);
			
		printf("\n\n");
		
		for(i=0; i < 20; i++){
			printf("%2d\t",i);
			for(j=0; j < 30; j++)
				printf(" %c ", tab[i][j]);
			printf("\n");
		}
		
		printf("\nDigite as coordenadas que deseja alterar(linha, coluna) (-1 para sair)\n");
		scanf("%d,%d",&i,&j);
		if(i == -1 || j == -1)
			break;
		if(i < 0 || i > 20 || j < 0 || j > 30){
			printf("coordenadas invalidas\n");
			continue;
		}
		tab[i][j] = 'x';
	}while(i != -1 || j != -1);
}