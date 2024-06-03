#include <stdio.h>

typedef struct endereco{
	char end[40];
	char munic[20];
	char UF[3];
	char cep[10];
}typeEnd;


main(){
	char tab[20][14];
	int i, j;
	
	for(i = 20; i > 0; i = i - 1){
		for(j=1; j < 15; j++)
			tab[i][j] = '.';
	}
		
	do{
		printf("\t");
		
		for(j=1; j < 15; j++)
			printf("%2d ", j);
			
		printf("\n\n");
		
		for(i = 20; i > 0; i = i - 1){
			printf("%2d\t",i);
			for(j=1; j < 15; j++)
				printf(" %c ", tab[i][j]);
			printf("\n");
		}
		
		printf("\nDigite as coordenadas que deseja alterar(linha, coluna) (-1 para sair)\n");
		scanf("%d %d",&i,&j);
		if(i == -1 || j == -1)
			break;
		if(i < 0 || i > 20 || j < 0 || j > 14){
			printf("coordenadas invalidas\n");
			continue;
		}
		tab[i][j] = 'R';
	}while(i != -1 || j != -1);
}