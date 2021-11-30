#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

//void's (por ordem de execução)
void render (void);
void selecao (void);
void movimento (void);
void erro_movimento (void);
void venceu (void);

//outras
char posicao[9][9];
int posicao_selecionada[2];
int posicao_movida[2];
char caracter_selecionado;
char caracter_movido;
int jogador = 1;
int vencedor;

//menu
int main ()
{
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
	printf("\n\nPRESSIONE 'ENTER' PARA COME%cAR!", 128);
	getchar();
	//definir local das peças iniciais
	posicao[1][2] = 'X', posicao[1][4] = 'X', posicao[1][6] = 'X', posicao[1][8] = 'X';
	posicao[2][1] = 'X', posicao[2][3] = 'X', posicao[2][5] = 'X', posicao[2][7] = 'X';
	posicao[3][2] = 'X', posicao[3][4] = 'X', posicao[3][6] = 'X', posicao[3][8] = 'X';
	posicao[6][1] = 'O', posicao[6][3] = 'O', posicao[6][5] = 'O', posicao[6][7] = 'O';
	posicao[7][2] = 'O', posicao[7][4] = 'O', posicao[7][6] = 'O', posicao[7][8] = 'O';
	posicao[8][1] = 'O', posicao[8][3] = 'O', posicao[8][5] = 'O', posicao[8][7] = 'O';
	render();
}
void render (void)
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
		venceu();
	}
	if(posicao[8][1] == 'X' || posicao[8][2] == 'X' || posicao[8][3] == 'X' || posicao[8][4] == 'X' || posicao[8][5] == 'X' || posicao[8][6] == 'X' || posicao[8][7] == 'X' || posicao[8][8] == 'X')
	{
		vencedor = 2;
		printf("\n\nO JOGO TERMINOU!");
		Sleep(5000);
		venceu();
	}
	//verificar qual o proximo passo
	if(caracter_selecionado != NULL)
	{
		movimento();
	}
	else
	{
		selecao();
	}
}
void selecao (void)
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
		render();
	}
	else if(jogador == 2 && caracter_selecionado == 'X')
	{
		posicao[posicao_selecionada[0]][posicao_selecionada[1]] = 'S';
		render();
	}
	//selecionou errado
	else
	{
		caracter_selecionado = NULL;
		printf("\nVOC%c N%cO SELECIONOU UMA PE%cA SUA!", 210, 199, 128);
		printf("\nAGUARDE 5 SEGUNDOS!");
		Sleep(5000);
		render();
	}
}
void movimento (void)
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
		erro_movimento();
	}
	printf("DIGITE A COORDENADA EM 'X' (COLUNA) PARA MOVER SUA PE%cA: ", 128);
	scanf("%d", &posicao_movida[1]);
	if(posicao_movida[1] <= 0 || posicao_movida[1] >= 9)
	{
		erro_movimento();
	}
	//armazenar caracter movido e verificar se é nulo
	caracter_movido = posicao[posicao_movida[0]][posicao_movida[1]];
	if(caracter_movido != NULL)
	{
		erro_movimento();
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
		erro_movimento();
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
		erro_movimento();
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
	render();
}
void erro_movimento (void)
{
	printf("\nVOC%c N%cO SELECIONOU UMA CASA V%cLIDA! REFA%cA A SELE%c%cO!", 210, 199, 181, 128, 128, 199);
	printf("\nAGUARDE 5 SEGUNDOS!");
	posicao[posicao_selecionada[0]][posicao_selecionada[1]] = caracter_selecionado;
	caracter_selecionado = NULL;
	Sleep(5000);
	render();
}
void venceu (void)
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
	venceu();
}
