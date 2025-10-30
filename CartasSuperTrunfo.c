#include <stdio.h>

int main() {
    char codigo[4]; // Exemplo: A01
    char nomeCidade[50];
    char nomeEstado[50];
    long int populacao;
    float area;
    double pib;
    int pontosTuristicos;

    printf("===== CADASTRO DE CARTA - SUPER TRUNFO: PAISES =====\n\n");

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", codigo);

    printf("Digite o nome do Estado: ");
    scanf(" %[^\n]", nomeEstado); // lê até o fim da linha (inclui espaços)

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade);

    printf("Digite a População da cidade: ");
    scanf("%ld", &populacao);

    printf("Digite a Área da cidade (em km²): ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%lf", &pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos);

    printf("\n===== DADOS DA CARTA CADASTRADA =====\n");
    printf("Código: %s\n", codigo);
    printf("Estado: %s\n", nomeEstado);
    printf("Cidade: %s\n", nomeCidade);
    printf("População: %ld habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2lf bilhões\n", pib);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);
    printf("=====================================\n");

    return 0;
}
