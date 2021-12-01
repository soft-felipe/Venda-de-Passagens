#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // colorir o terminal
#define L 12
#define C 4

typedef struct {
	
	char nome[40];
	char rg[40];
	char email[40];
	char telefone[40];
	char telfoneEmer[40];
	char situacao;
	
} PASSAGEIRO;

typedef struct {
	
	PASSAGEIRO poltronas[L][C];
	char partindoDe[40];
	char destinoFinal[40];
	float valorPassagem;
	int numeroViagem; // quando adicionar mais viagens
	
} VIAGEM;

void imprimir_lateral () {
	
	HANDLE  hConsole; // declaracao da viariavel para mudar a cor
	int asc3 = 186;
	
	// ************* MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	
	printf("     %c\n", asc3);
	printf("             %c     ", asc3);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
}

void interface_companhia () {
	
	HANDLE  hConsole;
	int asc = 187, asc1 = 201, asc2 = 205, asc3 = 186, asc4 = 200, asc5 = 188, i;
	
	// ************* MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	
	printf("             ");
	printf("%c", asc1);
	for (i = 0; i < 51; i++) {
		printf("%c", asc2);
	}
	printf("%c\n", asc);
	
	printf("             %c     ", asc3);
	
	// *********** VOLTANDO AO NORMAL*************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	
	printf("-----------------------------------------");
	imprimir_lateral();
	printf("COMPANHIA DE VIAGENS RODOVIARIAS | UFG-ES");
	imprimir_lateral();
	printf("-----------------------------------------");
	imprimir_lateral();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("           -------------------           ");
	imprimir_lateral();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("          |   [UFG-ES]        |          ");
	imprimir_lateral();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("           --O-O-----------O--           ");
	imprimir_lateral();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("_  _  _  _  _  _  _  _  _  _  _  _  _  _ ");
	imprimir_lateral();
	printf("                                        ");
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	
	printf("      %c\n", asc3);
	printf("             ");
	printf("%c", asc4);
	for (i = 0; i < 51; i++) {
		printf("%c", asc2);
	}
	printf("%c\n\n\n", asc5);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	
	printf("%c Felipe Moreira da Silva | Engenharia de Software\n\n\n", asc3 = 254);
}

void iniciar_viagem (VIAGEM *v) {
	
	HANDLE  hConsole;
	int lin, col, asc = 27, asc1 = 26;
	
	for (lin = 0; lin < L; lin++) {
		for (col = 0; col < C; col++) {
			v->poltronas[lin][col].situacao = 'V';
		}
	}
	
	printf("++++++ VIAGENS  DISPONIVEIS ++++++\n\n");
	
	// ************* MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 112);
	
	printf("+--------------------------------+\n");
	printf("| Viagem 1:                      |\n");
	printf("| %c Partindo de: ANAPOLIS        |\n", asc);
	printf("| %c Indo para: GOIANIA           |\n", asc1);
	printf("| Horario de Saida: 17:00hrs     |\n| Horario de Chegada: 18:00hrs   |\n");
	printf("| ROTA 0001 - ONIBUS N 202105027 |\n");
	printf("| Valor da passagem: R$ 100,00   |\n");
	printf("+--------------------------------+\n\n");
	
	printf("+--------------------------------+\n");
	printf("| Viagem 2:                      |\n");
	printf("| %c Partindo de: SAO PAULO       |\n", asc);
	printf("| %c Indo para: RIO DE JANEIRO    |\n", asc1);
	printf("| Horario de Saida: 07:00hrs     |\n| Horario de Chegada: 14:30hrs   |\n");
	printf("| ROTA 0002 - ONIBUS N 202105048 |\n");
	printf("| Valor da passagem: R$ 350,00   |\n");
	printf("+--------------------------------+\n\n");
	
	// *********** VOLTANDO AO NORMAL ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	
	printf("Digite o numero da viagem:\n");
	scanf("%d", (&v->numeroViagem));
	getchar();
	printf("\n");
	
	
	while (v->numeroViagem != 1 && v->numeroViagem != 2) {
		
		// ************* MUDANDO A COR ***************
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		
		printf("Essa viagem nao esta disponivel!\nPor favor, digite um numero de viagem valida. Obrigado!\n");
		
		// *********** VOLTANDO AO NORMAL ************
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 7);
		
		scanf("%d", (&v->numeroViagem));
		getchar();
		printf("\n");
	} 
	
	if (v->numeroViagem == 1) {
		v->valorPassagem = 100.0;
	} else {
		v->valorPassagem = 350.0;
	}
	
	printf("Por favor, confirme o local de SAIDA.\n");
	fgets(v->partindoDe, 40, stdin);
	printf("\n");
	
	printf("Por favor, confirme o local de CHEGADA.\n");
	fgets(v->destinoFinal, 40, stdin);
	printf("\n");
}

