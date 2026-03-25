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


    system ("color 0F"); // Muda a cor do texto para verde 
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
        while (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero de 1 a 8: ");
            limparBuffer();
        }
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
            case 5:
                if (a < 0) {
                    printf("Erro: raiz de numero negativo!\n");
                    fprintf(historico, "sqrt(%.2f) = Erro (numero negativo)\n", a);
                } else {
                    printf("Resultado: %.2f\n", sqrt(a));
                    fprintf(historico, "sqrt(%.2f) = %.2f\n", a, sqrt(a));
                }
                break;
            case 6:
                printf("Resultado: %.2f\n", pow(a, b));
                fprintf(historico, "%.2f ^ %.2f = %.2f\n", a, b, pow(a, b));
                break;
            case 7: {
                FILE *arq = fopen("Historico.txt", "r");
                if (arq == NULL) {
                    printf("Historico vazio ou erro ao abrir.\n");
                } else {
                    char linha[100];
                    printf("\n===== HISTORICO =====\n");
                    while (fgets(linha, sizeof(linha), arq))
                        printf("%s", linha);
                    printf("=====================\n");
                    fclose(arq);
                }
                break;
            }
            case 8: {
                FILE *limpar = fopen("Historico.txt", "w");
                if (limpar == NULL) {
                    printf("Erro ao limpar historico!\n");
                } else {
                    fclose(limpar);
                    printf("Historico limpo com sucesso!\n");
                }
                break;
            }
            default:
                printf("Opcao invalida!\n");
                break;
        }

        do {
            printf("\nDeseja calcular novamente? (s/n): ");
            scanf(" %c", &continuar);
            limparBuffer();
            if (continuar != 's' && continuar != 'n') {
                printf("Entrada invalida! Digite 's' para sim ou 'n' para nao.\n");
            }
        } while (continuar != 's' && continuar != 'n');

        limparTela();

    } while (continuar == 's');

    fclose(historico);
    printf("\nAte Logo!\n");
    printf("Pressione ENTER para sair\n");
    limparBuffer();

    return 0;
}
