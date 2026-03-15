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
    if (historico == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
    return 1;
    }
    

    float a;
    float b;
    float soma;
    float mult;
    float subtr;
    int opcao;
    char continuar;
    printf(" \n ======BEM VINDO A CALCULADORA ONLINE====== \n");
    printf("\nPressione ENTER para iniciar\n");
    limparBuffer();
    limparTela();
    
    do{

    printf("Insira o primeiro numero:  ");
    scanf("%f", &a);
    limparBuffer();

    printf("Insira o segundo numero:  ");
    scanf("%f", &b);
    limparBuffer();

    printf("Escolha uma operacao:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5- Raiz Quadrada\n");
    printf("(Raiz usa apenas o primeiro numero)\n");
    printf("6- Potencia:\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
        soma = a + b;
        printf("Resultado: %.2f\n", soma);
        fprintf(historico, "%.2f + %.2f = %.2f\n", a, b, soma);
        break;
    case 2:
        subtr = a - b;
        printf("Resultado: %.2f\n", subtr);
        fprintf(historico, "%.2f - %.2f = %.2f\n", a, b, subtr);
        break;
    case 3:
        mult = a * b;
        printf("Resultado: %.2f\n", mult);
        fprintf(historico, "%.2f * %.2f = %.2f\n", a, b, mult);
        break;
    case 4:
    if (b == 0)
    {
        printf("Erro: Divisao por 0!\n");
        fprintf(historico, "%.2f / %.2f = Erro (divisao por zero)\n", a, b);
    } else {
        printf("Resultado: %.2lf\n", (double)a / b);
        fprintf(historico, "%.2f / %.2f = %.2lf\n", a, b, (double)a / b);
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
}
    printf("\nDeseja calcular novamente? (s/n): ");
    scanf(" %c", &continuar);
    limparBuffer();
    limparTela();

    } while (continuar == 's');

    fclose(historico);
    printf("\nAte Logo!\n");
    return 0;
}
