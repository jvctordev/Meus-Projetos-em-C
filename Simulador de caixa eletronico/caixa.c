#include <stdio.h>
#include <stdlib.h>

#define LIMITE_SAQUE_UNICO 500.00
#define TENTATIVAS_MAX 3

void exibirMenu();
float realizarDeposito(float saldoAtual);
float realizarSaque(float saldoAtual);

int main() {
    float saldo = 1000.00;
    int senhaMestra = 1234;
    int senhaDigitada, opcao;
    int tentativas = 0;
    int autenticado = 0;

    printf("===== SISTEMA BANCARIO AVANCADO =====\n");

    while (tentativas < TENTATIVAS_MAX) {
        printf("Digite sua senha: ");
        scanf("%d", &senhaDigitada);

        if (senhaDigitada == senhaMestra) {
            autenticado = 1;
            break;
        } else {
            tentativas++;
            printf("Senha incorreta! (%d/%d)\n", tentativas, TENTATIVAS_MAX);
        }
    }

    if (!autenticado) {
        printf("\n[BLOQUEADO] Muitas tentativas falhas. Encerrando...\n");
        return 0;
    }

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n>>> Saldo Atual: R$ %.2f\n", saldo);
                break;
            case 2:
                saldo = realizarDeposito(saldo);
                break;
            case 3:
                saldo = realizarSaque(saldo);
                break;
            case 4:
                printf("\nLimpando sessao... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}


void exibirMenu() {
    printf("\n-------------------------------\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar (Limite R$ %.2f)\n", LIMITE_SAQUE_UNICO);
    printf("4. Sair\n");
    printf("-------------------------------\n");
}

float realizarDeposito(float saldoAtual) {
    float valor;
    printf("Valor do deposito: R$ ");
    scanf("%f", &valor);

    if (valor > 0) {
        saldoAtual += valor;
        printf("Sucesso! Novo saldo: R$ %.2f\n", saldoAtual);
    } else {
        printf("Erro: Valor de deposito invalido.\n");
    }
    return saldoAtual;
}

float realizarSaque(float saldoAtual) {
    float valor;
    printf("Valor do saque: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Erro: Valor invalido.\n");
    } else if (valor > LIMITE_SAQUE_UNICO) {
        printf("Erro: O limite maximo por saque e R$ %.2f\n", LIMITE_SAQUE_UNICO);
    } else if (valor > saldoAtual) {
        printf("Erro: Saldo insuficiente. (Disponivel: R$ %.2f)\n", saldoAtual);
    } else {
        saldoAtual -= valor;
        printf("Saque de R$ %.2f realizado!\n", valor);
        printf("Saldo restante: R$ %.2f\n", saldoAtual);
    }
    return saldoAtual;
}