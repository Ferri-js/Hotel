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

void fclear();

void exibirMapaHotel();

void reservarApartamento(int i, int j);

void checkOut(int i, int j);

void checkIn (int i, int j);


int main() {
    matrizHotel();
    int opcao, andar, apto;
    char v;

    do {
        printf("\nMenu:\n1. Visualizar mapa do Hotel\n2. Reservar apartamento\n3. Chek-in\n4. Check-Out\n5. Cancelar Reserva\n0. Sair\nEscolha uma opcao: \n");
        scanf("%d", &opcao);
        fclear();

        switch (opcao) {
            case 1: // mostra o mapa do hotel
                exibirMapaHotel();
                break;
            case 2: //rezerva
                printf("Informe o andar e o numero do apartamento para reservar (1-20, 1-14): ");
                scanf("%d %d", &andar, &apto);
                fclear();
                reservarApartamento(andar, apto);
                printf("Reserva realizada com sucesso.\n");
                exibirMapaHotel();
                break;
            case 3: //check-in
                printf("digite o quarto no qual sera feito o check-in: \n");
                scanf("%d %d", &andar, &apto);
                fclear();
                checkIn(andar, apto);
                exibirMapaHotel();
                break;
            case 4: //check-out
                printf("em qual apartamento sera feito o check-out:\n");
                scanf("%d %d", &andar, &apto);
                fclear();
                checkOut(andar, apto);
                printf("Check-out realizado com sucesso.\n");
                break;
            case 5: //cancelamento de reserva
                printf("deseja cancelar a reserva de qual quarto");
                scanf("%d %d", &andar, &apto);
                fclear();
                printf("quarto reservado para: %c\tCPF: %c\n", hotel[andar][apto].hospede.nome[40], hotel[andar][apto].hospede.cpf);
                printf("deseja cancelar a reserva?(s/n)\n");
                scanf("%c", &v);
                fclear();
                if (v == 's' || v == 'S')
                {
                    checkOut(andar, apto);
                    break;
                }
                break;
                
            case 0: // sair
            printf("Saindo...\n");
            break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

}

void checkOut(int i, int j){
    hotel[i][j].status = '.';
    hotel[i][j].hospede.nome[40] = ' ';
    hotel[i][j].hospede.cpf[14] = ' ';
}

void checkIn (int i, int j){
    char v;
    if(hotel[i][j].status == '.'){
        printf("Digite o Nome\n");
        scanf("%c", hotel[i][j].hospede.nome[40]);
        fclear();
        printf("Digite o CPF:\n");
        scanf("%c", hotel[i][j].hospede.cpf[14]);
        fclear();
        printf("deseja confirmar o check in?(s/n)\n");
        scanf("%c", &v);
        fclear();
        if (v == 's' || v == 'S'){
            hotel[i][j].status = 'O';
        }else if (v == 'n' || v == 'N'){
            checkOut(i, j);
        }
        
        
    }else if (hotel[i][j].status == 'R'){
        printf("quarto reservado para:\t%c\tCPF:\t%c\n", hotel[i][j].hospede.nome[40], hotel[i][j].hospede.cpf[14]);
        printf("deseja confirmar o Check-in(s/n)?:\n");
        scanf("%c", &v);
        fclear();
        if (v == 's' || v == 'S'){
            hotel[i][j].status = 'O';
        }else if (v == 'n' || v == 'N'){
            checkOut(i, j);
        }
    }else{
        printf("Quarto Ocupado\nDeseja escolher outro quarto?\n");
        scanf("%c", &v);
        fclear();
        if (v == 's' || v == 'S')
        {
            printf("digite o quarto que deseja realizar o Check-in\n");
            scanf("%d %d", &i, &j);
            fclear();
            checkIn(i, j);
        }
        
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

void fclear(){
	char car;
	while((car = fgetc(stdin)) != EOF && car != '\n'){}
}