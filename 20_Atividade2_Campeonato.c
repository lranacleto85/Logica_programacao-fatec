//DESAFIO 2
//CAMPEONATO DE FUTEBOL
//Criar um Algoritmo onde podemos calcular os pontos de um Cmapeonato de Futebol.
//Serão dois times, os quais poderemos inserir os nomes.
//Os jogos serão 2 vetores onde terão 3 jogos do Time A contra o Time B. POr exemplo Vetor A0 e B0 serão o jogo 1, onde os mesmos poderão inserir os resultados.
//Assim como os vetores A1 e B1; e A2 e B2;
//Criar um vetor A (0,1,2) e Vetor B (0,1,2)
//Temos 2 times (A e B) que jogaram 3 vezes, neste caso são os vetores 0, um jogo, 1 é o segundo jogo e 2 é o terceiro jogo.
//Fazer um código no qual calcule os pontos finais apoós os jogos, onde vitória vale 3 pontos, empate 1 ponto e derrot 0 pontos.


#include <stdbool.h>
#include <stdio.h>

#define NUM_JOGOS 3
#define VITORIA 3
#define EMPATE 1
#define DERROTA 0
//Inserir dados dos times
int main() {
    char nomeTimeA[100], nomeTimeB[100];
    int pontosTimeA = 0, pontosTimeB = 0;

    printf("Digite o nome do Time A: ");
    scanf("%s", nomeTimeA);

    printf("Digite o nome do Time B: ");
    scanf("%s", nomeTimeB);

    int resultadosTimeA[NUM_JOGOS];
    int resultadosTimeB[NUM_JOGOS];

    // Entrada dos resultados dos jogos
    for (int i = 0; i < NUM_JOGOS; i++) {
        printf("Digite o resultado do jogo %d (Time A vs Time B) separando por espaço: ", i + 1);
        scanf("%d %d", &resultadosTimeA[i], &resultadosTimeB[i]);

        if (resultadosTimeA[i] > resultadosTimeB[i])
            pontosTimeA += VITORIA;
        else if (resultadosTimeA[i] < resultadosTimeB[i])
            pontosTimeB += VITORIA;
        else
        {
            pontosTimeA += EMPATE;
            pontosTimeB += EMPATE;
        }
    }

    // Exibição dos resultados
    printf("\nResultados dos jogos:\n");
    for (int i = 0; i < NUM_JOGOS; i++) {
        printf("Jogo %d: %s %d x %d %s\n", i + 1, nomeTimeA, resultadosTimeA[i], resultadosTimeB[i], nomeTimeB);
    }

    // Exibição dos pontos finais
    printf("\nPontos finais:\n");
    printf("%s: %d pontos\n", nomeTimeA, pontosTimeA);
    printf("%s: %d pontos\n", nomeTimeB, pontosTimeB);

    return 0;
}
