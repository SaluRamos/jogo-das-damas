#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int escolha;

//declaração de void's
void versao1 (void);
void render1 (void);
void selecao1 (void);
void movimento1 (void);
void erro_movimento1 (void);
void venceu1 (void);

void versao2 (void);
void render2 (void);
void selecao2 (void);
void movimento2 (void);
void erro_movimento2 (void);
void enemy2 (void);
void enemy_selected2 (void);
void venceu2 (void);
void derrota2 (void);

void versao3 (void);
void render3 (void);
void selecao3 (void);
void movimento3 (void);
void erro_movimento3 (void);
void venceu3 (void);

void versao4 (void);
void render4 (void);
void selecao4 (void);
void movimento4 (void);
void erro_movimento4 (void);
void enemy4 (void);
void enemy_selected4 (void);
void venceu4 (void);
void derrota4 (void);

//outras variaveis
char posicao[9][9];
int posicao_selecionada[2];
int posicao_movida[2];
char caracter_selecionado;
char caracter_movido;
int jogador = 1;
int vencedor;
int totalmovs;
int selected_mov, mov1, mov2, mov3, mov4, mov5, mov6;
int posicao_enemy[2];
int l = 1, c = 1, i = 0;
int enemys_l[13], enemys_c[13];
int randomm;
bool comeu = false;
bool enemy_comeu;
bool verify;

