#include <stdio.h>
#include <string.h>

typedef struct
{
    char state;
    char code[5];
    char name[50];
    unsigned int population;
    float area;
    float pib;
    int sights;
    float populationDensity;  // Será calculado durante a criação
    float pibCapita;          // Será calculado durante a criação
    float points;             // Para acumular pontos das comparações
} City;

City createCity() {
    City newCity;

    printf("Insira o estado da cidade: \n");
    scanf(" %c", &newCity.state);  // Note o espaço antes de %c - pular possiveis espaços em branco!
    
    printf("Insira o código da cidade: \n");
    scanf("%s", newCity.code);
    getchar(); // Limpar buffer
    
    printf("Insira o nome da cidade: \n");
    fgets(newCity.name, 49, stdin);
    newCity.name[strcspn(newCity.name, "\n")] = 0; // Remove quebra de linha
    
    printf("Quantas pessoas vivem nessa cidade: \n");
    scanf("%u", &newCity.population);
    
    printf("Qual a área aproximada dessa cidade em km²: \n");
    scanf("%f", &newCity.area);
    
    printf("Qual o valor aproximado do PIB dessa cidade: \n");
    scanf("%f", &newCity.pib);
    
    printf("Quantos pontos turísticos há nessa cidade: \n");
    scanf("%d", &newCity.sights);

    // Calculando os dados derivados
    newCity.populationDensity = (float)newCity.population / newCity.area;
    newCity.pibCapita = newCity.pib / newCity.population;
    newCity.points = 0.0; // Inicializar pontos com zero

    return newCity;
}

// Fazendo uso do asterisco e de ponteiros para acessar os dados via referência
// Caso contrário, a lógica de pontuação não funcionará devidamente
// Pois a função trabalhará em cima de uma cópia dos dados
void comparingCities(City *firstCity, City *secondCity, int attribute) {
    printf("\n=== COMPARAÇÃO ===\n");
    printf("%s VS %s\n", firstCity->name, secondCity->name);

    switch (attribute)
    {
    case 1: // População
        printf("Atributo - População!\n");

        if (firstCity->population > secondCity->population) {
            printf("A cidade %s ganhou!\n", firstCity->name);
            printf("A cidade %s possui um número maior de habitantes do que a cidade %s. %u VS %u\n", 
                   firstCity->name, secondCity->name, firstCity->population, secondCity->population);
        } else if(firstCity->population < secondCity->population) {
            printf("A cidade %s ganhou!\n", secondCity->name);
            printf("A cidade %s possui um número maior de habitantes do que a cidade %s. %u VS %u\n", 
                   secondCity->name, firstCity->name, secondCity->population, firstCity->population);
        } else {
            printf("EMPATE!!!\n");
        }

        firstCity->points += firstCity->population;
        secondCity->points += secondCity->population;

        break;
    case 2: // Area
        printf("Atributo - Área!\n");

        if (firstCity->area > secondCity->area) {
            printf("A cidade %s ganhou!\n", firstCity->name);
            printf("A cidade %s possui uma área maior do que a cidade %s. %.2f km² VS %.2f km²\n", 
                   firstCity->name, secondCity->name, firstCity->area, secondCity->area);
        } else if(firstCity->area < secondCity->area) {
            printf("A cidade %s ganhou!\n", secondCity->name);
            printf("A cidade %s possui uma área maior do que a cidade %s. %.2f km² VS %.2f km²\n", 
                   secondCity->name, firstCity->name, secondCity->area, firstCity->area);
        } else {
            printf("EMPATE!!!\n");
        }

        firstCity->points += firstCity->area;
        secondCity->points += secondCity->area;

        break;
    case 3: // PIB
        printf("Atributo - PIB!\n");

        if (firstCity->pib > secondCity->pib) {
            printf("A cidade %s ganhou!\n", firstCity->name);
            printf("A cidade %s possui um PIB maior do que a cidade %s. %.2f VS %.2f\n", 
                   firstCity->name, secondCity->name, firstCity->pib, secondCity->pib);
        } else if(firstCity->pib < secondCity->pib) {
            printf("A cidade %s ganhou!\n", secondCity->name);
            printf("A cidade %s possui um PIB maior do que a cidade %s. %.2f VS %.2f\n", 
                   secondCity->name, firstCity->name, secondCity->pib, firstCity->pib);
        } else {
            printf("EMPATE!!!\n");
        }

        firstCity->points += firstCity->pib;
        secondCity->points += secondCity->pib;

        break;
    case 4: // Pontos Turisticos
        printf("Atributo - Pontos Turísticos!\n");

        if (firstCity->sights > secondCity->sights) {
            printf("A cidade %s ganhou!\n", firstCity->name);
            printf("A cidade %s possui mais pontos turísticos do que a cidade %s. %d VS %d\n", 
                   firstCity->name, secondCity->name, firstCity->sights, secondCity->sights);
        } else if(firstCity->sights < secondCity->sights) {
            printf("A cidade %s ganhou!\n", secondCity->name);
            printf("A cidade %s possui mais pontos turísticos do que a cidade %s. %d VS %d\n", 
                   secondCity->name, firstCity->name, secondCity->sights, firstCity->sights);
        } else {
            printf("EMPATE!!!\n");
        }

        firstCity->points += firstCity->sights;
        secondCity->points += secondCity->sights;

        break;
    case 5: // Densidade Populacional - Menor ganha!
        printf("Atributo - Densidade Populacional!\n");

        if (firstCity->populationDensity < secondCity->populationDensity) {
            printf("A cidade %s ganhou!\n", firstCity->name);
            printf("A cidade %s possui menor densidade populacional do que a cidade %s. %.2f hab/km² VS %.2f hab/km²\n", 
                   firstCity->name, secondCity->name, firstCity->populationDensity, secondCity->populationDensity);
        } else if(firstCity->populationDensity > secondCity->populationDensity) {
            printf("A cidade %s ganhou!\n", secondCity->name);
            printf("A cidade %s possui menor densidade populacional do que a cidade %s. %.2f hab/km² VS %.2f hab/km²\n", 
                   secondCity->name, firstCity->name, secondCity->populationDensity, firstCity->populationDensity);
        } else {
            printf("EMPATE!!!\n");
        }

        // Para densidade, pontuamos o inverso (menor valor = mais pontos)
        firstCity->points += (1.0 / firstCity->populationDensity) * 1000; 
        secondCity->points += (1.0 / secondCity->populationDensity) * 1000;

        break;
    default:
        printf("Opção inválida, execute novamente o programa!\n");
        break;
    }
}

