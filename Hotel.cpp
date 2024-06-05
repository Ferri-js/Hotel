#include <stdio.h>

typedef struct endereco{
	char ender[40];
	char munic[20];
	char UF[3];
	char cep[10];
}tipoEnder;

typedef struct hospede{
    char cpf[14];
    char nome[40];
    char telefone[15];
    int idade;
    tipoEnder endereco;
    float valorHospedagem;
} tipoHospede;

typedef struct apartamento {
    char status;
    tipoHospede hospede;
} tipoApartamento;

tipoApartamento hotel[20][14];

void matrizHotel() {
    for (int i = 20; i > 0; i--) {
        for (int j = 1; j < 15; j++) {
            hotel[i][j].status = '.';
        }
    }
}

void exibirMapaHotel() {
    printf("Mapa dos apartamentos:\n");
    printf("\t");
    
    for(int j = 1; j < 15; j++)
    	printf("%2d ", j);
    printf("\n\n");
    
    for (int i = 20; i > 0; i--) { 
        printf("%2d:\t", i);
        for (int j = 1; j < 15; j++) {
            printf(" %c ", hotel[i][j].status);
        }
        printf("\n");
    }
}

void reservarApartamento(int i, int j) {
    if (hotel[i][j].status == '.') {
        hotel[i][j].status = 'R';
        printf("Apartamento %d-%d reservado com sucesso.\n", i + 1, j + 1);
    } else {
        printf("Apartamento %d-%d não está disponível para reserva.\n", i + 1, j + 1);
    }
}

int main() {
    matrizHotel();
    int opcao, andar, apto;
	char verificar;

    do {
        printf("\nMenu:\n1. Visualizar mapa do Hotel\n2. Reservar apartamento\n3. Realizar o chek-in\n0. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirMapaHotel();
                break;
            case 2:
                printf("Informe o andar e o número do apartamento para reservar (1-20, 1-14):\n");
                scanf("%d %d\n", &andar, &apto);
				printf("Nome de quem ira realizar a rezerva: \n");
				scanf("%c", hotel[andar][apto].hospede.nome);
                reservarApartamento(andar, apto);
                break;
			case 3:
				printf("em qual quarto sera feito o chek-in(andar quarto): \n");
				scanf("%d %d\n");
				printf("quarto reservado para: %c",hotel[andar][apto].hospede.nome );
				printf("desja confirmar o confirmar chck-in(s/n)?\n");
				scanf("%c", &verificar);
				if (verificar == 's'){
					hotel[andar][apto].status = 'O';
				}else{
					break;
				}
            case 0:
            printf("Saindo...\n");
            break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

}
