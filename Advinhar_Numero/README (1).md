# 🎯 Adivinhe o Número

Jogo de adivinhação desenvolvido em C como projeto de aprendizado. O computador sorteia um número entre 1 e 100 e o jogador tem até 10 tentativas para descobrir qual é.

---

## 🎮 Como jogar

1. O programa sorteia um número secreto entre **1 e 100**
2. Você tem **10 tentativas** para adivinhar
3. A cada chute, o jogo diz se o número é **muito alto** ou **muito baixo**
4. Ao final, você pode escolher jogar novamente

---

## ▶️ Como compilar e executar

**Compilar:**
```bash
gcc advinhar.c -o advinhar
```

**Executar:**
```bash
./advinhar
```

> No Windows com VS Code, use o botão **Compile & Run** ou o terminal com `& .'advinhar.exe'`

---

## 🖥️ Exemplo de execução

```
====Adivinhe o Numero====
Voce tem 10 tentativas!

Tentativa 1/10 - Digite seu chute: 50
Muito Alto!!!
Tentativa 2/10 - Digite seu chute: 25
Muito Baixo!!!
Tentativa 3/10 - Digite seu chute: 37

Parabens! Acertou em 3 tentativas!

Jogar novamente? (s/n): n

Obrigado por jogar!
```

---

## 🧠 Conceitos de C utilizados

| Conceito | Onde é usado |
|---|---|
| `rand()` e `srand()` | Gerar número aleatório a cada partida |
| `time(NULL)` | Semente baseada no horário para aleatoriedade real |
| `while` | Loop principal de chutes |
| `do while` | Loop externo para jogar novamente |
| `if / else if` | Dicas de alto ou baixo |
| Variável contadora | Contar tentativas |
| `char` | Ler resposta s/n do jogador |

---

## 📁 Estrutura do projeto

```
Advinhar_Numero/
├── advinhar.c    # Código fonte principal
├── output/       # Executável gerado pelo compilador
└── README.md     # Este arquivo
```

---

## 🚀 Possíveis melhorias futuras

- [ ] Escolher a dificuldade (fácil / médio / difícil)
- [ ] Placar com recorde de menor tentativas
- [ ] Modo multiplayer na mesma máquina

---

## 👨‍💻 Autor

Projeto desenvolvido como parte do aprendizado de programação em C.
Projeto pensado e desenvolvido por João Victor Dev
