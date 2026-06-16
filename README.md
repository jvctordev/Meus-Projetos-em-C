📚 Cadastro de Alunos

Projeto acadêmico em linguagem C que cadastra alunos com nome e nota, calcula a média da turma e informa automaticamente quem foi aprovado ou reprovado. Ideal para quem está começando e quer ver structs, arrays e funções funcionando juntos.

Funcionalidades

- Cadastro de N alunos com nome e nota O usuário informa quantos alunos serão cadastrados e insere os dados um por um.

- Cálculo da média da turma Ao final, o programa calcula a média aritmética das notas.

- Classificação automática Cada aluno é classificado como aprovado (nota >= 6.0) ou reprovado, com exibição organizada.

Como compilar e executar

Pré-requisito: compilador GCC (recomendado via MinGW no Windows).

gcc -Wall -std=c11 -o cadastro.exe cadastro.c
./cadastro.exe

Ou pelo prompt de comando do Windows:

gcc -Wall -std=c11 -o cadastro.exe cadastro.c
cadastro.exe

Exemplo de uso

Quantos alunos serao cadastrados? 3

--- Aluno 1 ---
Nome: Joao
Nota: 8.5

--- Aluno 2 ---
Nome: Maria
Nota: 5.0

--- Aluno 3 ---
Nome: Pedro
Nota: 7.0

========== RESULTADOS ==========
Media da turma: 6.83

Joao   - Nota: 8.50 - APROVADO
Maria  - Nota: 5.00 - REPROVADO
Pedro  - Nota: 7.00 - APROVADO
================================

Tecnologias e bibliotecas utilizadas

- Linguagem C (padrão C11)
- stdio.h — entrada e saída padrão (printf, scanf, fgets)
- string.h — manipulação de strings (strcspn)

Funcionalidades técnicas de destaque

- Leitura segura de nomes com fgets evitando estouro de buffer
- Limpeza do buffer do teclado com getchar() após leituras numéricas
- Uso de typedef para criar o tipo Aluno, tornando o código mais limpo
- Constante NOTA_MINIMA centralizada para facilitar alteração do critério de aprovação
- Organização do código em funções separadas por responsabilidade

Compatibilidade

Sistema Operacional Compatível
Windows✅ Sim
Linux / macOS✅ Sim (compila sem modificações)

Autores

[João Victor Garcia Quaresma]