int main() {
    City firstCity = createCity();
    City secondCity = createCity();
    int attribute1, attribute2;

    // Menu de atributos
    printf("=== SUPER TRUNFO - CIDADES ===\n");
    printf("Atributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");

    printf("\nEscolha o primeiro atributo: ");
    scanf("%d", &attribute1);
    
    printf("Escolha o segundo atributo: ");
    scanf("%d", &attribute2);

    if (attribute1 == attribute2) {
        printf("Erro ao comparar, você deve escolher atributos diferentes!\n");
        return 1;
    }

    // Fazendo as comparações
    printf("\n=== PRIMEIRA COMPARAÇÃO ===\n");
    comparingCities(&firstCity, &secondCity, attribute1);
    
    printf("\n=== SEGUNDA COMPARAÇÃO ===\n");
    comparingCities(&firstCity, &secondCity, attribute2);

    // Comparação Final - Somatório!
    printf("\n=== COMPARAÇÃO FINAL - SOMATORIA DE PONTOS ===\n");
    printf("=== %s com um total de %.2f pontos === VS === %s com um total de %.2f pontos ===\n", 
           firstCity.name, firstCity.points, secondCity.name, secondCity.points);
    
    if (firstCity.points > secondCity.points) {
        printf("%s venceu o Super Trunfo!\n", firstCity.name);
    } else if (firstCity.points < secondCity.points) {
        printf("%s venceu o Super Trunfo!\n", secondCity.name);
    } else {
        printf("EMPATE TOTAL! Ambas as cidades têm %.2f pontos!\n", firstCity.points);
    }

    return 0;
}
