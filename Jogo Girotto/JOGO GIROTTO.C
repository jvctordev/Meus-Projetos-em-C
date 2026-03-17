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
// ===== MENU DE SETAS =====
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
            if (tecla == KEY_DOWN && selecionado < total - 1) selecionado++;  //le a tecla pressionada
        } else if (tecla == KEY_ENTER) {
            return selecionado + 1;
        } //se pressionar enter, confirma a seleção e retorna ao item escolhido
    }
}   // <-- fecha o menu aqui

// ===== MAIN =====
int main() {
    srand(time(NULL));

    const char *itens[] = {
        "||    Perguntas e Respostas||",
        "||    Cobra na Caixa!      ||",
        "||    Gousmas War          ||",
        "||    Sair                 ||"
    };

    int pos;
    do {
        pos = menu("[JOGOS DO GIRROTO] 3 em 1", itens, 4);

        switch (pos) {
            case 1: system("cls"); jogoPerguntaseRespostas(); break;
            case 2: system("cls"); jogoCobraNaCaixa();        break;
            case 3: system("cls"); jogoGousmasWar();          break;  
            case 4:
                system("cls");
                printf("Ate logo, Girroto!\n");
                system("pause");
                break;
        }
    } while (pos != 4);

    return 0;
}




void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void jogoPerguntaseRespostas() {
    int resposta, correta, opcao;

    char perguntas[5][200] = {  
        "De quem e a frase 'Penso, logo existo'?",
        "Atualmente, quantos elementos quimicos a tabela periodica possui?",
        "O que a palavra 'Legend' significa em portugues?",
        "Qual o numero minimo de jogadores em cada time de uma partida de futebol?",
        "Em que periodo da pre-historia o fogo foi descoberto?"};
    char alternativas[5][4][100] = {   
        {"1) Platao", "2) Galileu Galilei", "3) Descartes", "4) Socrates"},
        {"1) 113", "2) 109", "3) 108", "4) 118"},
        {"1) Legenda", "2) Conto", "3) Historia", "4) Lenda"},
        {"1) 8", "2) 10", "3) 9", "4) 7"},
        {"1) Neolitico", "2) Paleolitico", "3) Idade dos Metais", "4) Periodo da Pedra Polida"} };  // [5] correto
    int corretas[5] = {3, 4, 4, 4, 2};

    do {
        int acertos = 0;
        for (int i = 0; i < 5; i++) {

            LimparTela();

            printf("\nPergunta %d: %s\n", i+1, perguntas[i]);
            for (int j = 0; j < 4; j++)
                printf("%s\n", alternativas[i][j]);

            printf("Sua resposta (1-4): ");
            scanf("%d", &resposta);
            limparBuffer();

            while (resposta < 1 || resposta > 4) {
                printf("Opcao invalida, insira um numero de 1-4: ");
                scanf("%d", &resposta);
                limparBuffer();
            }

            correta = corretas[i];

            if (resposta == correta) {
                printf("Certa resposta!\n");
                acertos++;
            } else {
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

    } while (opcao == 1); 
        printf("\nRetornando ao menu principal...\n"); // único do-while, fechando certo

    LimparTela();
    
}

void jogoCobraNaCaixa(){

    char nomes[7][20] = {
        "Ramses", "Nefertiti", "Anubis", "Cleopatra",
        "Tutankhamon", "Horus", "Isis"
    };

    char jogadores[2][20];


    for (int p = 0; p < 2; p++){
        int escolha;
            LimparTela();

        printf("===JOGADOR %d ESCOLHA SEU EXPLORADOR===\n\n", p + 1);
        for (int i = 0; i < 7; i++){
            printf("%d - %s\n", i + 1, nomes[i]);
        }

        printf("\nEscolha (1-7): ");
        scanf("%d", &escolha);

        while (escolha < 1 || escolha > 7){
            printf("Opcao Invalida! Digite entre 1 e 7: ");
            scanf("%d", &escolha);
        }


        strcpy(jogadores[p], nomes[escolha - 1]);
    }

    int opcao;
    
    do {
        srand(time(NULL));

        int caixas[5] = {0, 0, 0, 0, 0};
        int abertas[5] = {0, 0, 0, 0, 0};

        int botao = rand() % 5;

        int cobra;
        do {
            cobra = rand() % 5;
    }  while (cobra == botao);

    caixas[botao] = 1;
    caixas[cobra] = 2;

    int turno = rand() % 2;

    LimparTela();
    printf("A Tumba esta pronta...\n");
    printf("O Primeiro a jogar sera: %s!\n\n", jogadores[turno]);
    printf("Pressione ENTER para comecar....");
    getchar(); getchar();

    int jogoAtivo = 1;


    while (jogoAtivo){
        LimparTela();
        printf("=============================\n");
            printf("      COBRA NA CAIXA\n");
            printf("=============================\n\n");
            printf("Vez de: %s\n\n", jogadores[turno]);


        printf("CAIXAS:\n");
        for (int i = 0; i < 5; i++){
            if (abertas[i]){
                printf(" [%d - ABERTA]\n", i + 1);
            } else {
                printf(" [%d - FECHADA]\n", i + 1);
            }
        }

        int escolha;
        printf("\nEscolha uma caixa (1-5): ");
        scanf("%d", &escolha);

        while (escolha < 1 || escolha > 5){
            printf("Opcao Invalida! Digite entre 1 e 5: ");
            scanf("%d", &escolha);
        }

        while (abertas[escolha - 1] == 1){
            printf("Essa caixa ja foi aberta! Escolha outra: ");
                scanf("%d", &escolha);
                while (escolha < 1 || escolha > 5) {
                    printf("Opcao invalida! Digite entre 1 e 5: ");
                    scanf("%d", &escolha);
        }

    }

    abertas[escolha - 1] = 1;

    if (caixas[escolha - 1] == 1) {
                LimparTela();
                printf("=============================\n");
                printf("  ** BOTAO ENCONTRADO! **\n");
                printf("=============================\n");
                printf("%s abriu a porta e escapou da tumba!\n", jogadores[turno]);
                printf("%s VENCEU!\n", jogadores[turno]);
                jogoAtivo = 0;

            } else if (caixas[escolha - 1] == 2) {
                LimparTela();
                printf("=============================\n");
                printf("      ** COBRA!! **\n");
                printf("=============================\n");
                printf("%s encontrou a cobra...\n", jogadores[turno]);
                printf("%s perdeu! %s VENCEU!\n", jogadores[turno], jogadores[1 - turno]);
                jogoAtivo = 0;

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
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Opcao invalida! Digite 1 para jogar novamente ou 0 para sair: ");
            scanf("%d", &opcao);
        }

    } while (opcao == 1);

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
        int jogoAtivo = 1;

        while (jogoAtivo) {
            LimparTela();

            // Exibe o estado atual do jogo
            printf("=============================\n");
            printf("        GOUSMAS WAR\n");
            printf("=============================\n\n");

            for (int p = 0; p < 2; p++) {
                printf("JOGADOR %d:\n", p + 1);
                for (int g = 0; g < 2; g++) {
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
            scanf("%d", &acao);

            while (acao < 1 || acao > 2) {
                printf("Opcao invalida! Digite 1 ou 2: ");
                scanf("%d", &acao);
            }

            // ──────────────────────────────────
            // AÇÃO 1 — ATACAR
            // ──────────────────────────────────
            if (acao == 1) {
                int adversario = 1 - turno;

                // Escolhe Gousma atacante (deve estar ativa)
                printf("\nSua Gousma para atacar:\n");
                for (int g = 0; g < 2; g++) {
                    if (gousmas[turno][g].ativa)
                        printf("  %d - Gousma %d (Furia: %d)\n", g + 1, g + 1, gousmas[turno][g].furia);
                    else
                        printf("  %d - Gousma %d (DESTRUIDA)\n", g + 1, g + 1);
                }

                int atacante;
                printf("Escolha (1-2): ");
                scanf("%d", &atacante);
                atacante--;

                while (atacante < 0 || atacante > 1 || !gousmas[turno][atacante].ativa) {
                    printf("Escolha uma Gousma ativa (1-2): ");
                    scanf("%d", &atacante);
                    atacante--;
                }

                // Escolhe Gousma alvo (deve estar ativa)
                printf("\nGousma inimiga para atacar:\n");
                for (int g = 0; g < 2; g++) {
                    if (gousmas[adversario][g].ativa)
                        printf("  %d - Gousma %d (Furia: %d)\n", g + 1, g + 1, gousmas[adversario][g].furia);
                    else
                        printf("  %d - Gousma %d (DESTRUIDA)\n", g + 1, g + 1);
                }

                int alvo;
                printf("Escolha (1-2): ");
                scanf("%d", &alvo);
                alvo--;

                while (alvo < 0 || alvo > 1 || !gousmas[adversario][alvo].ativa) {
                    printf("Escolha uma Gousma inimiga ativa (1-2): ");
                    scanf("%d", &alvo);
                    alvo--;
                }

                // Aplica o ataque: furia do alvo += furia do atacante
                gousmas[adversario][alvo].furia += gousmas[turno][atacante].furia;

                printf("\nGousma %d atacou a Gousma %d do adversario!\n",
                    atacante + 1, alvo + 1);
                printf("Furia da Gousma alvo agora: %d\n",
                    gousmas[adversario][alvo].furia);

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

                int doadora;
                printf("Escolha (1-2): ");
                scanf("%d", &doadora);
                doadora--;

                while (doadora < 0 || doadora > 1 || !gousmas[turno][doadora].ativa) {
                    printf("Escolha uma Gousma ativa como doadora (1-2): ");
                    scanf("%d", &doadora);
                    doadora--;
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

            // Verifica se algum jogador perdeu (as 2 Gousmas destruídas)
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
                printf("\nPressione ENTER para continuar...");
                getchar(); getchar();
                turno = 1 - turno;
            }
        }

        // Menu final
        printf("O que deseja fazer?\n");
        printf("1 - Jogar novamente\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        getchar();
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Opcao invalida! Digite 1 para jogar novamente ou 0 para sair: ");
            scanf("%d", &opcao);
        }

    } while (opcao == 1);

    LimparTela();
}