void menu () {
	
	HANDLE  hConsole;
	int asc = 186, asc1 = 201, asc2 = 187, asc3 = 205, asc4 = 200, asc5 = 188, i;
	
	// *********** MUDANDO A COR DO MENU ****************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	// **************************************************
	
	printf("%c", asc1);
	for (i = 0; i < 25; i++) {
		printf("%c", asc3);
	}
	printf(" M E N U ");
	for (i = 0; i < 26; i++) {
		printf("%c", asc3);
	}
	printf("%c\n", asc2);
	
	printf("%c                                                            %c\n", asc, asc);
	printf("%c    1 - Comprar passagem.                                   %c\n", asc, asc);
	printf("%c    2 - Reservar um acento.                                 %c\n", asc, asc);
	printf("%c    3 - Vizualizar a situacao de todos os acentos.          %c\n", asc, asc);
	printf("%c    4 - Vizualizar a situacao de um determinado acento.     %c\n", asc, asc);
	printf("%c    5 - Exibir as passagens ja compradas.                   %c\n", asc, asc);
	printf("%c    6 - Sair do aplicativo.                                 %c\n", asc, asc);
	printf("%c                                                            %c\n", asc, asc);
	
	printf("%c", asc4);
	for (i = 0; i < 60; i++) {
		printf("%c", asc3);
	}
	printf("%c", asc5);
	
	// ********* VOLTANDO AO NORMAL *****************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	// **********************************************
	printf("\n\n");
	printf("Escoha uma opcao:\n");
}

 void comprar_passagem (PASSAGEIRO *p) {
	
	printf("Digite o nome do passageiro:\n");
	fgets(p->nome, 40, stdin);
	printf("\n");
	
	printf("Digite o CPF do passageiro: (EX: 123.456.789-12)\n");
	fgets(p->rg, 40, stdin);
	printf("\n");
	
	printf("Digite o e-mail do passageiro:\n");
	fgets(p->email, 40, stdin);
	printf("\n");
	
	printf("Digite o numero de telefone do passageiro:\n");
	fgets(p->telefone, 40, stdin);
	printf("\n");
	
	printf("Digite um numero de telefone em caso de emergencias:\n");
	fgets(p->telfoneEmer, 40, stdin);
	printf("\n");	
}

