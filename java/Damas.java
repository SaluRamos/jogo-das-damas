import java.util.Scanner;
import java.util.Random;

public class Damas
{
    //MATRIZ BIDIMENSIONAL QUE ARMAZENA A LOCALIZAÇÃO DAS PEÇAS
    static char[][] table = new char[8][8];
    /*REPRESENTA O JOGADOR DA RODADA ATUAL!
    1 = PRETAS!
    2 = BRANCAS!
    OBS: Começa com 1 por conta da primeira inversão!*/
    static int atual_player = 1;
    /*REPRESENTA O TIPO DE JOGO SELECIONADO!
    vai de 1 a 4.
    esta variavel só pode ser alterada in-game na versão 5.*/
    static int game_type = 4;
    //declarar as variaveis de seleção de coordenada
    public static int selected_linha;
    public static int selected_coluna;
    //variaveis de verificação da repetição de jogada
    public static boolean try_play_again = false;
    public static boolean move_again = false;
    public static boolean computer_try_play_again = false;
    public static int computer_play_again_linha;
    public static int computer_play_again_coluna;
    //outras variaveis do computador
    public static Random rand = new Random();
    public static int selecao_random;
    public static int movimento_random;
    public static boolean teste2 = false;
    public static int[][] posicoes_computador = new int[12][2];
    public static int[][] selecoes_computador = new int[12][2];
    public static int[][] movimentos_selecao = new int[12][8];
    //método 'main' usado apenas para iniciar o software
    public static void main (String args[])
    {
        iniciar();
    }
    /*Este método define valores inicias
    e passa as regras do jogo ao jogador*/
    public static void iniciar ()
    {
        //limpa o terminal/console
        cls();
        //informações do jogo
        //para o modo 5, defina o game_type através de input aqui!
        System.out.printf("VERS%CO 1!\n", 195);
        System.out.printf("%c poss%cvel tomar apenas uma pe%ca advers%cria em cada rodada!\n", 201, 237, 231, 225);
        System.out.printf("Vence quem chegar na linha oposta do tabuleiro!\n");
        System.out.printf("Jogo para duas pessoas!\n\n");
        System.out.printf("VERS%CO 2!\n", 195);
        System.out.printf("%c poss%cvel tomar apenas uma pe%ca advers%cria em cada rodada!\n", 201, 237, 231, 225);
        System.out.printf("Vence quem chegar na linha oposta do tabuleiro!\n");
        System.out.printf("Jogo para uma pessoa contra computador!\n\n");
        System.out.printf("VERS%CO 3!\n", 195);
        System.out.printf("%c poss%cvel tomar mais de uma pe%ca advers%cria em cada rodada!\n", 201, 237, 231, 225);
        System.out.printf("Vence quem chegar na linha oposta do tabuleiro!\n");
        System.out.printf("Jogo para duas pessoas!\n\n");
        System.out.printf("VERS%CO 4!\n", 195);
        System.out.printf("%c poss%cvel tomar mais de uma pe%ca advers%cria em cada rodada!\n", 201, 237, 231, 225);
        System.out.printf("Vence quem chegar na linha oposta do tabuleiro!\n");
        System.out.printf("Jogo para uma pessoa contra computador!\n");
        //Esperar input do usuario para iniciar o jogo
        Scanner waiting = new Scanner(System.in);
        System.out.printf("\nDIGITE QUAL VERS%cO DESEJA JOGAR: ", 195);
        int any1 = waiting.nextInt();
        switch (any1)
        {
            case 1: game_type = 1; break;
            case 2: game_type = 2; break;
            case 3: game_type = 3; break;
            case 4: game_type = 4; break;
            default:
                System.out.print("\nVOCE DIGITOU UM MODO DE JOGO QUE NAO EXISTE!");
                System.exit(0);
            break;
        }
        //define a matriz 'table' como vazia
        for (int i = 0; i <= 7; i++)
        {
            for (int w = 0; w <= 7; w++)
            {
                table[i][w] = 32;
            }
        }
        //define as posições das peças pretas
        table[0][0] = 80;
        table[0][2] = 80;
        table[0][4] = 80;
        table[0][6] = 80;
        table[1][1] = 80;
        table[1][3] = 80;
        table[1][5] = 80;
        table[1][7] = 80;
        table[2][0] = 80;
        table[2][2] = 80;
        table[2][4] = 80;
        table[2][6] = 80;
        //define as posições das peças brancas
        table[5][1] = 66;
        table[5][3] = 66;
        table[5][5] = 66;
        table[5][7] = 66;
        table[6][0] = 66;
        table[6][2] = 66;
        table[6][4] = 66;
        table[6][6] = 66;
        table[7][1] = 66;
        table[7][3] = 66;
        table[7][5] = 66;
        table[7][7] = 66;
        renderizar();
    }
    /*Este método renderiza o tabuleiro
    e verifica se há vitória de algum dos
    jogadores*/
    public static void renderizar ()
    {
        //limpa terminal/console
        cls();
        //renderizar o tabuleiro
        System.out.print("     1 2 3 4 5 6 7 8\n");
        System.out.print("     + + + + + + + +\n");
        for(int x = 0; x <= 7; x++)
        {
            //printa o tabuleiro
            System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
        }
        /*verificar vitória.
        todos os modos de jogo possuem mesmo modo de vitória*/
        //verifica se tem peças nas linhas extremas.
        for (int i = 0; i <= 7; i++)
        {
            //caso BRANCAS vençam
            if (table[0][i] == 66)
            {
                fim_de_jogo(2);
            }
            //caso PRETAS vençam
            if (table[7][i] == 80)
            {
                fim_de_jogo(1);
            }
        }
        //verifica se algum jogador perdeu todas as peças.
        int[] pecas_contador = new int[2];
        for (int i = 0; i <= 7; i++)
        {
            for (int w = 0; w <= 7; w++)
            {
                if(table[i][w] == 80)
                {
                    pecas_contador[0]++;
                }
                else if (table[i][w] == 66)
                {
                    pecas_contador[1]++;
                }
            }
        }
        //se não houver peças pretas
        if (pecas_contador[0] == 32)
        { 
            fim_de_jogo(2);
        //se não houver peças brancas
        }else if (pecas_contador[1] == 32)
        {
            fim_de_jogo(1);
        }
        //inverter vez de jogo
        if (atual_player == 1)
        {
            atual_player = 2;
        }
        else
        {
            atual_player = 1;
        }
        //selecionar peça
        //só há necessidade quando for vez do jogador
        if(atual_player == 2 || game_type == 1 && atual_player == 1 || game_type == 3 && atual_player == 1)
        {
            //mostrar de quem é a vez
            if(atual_player == 2)
            {
                System.out.printf("\nVEZ DAS PE%cAS BRANCAS:\n", 199);
            }
            else
            {
                System.out.printf("\nVEZ DAS PE%cAS PRETAS:\n", 199);
            }
            selecionar_peca();
        }
        //redirecionar jogada
        if (game_type == 1 || game_type == 3)
        {
            //estes dois modos de jogo funcionam jogador contra jogador
            jogador();
        }
        else
        {
            //os outros dois modos de jogo (modo 2 e 4) funcionam computador contra jogador
            if(atual_player == 1)
            {
                computador();
            }
            else
            {
                jogador();
            }
        }
    }
    //Este método é chamado na seleção de peças de um jogador
    public static void selecionar_peca ()
    {
        //esperar input da coordenada linha
        Scanner select_linha_scanner = new Scanner(System.in);
        System.out.printf("\nDIGITE A LINHA DA PE%cA QUE DESEJA SELECIONAR: ", 199);
        selected_linha = select_linha_scanner.nextInt();
        //esperar input da coordenada coluna
        Scanner select_coluna_scanner = new Scanner(System.in);
        System.out.printf("DIGITE A COLUNA DA PE%cA QUE DESEJA SELECIONAR: ", 199);
        selected_coluna = select_coluna_scanner.nextInt();
        //verificar se a peça selecionada pertence ao jogador
        if(atual_player == 1 && table[selected_linha - 1][selected_coluna - 1] == 80 || atual_player == 2 && table[selected_linha - 1][selected_coluna - 1] == 66)
        {
            table[selected_linha - 1][selected_coluna - 1] = 88;
            cls();
            //renderizar o tabuleiro
            System.out.print("     1 2 3 4 5 6 7 8\n");
            System.out.print("     + + + + + + + +\n");
            for(int x = 0; x <= 7; x++)
            {
                //printa o tabuleiro
                System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
            }
        }
        else
        {
            System.out.printf("\nN%cO FOI SELECIONADO UMA COORDENADA V%cLIDA!\nTENTE SELECIONAR NOVAMENTE!\n", 195, 193);
            selecionar_peca();
        }
    }
    //Este método é chamado na movimentação de peças de um jogador
    public static void jogador ()
    {
        //esperar input da coordenada linha
        Scanner move_linha_scanner = new Scanner(System.in);
        System.out.printf("\nDIGITE A LINHA DA POSI%c%cO PARA MOVER A PE%cA: ", 199, 195, 199);
        int moved_linha = move_linha_scanner.nextInt();
        //esperar input da coordenada coluna
        Scanner move_coluna_scanner = new Scanner(System.in);
        System.out.printf("DIGITE A COLUNA DA POSI%c%cO PARA MOVER A PE%cA: ", 199, 195, 199);
        int moved_coluna = move_coluna_scanner.nextInt();
        //definir peça oposta e atual
        char peca_atual;
        char peca_oposta;
        if(atual_player == 1)
        {
            peca_atual = 80;
            peca_oposta = 66;
        }
        else
        {
            peca_atual = 66;
            peca_oposta = 80;
        }
        //verifica se a posição do movimento esta dentro do tabuleiro
        //caso não, volta pra seleção
        if(moved_coluna < 1 || moved_coluna > 8 || moved_linha < 1 || moved_linha > 8)
        {
            if (move_again == false)
            {
                table[selected_linha - 1][selected_coluna - 1] = peca_atual;
                cls();
                System.out.print("     1 2 3 4 5 6 7 8\n");
                System.out.print("     + + + + + + + +\n");
                for(int x = 0; x <= 7; x++)
                {
                    System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
                }
                System.out.printf("\nN%cO FOI SELECIONADO UMA COORDENADA V%cLIDA!\nTENTE SELECIONAR NOVAMENTE!\n", 195, 193);
                selecionar_peca();
                jogador();
            }
            else if (move_again == true)
            {
                cls();
                System.out.print("     1 2 3 4 5 6 7 8\n");
                System.out.print("     + + + + + + + +\n");
                for(int x = 0; x <= 7; x++)
                {
                    System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
                }
                System.out.printf("\nN%cO FOI SELECIONADO UMA COORDENADA V%cLIDA!\nTENTE MOVER NOVAMENTE!\n", 195, 193);
                jogador();
            }
        }
        //8 possiveis movimentos: 4 são referentes a andar e 4 referentes a comer outras peças
        if (table[moved_linha - 1][moved_coluna - 1] == 32)
        {
            //para casos de mover
            //-1 -1
            //-1 +1
            //+1 -1
            //+1 +1
            if (moved_linha - 1 == selected_linha - 2 && moved_coluna - 1 == selected_coluna - 2 ||
            moved_linha - 1 == selected_linha - 2 && moved_coluna - 1 == selected_coluna ||
            moved_linha - 1 == selected_linha && moved_coluna - 1 == selected_coluna - 2 ||
            moved_linha - 1 == selected_linha && moved_coluna - 1 == selected_coluna)
            {
                if (move_again == false)
                {
                    //nova posição da peça movida
                    table[moved_linha - 1][moved_coluna - 1] = peca_atual;
                    //posição selecionada resetada
                    table[selected_linha - 1][selected_coluna - 1] = 32;
                }
                
            }
            //para casos de comer
            //-2 -2
            else if (moved_linha - 1 == selected_linha - 3 && moved_coluna - 1 == selected_coluna - 3)
            {
                if (table[selected_linha - 2][selected_coluna - 2] == peca_oposta)
                {
                    //nova posição da peça movida
                    table[moved_linha - 1][moved_coluna - 1] = peca_atual;
                    //posição da peça inimiga
                    table[selected_linha - 2][selected_coluna - 2] = 32;
                    //posição selecionada resetada
                    table[selected_linha - 1][selected_coluna - 1] = 32;
                    try_play_again = true;
                }
            }
            //-2 +2
            else if (moved_linha - 1 == selected_linha - 3 && moved_coluna - 1 == selected_coluna + 1)
            {
                if (table[selected_linha - 2][selected_coluna] == peca_oposta)
                {
                    //nova posição da peça movida
                    table[moved_linha - 1][moved_coluna - 1] = peca_atual;
                    //posição da peça inimiga
                    table[selected_linha - 2][selected_coluna] = 32;
                    //posição selecionada resetada
                    table[selected_linha - 1][selected_coluna - 1] = 32;
                    try_play_again = true;
                }
            }
            //+2 -2
            else if (moved_linha - 1 == selected_linha + 1 && moved_coluna - 1 == selected_coluna - 3)
            {
                if (table[selected_linha][selected_coluna - 2] == peca_oposta)
                {
                    //nova posição da peça movida
                    table[moved_linha - 1][moved_coluna - 1] = peca_atual;
                    //posição da peça inimiga
                    table[selected_linha][selected_coluna - 2] = 32;
                    //posição selecionada resetada
                    table[selected_linha - 1][selected_coluna - 1] = 32;
                    try_play_again = true;
                }
            }
            //+2 +2
            else if (moved_linha - 1 == selected_linha + 1 && moved_coluna - 1 == selected_coluna + 1)
            {
                if (table[selected_linha][selected_coluna] == peca_oposta)
                {
                    //nova posição da peça movida
                    table[moved_linha - 1][moved_coluna - 1] = peca_atual;
                    //posição da peça inimiga
                    table[selected_linha][selected_coluna] = 32;
                    //posição selecionada resetada
                    table[selected_linha - 1][selected_coluna - 1] = 32;
                    try_play_again = true;
                }
            }
        }
        //verifica se a peça selecionada foi alterada
        if(table[selected_linha - 1][selected_coluna - 1] == 88 && move_again == false)
        {
            table[selected_linha - 1][selected_coluna - 1] = peca_atual;
            cls();
            System.out.print("     1 2 3 4 5 6 7 8\n");
            System.out.print("     + + + + + + + +\n");
            for(int x = 0; x <= 7; x++)
            {
                System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
            }
            System.out.printf("\nN%cO FOI SELECIONADO UMA COORDENADA V%cLIDA!\nTENTE SELECIONAR NOVAMENTE!\n", 195, 193);
            selecionar_peca();
            jogador();
        }
        else if (table[selected_linha - 1][selected_coluna - 1] == 88 && move_again == true)
        {  
            cls();
            System.out.print("     1 2 3 4 5 6 7 8\n");
            System.out.print("     + + + + + + + +\n");
            for(int x = 0; x <= 7; x++)
            {
                System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
            }
            System.out.printf("\nN%cO FOI SELECIONADO UMA COORDENADA V%cLIDA!\nTENTE MOVER NOVAMENTE!\n", 195, 193);
            jogador();
        }
        //verifica se comeu uma peça e esta no game_type correto
        boolean teste1 = false;
        if (game_type == 3 && try_play_again == true || game_type == 4 && try_play_again == true)
        {
            try_play_again = false;
            //verifica se pode comer outra peça
            if (moved_coluna - 3 >= 0)
            {
                if (table[moved_linha - 2][moved_coluna - 2] == peca_oposta && table[moved_linha - 3][moved_coluna - 3] == 32)
                {
                    teste1 = true;
                }
            }
            if (moved_linha - 3 >= 0 && moved_linha + 1 <= 7)
            {
                if (table[moved_linha - 2][moved_coluna] == peca_oposta && table[moved_linha - 3][moved_coluna + 1] == 32 ||
                table[moved_linha][moved_coluna - 2] == peca_oposta && table[moved_linha + 1][moved_coluna - 3] == 32)
                {
                    teste1 = true;
                }
            }
            if (moved_linha + 1 <= 7)
            {
                if (table[moved_linha][moved_coluna] == peca_oposta && table[moved_linha + 1][moved_coluna + 1] == 32)
                {
                    teste1 = true;
                }
            }
            if (teste1 == true)
            {
                //ativa o modo captura
                move_again = true;
                //ou seja, só permite que vc realize a proxima jogada capturando outra peça
                //seleciona a peça
                table[moved_linha - 1][moved_coluna - 1] = 88;
                selected_linha = moved_linha;
                selected_coluna = moved_coluna;
                //printa o tabuleiro
                cls();
                System.out.print("     1 2 3 4 5 6 7 8\n");
                System.out.print("     + + + + + + + +\n");
                for(int x = 0; x <= 7; x++)
                {
                    //printa o tabuleiro
                    System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
                }
                //retorna a seleção
                jogador();
            }
            else
            {
                move_again = false;
            }
        }
        //redirecionar
        renderizar();
    }
    //Este método é chamado na vez de um computador
    public static void computador ()
    {
        //limpa a matriz selecoes_computador, posicoes_computador e movimentos_selecao
        selecoes_computador = new int[12][2];
        posicoes_computador = new int[12][2];
        movimentos_selecao = new int[12][8];
        //o contador deve se manter aqui para resetar sempre que a função computador for chamada
        int contador1 = 0;
        //lista as peças
        for (int linha = 0; linha <= 7; linha++)
        {
            for (int coluna = 0; coluna <= 7; coluna++)
            {
                if (table[linha][coluna] == 80)
                {
                    posicoes_computador[contador1][0] = linha;
                    posicoes_computador[contador1][1] = coluna;
                    contador1++;
                }
            }
        }
        //contator2 representa o total de itens(peças)/linhas da matriz selecoes_computador
        int contador2 = 0;
        //contar faz uma verificao se a peça testada deve ser acrescentada na matriz selecoes_computador
        boolean contar = false;
        //faz a verificação
        for(int i = 0; i <= contador1 - 1; i++)
        {
            //verifica se tem inimigos na vizinhança e se é possível come-los
            //-2 -2
            if (posicoes_computador[i][0] - 2 >= 0 && posicoes_computador[i][1] - 2 >= 0)
            {
                if(table[posicoes_computador[i][0] - 1][posicoes_computador[i][1] - 1] == 66 && 
                table[posicoes_computador[i][0] - 2][posicoes_computador[i][1] - 2] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][0] = 80;
                    contar = true;
                }
            }
            //-2 +2
            if (posicoes_computador[i][0] - 2 >= 0 && posicoes_computador[i][1] + 2 <= 7)
            {
                if(table[posicoes_computador[i][0] - 1][posicoes_computador[i][1] + 1] == 66 && 
                table[posicoes_computador[i][0] - 2][posicoes_computador[i][1] + 2] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][1] = 80;
                    contar = true;
                }
            }
            //+2 -2
            if (posicoes_computador[i][0] + 2 <= 7 && posicoes_computador[i][1] - 2 >= 0)
            {
                if(table[posicoes_computador[i][0] + 1][posicoes_computador[i][1] - 1] == 66 && 
                table[posicoes_computador[i][0] + 2][posicoes_computador[i][1] - 2] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][2] = 80;
                    contar = true;
                }
            }
            //+2 +2
            if (posicoes_computador[i][0] + 2 <= 7 && posicoes_computador[i][1] + 2 <= 7)
            {
                if(table[posicoes_computador[i][0] + 1][posicoes_computador[i][1] + 1] == 66 && 
                table[posicoes_computador[i][0] + 2][posicoes_computador[i][1] + 2] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][3] = 80;
                    contar = true;
                }
            }
            //verifica se tem peças nas vizinhanças para mover
            //-1 -1
            if (posicoes_computador[i][0] - 1 >= 0 && posicoes_computador[i][1] - 1 >= 0)
            {
                if(table[posicoes_computador[i][0] - 1][posicoes_computador[i][1] - 1] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][4] = 80;
                    contar = true;
                }
            }
            //-1 +1
            if (posicoes_computador[i][0] - 1 >= 0 && posicoes_computador[i][1] + 1 <= 7)
            {
                if(table[posicoes_computador[i][0] - 1][posicoes_computador[i][1] + 1] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][5] = 80;
                    contar = true;
                }
            }
            //+1 -1
            if (posicoes_computador[i][0] + 1 <= 7 && posicoes_computador[i][1] - 1 >= 0)
            {
                if(table[posicoes_computador[i][0] + 1][posicoes_computador[i][1] - 1] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][6] = 80;
                    contar = true;
                }
            }
            //+1 +1
            if (posicoes_computador[i][0] + 1 <= 7 && posicoes_computador[i][1] + 1 <= 7)
            {
                if(table[posicoes_computador[i][0] + 1][posicoes_computador[i][1] + 1] == 32)
                {
                    //armazena este movimento
                    movimentos_selecao[contador2][7] = 80;
                    contar = true;
                }
            }
            //acrescenta a peça na matriz selecoes_computador se ela contem movimentos possiveis
            if(contar == true)
            {
                //armazena x e y
                selecoes_computador[contador2][0] = posicoes_computador[i][0];
                selecoes_computador[contador2][1] = posicoes_computador[i][1];
                //reseta e adiciona
                contar = false;
                contador2++;
            }
        }
        /*essa variavel é absolutamente necessaria 
        para os dois while's a seguir nao entrar em 
        um loop infinito em uma tentativa de 
        repetição da jogada*/
        int frio_e_calculista = 0;
        //randomiza a escolha de uma das peças de seleçoes_computador
        //randomiza um dos movimentos da peça de movimentos_selecao
        if (computer_try_play_again == false)
        {
            selecao_random = rand.nextInt(contador2);
            movimento_random = rand.nextInt(8);
            while (movimentos_selecao[selecao_random][movimento_random] != 80)
            {
                movimento_random = rand.nextInt(8);
                frio_e_calculista++;
            }
        }
        //caso esteja repetindo jogada, ignora o selecao_random (pois deve movimentar a mesma peça)
        //escolhe aleatoriamente um dos movimentos para comer outra peça
        //ou seja: movimento tipo 1, 2, 3 ou 4 apenas
        if (computer_try_play_again == true)
        {
            //loop para encontrar dentro da selecoes_computador a linha em que a peça movida anteriormente esta
            for (int i = 0; i <= contador2 - 1; i++)
            {
                
                //quando as coordenadas bateterem
                if(selecoes_computador[i][0] == computer_play_again_linha && selecoes_computador[i][1] == computer_play_again_coluna)
                {
                    selecao_random = i;
                    //randomiza um valor válido para mover a peça anterior e comer outra peça
                    movimento_random = rand.nextInt(4);
                    while (movimentos_selecao[i][movimento_random] != 80)
                    {
                        movimento_random = rand.nextInt(4);
                        frio_e_calculista++;
                        if (frio_e_calculista >= 100)
                        {
                            movimento_random = -1;
                            break;
                        }
                    }
                }
            }
        }
        //printa as matrizes obtidas
        //mostra as coordenadas das peças que podem realizar movimentos, afim do computador no futuro
        //escolher aleatoriamente a peça para movimentar rapidamente
        System.out.printf("\nPOSSIVEIS MOVIMENTOS DO COMPUTADOR!\n\nTIPO:              1 2 3 4 5 6 7 8\n");
        for (int i = 0; i <= contador2 - 1; i++)
        {
            System.out.printf("linha %d coluna %d = ", selecoes_computador[i][0] + 1, selecoes_computador[i][1] + 1);
            for (int w = 0; w <= 7; w++)
            {
                System.out.printf("%d ", movimentos_selecao[i][w]);
            }
            System.out.print("\n");
        }
        if (movimento_random != -1)
        {
            System.out.printf("\nVAI REALIZAR\nlinha %d coluna %d = movimento tipo %d\n", selecoes_computador[selecao_random][0] + 1, selecoes_computador[selecao_random][1] + 1, movimento_random + 1);
        }
        else
        {
            System.out.printf("\nVAI REALIZAR\nlinha %d coluna %d = nao ha mais movimentos a se fazer, ja acabou a jogada do computador\n", selecoes_computador[selecao_random][0] + 1, selecoes_computador[selecao_random][1] + 1);
        }
        //esta variavel é usada para verificar se pode comer outra peça apenas se comeu alguma
        boolean comeu = false;
        //após ter decidido o movimento, realiza o mesmo
        switch (movimento_random) {
            case 0:
                //-2 -2
                table[selecoes_computador[selecao_random][0] - 2][selecoes_computador[selecao_random][1] - 2] = 88;
                table[selecoes_computador[selecao_random][0] - 1][selecoes_computador[selecao_random][1] - 1] = 32;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
                comeu = true;
            break;
            case 1:
                //-2 +2
                table[selecoes_computador[selecao_random][0] - 2][selecoes_computador[selecao_random][1] + 2] = 88;
                table[selecoes_computador[selecao_random][0] - 1][selecoes_computador[selecao_random][1] + 1] = 32;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
                comeu = true;
            break;
            case 2:
                //+2 -2
                table[selecoes_computador[selecao_random][0] + 2][selecoes_computador[selecao_random][1] - 2] = 88;
                table[selecoes_computador[selecao_random][0] + 1][selecoes_computador[selecao_random][1] - 1] = 32;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
                comeu = true;
            break;
            case 3:
                //+2 +2
                table[selecoes_computador[selecao_random][0] + 2][selecoes_computador[selecao_random][1] + 2] = 88;
                table[selecoes_computador[selecao_random][0] + 1][selecoes_computador[selecao_random][1] + 1] = 32;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
                comeu = true;
            break;
            case 4:
                //-1 -1
                table[selecoes_computador[selecao_random][0] - 1][selecoes_computador[selecao_random][1] - 1] = 80;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
            break;
            case 5:
                //-1 +1
                table[selecoes_computador[selecao_random][0] - 1][selecoes_computador[selecao_random][1] + 1] = 80;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
            break;
            case 6:
                //+1 -1
                table[selecoes_computador[selecao_random][0] + 1][selecoes_computador[selecao_random][1] - 1] = 80;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
            break;
            case 7:
                //+1 +1
                table[selecoes_computador[selecao_random][0] + 1][selecoes_computador[selecao_random][1] + 1] = 80;
                table[selecoes_computador[selecao_random][0]][selecoes_computador[selecao_random][1]] = 32;
            break;
            default:
            break;
        }
        //busca no tabuleiro pelo local da peça que FOI MOVIDA E COMEU UMA PEÇA INIMIGA
        for (int i = 0; i <= 7; i++)
        {
            for (int w = 0; w <= 7; w++)
            {
                //encontra o local da peça 88 ("X")
                if (table[i][w] == 88)
                {
                    //armazena as coordenadas dessa peça movida
                    computer_play_again_linha = i;
                    computer_play_again_coluna = w;
                    //aplica o verdadeiro valor a essa peça
                    table[i][w] = 80;   
                }
            }
        }
        //teste2 é usado para apontar que é possivel o computador jogar novamente ou não
        //Obs: Jogador novamente e obrigatoriamente comer uma peça inimiga!
        //verifica se a partir do novo local da peça é possivel comer peça inimiga NOVAMENTE
        teste2 = false;
        if (computer_play_again_linha - 2 >= 0)
        {
            if (table[computer_play_again_linha - 1][computer_play_again_coluna - 1] == 66 && table[computer_play_again_linha - 2][computer_play_again_coluna - 2] == 32)
            {
                teste2 = true;
            }
        }
        if (computer_play_again_linha - 2 >= 0 && computer_play_again_coluna + 2 <= 7)
        {
            if (table[computer_play_again_linha - 1][computer_play_again_coluna + 1] == 66 && table[computer_play_again_linha - 2][computer_play_again_coluna + 2] == 32 || 
            table[computer_play_again_linha + 1][computer_play_again_coluna - 1] == 66 && table[computer_play_again_linha + 2][computer_play_again_coluna - 2] == 32)
            {
                teste2 = true;
            }
        }
        if (computer_play_again_linha + 2 <= 7)
        {
            if (table[computer_play_again_linha + 1][computer_play_again_coluna + 1] == 66 && table[computer_play_again_linha + 2][computer_play_again_coluna + 2] == 32)
            {
                teste2 = true;
            }
        }
        //verifica se o computador vai jogar novamente
        if (teste2 = true && comeu == true && game_type == 4)
        {
            comeu = false;
            //verificou que a próxima rodada é possivel comer outra peça a partir da mesma seleção de agora
            computer_try_play_again = true;
            //renderiza o tabuleiro o tabuleiro
            cls();
            System.out.print("     1 2 3 4 5 6 7 8\n");
            System.out.print("     + + + + + + + +\n");
            for(int x = 0; x <= 7; x++)
            {
                //printa o tabuleiro
                System.out.printf("%d + |%c|%c|%c|%c|%c|%c|%c|%c|\n", (x+1), table[x][0], table[x][1], table[x][2], table[x][3], table[x][4], table[x][5], table[x][6], table[x][7]);
            }
            //chama a função computador novamente
            computador();
        }
        else
        {
            //reseta valores
            comeu = false;
            computer_try_play_again = false;
        }
        //redirecionar
        renderizar();
    }
    //Este método é chamando quando um jogador ganha o jogo
    public static void fim_de_jogo (int winner)
    {
        cls();
        if(winner == 1)
        {
            System.out.printf("Parab%cns ao jogador PRETO por vencer a partida!", 233);
        }
        else
        {
            System.out.printf("Parab%cns ao jogador BRANCO por vencer a partida!", 233);
        }
        System.exit(0);
    }
    //Este método é usado apenas para limpar o terminal/console
    public static void cls ()
    {
        for (int i = 0; i < 50; ++i)
        {
            System.out.println();
        }
    }
}