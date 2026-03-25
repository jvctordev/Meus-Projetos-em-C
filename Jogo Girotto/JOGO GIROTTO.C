#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //header file, significa console input e serve pra interagir com o terminal do DOS/Windows
#include <windows.h> //header file, fornecido pela WinAPI, para programar diretamente no sistema operacional do Windows
#include <time.h>
#include <string.h>
#include <ctype.h>

#define KEY_UP       72
#define KEY_DOWN     80
#define KEY_ENTER    13
#define ARROW_PREFIX 224
//definições de constantes que representam os codigos de teclas do teclado, quando voce pressiona uma tecla, o sistema envia um codigo numerico 

// ===== Definição dos jogos =====
void limparBuffer();
void jogoPerguntaseRespostas();
void jogoCobraNaCaixa();
void jogoGousmasWar();
void LimparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
struct Gousma {
    int furia;
    int ativa;  // 1 = ativa, 0 = destruída
};
// MENU DE SETAS 
int menu(const char *titulo, const char *itens[], int total) {
    int selecionado = 0;
    int tecla;

    while (1) {
//rodando infinitamente ate pressionar enter
        system("cls");
//sistema de limpar a tela
        printf("---------------------------------------------------\n");
        printf("            %s\n", titulo);
        printf("---------------------------------------------------\n\n");

        for (int i = 0; i < total; i++) {
            if (i == selecionado)
                printf("  >> %s <<\n", itens[i]);
            else
                printf("     %s\n", itens[i]); //percorre os itens e deixa selecionado
        } 

        printf("\n  [Setas para navegar, ENTER para confirmar] \n");

        tecla = getch();
        if (tecla == ARROW_PREFIX) { //se for a tecla especial, le o segundo codigo
            tecla = getch();
            if (tecla == KEY_UP   && selecionado > 0)         selecionado--;
            if (tecla == KEY_DOWN && selecionado < total - 1) selecionado++;  //le a tecla pressionada, caso seja pra cima ou pra baixo
        } else if (tecla == KEY_ENTER) {
            return selecionado + 1;
        } //se pressionar enter, confirma a seleção e retorna ao item escolhido
    }
}   // <-- fecha o menu aqui


int main() {

    srand(time(NULL));

    const char *itens[] = { //definição dos itens do menu(const char)
        "||    Perguntas e Respostas||",
        "||    Cobra na Caixa!      ||",
        "||    Gousmas War          ||",
        "||    Sair                 ||"
    };

    int pos; //declaração da variavel pos do tipo n inteiro
    do {
        pos = menu("[JOGOS DO GIRROTO] 3 em 1", itens, 4); //a função menu() retorna um caso(ex. 1,2,3 etc)

        switch (pos) {
            case 1: system("cls"); jogoPerguntaseRespostas(); break;
            case 2: system("cls"); jogoCobraNaCaixa();        break;
            case 3: system("cls"); jogoGousmasWar();          break;  
            case 4: //se for 4, sai do jogo
                system("cls");
                printf("Ate logo, Girroto!\n");
                system("pause");
                break;
        } 
    } while (pos != 4); //não é possivel ser diferente de 4 itens

    return 0;
}


void limparBuffer() { //limpar o buffer de entrada
    int c; //usa int, não char pois o E0F é definido como -1 
    while ((c = getchar()) != '\n' && c != EOF); //getchar le o caractere buffer e atribui a c, e o E0F para quando a leitura acabar
}


