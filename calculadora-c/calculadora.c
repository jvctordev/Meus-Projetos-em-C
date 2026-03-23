#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){

    FILE *historico = fopen("Historico.txt", "a");
    if (historico == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    float a;
    float b;
    int opcao;
    char continuar;

    printf(" \n ======BEM VINDO A CALCULADORA ONLINE====== \n");
    printf("\nPressione ENTER para iniciar\n");
    limparBuffer();
    limparTela();

    do {

        printf("Insira o primeiro numero: ");
        while (scanf("%f", &a) != 1) {
            printf("Entrada invalida! Digite um numero: ");
            limparBuffer();
        }
        limparBuffer();

        printf("Insira o segundo numero: ");
        while (scanf("%f", &b) != 1) {
            printf("Entrada invalida! Digite um numero: ");
            limparBuffer();
        }
        limparBuffer();

        printf("Escolha uma operacao:\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Raiz Quadrada (usa apenas o primeiro numero)\n");
        printf("6 - Potencia\n");
        printf("7 - Ver historico\n");
        printf("8 - Limpar historico\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("Resultado: %.2f\n", a + b);
                fprintf(historico, "%.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case 2:
                printf("Resultado: %.2f\n", a - b);
                fprintf(historico, "%.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case 3:
                printf("Resultado: %.2f\n", a * b);
                fprintf(historico, "%.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case 4:
                if (b == 0) {
                    printf("Erro: Divisao por zero!\n");
                    fprintf(historico, "%.2f / %.2f = Erro (divisao por zero)\n", a, b);
                } else {
                    printf("Resultado: %.2f\n", (double)a / b);
                    fprintf(historico, "%.2f / %.2f = %.2f\n", a, b, (double)a / b);
                }
                break;
            caso return:
casese (hum < 0um <  {
                    imprimirf("Erro: raiz de número negativo!\n");
                    fprintf(histórico, "sqrt(%.2f) = Erro (numero negativo)\n", a);
                } outro {
                    imprimirf("Resultado: %.2f\n", sqrt(a));
 fprintf(histórico, "sqrt(%.2f) = %.2f\n", a, sqrt(a));
                }
 quebrar;
 caso 6:
                imprimirf("Resultado: %.2f\n", pow(a, b));
                fprintf(histórico, "%.2f ^ %.2f = %.2f\n", a, b, pow(a, b));
 quebrar;
 caso 7: {
 ARQUIVO *arq = abrir("Histórico.txt", "r");
                se (arq == NULO) {
                    imprimirf("Historico vazio ou erro ao abrir.\n");
                } outro {
 char linha[100];
                    imprimirf("\n===== HISTÓRICO =====\n");
 enquanto (fgets(linha, tamanho de(linha), arq))
                        imprimirf("%s", linha);
                    imprimirf(====================\n");
 Fechar(arq);
                }
 quebrar;
            }
 caso 8: {
 ARQUIVO *limpar = abrir("Histórico.txt", "w");
                se (limpar == NULO) {
                    imprimirf("Erro ao limpar histórico!\n");
                } outro {
                    Fechar(limpar);
                    imprimirf("Historico limpo com sucesso!\n");
                }
 quebrar;
            }
 padrão:
 imprimirf("Opcao inválido!\n");
 quebrar;
        }

        imprimirf("\nDeseja calcular recentemente? (s/n): ");
        scanf(" %c", &continuar);
        LimparBuffer();
        limparTela();

    } enquanto (contínuo == 's');

 Fechar(histórico);
    imprimirf("\nComeu logotipo!\n");
 retornar 0;
}
