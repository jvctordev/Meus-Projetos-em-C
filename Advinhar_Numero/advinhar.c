#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int limite = 10;
    char resposta;

    do {
        int secreto = rand() % 100 + 1;
        int chute = 0;
        int tentativas = 0;

        printf("\n====Adivinhe o Numero====\n");
        printf("Voce tem %d tentativas!\n\n", limite);

        while (chute != secreto && tentativas < limite){
            tentativas++;
            printf("Tentativa %d/%d - Digite seu chute: ", tentativas, limite);
            scanf("%d", &chute);

            if (chute > secreto){
                printf("Muito Alto!!!\n");
            } else if (chute < secreto){
                printf("Muito Baixo!!!\n");
            }
        }

        if (chute == secreto){
            printf("\nParabens! Acertou em %d tentativas!\n", tentativas);
        } else {
            printf("\nQue pena! O numero era %d\n", secreto);
        }

        printf("\nJogar novamente? (s/n): ");
        scanf(" %c", &resposta);

    } while (resposta == 's');

    printf("\nObrigado por jogar!\n");
    return 0;
}