void exibir_acentos (VIAGEM v) {
	
	HANDLE  hConsole;
	int lin, col, asc, asc1, asc2;
	
	// ************* MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	// *******************************************
	
	printf("IMPORTANTE: As colunas de numero 1 e 4 sao referentes aos acentos na JANELA.\n");
	printf("IMPORTANTE: As colunas de numero 2 e 3 sao referentes aos acentos no CORREDOR.\n\n");
	
	// *********** VOLTANDO AO NORMAL ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	// **********************************************
		
	printf("+++++++ EXIBICAO DOS ACENTOS +++++++\n\n");
	printf("   ESQUERDA  %c  DIREITA\n\n", asc = 179);
	
	printf("     01  02     03  04\n\n");
	for (lin = 0; lin < L; lin++) {
		printf("%02d - ", lin+1);
		for (col = 0; col < C-1; col++) {
			
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 9);
			
			if (v.poltronas[lin][col].situacao == 'V') {
				printf("[]  ");
			} else if (v.poltronas[lin][col].situacao == 'O') {
				printf("%c%c  ", asc1 = 219, asc1);
			} else if (v.poltronas[lin][col].situacao == 'R') {
				printf("%c%c  ", asc2 = 176, asc2);
			}
			
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 7);
			
			if (col == 1) {
				printf("%c  ", asc = 179);
			}	
		}
		
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 9);
		
		if (v.poltronas[lin][col].situacao == 'V') {
			printf("[]\n\n");
		} else if (v.poltronas[lin][col].situacao == 'O') {
			printf("%c%c  \n\n", asc1 = 219, asc1);
		} else if (v.poltronas[lin][col].situacao == 'R') {
			printf("%c%c  \n\n", asc2 = 176, asc2);
		}	
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 7);	
	}
	
	printf("++++++++ LEGENDA ++++++++\n");
	printf("+ ");
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	
	printf("[]");
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	
	printf(" - Acento vazio     +\n");
	printf("+ ");
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	
	printf("%c%c",asc1 = 219, asc1);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	
	printf(" - Acento ocupado   +\n");
	printf("+ ");
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	
	printf("%c%c", asc2 = 176, asc2);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	
	printf(" - Acento reservado +\n");
	printf("+++++++++++++++++++++++++\n\n");
} 

void cadastrar_passageiro (VIAGEM *v, PASSAGEIRO p, int lin, int col) {
	
	v->poltronas[lin-1][col-1] = p;
}

void exibir_passageiro (PASSAGEIRO p, VIAGEM v, int lin, int col) {
	
	HANDLE  hConsole;
	
	// ************* MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	// *******************************************
	
	printf("=====================================================\n\n");
	
	printf("NOME: %48s", p.nome);
	printf("CPF: %49s", p.rg);
	printf("E-MAIL: %46s", p.email);
	printf("SAINDO DE: %43s", v.partindoDe);
	printf("INDO PARA: %43s", v.destinoFinal);
	printf("VALOR DA PASSAGEM:                          R$ %.2f\n", v.valorPassagem);
	printf("NUMERO DE TELEFONE: %34s", p.telefone);
	printf("NUMERO DE TELEFONE PARA EMERGENCIAS: %17s", p.telfoneEmer);
	
	if (v.numeroViagem == 1) {
		printf("HORARIO DE SAIDA:                            17:00hrs\nHORARIO DE CHEGADA:                          18:00hrs\n");
		printf("ROTA 0001    -    ONIBUS N:                 202105027\n");
	} else {
		printf("HORARIO DE SAIDA:                            07:00hrs\nHORARIO DE CHEGADA:                          14:30hrs\n");
		printf("ROTA 0002    -    ONIBUS N:                 202105048\n");
	}
	
	
	if (v.poltronas[lin][col].situacao != 'V' && col == 0 || col == 3) {
		printf("ACENTO (fileira, coluna):            (%2d, %d) - JANELA\n\n", lin+1, col+1);
	} else if (v.poltronas[lin][col].situacao != 'V' && col == 1 || col == 2) {
		printf("ACENTO (fileira, coluna):          (%2d, %d) - CORREDOR\n\n", lin+1, col+1);
	} /* else if (v.poltronas[lin][col].situacao == 'R' && col == 0 || col == 3) {
		printf("ACENTO (fileira, coluna): *Reserva* (%d, %d) - JANELA\n\n", lin+1, col+1);
	} else if (v.poltronas[lin][col].situacao == 'R' && col == 1 || col == 2) {
		printf("ACENTO (fileira, coluna): *Reserva* (%d, %d) - CORREDOR\n\n", lin+1, col+1);
	} */	
	printf("=====================================================");
	
	// *********** VOLTANDO AO NORMAL ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	// **********************************************
	
	printf("\n\n\n");
}

