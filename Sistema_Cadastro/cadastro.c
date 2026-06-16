#include <stdio.h>
#include <string.h>

#define MAX_NOME 100
#define NOTA_MINIMA 6.0

typedef struct {
    char nome[MAX_NOME];
    float nota;
} Aluno;

int cadastrarAlunos(Aluno alunos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        fgets(alunos[i].nome, MAX_NOME, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        getchar();
    }
    return quantidade;
}

float calcularMedia(Aluno alunos[], int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].nota;
    }
    return soma / quantidade;
}

void exibirResultados(Aluno alunos[], int quantidade, float media) {
    printf("\n========== RESULTADOS ==========\n");
    printf("Media da turma: %.2f\n\n", media);

    for (int i = 0; i < quantidade; i++) {
        printf("%s - Nota: %.2f - %s\n",
               alunos[i].nome,
               alunos[i].nota,
               alunos[i].nota >= NOTA_MINIMA ? "APROVADO" : "REPROVADO");
    }
    printf("================================\n");
}

int main() {
    int quantidade;

    printf("Quantos alunos serao cadastrados? ");
    scanf("%d", &quantidade);
    getchar();

    Aluno alunos[quantidade];

    cadastrarAlunos(alunos, quantidade);
    float media = calcularMedia(alunos, quantidade);
    exibirResultados(alunos, quantidade, media);

    return 0;
}
