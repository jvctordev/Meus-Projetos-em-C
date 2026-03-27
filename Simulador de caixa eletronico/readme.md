# 🏦 Simulador de Caixa Eletrônico (C-Project)

Este é um simulador de terminal desenvolvido em **Linguagem C**. O projeto simula as operações fundamentais de um terminal bancário, focando em lógica de programação, segurança de acesso e organização modular.

---

## 🛠️ Funcionalidades

* **Autenticação:** Proteção por senha com limite de 3 tentativas antes do bloqueio do sistema.
* **Consulta de Saldo:** Exibição em tempo real do saldo disponível.
* **Depósito:** Adição de valores ao saldo com validação de entrada (apenas valores positivos).
* **Saque com Limite:** Retirada de valores com verificação de saldo e limite máximo de **R$ 500,00** por operação.
* **Interface Modular:** Código estruturado com funções para facilitar a leitura e manutenção.

## 💻 Conceitos Aplicados

Este projeto utiliza conceitos essenciais da linguagem C:
* **Estruturas de Controle:** `if/else`, `switch-case`.
* **Laços de Repetição:** `do-while` e `while`.
* **Modularização:** Uso de funções com protótipos e retorno de valores.
* **Constantes:** Uso de `#define` para regras de negócio (limites e tentativas).

## 🚀 Como Rodar o Projeto

1.  **Compilar:**
    ```bash
    gcc caixa_eletronico.c -o caixa_eletronico
    ```

2.  **Executar:**
    ```bash
    ./caixa_eletronico
    ```

> **Acesso Padrão:**
> * **Senha:** `1234`

---

## 📅 Roadmap de Evolução
- [ ] Implementar histórico de transações (extrato).
- [ ] Permitir a alteração da senha mestre pelo usuário.
- [ ] **Persistência de Dados:** Salvar o saldo final em um arquivo `.txt` para carregar no próximo uso.

---
*Desenvolvido como o 3º projeto de aprendizado em C.*