void parar () {
	
	HANDLE  hConsole;
	
	// *********** MUDANDO A COR ***************
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	// *****************************************
	
	printf("\t\tPressione ENTER para continuar.");
	getchar();
	getchar();
	printf("\n\n");
}

void passagem_comprada () {
	
	HANDLE  hConsole;
	int asc = 1;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	
	printf("Sua passagem foi comprada com sucesso!\n");
	printf("Muito obrigado pela sua preferencia %c.\n\n", asc);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
}

void passagem_reservada () {
	
	HANDLE  hConsole;
	int asc = 1;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	
	printf("Sua passagem foi reservada com sucesso!\n");
	printf("Muito obrigado pela sua preferencia %c.\n\n", asc);
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
}

void Carregar_viagem(VIAGEM *v){
	FILE *fp;
    
	fp = fopen ("Viagem.dat", "rb"); 
	if (fp == NULL) {  
		iniciar_viagem(&(*v));
	} else {
		fread(&(*v),sizeof(VIAGEM),1,fp); 
	    fclose(fp);
	}
}

void Gravar_viagem(VIAGEM v) {
	FILE *fp;  
	
	fp = fopen ("Viagem.dat", "wb"); 
	if (fp == NULL) {  
		printf ("Erro ao abrir o arquivo.\n");  
		return;  
	} else {  
		printf ("Arquivo Binario criado com sucesso.\n");  
		fwrite(&v, sizeof(VIAGEM), 1, fp); 
	}         
	fclose (fp);        
}

