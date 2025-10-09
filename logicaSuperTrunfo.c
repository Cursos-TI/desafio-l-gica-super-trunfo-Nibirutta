#include <stdio.h>
#include <string.h>

int main() {
    // Variaveis de utilidade
    int userOption;

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

    // Fazendo a comparação

    // Menu interativo
    printf("Atributos comparaveis:\n");
    printf("1 - População\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha o atributo que você deseja comparar.\n");
    scanf("%d", &userOption);

    printf("%s VS %s\n", city_1, city_2);

    // Aplicando o switch para a escolha de caminhos alternativos de acordo com o atributo
    switch (userOption)
    {
    case 1:
        printf("Atributo - População\n");
        printf("%s possui %d pessoas.\n", city_1, populationAmount_1);
        printf("%s possui %d pessoas.\n", city_2, populationAmount_2);

        if (populationAmount_1 > populationAmount_2) {
            printf("Primeira cidade venceu! (%s)", city_1);
        } else if (populationAmount_1 < populationAmount_2) {
            printf("Segunda cidade venceu! (%s)", city_2);
        } else {
            printf("Empate!");
        }

        break;
    case 2:
        printf("Atributo - Area\n");
        printf("%s possui uma area de %.2f.\n", city_1, area_1);
        printf("%s possui uma area de %.2f.\n", city_2, area_2);

        if (area_1 > area_2) {
            printf("Primeira cidade venceu! (%s)", city_1);
        } else if (area_1 < area_2) {
            printf("Segunda cidade venceu! (%s)", city_2);
        } else {
            printf("Empate!");
        }

        break;
    case 3:
        printf("Atributo - PIB\n");
        printf("%s possui um PIB de %.2f.\n", city_1, pib_1);
        printf("%s possui um PIB de %.2f.\n", city_2, pib_2);

        if (pib_1 > pib_2) {
            printf("Primeira cidade venceu! (%s)", city_1);
        } else if (pib_1 < pib_2) {
            printf("Segunda cidade venceu! (%s)", city_2);
        } else {
            printf("Empate!");
        }

        break;
    case 4:
        printf("Atributo - Pontos Turisticos\n");
        printf("%s tem um total de %d pontos turisticos.\n", city_1, sights_1);
        printf("%s tem um total de %d pontos turisticos.\n", city_2, sights_2);

        if (sights_1 > sights_2) {
            printf("Primeira cidade venceu! (%s)", city_1);
        } else if (sights_1 < sights_2) {
            printf("Segunda cidade venceu! (%s)", city_2);
        } else {
            printf("Empate!");
        }

        break;
    case 5:
        printf("Atributo - Densidade Populacional\n");
        printf("%s tem uma densidade populacional de %.2f habitantes.\n", city_1, populationDensity_1);
        printf("%s tem uma densidade populacional de %.2f habitantes.\n", city_2, populationDensity_2);

        if (populationDensity_1 > populationDensity_2) {
            printf("Segunda cidade venceu! (%s)", city_2);
        } else if (populationDensity_1 < populationDensity_2) {
            printf("Primeira cidade venceu! (%s)", city_1);
        } else {
            printf("Empate!");
        }

        break;
    default:
        printf("Opção inválida");
        break;
    }

    return 0;
}
