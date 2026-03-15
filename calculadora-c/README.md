# Calculadora em C

Minha primeira calculadora desenvolvida em C, com menu interativo e histórico de cálculos.

## Funcionalidades

- Soma, subtração, multiplicação e divisão
- Raiz quadrada e potência
- Tratamento de erros (divisão por zero, raiz de número negativo)
- Histórico de cálculos salvo em `Historico.txt`
- Loop para realizar múltiplos cálculos sem reiniciar o programa
- Compatível com Windows e Linux

## Como compilar

**Linux/Mac:**
```bash
gcc calculadora.c -o calculadora -lm
```

**Windows (MinGW):**
```bash
gcc calculadora.c -o calculadora.exe
```

## Como usar

1. Execute o programa
2. Insira o primeiro e o segundo número
3. Escolha a operação no menu
4. O resultado aparece na tela e é salvo em `Historico.txt`
5. Escolha se deseja calcular novamente

## Aprendizados

- Funções em C
- Entrada e saída com `scanf` e `printf`
- Estrutura `switch/case`
- Loop `do/while`
- Leitura e escrita de arquivos com `FILE`
- Biblioteca `math.h`
