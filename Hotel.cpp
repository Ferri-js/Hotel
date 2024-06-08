#include <stdio.h>

typedef struct endereco 
{
    char ender[40];
    char munic[20];
    char UF[3];
    char cep[10];
} tipoEnder;

typedef struct hospede 
{
    char cpf[14];
    char nome[40];
    char telefone[15];
    tipoEnder endereco;
    float valorHospedagem;
} tipoHospede;

typedef struct apartamento 
{
    char status;
    tipoHospede hospede;
} tipoApartamento;

tipoApartamento hotel[20][14];

void matrizHotel() 
{
    for (int i = 19; i >= 0; i--)
	{
        for (int j = 0; j <= 14; j++) 
		{
            hotel[i][j].status = '.';
        }
    }
}

void fclear();

void exibirMapaHotel();

void reservarApartamento(int i, int j);

void checkOut(int i, int j);

void checkIn(int i, int j);

void cReserva(int i, int j);

int main() 
{
    matrizHotel();
    int opcao, andar, apto;
    char confirmacao;

    do 
	{
        printf("\nMenu:\n1. Visualizar mapa do Hotel\n2. Reservar apartamento\n3. Check-in\n4. Check-Out\n5. Cancelar Reserva\n0. Sair\nEscolha uma opcao: \n");
        scanf("%d", &opcao);
        fclear();
        int i, j;

        switch (opcao) 
		{
            case 1: // mostra o mapa do hotel
                exibirMapaHotel();
                break;
            case 2: // reserva
                printf("Informe o andar e o numero do apartamento para reservar (1-20, 1-14): ");
                scanf("%d %d", &andar, &apto);
                fclear();
                reservarApartamento(andar - 1, apto - 1);
                exibirMapaHotel();
                break;
            case 3: // check-in
                printf("Digite o quarto no qual sera feito o check-in: ");
                scanf("%d %d", &andar, &apto);
                fclear();
                checkIn(andar - 1, apto - 1);
                exibirMapaHotel();
                break;
            case 4: // check-out
                printf("Em qual apartamento sera feito o check-out: ");
                scanf("%d %d", &andar, &apto);
                fclear();
                if((hotel[i][j].status == '.') || (hotel[i][j].status == 'R'))
                {
                	printf("O quarto selecionado nao esta ocupado\n");
                	exibirMapaHotel();
                	break;
				}
                else
				{
				checkOut(andar - 1, apto - 1);
                exibirMapaHotel();
                break;
            	}
            case 5: // cancelamento de reserva
                printf("Deseja cancelar a reserva de qual quarto: ");
                scanf("%d %d", &andar, &apto);
                fclear();
                if(hotel[i][j].status == '.')
                {
                	printf("O quarto selecionado nao esta reservado\n");
                	break;
				}
				else if(hotel[i-1][j-1].status == 'O')
				{
					printf("O quarto selecionado esta ocupado\n");
					break;
				}
                else{
                printf("Quarto reservado para: %s\tCPF: %s\n", hotel[andar - 1][apto - 1].hospede.nome, hotel[andar - 1][apto - 1].hospede.cpf);
                printf("Deseja cancelar a reserva? (s/n): ");
                scanf("%c", &confirmacao);
                fclear();
                if (confirmacao == 's' || confirmacao == 'S') 
				{
                    checkOut(andar - 1, apto - 1);
                    exibirMapaHotel();
                }
                }
                break;
            case 0: // sair
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

void checkOut(int i, int j)
{
    hotel[i][j].status = '.';
    hotel[i][j].hospede.nome[40] = ' ';
    hotel[i][j].hospede.cpf[14] = ' ';
}

void checkIn(int i, int j) 
{
    char confirmacao; //S ou s confirma, n ou N cancela
    if (hotel[i][j].status == '.') 
	{
        printf("Digite o Nome: ");
        scanf("%s", hotel[i][j].hospede.nome);
        fclear();
        printf("Digite o CPF: ");
        scanf("%s", hotel[i][j].hospede.cpf);
        fclear();
        printf("Deseja confirmar o check-in? (s/n): ");
        scanf("%c", &confirmacao);
        fclear();
        if (confirmacao == 's' || confirmacao == 'S') 
		{
            hotel[i][j].status = 'O';
        } else if (confirmacao == 'n' || confirmacao == 'N') 
		{
            checkOut(i, j);
        }
    } else if (hotel[i][j].status == 'R') 
	{
        printf("Quarto reservado para: %s\tCPF: %s\n", hotel[i][j].hospede.nome, hotel[i][j].hospede.cpf);
        printf("Deseja confirmar o check-in? (s/n): ");
        scanf("%c", &confirmacao);
        fclear();
        if (confirmacao == 's' || confirmacao == 'S') 
		{
            hotel[i][j].status = 'O';
        } else if (confirmacao == 'n' || confirmacao == 'N') 
		{
            checkOut(i, j);
        }
    } else 
	{
        printf("Quarto Ocupado\nDeseja escolher outro quarto? (s/n): ");
        scanf("%c", &confirmacao);
        fclear();
        if (confirmacao == 's' || confirmacao == 'S') 
		{
            printf("Digite o quarto que deseja realizar o check-in: ");
            scanf("%d %d", &i, &j);
            fclear();
            checkIn(i, j);
        }
    }
}

void reservarApartamento(int i, int j) 
{
    if (hotel[i][j].status == '.') 
	{
        hotel[i][j].status = 'R';
        printf("Apartamento %d-%d reservado com sucesso.\n", i + 1, j + 1);
    } else 
	{
        printf("Apartamento %d-%d não está disponível para reserva.\n", i + 1, j + 1);
    }
}

void exibirMapaHotel() 
{
    printf("Mapa dos apartamentos:\n");
    printf("Apartamentos");
	printf("\t");
	
    for (int j = 0; j < 14; j++)
        printf(" %2d ", j + 1);
    printf("\n\n");

    for (int i = 19; i >= 0; i--) 
	{
        printf("Andar \t  %4d\t", i + 1);
        for (int j = 0; j < 14; j++)
		{
            printf(" %2c ", hotel[i][j].status);
        }
        printf("\n");
    }
}

void fclear() 
{
    char car;
    while ((car = fgetc(stdin)) != EOF && car != '\n') {}
}

void cReserva (int i, int j){
    
}