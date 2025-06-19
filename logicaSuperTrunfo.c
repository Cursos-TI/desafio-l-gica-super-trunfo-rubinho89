#include <stdio.h>
#include <string.h>

float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

int main() {
    // Carta 1
    int populacao1, pontosTuristicos1;
    float area1, pib1, densidade1, pibPerCapita1;
    char nome1[50], estado1[3], codigo1[10];

    // Carta 2
    int populacao2, pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2;
    char nome2[50], estado2[3], codigo2[10];

    // Entrada da Carta 1
    printf("=== CADASTRO DA CARTA 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado1);
    printf("Nome da cidade: ");
    scanf("%s", nome1);
    printf("Código: ");
    scanf("%s", codigo1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área em km²: ");
    scanf("%f", &area1);
    printf("PIB (em milhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = calcularPIBPerCapita(pib1, populacao1);

    // Entrada da Carta 2
    printf("\n=== CADASTRO DA CARTA 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado2);
    printf("Nome da cidade: ");
    scanf("%s", nome2);
    printf("Código: ");
    scanf("%s", codigo2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área em km²: ");
    scanf("%f", &area2);
    printf("PIB (em milhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = calcularPIBPerCapita(pib2, populacao2);

    // Escolha dos atributos
    int atributo1, atributo2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    char nomeAtributo1[30], nomeAtributo2[30];

    // Menu para o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("6 - Pontos Turísticos\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; strcpy(nomeAtributo1, "População"); break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; strcpy(nomeAtributo1, "Área"); break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; strcpy(nomeAtributo1, "PIB"); break;
        case 4: valor1_c1 = densidade1; valor1_c2 = densidade2; strcpy(nomeAtributo1, "Densidade Populacional"); break;
        case 5: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; strcpy(nomeAtributo1, "PIB per capita"); break;
        case 6: valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; strcpy(nomeAtributo1, "Pontos Turísticos"); break;
        default: printf("Opção inválida!\n"); return 1;
    }

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1)
            printf("%d - %s\n", i,
                i == 1 ? "População" :
                i == 2 ? "Área" :
                i == 3 ? "PIB" :
                i == 4 ? "Densidade Populacional" :
                i == 5 ? "PIB per capita" :
                         "Pontos Turísticos");
    }
    printf("Opção: ");
    scanf("%d", &atributo2);
    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 6) {
        printf("Segunda opção inválida!\n");
        return 1;
    }

    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; strcpy(nomeAtributo2, "População"); break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; strcpy(nomeAtributo2, "Área"); break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; strcpy(nomeAtributo2, "PIB"); break;
        case 4: valor2_c1 = densidade1; valor2_c2 = densidade2; strcpy(nomeAtributo2, "Densidade Populacional"); break;
        case 5: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; strcpy(nomeAtributo2, "PIB per capita"); break;
        case 6: valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; strcpy(nomeAtributo2, "Pontos Turísticos"); break;
    }

    // Comparação individual
    int pontos1 = 0, pontos2 = 0;

    printf("\n====== COMPARAÇÃO ======\n");
    printf("%s: %s = %.2f | %s = %.2f\n", nomeAtributo1, nome1, valor1_c1, nome2, valor1_c2);
    if (atributo1 == 4) { // densidade: menor vence
        if (valor1_c1 < valor1_c2) pontos1++;
        else if (valor1_c2 < valor1_c1) pontos2++;
    } else {
        if (valor1_c1 > valor1_c2) pontos1++;
        else if (valor1_c2 > valor1_c1) pontos2++;
    }

    printf("%s: %s = %.2f | %s = %.2f\n", nomeAtributo2, nome1, valor2_c1, nome2, valor2_c2);
    if (atributo2 == 4) { // densidade: menor vence
        if (valor2_c1 < valor2_c2) pontos1++;
        else if (valor2_c2 < valor2_c1) pontos2++;
    } else {
        if (valor2_c1 > valor2_c2) pontos1++;
        else if (valor2_c2 > valor2_c1) pontos2++;
    }

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n", nome2, soma2);

    // Resultado final
    printf("\n====== RESULTADO FINAL ======\n");
    if (soma1 > soma2)
        printf("Vencedor: %s\n", nome1);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", nome2);
    else
        printf("Empate!\n");

    return 0;
}

