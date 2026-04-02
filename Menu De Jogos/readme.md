Jogos do Girroto — 3 em 1

Coleção de três minigames em C para dois jogadores (ou um jogador contra as perguntas), desenvolvida como trabalho acadêmico. O programa roda no terminal do Windows e apresenta um menu interativo navegável por setas do teclado.
Jogos disponíveis
1. Perguntas e Respostas

Quiz de cultura geral com 5 perguntas de múltipla escolha (4 alternativas cada). O jogador responde todas as perguntas em sequência e ao final recebe sua pontuação de acertos.
2. Cobra na Caixa

Jogo para dois jogadores. Cada um escolhe um "Explorador" (personagens com nomes do Egito Antigo) e se revezam abrindo caixas em busca de um botão que abre a saída da tumba — mas uma das caixas esconde uma cobra. Quem encontrar o botão vence; quem encontrar a cobra perde.
3. Gousmas War

Jogo de estratégia para dois jogadores baseado em "Chopsticks". Cada jogador controla duas criaturas chamadas Gousmas, cada uma com um valor de Fúria. Os jogadores se alternam escolhendo entre duas ações:

    Atacar — soma a Fúria de uma Gousma própria à Fúria de uma Gousma inimiga.
    Dividir — redistribui Fúria entre as próprias Gousmas (podendo reviver uma destruída).

Uma Gousma é destruída quando sua Fúria ultrapassa 5. Perde quem tiver as duas Gousmas destruídas.
Requisitos

    Sistema operacional Windows
    Compilador C com suporte a C99 ou superior (ex.: GCC via MinGW, MSVC)

    O projeto usa as bibliotecas conio.h e windows.h, que são exclusivas do ambiente Windows.

Como compilar e executar

Usando GCC (MinGW):
bash
Copiar

gcc -std=c99 -o jogos jogos.c
./jogos.exe

Ou pelo próprio terminal do Windows:
bash
Copiar

gcc jogos.c -o jogos.exe
jogos.exe

Estrutura do código

jogos.c
│
├── main()                    — Inicializa o gerador aleatório e exibe o menu principal
├── menu()                    — Menu navegável com setas ↑↓ e ENTER
├── lerInteiro()              — Leitura segura de inteiros (rejeita letras e valores fora do intervalo)
├── limparBuffer()            — Limpa o buffer de entrada do teclado
├── LimparTela()              — Limpa o terminal (compatível com Windows)
│
├── jogoPerguntaseRespostas() — Lógica do quiz de perguntas e respostas
├── jogoCobraNaCaixa()        — Lógica do jogo Cobra na Caixa
└── jogoGousmasWar()          — Lógica do Gousmas War (struct Gousma)

Decisões técnicas relevantes
Recurso 	Motivo
fgets + strtol em lerInteiro() 	Evita travamento do buffer e rejeita entradas inválidas com segurança
srand(time(NULL)) 	Garante aleatoriedade diferente a cada execução
getch() + códigos de seta 	Permite navegação no menu sem precisar pressionar ENTER
struct Gousma 	Agrupa os atributos furia e ativa de cada criatura em uma única estrutura
do-while nos menus finais 	Permite ao jogador reiniciar a partida sem voltar ao menu principal


Autores: João Victor Quaresma e Lucas Okiyama

Trabalho acadêmico desenvolvido para a disciplina de Algorimo e codificação de software — [CESUPA ARGO].