void jogoPerguntaseRespostas() {  
    int resposta, correta, opcao; //variaveis nescessarias para encontrar as vizualizações do jogo

    char perguntas[5][200] = {  //todas as perguntas
        "De quem e a frase 'Penso, logo existo'?",
        "Atualmente, quantos elementos quimicos a tabela periodica possui?",
        "O que a palavra 'Legend' significa em portugues?",
        "Qual o numero minimo de jogadores em cada time de uma partida de futebol?",
        "Em que periodo da pre-historia o fogo foi descoberto?"};
    char alternativas[5][4][100] = {   //todas as alternativas
        {"1) Platao", "2) Galileu Galilei", "3) Descartes", "4) Socrates"},
        {"1) 113", "2) 109", "3) 108", "4) 118"},
        {"1) Legenda", "2) Conto", "3) Historia", "4) Lenda"},
        {"1) 8", "2) 10", "3) 9", "4) 7"},
        {"1) Neolitico", "2) Paleolitico", "3) Idade dos Metais", "4) Periodo da Pedra Polida"} }; 
    int corretas[5] = {3, 4, 4, 4, 2}; //definição das respostas como int

    do { //definição para o loop do jogo(do)
        LimparTela(); //limpa o terminal
        int acertos = 0;  //definição do começo do jogo, acertos zerados

        for (int i = 0; i < 5; i++) {  //loop das perguntas, entre a primeira e a ultima
            printf("\nPergunta %d: %s\n", i+1, perguntas[i]); //percorre as 5 perguntas
            for (int j = 0; j < 4; j++) //loop das alternativas, 1,2,3 ou 4
                printf("%s\n", alternativas[i][j]); //percorre as alternativas

            printf("Sua resposta (1-4): ");
            scanf("%d", &resposta);
            limparBuffer(); //escolha da alternativa

            while (resposta < 1 || resposta > 4) {
                printf("Opcao invalida, insira um numero de 1-4: ");
                scanf("%d", &resposta);
                limparBuffer();
            } //caso o usuario coloque algo que não esta entre as alternativas

            correta = corretas[i];

            if (resposta == correta) { //confirmando qual resposta é a certa
                printf("Certa resposta!\n");
                acertos++; //pontuação
            } else { //confirmando caso a resposta seja errada
                printf("Resposta errada! A correta era: %s\n",
                    alternativas[i][correta - 1]); 
            }
                printf("\nPressione ENTER para continuar...");
                limparBuffer();
        }

        LimparTela();
        printf("=============================\n");
        printf("       FIM DE JOGO!\n");
        printf("=============================\n");
        printf("Voce acertou %d de 5 perguntas!\n\n", acertos);
        printf("1 - Jogar novamente\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();
        //tela de fim de jogo
    } while (opcao == 1); 
        printf("\nRetornando ao menu principal...\n"); // único do-while, fechando certo

    LimparTela();
    
}

void jogoCobraNaCaixa(){

    char nomes[7][20] = {
        "Ramses", "Nefertiti", "Anubis", "Cleopatra",
        "Tutankhamon", "Horus", "Isis"
    }; //nomes dos players

    char jogadores[2][20]; //armazenamento dos jogadores escolhidos


    for (int p = 0; p < 2; p++){ //loop que executa 2
        int escolha; //variavel de resposta do jogador
            LimparTela();

        printf("===JOGADOR %d ESCOLHA SEU EXPLORADOR===\n\n", p + 1); //titulo
        for (int i = 0; i < 7; i++){ //loop para a escolha do nome do player
            printf("%d - %s\n", i + 1, nomes[i]); 
        }

        printf("\nEscolha (1-7): ");
        scanf("%d", &escolha); //armazena a escolha do jogador

        while (escolha < 1 || escolha > 7){
            printf("Opcao Invalida! Digite entre 1 e 7: "); //validação 
            scanf("%d", &escolha);
            limparBuffer();
        }


        strcpy(jogadores[p], nomes[escolha - 1]);
    }

    int opcao;
    
    do {
        srand(time(NULL));//comando pra gerar numeros aleatorios

        int caixas[5] = {0, 0, 0, 0, 0}; //define a quantidade de caixas
        int abertas[5] = {0, 0, 0, 0, 0};//define as caixas abertas

        int botao = rand() % 5; //comando para o botao ser colocado em uma caixa aleatoria sempre.

        int cobra;
        do {
            cobra = rand() % 5; //comando para a cobra ser colocada em uma caixa aleatoria sempre, e o do-while garante que a cobra e o botao não fiquem na mesma caixa

    }  while (cobra == botao);

    caixas[botao] = 1; //comando para definir o botao como 1, e a cobra como 2, para diferenciar as caixas
    caixas[cobra] = 2; //comando para definir a cobra como 2, e o botao como 1, para diferenciar as caixas

    int turno = rand() % 2; //comando para escolher aleatoriamente quem começa, 0 ou 1, e o turno é definido por essa variavel

    LimparTela();//inicio do jogo COBRA NA CAIXA, com a definição do botao, da cobra, e do jogador que começa
    printf("A Tumba esta pronta...\n");
    printf("O Primeiro a jogar sera: %s!\n\n", jogadores[turno]);
    printf("Pressione ENTER para comecar....");
    getchar(); getchar();

    int jogoAtivo = 1; //mostra que o jogo esta ativo, e o loop do jogo roda enquanto isso for verdade


    while (jogoAtivo){ //loop do jogo
        LimparTela();
        printf("=============================\n");
            printf("      COBRA NA CAIXA\n");
            printf("=============================\n\n");
            printf("Vez de: %s\n\n", jogadores[turno]);


        printf("CAIXAS:\n");
        for (int i = 0; i < 5; i++){ //loop que mostra as 5 caixas, mostra as abertas e fechadas
            if (abertas[i]){
                printf(" [%d - ABERTA]\n", i + 1);
            } else {
                printf(" [%d - FECHADA]\n", i + 1);
            }
        }

        int escolha;
        printf("\nEscolha uma caixa (1-5): "); //usuario escolhe a sua caixa
        scanf("%d", &escolha);

        while (escolha < 1 || escolha > 5){
            printf("Opcao Invalida! Digite entre 1 e 5: "); //caso o usuario digite um numero fora da quantidade de caixas
            scanf("%d", &escolha);
        }

        while (abertas[escolha - 1] == 1){
            printf("Essa caixa ja foi aberta! Escolha outra: "); //se a caixa ja estiver aberta aparece essa mensagem
                scanf("%d", &escolha);
                while (escolha < 1 || escolha > 5) {
                    printf("Opcao invalida! Digite entre 1 e 5: "); //caso o usuario digite novamente um numero fora do intervalo
                    scanf("%d", &escolha);
        }

    }

    abertas[escolha - 1] = 1; //comando para mostrar que uma caixa foi aberta, e o loop de escolha de caixa roda enquanto a caixa escolhida for diferente de 1, ou seja, diferente do botao, e diferente de 2, ou seja, da cobra

    if (caixas[escolha - 1] == 1) {
                LimparTela();
                printf("=============================\n");
                printf("  ** BOTAO ENCONTRADO! **\n");
                printf("=============================\n");
                printf("%s abriu a porta e escapou da tumba!\n", jogadores[turno]);
                printf("%s VENCEU!\n", jogadores[turno]);
                jogoAtivo = 0; //jogo encerrado por vitoria do jogador que encontrou o botao

            } else if (caixas[escolha - 1] == 2) {
                LimparTela();
                printf("=============================\n");
                printf("      ** COBRA!! **\n");
                printf("=============================\n");
                printf("%s encontrou a cobra...\n", jogadores[turno]);
                printf("%s perdeu! %s VENCEU!\n", jogadores[turno], jogadores[1 - turno]);
                jogoAtivo = 0; //jogo encerrado por vitoria do jogador que não encontrou a cobra

            } else {
                printf("\nCaixa vazia! Vez de %s.\n", jogadores[1 - turno]);
                printf("Pressione ENTER para continuar...");
                getchar(); getchar();
                turno = 1 - turno;  // passa a vez
            }
        }
    printf("\nO que deseja fazer?\n");
        printf("1 - Jogar novamente\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        getchar();
        scanf("%d", &opcao); //menu final do jogo, para jogar novamente ou voltar ao menu principal

        while (opcao != 0 && opcao != 1) { //loop de validação do menu final, para garantir que o usuario escolha uma opção valida
            printf("Opcao invalida! Digite 1 para jogar novamente ou 0 para sair: ");
            scanf("%d", &opcao);
        }

    } while (opcao == 1); //loop para jogar novamente, caso o usuario escolha 1, e caso escolha 0, o jogo retorna ao menu principal

    LimparTela();
}

void jogoGousmasWar() {

    // gousmas[jogador][gousma] — cada jogador tem 2 Gousmas
    struct Gousma gousmas[2][2];

    int opcao;

    do {
        // Inicializa todas as Gousmas com furia=1 e ativas
        for (int p = 0; p < 2; p++) {
            for (int g = 0; g < 2; g++) {
                gousmas[p][g].furia = 1;
                gousmas[p][g].ativa = 1;
            }
        }

        int turno = 0;     // jogador 0 começa
        int jogoAtivo = 1; // flag para controlar o loop do jogo, enquanto for 1, o jogo continua, e quando for 0, o jogo termina

        while (jogoAtivo) {
            LimparTela();

            // Exibe o estado atual do jogo
            printf("=============================\n");
            printf("        GOUSMAS WAR\n");
            printf("=============================\n\n");

            for (int p = 0; p < 2; p++) { //loop para mostrar o estado das gousmas de cada jogador
                printf("JOGADOR %d:\n", p + 1);
                for (int g = 0; g < 2; g++) { //loop para mostrar o estado de cada gousma, se esta ativa ou destruida, e sua furia
                    if (gousmas[p][g].ativa)
                        printf("  Gousma %d: Furia = %d\n", g + 1, gousmas[p][g].furia);
                    else
                        printf("  Gousma %d: DESTRUIDA\n", g + 1);
                }
                printf("\n");
            }

            printf("--- Vez do JOGADOR %d ---\n\n", turno + 1);
            printf("1 - Atacar\n");
            printf("2 - Dividir\n");
            printf("Escolha: ");

            int acao;
            scanf("%d", &acao); //escolha da ação, atacar ou dividir

            while (acao < 1 || acao > 2) { //validação da escolha da ação, para garantir que o usuario escolha uma opção valida
                printf("Opcao invalida! Digite 1 ou 2: ");
                scanf("%d", &acao);
            }

            // ──────────────────────────────────
            // AÇÃO 1 — ATACAR
            // ──────────────────────────────────
            if (acao == 1) { //se a ação escolhida for atacar, o jogador escolhe uma gousma atacante e uma gousma alvo, e a furia do alvo aumenta pela furia do atacante, e caso a furia do alvo ultrapasse 5, ela é destruida
                int adversario = 1 - turno;

                // Escolhe Gousma atacante (deve estar ativa)
                printf("\nSua Gousma para atacar:\n");
                for (int g = 0; g < 2; g++) { // loop para mostrar as gousmas ativas do jogador, para escolher a gousma atacante
                    if (gousmas[turno][g].ativa) //se a gousma estiver ativa, mostra a furia dela, caso contrario, mostra que ela esta destruida
                        printf("  %d - Gousma %d (Furia: %d)\n", g + 1, g + 1, gousmas[turno][g].furia);
                    else
                        printf("  %d - Gousma %d (DESTRUIDA)\n", g + 1, g + 1);
                }

                int atacante; //variavel para armazenar a escolha da gousma atacante
                printf("Escolha (1-2): "); //escolha da gousma atacante
                scanf("%d", &atacante); //armazena a escolha da gousma atacante, e o do-while garante que a escolha seja valida, ou seja, que seja 1 ou 2, e que a gousma escolhida esteja ativa
                atacante--;

                while (atacante < 0 || atacante > 1 || !gousmas[turno][atacante].ativa) { //validação da escolha da gousma atacante, para garantir que o usuario escolha uma gousma ativa e dentro do intervalo de 1 a 2
                    printf("Escolha uma Gousma ativa (1-2): ");
                    scanf("%d", &atacante);
                    atacante--;
                }

                // Escolhe Gousma alvo (deve estar ativa)
                printf("\nGousma inimiga para atacar:\n");
                for (int g = 0; g < 2; g++) { // loop para mostrar as gousmas ativas do adversario, para escolher a gousma alvo
                    if (gousmas[adversario][g].ativa)
                        printf("  %d - Gousma %d (Furia: %d)\n", g + 1, g + 1, gousmas[adversario][g].furia); //se a gousma do adversario estiver ativa, mostra a furia dela, caso contrario, mostra que ela esta destruida
                    else
                        printf("  %d - Gousma %d (DESTRUIDA)\n", g + 1, g + 1); //se a gousma do adversario estiver destruida, mostra que ela esta destruida, e o loop de escolha da gousma alvo roda enquanto a escolha for invalida, ou seja, fora do intervalo de 1 a 2, ou seja, uma gousma que não esteja ativa
                }

                int alvo; //variavel para armazenar a escolha da gousma alvo
                printf("Escolha (1-2): ");
                scanf("%d", &alvo);
                alvo--;

                while (alvo < 0 || alvo > 1 || !gousmas[adversario][alvo].ativa) { //validação da escolha da gousma alvo, para garantir que o usuario escolha uma gousma ativa do adversario e dentro do intervalo de 1 a 2
                    printf("Escolha uma Gousma inimiga ativa (1-2): "); //se a escolha for invalida, mostra essa mensagem, e o loop continua até que o usuario escolha uma gousma ativa do
                    scanf("%d", &alvo);
                    alvo--;
                }

                // Aplica o ataque: furia do alvo += furia do atacante
                gousmas[adversario][alvo].furia += gousmas[turno][atacante].furia;

                printf("\nGousma %d atacou a Gousma %d do adversario!\n",
                    atacante + 1, alvo + 1); //mostra a ação realizada, e o resultado do ataque, mostrando a nova furia da gousma alvo
                printf("Furia da Gousma alvo agora: %d\n",
                    gousmas[adversario][alvo].furia); //mostra a nova furia da gousma alvo, apos o ataque, e o loop de verificação de destruição roda depois disso, para verificar se a furia da gousma alvo ultrapassou 5, e caso tenha ultrapassado, a gousma alvo é destruida

            // ──────────────────────────────────
            // AÇÃO 2 — DIVIDIR
            // ──────────────────────────────────
            } else {

                // Escolhe Gousma doadora (deve estar ativa)
                printf("\nEscolha sua Gousma doadora:\n");
                for (int g = 0; g < 2; g++) {
                    if (gousmas[turno][g].ativa)
                        printf("  %d - Gousma %d (Furia: %d)\n", g + 1, g + 1, gousmas[turno][g].furia);
                    else
                        printf("  %d - Gousma %d (DESTRUIDA)\n", g + 1, g + 1);
                }

                int doadora; //variavel para armazenar a escolha da gousma doadora
                printf("Escolha (1-2): "); //escolha da gousma doadora
                scanf("%d", &doadora); //armazena a escolha da gousma doadora, e o do-while garante que a escolha seja valida, ou seja, que seja 1 ou 2, e que a gousma escolhida esteja ativa
                doadora--; //ajuste para o indice do array, já que o usuario escolhe entre 1 e 2, mas os indices do array são 0 e 1

                while (doadora < 0 || doadora > 5 || !gousmas[turno][doadora].ativa) { //validação da escolha da gousma doadora, para garantir que o usuario escolha uma gousma ativa e dentro do intervalo de 1 a 2
                    printf("Escolha uma Gousma ativa como doadora (1-2): "); //se a escolha for invalida, mostra essa mensagem, e o loop continua até que o usuario escolha uma gousma ativa
                    scanf("%d", &doadora);
                    doadora--;
                }

                if (gousmas[turno][doadora].furia < 2) { //verifica se a gousma doadora tem furia suficiente para dividir, ou seja, pelo menos 2, e caso não tenha, mostra essa mensagem e volta para a escolha da ação, sem passar a vez
                    printf("Essa Gousma nao tem furia suficiente para dividir! Escolha outra acao.\n");
                    printf("Pressione ENTER para continuar...");
                    getchar(); getchar();
                    continue; //volta para o inicio do loop do jogo, sem passar a vez
                }

                int receptora = 1 - doadora;  // a outra Gousma é sempre a receptora

                printf("\nGousma %d (doadora): Furia = %d\n",
                    doadora + 1, gousmas[turno][doadora].furia); 

                if (!gousmas[turno][receptora].ativa)
                    printf("Gousma %d (receptora): DESTRUIDA — sera revivida!\n", receptora + 1);
                else
                    printf("Gousma %d (receptora): Furia = %d\n",
                        receptora + 1, gousmas[turno][receptora].furia);

                // Valida quantidade a transferir (mínimo 1, não pode zerar a doadora)
                int transferir;
                printf("Quanto transferir (1 a %d): ", gousmas[turno][doadora].furia - 1);
                scanf("%d", &transferir);

                while (transferir < 1 || transferir >= gousmas[turno][doadora].furia) {
                    printf("Invalido! Transfira entre 1 e %d: ",
                        gousmas[turno][doadora].furia - 1);
                    scanf("%d", &transferir);
                }

                // Aplica a divisão
                gousmas[turno][doadora].furia -= transferir;

                if (!gousmas[turno][receptora].ativa) {
                    // Revive a Gousma destruída
                    gousmas[turno][receptora].ativa = 1;
                    gousmas[turno][receptora].furia = transferir;
                    printf("\nGousma %d foi REVIVIDA com furia = %d!\n",
                        receptora + 1, transferir);
                } else {
                    gousmas[turno][receptora].furia += transferir;
                    printf("\nGousma %d agora tem furia = %d!\n",
                        receptora + 1, gousmas[turno][receptora].furia);
                }
            }

            // Verifica destruições (furia > 5) em todas as Gousmas
            for (int p = 0; p < 2; p++) {
                for (int g = 0; g < 2; g++) {
                    if (gousmas[p][g].ativa && gousmas[p][g].furia > 5) {
                        gousmas[p][g].ativa = 0;
                        printf("\nGousma %d do Jogador %d foi DESTRUIDA! (furia = %d)\n",
                            g + 1, p + 1, gousmas[p][g].furia);
                    }
                }
            }

            // Verifica se algum jogador perdeu (as 2 Gousmas destruídas, se perdeu encerra o jogo e o outro jogador venceu)
            for (int p = 0; p < 2; p++) {
                if (!gousmas[p][0].ativa && !gousmas[p][1].ativa) {
                    LimparTela();
                    printf("=============================\n");
                    printf("       FIM DE JOGO!\n");
                    printf("=============================\n\n");
                    printf("Jogador %d perdeu todas as Gousmas!\n", p + 1);
                    printf("JOGADOR %d VENCEU!\n\n", (1 - p) + 1);
                    jogoAtivo = 0;
                }
            }

            // Só troca o turno e pausa se o jogo ainda estiver ativo
            if (jogoAtivo) {
                printf("\nPressione ENTER para continuar..."); //pausa para o jogador ver o resultado da sua ação antes de passar a vez, e o turno só muda se o jogo ainda estiver ativo, ou seja, se ninguém perdeu todas as gousmas
                getchar(); getchar();
                turno = 1 - turno;
            }
        }

        // Menu final com loop caso mude de ideia e queira jogar novamente, ou voltar ao menu principal
        printf("O que deseja fazer?\n");
        printf("1 - Jogar novamente\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        getchar();
        scanf("%d", &opcao); //menu final do jogo, para jogar novamente ou voltar ao menu principal

        while (opcao != 0 && opcao != 1) { //loop para que o usuario digite uma opcao valida
            printf("Opcao invalida! Digite 1 para jogar novamente ou 0 para sair: ");
            scanf("%d", &opcao);
        }

    } while (opcao == 1); //loop para jogar novamente, caso o usuario escolha 1, e caso escolha 0, o jogo retorna ao menu principal

    LimparTela();
}
