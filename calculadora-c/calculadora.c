#include <stdio.h>
#include <stdlib.h>
#include <matemática.h>

vazio LimparBuffer() {
 int c;
    enquanto ((c = getchar()) != '\n' && c!= EOF);
}
vazio limparTela() {
    #ifdef _WIN32
        sistema("cls");
    #else
        sistema("claro");
    #endif
}

int principal(){

 ARQUIVO *histórico = abrir("Histórico.txt", "a");
    se (histórico == NULO)
    {
        imprimirf("Erro ao abrir arquivo!\n");
    retornar 1;
    }
    

 flutuar a;
 flutuador b;
 soma flutuante;
 flutuador mult;
 flutuar subtr;
 int opcao;
 char contínuo;
    imprimirf(" \n ======BEM VINDO A CALCULADORA ONLINE====== \n");
    imprimirf("\nPressione ENTER para iniciar\n");
    LimparBuffer();
    limparTela();
    
    fazer{

    imprimirf("Insira o primeiro número:");
    scanf("%f", &a);
    LimparBuffer();

    imprimirf("Insira o segundo número:");
    scanf("%f", &b);
    LimparBuffer();

    imprimirf("Escola uma operação:\n");
    imprimirf("1 - Soma\n");
    imprimirf("2 - Subtracao\n");
    imprimirf("3 - Multiplicação\n");
    imprimirf("4 - Divisão\n");
    imprimirf("5- Raiz Quadrada\n");
    imprimirf("(Raiz usa apenas o primeiro número)\n");
    imprimirf("6- Potência:\n");
    imprimirf("Opcao: ");
    scanf("%d", &opcao);
    LimparBuffer();

    interruptor (opcao)
    {
 caso 1:
 soma = a + b;
        imprimirf("Resultado: %.2f\n", soma);
        fprintf(histórico, "%.2f + %.2f = %.2f\n", a, b, soma);
 quebrar;
 caso 2:
 subtr = a - b;
        imprimirf("Resultado: %.2f\n", subtr);
        fprintf(histórico, "%.2f - %.2f = %.2f\n", a, b, subtr);
 quebrar;
 caso 3:
 mult = a * b;
        imprimirf("Resultado: %.2f\n", multiplicador);
        fprintf(histórico, "%.2f * %.2f = %.2f\n", a, b, mult);
 quebrar;
 caso 4:
    se (b == 0)
    {
        imprimirf("Erro: Divisão por 0!\n");
        fprintf(histórico, "%.2f / %.2f = Erro (divisão por zero)\n", a, b);
    } outro {
        imprimirf("Resultado: %.2lf\n", (duplo)a / b);
 fprintf(histórico, "%.2f / %.2f = %.2lf\n", a, b, (duplo)a / b);
    }
 quebrar;
 caso 5:
    se (zumbir < 0) {
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
