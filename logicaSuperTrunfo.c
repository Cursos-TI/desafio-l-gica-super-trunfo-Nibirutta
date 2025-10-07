#include <stdio.h>
#include <string.h>

int main() {
    // Dados da primeira carta

    char state_1, code_1[5], city_1[50];
    int sights_1;
    float area_1, pib_1, pibCapita_1, populationDensity_1;
    unsigned int populationAmount_1;

    // Dados da segunda carta

    char state_2, code_2[5], city_2[50];
    int  sights_2;
    float area_2, pib_2, pibCapita_2, populationDensity_2;
    unsigned int populationAmount_2;

    // Leitura dos dados - Cidade 01

    printf("Insira o estado da cidade: \n");
    scanf("%c", &state_1);

    printf("Insira o código da cidade: \n");
    scanf("%s", code_1);
    getchar(); // Retira a quebra de linha do comando de leitura para que o próximo comando funcione corretamente, faça isso sempre que alternar entre leitura de chars, strings e numbers - float, int, double...

    printf("Insira o nome da cidade: \n");
    fgets(city_1, 49, stdin); // Faz a leitura do teclado(stdin), obecedendo o espaçamento e capturando todos os elementos corretamente
    city_1[strcspn(city_1, "\n")] = 0; // Apaga a quebra de linha gerada pelo fgets, substituindo pelo 0.

    printf("Quantas pessoas vivem nessa cidade: \n");
    scanf("%u", &populationAmount_1);

    printf("Qual a area aproximada dessa cidade em quilometros quadrados: \n");
    scanf("%f", &area_1);

    printf("Qual o valor aproximado do PIB dessa cidade: \n");
    scanf("%f", &pib_1);

    printf("Quantos pontos turísticos há nessa cidade: \n");
    scanf("%i", &sights_1);

    // Calculo dos dados complexos - Para não haver perda de dados em um calculo que envolve numeros inteiros e floats, recomenda-se o uso do casting explicito.
    populationDensity_1 = (float) populationAmount_1 / area_1; // Densidade Populacional

    pibCapita_1 = (float) pib_1 / populationAmount_1; // PIB per Capita

    getchar(); // Retira a quebra de linha do comando de leitura para que o próximo comando funcione corretamente, faça isso sempre que alternar entre leitura de chars, strings e numbers - float, int, double...

    // Leitura dos dados - Cidade 02

    printf("Insira o estado da cidade: \n");
    scanf("%c", &state_2);

    printf("Insira o código da cidade: \n");
    scanf("%s", code_2);
    getchar(); // Retira a quebra de linha do comando de leitura para que o próximo comando funcione corretamente, faça isso sempre que alternar entre leitura de chars, strings e numbers - float, int, double...

    printf("Insira o nome da cidade: \n");
    fgets(city_2, 49, stdin); // Faz a leitura do teclado(stdin), obecedendo o espaçamento e capturando todos os elementos corretamente
    city_2[strcspn(city_2, "\n")] = 0; // Apaga a quebra de linha gerada pelo fgets, substituindo pelo 0.

    printf("Quantas pessoas vivem nessa cidade: \n");
    scanf("%u", &populationAmount_2);

    printf("Qual a area aproximada dessa cidade em quilometros quadrados: \n");
    scanf("%f", &area_2);

    printf("Qual o valor aproximado do PIB dessa cidade: \n");
    scanf("%f", &pib_2);

    printf("Quantos pontos turísticos há nessa cidade: \n");
    scanf("%i", &sights_2);

    // Calculo dos dados complexos - Para não haver perda de dados em um calculo que envolve numeros inteiros e floats, recomenda-se o uso do casting explicito.
    populationDensity_2 = (float) populationAmount_2 / area_2; // Densidade Populacional

    pibCapita_2 = (float) pib_2 / populationAmount_2; // PIB per Capita

    // Fazendo a comparação - Atributo escolhido: Densidade Populacional

    printf("\nComparação das cartas (Atributo: Densidade Populacional - Menor Vence) \n\n");
    printf("Carta 1 - %s: %.2f \n", city_1, populationDensity_1);
    printf("Carta 2 - %s: %.2f \n", city_2, populationDensity_2);

    // Como o vencedor desse atributo o menor vence, fiz uso do sinal de comparação menor (<) e aproveitei a oportunidade para implementar o caso de empate
    if (populationDensity_1 < populationDensity_2) {
        printf("A cidade vencedora é %s", city_1);
    } else if (populationDensity_2 < populationDensity_1) {
        printf("A cidade vencedora é %s", city_2);
    } else {
        printf("Empate!");
    }

    return 0;
}
