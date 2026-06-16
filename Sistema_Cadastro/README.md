# 📚 Sistema de Cadastro de Alunos

Programa em C para cadastro de alunos, cálculo de média da turma e exibição do resultado de aprovação/reprovação de cada aluno.

---

## ✨ Funcionalidades

- Cadastro de N alunos com nome e nota
- Cálculo automático da média da turma
- Exibição do status individual (**APROVADO** / **REPROVADO**) com base na nota mínima de **6.0**

---

## 🖥️ Exemplo de uso

```
Quantos alunos serao cadastrados? 3

--- Aluno 1 ---
Nome: João Silva
Nota: 7.5

--- Aluno 2 ---
Nome: Maria Souza
Nota: 4.0

--- Aluno 3 ---
Nome: Pedro Lima
Nota: 8.2

========== RESULTADOS ==========
Media da turma: 6.57

João Silva - Nota: 7.50 - APROVADO
Maria Souza - Nota: 4.00 - REPROVADO
Pedro Lima - Nota: 8.20 - APROVADO
================================
```

---

## 🚀 Como compilar e executar

### Pré-requisitos

- GCC (ou qualquer compilador C compatível com C99 ou superior)

### Compilação

```bash
gcc -o alunos main.c
```

### Execução

```bash
./alunos
```

> No Windows, use `alunos.exe` após compilar.

---

## 📁 Estrutura do projeto

```
.
└── main.c   # Código-fonte principal
```

---

## 🛠️ Tecnologias

- **Linguagem:** C (C99)
- **Compilador recomendado:** GCC

---

## 📌 Observações

- A nota mínima para aprovação é `6.0`, definida via constante `NOTA_MINIMA`.
- O programa utiliza VLA (*Variable Length Array*) para alocar os alunos dinamicamente na stack com base na quantidade informada pelo usuário.
- Nomes são lidos com `fgets` para suportar espaços.
