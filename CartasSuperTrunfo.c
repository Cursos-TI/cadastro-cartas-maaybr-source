# super_trunfo_final.c

#include <stdio.h>
#include <string.h>

/*
 * Super Trunfo - Desafio Final
 * Comparações Avançadas com Atributos Múltiplos
 *
 * Arquivo: super_trunfo_final.c
 * Descrição: Programa em C que permite cadastrar duas cartas (cidades/países),
 * calcular propriedades derivadas (densidade populacional, PIB per capita),
 * e comparar as cartas com base em dois atributos distintos escolhidos pelo jogador.
 * Regras especiais:
 *  - Para Densidade Populacional (atributo 5), vence o menor valor.
 *  - Para os demais atributos, vence o maior valor.
 *  - Se a soma dos dois atributos for igual para ambas as cartas, declara-se Empate.
 *
 * Observações:
 *  - Entrada robusta mínima: o programa verifica se os atributos escolhidos são válidos
 *    e diferentes entre si.
 *  - O código está comentado para facilitar manutenção e entendimento.
 */

typedef struct {
    char codigo[4];             // código da carta (ex: A01)
    char nomeEstado[50];        // nome do estado
    char nomeCidade[50];        // nome da cidade
    long int populacao;         // população (inteiro grande)
    float area;                 // área em km²
    double pib;                 // pib em bilhões
    int pontosTuristicos;       // número de pontos turísticos
    double densidadePopulacional; // densidade calculada (hab/km²)
    double pibPerCapita;        // pib per capita (valor monetário)
} Carta;

/* Calcula propriedades derivadas que dependem de entradas do usuário */
void calcularPropriedades(Carta *c) {
    if (c->area <= 0) { // evita divisão por zero
        c->densidadePopulacional = 0.0;
    } else {
        c->densidadePopulacional = c->populacao / c->area;
    }

    if (c->populacao <= 0) {
        c->pibPerCapita = 0.0;
    } else {
        /*
         * PIB foi inserido em "bilhões" (por exemplo: 68.2 significa 68.2 bilhões).
         * Convertemos para unidades monetárias inteiras (por exemplo, reais) multiplicando por 1e9
         * antes de dividir pela população.
         */
        c->pibPerCapita = (c->pib * 1000000000.0) / c->populacao;
    }
}

