#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

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

float lerNumeroSeguro(const char *mensagem) {
    char buffer[100];
    float num;
    char resto;
    while (1) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%f %c", &num, &resto) == 1) {
                return num;
            }
        }
        printf("Entrada invalida! Digite um numero:\n");
    }
}

int lerInteiroSeguro(const char *mensagem) {
    char buffer[100];
    int num;
    char resto;
    while (1) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d %c", &num, &resto) == 1) {
                return num;
            }
        }
        printf("Entrada invalida! Digite um numero de 1 a 8:\n");
    }
}

int main() {
    #ifdef _WIN32
        system("color 0F"); 
    #endif

    float a, b;
    int opcao;
    char continuar;

    printf(" \n ======BEM VINDO A CALCULADORA ONLINE====== \n");
    printf("\nPressione ENTER para iniciar\n");
    limparBuffer();
    limparTela();

    do {
        FILE *historico = fopen("Historico.txt", "a+");
        if (historico == NULL) {
            printf("Erro ao abrir arquivo!\n");
            return 1;
        }

        a = lerNumeroSeguro("Insira o primeiro numero: ");
        b = lerNumeroSeguro("Insira o segundo numero: ");

        // LOOP DO MENU: Só sai daqui se digitar de 1 a 8
        while (1) {
            printf("\nEscolha uma operacao:\n");
            printf("1 - Soma\n");
            printf("2 - Subtracao\n");
            printf("3 - Multiplicacao\n");
            printf("4 - Divisao\n");
            printf("5 - Raiz Quadrada (usa apenas o primeiro numero)\n");
            printf("6 - Potencia\n");
            printf("7 - Ver historico\n");
            printf("8 - Limpar historico\n");
            
            opcao = lerInteiroSeguro("Opcao: ");

            if (opcao >= 1 && opcao <= 8) {
                break; // Opção válida, sai do loop do menu e vai para o switch
            } else {
                printf("\n[ERRO] Opcao %d inexistente! Escolha um numero entre 1 e 8.\n", opcao);
            }
        }

        printf("\n-----------------------------\n");
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
                    printf("Resultado: %.2f\n", a / b);
                    fprintf(historico, "%.2f / %.2f = %.2f\n", a, b, a / b);
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
                rewind(historico);
                char linha[100];
                printf("\n===== HISTORICO =====\n");
                int vazio = 1;
                while (fgets(linha, sizeof(linha), historico)) {
                    printf("%s", linha);
                    vazio = 0;
                }
                if(vazio) printf("Historico vazio.\n");
                printf("=====================\n");
                break;
            }
            case 8:
                fclose(historico);
                historico = fopen("Historico.txt", "w");
                printf("Historico limpo com sucesso!\n");
                break;
        }
        printf("-----------------------------\n");

        fclose(historico);

        do {
            printf("\nDeseja calcular novamente? (s/n): ");
            scanf(" %c", &continuar);
            limparBuffer();
            continuar = (char)tolower(continuar);
            if (continuar != 's' && continuar != 'n') {
                printf("Entrada invalida! Digite 's' para sim ou 'n' para nao.\n");
            }
        } while (continuar != 's' && continuar != 'n');

        limparTela();

    } while (continuar == 's');

    printf("\nAte Logo!\nPressione ENTER para sair\n");
    limparBuffer();

    return 0;
}
