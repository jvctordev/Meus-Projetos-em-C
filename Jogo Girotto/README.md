# 🎮 Jogos do Girroto — 3 em 1

Projeto desenvolvido em **linguagem C** com três jogos interativos em modo terminal, navegação por setas do teclado e menu principal animado.

---

## 📋 Jogos disponíveis

### 1. ❓ Perguntas e Respostas
Responda 5 perguntas de múltipla escolha e veja quantas você acerta!
- 5 perguntas fixas com 4 alternativas cada
- Exibe a resposta correta em caso de erro
- Placar ao final com opção de jogar novamente

### 2. 🐍 Cobra na Caixa
Dois jogadores presos em uma tumba egípcia precisam encontrar o botão de saída — sem cair na cobra!
- 2 jogadores escolhem um explorador de uma lista de 7 nomes
- 5 caixas: uma tem o botão da saída, outra esconde a cobra
- Turnos alternados até alguém vencer ou perder
- Posição do botão e da cobra sorteada a cada nova partida

### 3. ⚔️ Gousmas War
Jogo de estratégia onde dois jogadores controlam criaturas chamadas Gousmas e manipulam sua fúria para vencer!
- Cada jogador começa com 2 Gousmas (fúria = 1)
- Ações disponíveis: **Atacar** ou **Dividir** fúria
- Gousma com fúria > 5 é destruída
- Possível reviver Gousmas destruídas pela ação Dividir
- Vence quem destruir as 2 Gousmas do adversário

---

## 🖥️ Requisitos

- Sistema Operacional: **Windows**
- Compilador: **GCC (MinGW)** ou similar
- Bibliotecas utilizadas:
  - `stdio.h` — entrada e saída
  - `stdlib.h` — funções gerais
  - `conio.h` — leitura de teclas (Windows)
  - `windows.h` — funções do sistema Windows
  - `time.h` — geração de números aleatórios
  - `string.h` — manipulação de strings
  - `ctype.h` — classificação de caracteres

> ⚠️ Este projeto utiliza `conio.h` e `windows.h`, portanto **não é compatível com Linux/Mac** sem adaptações.

---

## ▶️ Como compilar e executar

**1. Clone o repositório:**
```bash
git clone https://github.com/seuusuario/JogoGirotto.git
cd JogoGirotto
```

**2. Compile com GCC:**
```bash
gcc JogoGirotto.c -o JogoGirotto.exe
```

**3. Execute:**
```bash
JogoGirotto.exe
```

---

## 🕹️ Como jogar

- Use as **setas ↑ ↓** do teclado para navegar no menu
- Pressione **ENTER** para confirmar a seleção
- Dentro dos jogos, use os **números** para escolher opções

---

## 📁 Estrutura do projeto

```
JogoGirotto/
│
├── JogoGirotto.c     # Código fonte completo
└── README.md         # Este arquivo
```

---

## 👨‍💻 Autor

Desenvolvido por **Girotto**  
Projeto de aprendizado em linguagem C 🚀