/* Exibe todos os campos de uma carta de forma organizada */
void exibirCarta(const Carta *c) {
    printf("\nCódigo: %s\n", c->codigo);
    printf("Estado: %s\n", c->nomeEstado);
    printf("Cidade: %s\n", c->nomeCidade);
    printf("População: %ld habitantes\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2lf bilhões\n", c->pib);
    printf("Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c->densidadePopulacional);
    printf("PIB per Capita: R$ %.2lf\n", c->pibPerCapita);
}

/* Retorna o valor numérico correspondente ao atributo escolhido */
double obterValorAtributo(const Carta *c, int atributo) {
    switch (atributo) {
        case 1: return (double)c->populacao;
        case 2: return (double)c->area;
        case 3: return c->pib;
        case 4: return (double)c->pontosTuristicos;
        case 5: return c->densidadePopulacional; // regra invertida: menor vence
        case 6: return c->pibPerCapita;
        default: return 0.0;
    }
}

/* Nome textual do atributo, para exibição no menu e resultados */
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

/* Exibe o menu de atributos, ignorando a opção passada em 'ignorar' (use 0 para não ignorar nenhuma) */
void exibirMenuAtributos(int ignorar) {
    printf("\nEscolha um atributo para comparar:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Populacional (vence menor)\n");
    if (ignorar != 6) printf("6 - PIB per Capita\n");
}

int main() {
    Carta c1, c2;
    int atributo1 = 0, atributo2 = 0;
    double v1a, v2a, v1b, v2b; // valores dos atributos para cada carta
    double soma1, soma2;

    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n");

    /* Cadastro da primeira carta (entrada interativa) */
    printf("\n--- CADASTRO DA CARTA 1 ---\n");
    printf("Código (ex: A01): "); scanf("%3s", c1.codigo);
    printf("Estado: "); scanf(" %[^
]", c1.nomeEstado);
    printf("Cidade: "); scanf(" %[^
]", c1.nomeCidade);
    printf("População: "); scanf("%ld", &c1.populacao);
    printf("Área (km²): "); scanf("%f", &c1.area);
    printf("PIB (em bilhões): "); scanf("%lf", &c1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c1.pontosTuristicos);

    /* Cadastro da segunda carta (entrada interativa) */
    printf("\n--- CADASTRO DA CARTA 2 ---\n");
    printf("Código (ex: B02): "); scanf("%3s", c2.codigo);
    printf("Estado: "); scanf(" %[^
]", c2.nomeEstado);
    printf("Cidade: "); scanf(" %[^
]", c2.nomeCidade);
    printf("População: "); scanf("%ld", &c2.populacao);
    printf("Área (km²): "); scanf("%f", &c2.area);
    printf("PIB (em bilhões): "); scanf("%lf", &c2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c2.pontosTuristicos);

    /* Calcula propriedades derivadas após o cadastro */
    calcularPropriedades(&c1);
    calcularPropriedades(&c2);

    /* Mostra as cartas para o usuário conferir */
    printf("\n===== CARTA 1 =====");
    exibirCarta(&c1);
    printf("\n===== CARTA 2 =====");
    exibirCarta(&c2);

    /* Escolha do primeiro atributo (validação de entrada) */
    do {
        exibirMenuAtributos(0);
        printf("Digite o número do PRIMEIRO atributo (1-6): ");
        if (scanf("%d", &atributo1) != 1) {
            /* limpa entrada inválida */
            int ch; while ((ch = getchar()) != '\n' && ch != EOF);
            atributo1 = 0;
        }
        if (atributo1 < 1 || atributo1 > 6) printf("⚠️ Opção inválida! Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 6);

    /* Escolha do segundo atributo (deve ser diferente do primeiro) */
    do {
        exibirMenuAtributos(atributo1); // menu dinâmico: não mostra o atributo já escolhido
        printf("Digite o número do SEGUNDO atributo (1-6, diferente do primeiro): ");
        if (scanf("%d", &atributo2) != 1) {
            int ch; while ((ch = getchar()) != '\n' && ch != EOF);
            atributo2 = 0;
        }
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1)
            printf("⚠️ Opção inválida ou repetida! Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);

    /* Obtém os valores numéricos dos atributos escolhidos para ambas as cartas */
    v1a = obterValorAtributo(&c1, atributo1);
    v2a = obterValorAtributo(&c2, atributo1);
    v1b = obterValorAtributo(&c1, atributo2);
    v2b = obterValorAtributo(&c2, atributo2);

    /* Soma dos atributos para determinar o vencedor final */
    soma1 = v1a + v1b;
    soma2 = v2a + v2b;

    /* Exibição organizada dos resultados */
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributos escolhidos: %d - %s ; %d - %s\n", atributo1, nomeAtributo(atributo1), atributo2, nomeAtributo(atributo2));

    printf("\n%-30s | %-18s | %-18s\n", "Atributo", c1.nomeCidade, c2.nomeCidade);
    printf("--------------------------------------------------------------------------------\n");
    printf("%-30s | %-18.2lf | %-18.2lf\n", nomeAtributo(atributo1), v1a, v2a);
    printf("%-30s | %-18.2lf | %-18.2lf\n", nomeAtributo(atributo2), v1b, v2b);

    /* Determina o vencedor por atributo (considera regra especial para densidade) */
    int vencedorA1, vencedorA2; // 1 -> carta1 vence ; 2 -> carta2 vence ; 0 -> empate
    if (atributo1 == 5) { // densidade: menor vence
        vencedorA1 = (v1a < v2a) ? 1 : (v2a < v1a ? 2 : 0);
    } else {
        vencedorA1 = (v1a > v2a) ? 1 : (v2a > v1a ? 2 : 0);
    }

    if (atributo2 == 5) {
        vencedorA2 = (v1b < v2b) ? 1 : (v2b < v1b ? 2 : 0);
    } else {
        vencedorA2 = (v1b > v2b) ? 1 : (v2b > v1b ? 2 : 0);
    }

    printf("\nVencedor no atributo '%s': %s\n", nomeAtributo(atributo1),
           vencedorA1 == 1 ? c1.nomeCidade : (vencedorA1 == 2 ? c2.nomeCidade : "Empate"));
    printf("Vencedor no atributo '%s': %s\n", nomeAtributo(atributo2),
           vencedorA2 == 1 ? c1.nomeCidade : (vencedorA2 == 2 ? c2.nomeCidade : "Empate"));

    /* Exibe as somas e decide o vencedor final (ou empate) */
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2lf\n", c1.nomeCidade, soma1);
    printf("%s: %.2lf\n", c2.nomeCidade, soma2);

    printf("\n===== VENCEDOR FINAL =====\n");
    (soma1 > soma2) ? printf("🏆 %s venceu a rodada!\n", c1.nomeCidade) :
    (soma2 > soma1) ? printf("🏆 %s venceu a rodada!\n", c2.nomeCidade) :
                      printf("🤝 Empate!\n");

    printf("=====================================\n");

    return 0;
}