int main ()
{
	printf("\n\nVERS%cO 1 - Jogador contra jogador. N%co %c poss%cvel comer v%crias pe%cas em sequ%cncia. Ganha quem chegar ao lado oposto.", 199, 198, 130,161, 160, 135, 136);
	printf("\nVERS%cO 2 - Jogador contra computador. N%co %c poss%cvel comer v%crias pe%cas em sequ%cncia. Ganha quem chegar ao lado oposto.", 199, 198, 130,161, 160, 135, 136);
	printf("\nVERS%cO 3 - Jogador contra jogador. %c poss%cvel comer v%crias pe%cas em sequ%cncia. Ganha quem chegar ao lado oposto.", 199, 144, 161, 160, 135, 136);
	printf("\nVERS%cO 4 - Jogador contra computador. %c poss%cvel comer v%crias pe%cas em sequ%cncia. Ganha quem chegar ao lado oposto.", 199, 144, 161, 160, 135, 136);
	printf("\n\nDIGITE A VERS%cO QUE DESEJA SELECIONAR: ", 199);
	scanf("%d", &escolha);
	
	if(escolha == 1)
	{
		versao1();
	}
	else if(escolha == 2)
	{
		versao2();
	}
	else if(escolha == 3)
	{
		versao3();
	}
	else if(escolha == 4)
	{
		versao4();
	}
}
void versao1 (void)
{
	system("cls");
	//tutorial
	system("color 70");
	printf("JOGO DA DAMA - VERS%cO 1 (by.: Salu Ramos)", 199);
	printf("\n\nTUTORIAL:");
	printf("\n- Para escolher a posi%c%co desejada: Digite a coordenada em Y (linha), depois em X (coluna).", 135, 198, 198, 135);
	printf("\n- 'X' representa as pe%cas pretas e 'O' as pe%cas brancas.", 135, 135);
	printf("\n- As pe%cas brancas come%cam o jogo.", 135, 135);
	printf("\n- Vence o jogador que colocar uma pe%ca na linha oposta do tabuleiro.", 135);
	printf("\n- O jogo funciona para 2 pessoas.");
	printf("\n- N%co %c poss%cvel comer mais de uma pe%ca seguidamente.", 198, 130, 161, 135);
	printf("\n\nO JOGO COME%cA EM 10 SEGUNDOS!", 128);
	Sleep(10000);
	//definir local das peças iniciais
	posicao[1][2] = 'X', posicao[1][4] = 'X', posicao[1][6] = 'X', posicao[1][8] = 'X';
	posicao[2][1] = 'X', posicao[2][3] = 'X', posicao[2][5] = 'X', posicao[2][7] = 'X';
	posicao[3][2] = 'X', posicao[3][4] = 'X', posicao[3][6] = 'X', posicao[3][8] = 'X';
	posicao[6][1] = 'O', posicao[6][3] = 'O', posicao[6][5] = 'O', posicao[6][7] = 'O';
	posicao[7][2] = 'O', posicao[7][4] = 'O', posicao[7][6] = 'O', posicao[7][8] = 'O';
	posicao[8][1] = 'O', posicao[8][3] = 'O', posicao[8][5] = 'O', posicao[8][7] = 'O';
	render1();
}
void render1 (void)
{
	//atualizar tabuleiro
	system("cls");
	printf("\n     1 2 3 4 5 6 7 8");
	printf("\n     + + + + + + + +");
	printf("\n1 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[1][1], posicao[1][2], posicao[1][3], posicao[1][4], posicao[1][5], posicao[1][6], posicao[1][7], posicao[1][8]);
	printf("\n2 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[2][1], posicao[2][2], posicao[2][3], posicao[2][4], posicao[2][5], posicao[2][6], posicao[2][7], posicao[2][8]);
	printf("\n3 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[3][1], posicao[3][2], posicao[3][3], posicao[3][4], posicao[3][5], posicao[3][6], posicao[3][7], posicao[3][8]);
	printf("\n4 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[4][1], posicao[4][2], posicao[4][3], posicao[4][4], posicao[4][5], posicao[4][6], posicao[4][7], posicao[4][8]);
	printf("\n5 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[5][1], posicao[5][2], posicao[5][3], posicao[5][4], posicao[5][5], posicao[5][6], posicao[5][7], posicao[5][8]);
	printf("\n6 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[6][1], posicao[6][2], posicao[6][3], posicao[6][4], posicao[6][5], posicao[6][6], posicao[6][7], posicao[6][8]);
	printf("\n7 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[7][1], posicao[7][2], posicao[7][3], posicao[7][4], posicao[7][5], posicao[7][6], posicao[7][7], posicao[7][8]);
	printf("\n8 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[8][1], posicao[8][2], posicao[8][3], posicao[8][4], posicao[8][5], posicao[8][6], posicao[8][7], posicao[8][8]);
	//verificar vitória
	if(posicao[1][1] == 'O' || posicao[1][2] == 'O' || posicao[1][3] == 'O' || posicao[1][4] == 'O' || posicao[1][5] == 'O' || posicao[1][6] == 'O' || posicao[1][7] == 'O' || posicao[1][8] == 'O')
	{
		vencedor = 1;
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu1();
	}
	if(posicao[8][1] == 'X' || posicao[8][2] == 'X' || posicao[8][3] == 'X' || posicao[8][4] == 'X' || posicao[8][5] == 'X' || posicao[8][6] == 'X' || posicao[8][7] == 'X' || posicao[8][8] == 'X')
	{
		vencedor = 2;
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu1();
	}
	//verificar qual o proximo passo
	if(caracter_selecionado != NULL)
	{
		movimento1();
	}
	else
	{
		selecao1();
	}
}
void selecao1 (void)
{
	//qual jogador
	if(jogador == 1)
	{
		printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	}
	else
	{
		printf("\n\nJOGADOR 2: PE%cAS 'X'", 128);
	}
	//selecionar peça
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[0]);
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[1]);
	//armazenar caracter selecionado
	caracter_selecionado = posicao[posicao_selecionada[0]][posicao_selecionada[1]];
	//selecionou correto
	if(jogador == 1 && caracter_selecionado == 'O')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render1();
	}
	else if(jogador == 2 && caracter_selecionado == 'X')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render1();
	}
	//selecionou errado
	else
	{
		caracter_selecionado = NULL;
		printf("\nVOC%c N%cO SELECIONOU UMA PE%cA SUA!", 210, 199, 128);
		printf("\nAGUARDE 5 SEGUNDOS!");
		Sleep(5000);
		render1();
	}
}
void movimento1 (void)
{	
	//qual jogador esta fazendo o movimento?
	if(jogador == 1)
	{
		printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	}
	else
	{
		printf("\n\nJOGADOR 2: PE%cAS 'X'", 128);
	}
	//definir casa para mover e verificar se encontra-se dentro do tabuleiro
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[0]);
	if(posicao_movida[0] <= 0 || posicao_movida[0] >= 9)
	{
		erro_movimento1();
	}
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[1]);
	if(posicao_movida[1] <= 0 || posicao_movida[1] >= 9)
	{
		erro_movimento1();
	}
	//armazenar caracter movido e verificar se é nulo
	caracter_movido = posicao[posicao_movida[0]][posicao_movida[1]];
	if(caracter_movido != NULL)
	{
		erro_movimento1();
	}
	//JOGADOR 1 (movimento especifico de andar)
	if(jogador == 1)
	{
		//andar -1 -1
	if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]-1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar -1 +1
	else if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]+1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
		//comer -2 -2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento1();
	}
	}
	//JOGADOR 2 (movimento especifico de andar)
	if(jogador == 2)
	{
		//andar +1 -1
	if(posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]+1 && posicao_movida[1] == posicao_selecionada[1]-1)
	{
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar +1 +1
	else if(posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]+1 && posicao_movida[1] == posicao_selecionada[1]+1)
	{
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
		//comer -2 -2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'O')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'O')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'O')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'O')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento1();
	}	
	}
	//redefinir valores e trocar de jogador
	posicao_selecionada[0] = NULL;
	posicao_selecionada[1] = NULL;
	posicao_movida[0] = NULL;
	posicao_movida[1] = NULL;
	caracter_selecionado = NULL;
	caracter_movido = NULL;
	if(jogador == 1)
	{
		jogador = 2;
	}
	else
	{
		jogador = 1;
	}
	render1();
}
void erro_movimento1 (void)
{
	printf("\nVOC%c N%cO SELECIONOU UMA CASA V%cLIDA! REFA%cA A SELE%c%cO!", 210, 199, 181, 128, 128, 199);
	printf("\nAGUARDE 5 SEGUNDOS!");
	posicao[posicao_selecionada[0]][posicao_selecionada[1]] = caracter_selecionado;
	caracter_selecionado = NULL;
	Sleep(5000);
	render1();
}
void venceu1 (void)
{
	system("cls");
	printf("\nPARAB%cNS JOGADOR '%d'! \nVOC%c VENCEU!", 144, vencedor,210);
	Sleep(300);
	system("color 1");
	Sleep(300);
	system("color 2");
	Sleep(300);
	system("color F");
	Sleep(300);
	system("color 4");
	Sleep(300);
	system("color 5");
	Sleep(300);
	system("color 6");
	Sleep(300);
	system("color 9");
	Sleep(300);
	system("color D");
	venceu1();
}
void versao2 (void)
{
	system("cls");
	//tutorial
	system("color 70");
	printf("JOGO DA DAMA - VERS%cO 2 (by.: Salu Ramos)", 199);
	printf("\n\nTUTORIAL:");
	printf("\n- Para escolher a posi%c%co desejada: Digite a coordenada em Y (linha), depois em X (coluna).", 135, 198, 198, 135);
	printf("\n- 'X' representa as pe%cas pretas e 'O' as pe%cas brancas.", 135, 135);
	printf("\n- As pe%cas brancas come%cam o jogo.", 135, 135);
	printf("\n- Vence o jogador que colocar uma pe%ca na linha oposta do tabuleiro.", 135);
	printf("\n- O jogo funciona para 1 pessoa contra o computador.");
	printf("\n- N%co %c poss%cvel comer mais de uma pe%ca seguidamente.", 198, 130, 161, 135);
	printf("\n\nO JOGO COME%cA EM 10 SEGUNDOS!", 128);
	Sleep(10000);
	//definir local das peças iniciais
	posicao[1][2] = 'X', posicao[1][4] = 'X', posicao[1][6] = 'X', posicao[1][8] = 'X';
	posicao[2][1] = 'X', posicao[2][3] = 'X', posicao[2][5] = 'X', posicao[2][7] = 'X';
	posicao[3][2] = 'X', posicao[3][4] = 'X', posicao[3][6] = 'X', posicao[3][8] = 'X';
	posicao[6][1] = 'O', posicao[6][3] = 'O', posicao[6][5] = 'O', posicao[6][7] = 'O';
	posicao[7][2] = 'O', posicao[7][4] = 'O', posicao[7][6] = 'O', posicao[7][8] = 'O';
	posicao[8][1] = 'O', posicao[8][3] = 'O', posicao[8][5] = 'O', posicao[8][7] = 'O';
	render2();
}
void render2 (void)
{
	//atualizar tabuleiro
	system("cls");
	printf("\n     1 2 3 4 5 6 7 8");
	printf("\n     + + + + + + + +");
	printf("\n1 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[1][1], posicao[1][2], posicao[1][3], posicao[1][4], posicao[1][5], posicao[1][6], posicao[1][7], posicao[1][8]);
	printf("\n2 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[2][1], posicao[2][2], posicao[2][3], posicao[2][4], posicao[2][5], posicao[2][6], posicao[2][7], posicao[2][8]);
	printf("\n3 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[3][1], posicao[3][2], posicao[3][3], posicao[3][4], posicao[3][5], posicao[3][6], posicao[3][7], posicao[3][8]);
	printf("\n4 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[4][1], posicao[4][2], posicao[4][3], posicao[4][4], posicao[4][5], posicao[4][6], posicao[4][7], posicao[4][8]);
	printf("\n5 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[5][1], posicao[5][2], posicao[5][3], posicao[5][4], posicao[5][5], posicao[5][6], posicao[5][7], posicao[5][8]);
	printf("\n6 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[6][1], posicao[6][2], posicao[6][3], posicao[6][4], posicao[6][5], posicao[6][6], posicao[6][7], posicao[6][8]);
	printf("\n7 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[7][1], posicao[7][2], posicao[7][3], posicao[7][4], posicao[7][5], posicao[7][6], posicao[7][7], posicao[7][8]);
	printf("\n8 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[8][1], posicao[8][2], posicao[8][3], posicao[8][4], posicao[8][5], posicao[8][6], posicao[8][7], posicao[8][8]);
	//verificar vitória ou derrota
	if(posicao[1][1] == 'O' || posicao[1][2] == 'O' || posicao[1][3] == 'O' || posicao[1][4] == 'O' || posicao[1][5] == 'O' || posicao[1][6] == 'O' || posicao[1][7] == 'O' || posicao[1][8] == 'O')
	{
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu2();
	}
	if(posicao[8][1] == 'X' || posicao[8][2] == 'X' || posicao[8][3] == 'X' || posicao[8][4] == 'X' || posicao[8][5] == 'X' || posicao[8][6] == 'X' || posicao[8][7] == 'X' || posicao[8][8] == 'X')
	{
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		derrota2();
	}
	//verificar qual o proximo passo
	if(caracter_selecionado != NULL && jogador == 1)
	{
		movimento2();
	}
	else if (jogador == 1)
	{
		selecao2();
	}
	if(jogador == 2)
	{
		printf("\n\nO COMPUTADOR ESTA JOGANDO! AGUARDE...");
		enemy2();
	}
}
void selecao2 (void)
{

	printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	//selecionar peça
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[0]);
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[1]);
	//armazenar caracter selecionado
	caracter_selecionado = posicao[posicao_selecionada[0]][posicao_selecionada[1]];
	//selecionou correto
	if(jogador == 1 && caracter_selecionado == 'O')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render2();
	}
	//selecionou errado
	else
	{
		caracter_selecionado = NULL;
		printf("\nVOC%c N%cO SELECIONOU UMA PE%cA SUA!", 210, 199, 128);
		printf("\nAGUARDE 5 SEGUNDOS!");
		Sleep(5000);
		render2();
	}
}
void movimento2 (void)
{	
	printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	//definir casa para mover e verificar se encontra-se dentro do tabuleiro
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[0]);
	if(posicao_movida[0] <= 0 || posicao_movida[0] >= 9)
	{
		erro_movimento2();
	}
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[1]);
	if(posicao_movida[1] <= 0 || posicao_movida[1] >= 9)
	{
		erro_movimento2();
	}
	//armazenar caracter movido e verificar se é nulo
	caracter_movido = posicao[posicao_movida[0]][posicao_movida[1]];
	if(caracter_movido != NULL)
	{
		erro_movimento2();
	}
	//MOVIMENTO
		//andar -1 -1
	if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]-1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar -1 +1
	else if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]+1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
		//comer -2 -2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento2();
	}
	//redefinir valores e trocar de jogador
	posicao_selecionada[0] = NULL;
	posicao_selecionada[1] = NULL;
	posicao_movida[0] = NULL;
	posicao_movida[1] = NULL;
	caracter_selecionado = NULL;
	caracter_movido = NULL;
	jogador = 2;
	render2();
}
void erro_movimento2 (void)
{
	printf("\nVOC%c N%cO SELECIONOU UMA CASA V%cLIDA! REFA%cA A SELE%c%cO!", 210, 199, 181, 128, 128, 199);
	printf("\nAGUARDE 5 SEGUNDOS!");
	posicao[posicao_selecionada[0]][posicao_selecionada[1]] = caracter_selecionado;
	caracter_selecionado = NULL;
	Sleep(5000);
	render2();
}
void enemy2 ()
{
	//verificar a localizacao das peças pretas
	while(l < 9)
	{
		if(posicao[l][c] == 'X')
		{
			i++;
			enemys_l[i] = l;
			enemys_c[i] = c;
			//printf("\n%d %d", enemys_l[i], enemys_c[i]);
		}
		c++;
		if(c > 8)
		{
			l++;
			c = 1;
		}
	}
	//random peça
	srand(time(NULL));
	randomm = (rand() % i) + 1;
	//printf("\nRANDOMM == %d", randomm);
	posicao_enemy[0] = enemys_l[randomm];
	posicao_enemy[1] = enemys_c[randomm];
	randomm = NULL;
	//printf("\n\ntestar linha: %d", posicao_enemy[0]);
	//printf("\ntestar coluna: %d", posicao_enemy[1]);
	//resetar valores do loop
	l = 1;
	c = 1;
	i = 1;
	while(i < 13)
	{
		enemys_l[i] = NULL;
		enemys_c[i] = NULL;
		i++;
	}
	i = 0;
	//verificar se selecionou uma peça que pode fazer movimentos
	if(posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] == NULL && posicao_enemy[1]-1 > 0)
	{
		totalmovs++;
		mov1 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] == NULL && posicao_enemy[1]+1 < 9)
	{
		totalmovs++;
		mov2 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]-2 > 0)
	{
		totalmovs++;
		mov3 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]+2 < 9)
	{
		totalmovs++;
		mov4 = totalmovs;
	}
	if(posicao[posicao_enemy[0]-2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]-2 > 0)
	{
		totalmovs++;
		mov5 = totalmovs;
	}
	if(posicao[posicao_enemy[0]-2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]+2 < 9)
	{
		totalmovs++;
		mov6 = totalmovs;
	}
	if(totalmovs > 0)
	{
		enemy_selected2();
	}
	else
	{
		Sleep(1000);
		//printf("\nTRY AGAIN");
		enemy2();
	}
}
void enemy_selected2 (void)
{
	//random mov
	Sleep(1000);
	selected_mov = (rand() % totalmovs)+1;
	//realizar movimento
	if(mov1 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] = 'X';
	}
	if(mov2 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] = 'X';
	}
	if(mov3 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+2][posicao_enemy[1]-2] = 'X';
		posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] = NULL;
	}
	if(mov4 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+2][posicao_enemy[1]+2] = 'X';
		posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] = NULL;
	}
	if(mov5 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]-2][posicao_enemy[1]-2] = 'X';
		posicao[posicao_enemy[0]-1][posicao_enemy[1]-1] = NULL;
	}
	if(mov6 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]-2][posicao_enemy[1]+2] = 'X';
		posicao[posicao_enemy[0]-1][posicao_enemy[1]+1] = NULL;
	}
	//resetar variaveis e trocar de jogador
	mov1 = 0;
	mov2 = 0;
	mov3 = 0;
	mov4 = 0;
	mov5 = 0;
	mov6 = 0;
	totalmovs = 0;
	posicao_enemy[0] = 0;
	posicao_enemy[1] = 0;
	jogador = 1;
	Sleep(2000);
	render2();
}
void venceu2 (void)
{
	system("cls");
	printf("\nPARAB%cNS! \nVOC%c VENCEU!", 144, 210);
	Sleep(300);
	system("color 1");
	Sleep(300);
	system("color 2");
	Sleep(300);
	system("color F");
	Sleep(300);
	system("color 4");
	Sleep(300);
	system("color 5");
	Sleep(300);
	system("color 6");
	Sleep(300);
	system("color 9");
	Sleep(300);
	system("color D");
	venceu2();
}
void derrota2 (void)
{
	system("cls");
	system("color 07");
	printf("\nVOC%c PERDEU!", 210);
}
void versao3 (void)
{
	system("cls");
	//tutorial
	system("color 70");
	printf("JOGO DA DAMA - VERS%cO 3 (by.: Salu Ramos)", 199);
	printf("\n\nTUTORIAL:");
	printf("\n- Para escolher a posi%c%co desejada: Digite a coordenada em Y (linha), depois em X (coluna).", 135, 198, 198, 135);
	printf("\n- 'X' representa as pe%cas pretas e 'O' as pe%cas brancas.", 135, 135);
	printf("\n- As pe%cas brancas come%cam o jogo.", 135, 135);
	printf("\n- Vence o jogador que colocar uma pe%ca na linha oposta do tabuleiro.", 135);
	printf("\n- O jogo funciona para 2 pessoas.");
	printf("\n- %c poss%cvel comer mais de uma pe%ca seguidamente.", 144, 161, 135);
	printf("\n\nO JOGO COME%cA EM 10 SEGUNDOS!", 128);
	Sleep(10000);
	//definir local das peças iniciais
	posicao[1][2] = 'X', posicao[1][4] = 'X', posicao[1][6] = 'X', posicao[1][8] = 'X';
	posicao[2][1] = 'X', posicao[2][3] = 'X', posicao[2][5] = 'X', posicao[2][7] = 'X';
	posicao[3][2] = 'X', posicao[3][4] = 'X', posicao[3][6] = 'X', posicao[3][8] = 'X';
	posicao[6][1] = 'O', posicao[6][3] = 'O', posicao[6][5] = 'O', posicao[6][7] = 'O';
	posicao[7][2] = 'O', posicao[7][4] = 'O', posicao[7][6] = 'O', posicao[7][8] = 'O';
	posicao[8][1] = 'O', posicao[8][3] = 'O', posicao[8][5] = 'O', posicao[8][7] = 'O';
	render3();
}
void render3 (void)
{
	//atualizar tabuleiro
	system("cls");
	printf("\n     1 2 3 4 5 6 7 8");
	printf("\n     + + + + + + + +");
	printf("\n1 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[1][1], posicao[1][2], posicao[1][3], posicao[1][4], posicao[1][5], posicao[1][6], posicao[1][7], posicao[1][8]);
	printf("\n2 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[2][1], posicao[2][2], posicao[2][3], posicao[2][4], posicao[2][5], posicao[2][6], posicao[2][7], posicao[2][8]);
	printf("\n3 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[3][1], posicao[3][2], posicao[3][3], posicao[3][4], posicao[3][5], posicao[3][6], posicao[3][7], posicao[3][8]);
	printf("\n4 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[4][1], posicao[4][2], posicao[4][3], posicao[4][4], posicao[4][5], posicao[4][6], posicao[4][7], posicao[4][8]);
	printf("\n5 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[5][1], posicao[5][2], posicao[5][3], posicao[5][4], posicao[5][5], posicao[5][6], posicao[5][7], posicao[5][8]);
	printf("\n6 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[6][1], posicao[6][2], posicao[6][3], posicao[6][4], posicao[6][5], posicao[6][6], posicao[6][7], posicao[6][8]);
	printf("\n7 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[7][1], posicao[7][2], posicao[7][3], posicao[7][4], posicao[7][5], posicao[7][6], posicao[7][7], posicao[7][8]);
	printf("\n8 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[8][1], posicao[8][2], posicao[8][3], posicao[8][4], posicao[8][5], posicao[8][6], posicao[8][7], posicao[8][8]);
	//verificar vitória
	if(posicao[1][1] == 'O' || posicao[1][2] == 'O' || posicao[1][3] == 'O' || posicao[1][4] == 'O' || posicao[1][5] == 'O' || posicao[1][6] == 'O' || posicao[1][7] == 'O' || posicao[1][8] == 'O')
	{
		vencedor = 1;
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu3();
	}
	if(posicao[8][1] == 'X' || posicao[8][2] == 'X' || posicao[8][3] == 'X' || posicao[8][4] == 'X' || posicao[8][5] == 'X' || posicao[8][6] == 'X' || posicao[8][7] == 'X' || posicao[8][8] == 'X')
	{
		vencedor = 2;
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu3();
	}
	//verificar qual o proximo passo
	if(caracter_selecionado != NULL)
	{
		movimento3();
	}
	else
	{
		selecao3();
	}
}
void selecao3 (void)
{
	//qual jogador
	if(jogador == 1)
	{
		printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	}
	else
	{
		printf("\n\nJOGADOR 2: PE%cAS 'X'", 128);
	}
	//selecionar peça
	if(comeu == false)
	{
		printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) DA SUA PE%cA: ", 128);
		scanf("%d", &posicao_selecionada[0]);
		printf("DIGITE A COORDENADA EM 'X' (COLUNA) DA SUA PE%cA: ", 128);
		scanf("%d", &posicao_selecionada[1]);
	}
	//armazenar caracter selecionado
	caracter_selecionado = posicao[posicao_selecionada[0]][posicao_selecionada[1]];
	//selecionou correto
	if(jogador == 1 && caracter_selecionado == 'O')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render3();
	}
	else if(jogador == 2 && caracter_selecionado == 'X')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render3();
	}
	//selecionou errado
	else
	{
		caracter_selecionado = NULL;
		printf("\nVOC%c N%cO SELECIONOU UMA PE%cA SUA!", 210, 199, 128);
		printf("\nAGUARDE 5 SEGUNDOS!");
		Sleep(5000);
		render3();
	}
}
void movimento3 (void)
{	
	//qual jogador esta fazendo o movimento?
	if(jogador == 1)
	{
		printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	}
	else
	{
		printf("\n\nJOGADOR 2: PE%cAS 'X'", 128);
	}
	//definir casa para mover e verificar se encontra-se dentro do tabuleiro
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[0]);
	if(posicao_movida[0] <= 0 || posicao_movida[0] >= 9)
	{
		erro_movimento3();
	}
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[1]);
	if(posicao_movida[1] <= 0 || posicao_movida[1] >= 9)
	{
		erro_movimento3();
	}
	//armazenar caracter movido e verificar se é nulo
	caracter_movido = posicao[posicao_movida[0]][posicao_movida[1]];
	if(caracter_movido != NULL)
	{
		erro_movimento3();
	}
	//JOGADOR 1
	if(jogador == 1)
	{
		//andar -1 -1
	if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]-1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar -1 +1
	else if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]+1)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
	else
	{
		//comer -2 -2
	if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento3();
	}
	}
	}
	//JOGADOR 2
	if(jogador == 2)
	{
		//andar +1 -1
	if(posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]+1 && posicao_movida[1] == posicao_selecionada[1]-1)
	{
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar +1 +1
	else if(posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]+1 && posicao_movida[1] == posicao_selecionada[1]+1)
	{
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
	else
	{
		//comer -2 -2
	if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'O')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'O')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'O')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'O')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'X';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento3();
	}	
	}
	}
	//verificar se pode comer novamente
	if(comeu == true)
	{
		posicao_selecionada[0] = posicao_movida[0];
		posicao_selecionada[1] = posicao_movida[1];
		if(jogador == 1)
		{
			if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]-2 > 0)
		{
		}
			else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]+2 < 9)
		{
		}
			else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]-2 > 0)
		{
		}
			else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]+2 < 9)
		{
		}
			else
		{
			comeu = false;
		}
		}
		if(jogador == 2)
		{
			if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'O' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]-2 > 0)
		{
		}
			else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'O' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]+2 < 9)
		{
		}
			else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'O' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]-2 > 0)
		{
		}
			else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'O' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]+2 < 9)
		{
		}
			else
		{
			comeu = false;
		}
		}
	}
	else
	{
		posicao_selecionada[0] = NULL;
		posicao_selecionada[1] = NULL;
	}
	//redefinir valores e trocar de jogador/renovar jogada
	caracter_selecionado = NULL;
	caracter_movido = NULL;
	posicao_movida[0] = NULL;
	posicao_movida[1] = NULL;
	if(jogador == 1 && comeu == false)
	{
		jogador = 2;
	}
	else if(comeu == false)
	{
		jogador = 1;
	}
	render3();
}
void erro_movimento3 (void)
{
	printf("\nVOC%c N%cO SELECIONOU UMA CASA V%cLIDA! REFA%cA A SELE%c%cO!", 210, 199, 181, 128, 128, 199);
	printf("\nAGUARDE 5 SEGUNDOS!");
	posicao[posicao_selecionada[0]][posicao_selecionada[1]] = caracter_selecionado;
	caracter_selecionado = NULL;
	Sleep(5000);
	render3();
}
void venceu3 (void)
{
	system("cls");
	printf("\nPARAB%cNS JOGADOR '%d'! \nVOC%c VENCEU!", 144, vencedor,210);
	Sleep(300);
	system("color 1");
	Sleep(300);
	system("color 2");
	Sleep(300);
	system("color F");
	Sleep(300);
	system("color 4");
	Sleep(300);
	system("color 5");
	Sleep(300);
	system("color 6");
	Sleep(300);
	system("color 9");
	Sleep(300);
	system("color D");
	venceu3();
}
void versao4 (void)
{
	system("cls");
	//tutorial
	system("color 70");
	printf("JOGO DA DAMA - VERS%cO 4 (by.: Salu Ramos)", 199);
	printf("\n\nTUTORIAL:");
	printf("\n- Para escolher a posi%c%co desejada: Digite a coordenada em Y (linha), depois em X (coluna).", 135, 198, 198, 135);
	printf("\n- 'X' representa as pe%cas pretas e 'O' as pe%cas brancas.", 135, 135);
	printf("\n- As pe%cas brancas come%cam o jogo.", 135, 135);
	printf("\n- Vence o jogador que colocar uma pe%ca na linha oposta do tabuleiro.", 135);
	printf("\n- O jogo funciona para 1 pessoa contra o computador.");
	printf("\n- %c poss%cvel comer mais de uma pe%ca seguidamente.", 144, 161, 135);
	printf("\n\nO JOGO COME%cA EM 10 SEGUNDOS!", 128);
	Sleep(10000);
	//definir local das peças iniciais
	posicao[1][2] = 'X', posicao[1][4] = 'X', posicao[1][6] = 'X', posicao[1][8] = 'X';
	posicao[2][1] = 'X', posicao[2][3] = 'X', posicao[2][5] = 'X', posicao[2][7] = 'X';
	posicao[3][2] = 'X', posicao[3][4] = 'X', posicao[3][6] = 'X', posicao[3][8] = 'X';
	posicao[6][1] = 'O', posicao[6][3] = 'O', posicao[6][5] = 'O', posicao[6][7] = 'O';
	posicao[7][2] = 'O', posicao[7][4] = 'O', posicao[7][6] = 'O', posicao[7][8] = 'O';
	posicao[8][1] = 'O', posicao[8][3] = 'O', posicao[8][5] = 'O', posicao[8][7] = 'O';
	render4();
}
void render4 (void)
{
	//atualizar tabuleiro
	system("cls");
	printf("\n     1 2 3 4 5 6 7 8");
	printf("\n     + + + + + + + +");
	printf("\n1 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[1][1], posicao[1][2], posicao[1][3], posicao[1][4], posicao[1][5], posicao[1][6], posicao[1][7], posicao[1][8]);
	printf("\n2 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[2][1], posicao[2][2], posicao[2][3], posicao[2][4], posicao[2][5], posicao[2][6], posicao[2][7], posicao[2][8]);
	printf("\n3 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[3][1], posicao[3][2], posicao[3][3], posicao[3][4], posicao[3][5], posicao[3][6], posicao[3][7], posicao[3][8]);
	printf("\n4 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[4][1], posicao[4][2], posicao[4][3], posicao[4][4], posicao[4][5], posicao[4][6], posicao[4][7], posicao[4][8]);
	printf("\n5 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[5][1], posicao[5][2], posicao[5][3], posicao[5][4], posicao[5][5], posicao[5][6], posicao[5][7], posicao[5][8]);
	printf("\n6 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[6][1], posicao[6][2], posicao[6][3], posicao[6][4], posicao[6][5], posicao[6][6], posicao[6][7], posicao[6][8]);
	printf("\n7 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[7][1], posicao[7][2], posicao[7][3], posicao[7][4], posicao[7][5], posicao[7][6], posicao[7][7], posicao[7][8]);
	printf("\n8 + |%c|%c|%c|%c|%c|%c|%c|%c|",posicao[8][1], posicao[8][2], posicao[8][3], posicao[8][4], posicao[8][5], posicao[8][6], posicao[8][7], posicao[8][8]);
	//verificar vitória ou derrota
	if(posicao[1][1] == 'O' || posicao[1][2] == 'O' || posicao[1][3] == 'O' || posicao[1][4] == 'O' || posicao[1][5] == 'O' || posicao[1][6] == 'O' || posicao[1][7] == 'O' || posicao[1][8] == 'O')
	{
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu4();
	}
	if(posicao[8][1] == 'X' || posicao[8][2] == 'X' || posicao[8][3] == 'X' || posicao[8][4] == 'X' || posicao[8][5] == 'X' || posicao[8][6] == 'X' || posicao[8][7] == 'X' || posicao[8][8] == 'X')
	{
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		derrota4();
	}
	//verificar se alguem vai repetir
	if(comeu == true)
	{
		movimento4();
	}
	else if(enemy_comeu == true)
	{
		printf("\n\nO COMPUTADOR VAI JOGAR NOVAMENTE!");
		Sleep(1000);
		enemy4();
	}
	//verificar qual o proximo passo
	if(caracter_selecionado != NULL && jogador == 1)
	{
		movimento4();
	}
	else if (jogador == 1)
	{
		selecao4();
	}
	if(jogador == 2)
	{
		printf("\n\nO COMPUTADOR ESTA JOGANDO! AGUARDE...");
		enemy4();
	}
}
void selecao4 (void)
{

	printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	//selecionar peça
	if(comeu == false)
	{
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[0]);
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) DA SUA PE%cA: ", 128);
	scanf("%d", &posicao_selecionada[1]);
	}
	//armazenar caracter selecionado
	caracter_selecionado = posicao[posicao_selecionada[0]][posicao_selecionada[1]];
	//selecionou correto
	if(caracter_selecionado == 'O')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render4();
	}
	//selecionou errado
	else
	{
		caracter_selecionado = NULL;
		printf("\nVOC%c N%cO SELECIONOU UMA PE%cA SUA!", 210, 199, 128);
		printf("\nAGUARDE 5 SEGUNDOS!");
		Sleep(5000);
		render4();
	}
}
void movimento4 (void)
{	
	printf("\n\nJOGADOR 1: PE%cAS 'O'", 128);
	//definir casa para mover e verificar se encontra-se dentro do tabuleiro
	printf("\n\nDIGITE A COORDENADA EM 'Y' (LINHA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[0]);
	if(posicao_movida[0] <= 0 || posicao_movida[0] >= 9)
	{
		erro_movimento4();
	}
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[1]);
	if(posicao_movida[1] <= 0 || posicao_movida[1] >= 9)
	{
		erro_movimento4();
	}
	//armazenar caracter movido e verificar se é nulo
	caracter_movido = posicao[posicao_movida[0]][posicao_movida[1]];
	if(caracter_movido != NULL)
	{
		erro_movimento4();
	}
	//MOVIMENTO
	comeu = false;
		//andar -1 -1
	if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]-1 && comeu == false)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;	
	}
		//andar -1 +1
	else if(posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == NULL && posicao_movida[0] == posicao_selecionada[0]-1 && posicao_movida[1] == posicao_selecionada[1]+1 && comeu == false)
	{
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
	}
		//comer -2 -2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer -2 +2
	else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]-2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//comer +2 -2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]-2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] = NULL;
		comeu = true;
	}
		//comer +2 +2
	else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao_movida[0] == posicao_selecionada[0]+2 && posicao_movida[1] == posicao_selecionada[1]+2 && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X')
	{
		posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] = 'O';
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = NULL;
		posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] = NULL;
		comeu = true;
	}
		//movimento errado (call void: erro_movimento)
	else
	{
		erro_movimento4();
	}
	//redefinir valores e trocar de jogador
	if(comeu == true)
	{
		posicao_selecionada[0] = posicao_movida[0];
		posicao_selecionada[1] = posicao_movida[1];
		caracter_selecionado = posicao[posicao_selecionada[0]][posicao_selecionada[1]];
		if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]-1] == 'X' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]-2 > 0)
		{
			posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		}
		else if(posicao[posicao_selecionada[0]-2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]-1][posicao_selecionada[1]+1] == 'X' && posicao_selecionada[0]-2 > 0 && posicao_selecionada[1]+2 < 9)
		{
			posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		}
		else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]-2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]-1] == 'X' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]-2 > 0)
		{
			posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		}
		else if(posicao[posicao_selecionada[0]+2][posicao_selecionada[1]+2] == NULL && posicao[posicao_selecionada[0]+1][posicao_selecionada[1]+1] == 'X' && posicao_selecionada[0]+2 < 9 && posicao_selecionada[1]+2 < 9)
		{
			posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		}
		else
		{
			comeu = false;
		}
	}
	if(comeu == false)
	{
		posicao_selecionada[0] = NULL;
		posicao_selecionada[1] = NULL;
		caracter_selecionado = NULL;
		jogador = 2;
	}
	posicao_movida[0] = NULL;
	posicao_movida[1] = NULL;
	caracter_movido = NULL;
	render4();
}
void erro_movimento4 (void)
{
	printf("\nVOC%c N%cO SELECIONOU UMA CASA V%cLIDA! REFA%cA A SELE%c%cO!", 210, 199, 181, 128, 128, 199);
	printf("\nAGUARDE 5 SEGUNDOS!");
	posicao[posicao_selecionada[0]][posicao_selecionada[1]] = caracter_selecionado;
	caracter_selecionado = NULL;
	Sleep(5000);
	render4();
}
void enemy4 ()
{
	//verificar a localizacao das peças pretas
	while(l < 9)
	{
		if(posicao[l][c] == 'X')
		{
			i++;
			enemys_l[i] = l;
			enemys_c[i] = c;
		}
		c++;
		if(c > 8)
		{
			l++;
			c = 1;
		}
	}
	//random peça
	if(enemy_comeu != true)
	{
		srand(time(NULL));
		randomm = (rand() % i) + 1;
		posicao_enemy[0] = enemys_l[randomm];
		posicao_enemy[1] = enemys_c[randomm];
		randomm = NULL;
	}
	//resetar valores do loop
	l = 1;
	c = 1;
	i = 1;
	while(i < 13)
	{
		enemys_l[i] = NULL;
		enemys_c[i] = NULL;
		i++;
	}
	i = 0;
	//verificar se selecionou uma peça que pode fazer movimentos
	if(posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] == NULL && posicao_enemy[1]-1 > 0 && enemy_comeu == false)
	{
		totalmovs++;
		mov1 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] == NULL && posicao_enemy[1]+1 < 9 && enemy_comeu == false)
	{
		totalmovs++;
		mov2 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]-2 > 0)
	{
		totalmovs++;
		mov3 = totalmovs;
	}
	if(posicao[posicao_enemy[0]+2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]+2 < 9)
	{
		totalmovs++;
		mov4 = totalmovs;
	}
	if(posicao[posicao_enemy[0]-2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]-2 > 0)
	{
		totalmovs++;
		mov5 = totalmovs;
	}
	if(posicao[posicao_enemy[0]-2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]+2 < 9)
	{
		totalmovs++;
		mov6 = totalmovs;
	}
	if(totalmovs > 0)
	{
		enemy_selected4();
	}
	else
	{
		Sleep(1000);
		enemy4();
	}
}
void enemy_selected4 (void)
{
	//random mov
	Sleep(1000);
	selected_mov = (rand() % totalmovs)+1;
	//realizar movimento
	if(mov1 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] = 'X';
	}
	if(mov2 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] = 'X';
	}
	if(mov3 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+2][posicao_enemy[1]-2] = 'X';
		posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] = NULL;
		posicao_enemy[0] = posicao_enemy[0]+2;
		posicao_enemy[1] = posicao_enemy[1]-2;
		verify = true;
	}
	if(mov4 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]+2][posicao_enemy[1]+2] = 'X';
		posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] = NULL;
		posicao_enemy[0] = posicao_enemy[0]+2;
		posicao_enemy[1] = posicao_enemy[1]+2;
		verify = true;
	}
	if(mov5 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]-2][posicao_enemy[1]-2] = 'X';
		posicao[posicao_enemy[0]-1][posicao_enemy[1]-1] = NULL;
		posicao_enemy[0] = posicao_enemy[0]-2;
		posicao_enemy[1] = posicao_enemy[1]-2;
		verify = true;
	}
	if(mov6 == selected_mov)
	{
		posicao[posicao_enemy[0]][posicao_enemy[1]] = NULL;
		posicao[posicao_enemy[0]-2][posicao_enemy[1]+2] = 'X';
		posicao[posicao_enemy[0]-1][posicao_enemy[1]+1] = NULL;
		posicao_enemy[0] = posicao_enemy[0]-2;
		posicao_enemy[1] = posicao_enemy[1]+2;
		verify = true;
	}
	//verificar se pode comer de novo
	if(verify == true)
	{
		if(posicao[posicao_enemy[0]-2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]-2 > 0)
		{
			enemy_comeu = true;
			printf("\nPODE COMER OUTRA PECA!");
		}
		else if(posicao[posicao_enemy[0]-2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]-1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]-2 > 0 && posicao_enemy[1]+2 < 9)
		{	
			enemy_comeu = true;
			printf("\nPODE COMER OUTRA PECA!");
		}
		else if(posicao[posicao_enemy[0]+2][posicao_enemy[1]-2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]-1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]-2 > 0)
		{
			enemy_comeu = true;
			printf("\nPODE COMER OUTRA PECA!");
		}
		else if(posicao[posicao_enemy[0]+2][posicao_enemy[1]+2] == NULL && posicao[posicao_enemy[0]+1][posicao_enemy[1]+1] == 'O' && posicao_enemy[0]+2 < 9 && posicao_enemy[1]+2 < 9)
		{
			enemy_comeu = true;
			printf("\nPODE COMER OUTRA PECA!");
		}
		else
		{
			enemy_comeu = false;
		}
	}
	verify = false;
	//resetar variaveis e trocar de jogador
	if(enemy_comeu != true)
	{
		posicao_enemy[0] = 0;
		posicao_enemy[1] = 0;
		jogador = 1;
	}
	mov1 = 0;
	mov2 = 0;
	mov3 = 0;
	mov4 = 0;
	mov5 = 0;
	mov6 = 0;
	totalmovs = 0;
	Sleep(2000);
	render4();
}
void venceu4 (void)
{
	system("cls");
	printf("\nPARAB%cNS! \nVOC%c VENCEU!", 144, 210);
	Sleep(300);
	system("color 1");
	Sleep(300);
	system("color 2");
	Sleep(300);
	system("color F");
	Sleep(300);
	system("color 4");
	Sleep(300);
	system("color 5");
	Sleep(300);
	system("color 6");
	Sleep(300);
	system("color 9");
	Sleep(300);
	system("color D");
	venceu4();
}
void derrota4 (void)
{
	system("cls");
	system("color 07");
	printf("\nVOC%c PERDEU!", 210);
}
