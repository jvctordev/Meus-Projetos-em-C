# 🎮 Jogos do Girroto — 3 em 1

Projeto desenvolvido como trabalho acadêmico, um conjunto de três minijogos
de terminal desenvolvidos em linguagem C, com navegação por menu interativo
usando teclas de seta.

---

## Jogos disponíveis

**1. Perguntas e Respostas**
Quiz com 5 perguntas de cultura geral, cada uma com 4 alternativas. Ao final,
o jogador vê sua pontuação e pode jogar novamente.

**2. Cobra na Caixa**
Jogo para 2 jogadores. Há 5 caixas: uma esconde um botão (vitória) e outra
esconde uma cobra (derrota). Os jogadores se revezam abrindo caixas até
alguém encontrar o botão ou a cobra. Cada jogador escolhe um explorador com
nome temático do Egito Antigo.

**3. Gousmas War**
Jogo de estratégia para 2 jogadores. Cada jogador controla 2 Gousmas, criaturas
com um atributo de Fúria iniciando em 1. A cada turno, o jogador pode atacar
uma Gousma inimiga (transferindo fúria) ou dividir fúria entre suas próprias
Gousmas. Gousmas com fúria acima de 5 são destruídas. Vence quem destruir
todas as Gousmas do adversário.

---

## Como compilar e executar

O projeto foi desenvolvido para Windows, pois utiliza as bibliotecas `conio.h`
e `windows.h`.

**Pré-requisito:** compilador GCC (recomendado via MinGW).

```bash
gcc jogos.c -o jogos.exe
./jogos.exe
```

Ou pelo prompt de comando do Windows:

```cmd
gcc jogos.c -o jogos.exe
jogos.exe
```

---

## Tecnologias e bibliotecas utilizadas

- Linguagem C (padrão C99)
- `stdio.h` — entrada e saída padrão
- `stdlib.h` — funções gerais como `rand()`, `srand()` e `system()`
- `conio.h` — leitura de teclas no terminal (Windows)
- `windows.h` — integração com a WinAPI
- `time.h` — semente para geração de números aleatórios
- `string.h` — manipulação de strings
- `ctype.h` — classificação de caracteres
- `errno.h` — detecção de erros na conversão de inteiros com `strtol`

---

## Funcionalidades técnicas de destaque

- Menu navegável com teclas de seta (cima/baixo) e confirmação com Enter
- Leitura segura de inteiros via `lerInteiro()`, que rejeita letras, símbolos
  e entradas vazias, exibindo mensagens de erro personalizadas
- Geração de posições aleatórias garantindo que botão e cobra nunca ocupem
  a mesma caixa no jogo Cobra na Caixa
- Lógica de reviver Gousmas destruídas através da ação de dividir fúria
- Loop `do-while` em todos os jogos permitindo jogar novamente sem reiniciar
  o programa

---

## Compatibilidade

| Sistema Operacional | Compatível |
|---------------------|------------|
| Windows             | ✅ Sim     |
| Linux / macOS       | ❌ Não (depende de `conio.h` e `windows.h`) |

---

## Autores

Desenvolvido por João Victor e Lucas Okiyama como projeto acadêmico de Algoritmo e codificação de software.