int main () {
	
	system("title Companhia De Onibus - Engenharia de Software - UFG");
	HANDLE  hConsole;
	PASSAGEIRO P;
	VIAGEM V;
	interface_companhia();
	Carregar_viagem (&V);
	
	int opcao, lin, col, asc ,asc2, asc3;
	
	do {
		menu ();
		scanf("%d", &opcao);
		getchar();
		printf("\n");
		
		switch (opcao) {
			
			case 1:
				comprar_passagem (&P);
				
				printf("Escolha um acento, que nao esteja ocupado ou reservado.\n\n");
				exibir_acentos (V);
				printf("\n");
				
				printf("Digite a fileira e coluna do acento:\n");
				scanf("%d %d", &lin, &col);
				printf("\n");
				
				while (lin < 1 || col < 1 || lin > 12 || col > 4) {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					// *******************************************
					
					printf("O numero digitado nao corresponde ao numero de fileiras ou colunas!\n");
					printf("Por favor, digite a fileira e coluna do acento novamente\n");
					
					// *********** VOLTANDO AO NORMAL ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 7);
					// **********************************************
					
					scanf("%d %d", &lin, &col);
					printf("\n");
				}
			
				while (V.poltronas[lin-1][col-1].situacao == 'O' || V.poltronas[lin-1][col-1].situacao == 'R') {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					// *******************************************
					
					printf("Esse acento nao esta disponivel! Por favor escolha outro.\n");
					printf("Digite novamente a fileira e coluna do acento:\n");
					
					// *********** VOLTANDO AO NORMAL ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 7);
					// **********************************************
					
					scanf("%d %d", &lin, &col);
					printf("\n");
				}
				
				passagem_comprada ();
				parar();
				
				P.situacao = 'O';
				cadastrar_passageiro (&V, P, lin, col);
				break;
				
			case 2:
				comprar_passagem (&P);
				
				printf("Escolha o acento que deseja reservar, que nao esteja ocupado ou resrvado.\n\n");
				exibir_acentos (V);
				printf("\n");
				
				printf("Digite a fileira e coluna do acento:\n");
				scanf("%d %d", &lin, &col);
				printf("\n");
				
				while (lin < 1 || col < 1 || lin > 12 || col > 4) {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					// *******************************************
					
					printf("O numero digitado nao corresponde ao numero de fileiras ou colunas!\n");
					printf("Por favor, digite a fileira e coluna do acento novamente\n");
					
					// *********** VOLTANDO AO NORMAL ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 7);
					// **********************************************
					
					scanf("%d %d", &lin, &col);
					printf("\n");
				}
				
				while (V.poltronas[lin-1][col-1].situacao == 'O' || V.poltronas[lin-1][col-1].situacao == 'R') {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					// *******************************************
					
					printf("Esse acento nao esta disponivel! Por favor escolha outro.\n");
					printf("Digite novamente a fileira e coluna do acento:\n");
					
					// *********** VOLTANDO AO NORMAL ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 7);
					// **********************************************
					
					scanf("%d %d", &lin, &col);
					printf("\n");
				}
				
				// ************* MUDANDO A COR ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 14);
				// *******************************************
				
				printf("IMPORTANTE: Lembre-se que voce tem ate 3 dias uteis para fazer o pagamento.\n\n");
				
				// *********** VOLTANDO AO NORMAL ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 7);
				// **********************************************
				
				passagem_reservada();
				parar();
				
				P.situacao = 'R';
				cadastrar_passageiro (&V, P, lin, col);
				break;
				
			case 3:
				exibir_acentos (V);
				parar();
				break;	
				
			case 4:
				exibir_acentos (V);
				printf("Digite a fileira e coluna a ser consultada:\n");
				scanf("%d %d", &lin, &col);
				printf("\n");
				
				while (lin < 1 || col < 1 || lin > 12 || col > 4) {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					// *******************************************
					
					printf("O numero digitado nao corresponde ao numero de fileiras ou colunas!\n");
					printf("Por favor, digite a fileira e coluna do acento novamente\n");
					
					// *********** VOLTANDO AO NORMAL ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 7);
					// **********************************************
					
					scanf("%d %d", &lin, &col);
					printf("\n");
				}
				
				if (V.poltronas[lin-1][col-1].situacao == 'V') {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 10);
					// *******************************************
					
					printf("O acento da fileira %d, coluna %d esta vazio %c\n\n", lin, col, asc2 = 1);
				} else {
					
					// ************* MUDANDO A COR ***************
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					
					// *******************************************
					printf("O acento da fileira %d, coluna %d esta ocupado!\n\n", lin, col);
				}
				
				// *********** VOLTANDO AO NORMAL ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 7);
				// **********************************************
				
				parar();
				break;
				
			case 5:
				printf("+++++++++ EXIBICAO DAS PASSAGENS COMPRADAS +++++++++\n\n");
				
				for (lin = 0; lin < L; lin++) {
					for (col = 0; col < C; col++) {
						if (V.poltronas[lin][col].situacao != 'V') {
							exibir_passageiro (V.poltronas[lin][col], V, lin, col);
						}
					}
				}
				
				parar();
				break;	
				
			case 6:
				printf("Obrigado por utilizar nossos servicos, volte sempre ");
				
				// ************* MUDANDO A COR ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
				// *******************************************
				
				printf("%c", asc = 3);
				
				
				// ************* MUDANDO A COR ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 14);
				// *******************************************
				
				printf("%c\n\n", asc2 = 1);
				
				// *********** VOLTANDO AO NORMAL ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 7);
				// **********************************************
				
				Gravar_viagem (V);
				break;	
				
			default:
				
				// ************* MUDANDO A COR ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
				// *******************************************
				
				printf("Opcao invalida!\n");
				printf("Por favor, digite uma opcao valida. Obrigado!\n\n");	
				
				// *********** VOLTANDO AO NORMAL ***************
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 7);
				// **********************************************
				
				parar();
				break;
		}	
	} while (opcao != 6);
	
	return 0;
}
