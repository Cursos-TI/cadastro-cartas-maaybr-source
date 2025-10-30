
# README.md

````
# Super Trunfo - Desafio Final (C)

Este repositório contém o programa "Super Trunfo" escrito em C, que implementa o Desafio Final: Comparações Avançadas com Atributos Múltiplos.

## Arquivos
- `super_trunfo_final.c` : Código-fonte em C com comentários e instruções.

## Requisitos
- Compilador C (gcc, clang ou equivalente)
- Sistema operacional com terminal (Linux, macOS, Windows com MinGW/Cygwin ou WSL)

## Como compilar
No terminal, execute:

```bash
gcc -o super_trunfo super_trunfo_final.c
````

Isso criará um executável chamado `super_trunfo`.

Em Windows (MinGW) você pode gerar `super_trunfo.exe` com o mesmo comando.

## Como executar

No terminal, execute:

```bash
./super_trunfo
```

No Windows (cmd/PowerShell):

```powershell
super_trunfo.exe
```

## Uso (exemplo de fluxo)

1. O programa pede o cadastro da **Carta 1** (código, estado, cidade, população, área, PIB em bilhões, pontos turísticos).
2. O programa pede o cadastro da **Carta 2**.
3. O programa exibe as informações calculadas (densidade populacional e PIB per capita) para ambas as cartas.
4. Você escolhe **DOIS atributos diferentes** para comparação (o segundo menu não mostrará a opção já escolhida):

   * 1 - População
   * 2 - Área
   * 3 - PIB
   * 4 - Pontos Turísticos
   * 5 - Densidade Populacional (vence o menor)
   * 6 - PIB per Capita
5. O programa exibe os valores de cada atributo para cada carta, informa o vencedor de cada atributo e soma os dois atributos para determinar o vencedor final.

## Regras de comparação

* Para **Densidade Populacional** (opção 5) vence o **menor** valor.
* Para os demais atributos vence o **maior** valor.
* Se a soma dos dois atributos for igual entre as cartas, o programa declara **Empate**.

## Exemplos

Supondo duas cartas cadastradas: Campinas (Carta A01) e Belo Horizonte (Carta B02).

Exemplo de seleção:

* Primeiro atributo: 3 (PIB)
* Segundo atributo: 5 (Densidade Populacional)

O programa exibirá uma tabela com os valores de PIB e densidade para ambas as cidades, dirá quem venceu em cada atributo e então mostrará a soma dos valores para decidir o vencedor final.




