//DESAFIO 1
//CORRIDA DE MOTOS
//Criar um Algoritmo em C onde o usuário possa inserir a quantidade de motociclitas participantes da corrida, depois inserir os nomes dos motociclitas..
//Cada motociclista terá direito a 3 voltas, o usuário deverá inserir o tempo de cada volta de cada motociclista.
//O Objetivo final é classificar os Motociclistas através do descarte do pior tempo e calculando a média dos outros dois valores e classificar os motociclitas de acordo com o menor tempo

#include <stdio.h>
#include <stdlib.h>
// Cria uma STRUCT para armazenar os dados dos pilotos
typedef struct {
    char nome[100];
    float tempos[3];
    float tempoMedio;
} Motociclista;

int main() {
    int quantidadeMotociclistas;
    printf("Informe a quantidade de motociclistas: ");
    scanf("%d", &quantidadeMotociclistas);

    Motociclista *motociclistas = (Motociclista *)malloc(quantidadeMotociclistas * sizeof(Motociclista)); // Alocação dos dados na memória Malloc

    // Entrada de Nome e Tempo de cada volta de cada motociclista
    for (int i = 0; i < quantidadeMotociclistas; i++) {
        printf("Informe o nome do motociclista %d: ", i + 1);
        scanf("%s", motociclistas[i].nome);
        
        printf("Informe os tempos de volta (em segundos) para o motociclista %d (3 voltas): ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Volta %d: ", j + 1);
            scanf("%f", &motociclistas[i].tempos[j]);
        }
    }

    // Calcular tempo médio e classificar os motociclistas
    for (int i = 0; i < quantidadeMotociclistas; i++) {
        float piorTempo = motociclistas[i].tempos[0];
        float somaTempos = 0.0;

        for (int j = 0; j < 3; j++) {
            if (motociclistas[i].tempos[j] < piorTempo)
                piorTempo = motociclistas[i].tempos[j];

            somaTempos += motociclistas[i].tempos[j];
        }

        motociclistas[i].tempoMedio = (somaTempos - piorTempo) / 2.0;
    }

    // Ordenar os motociclistas de acordo com o tempo médio
    for (int i = 0; i < quantidadeMotociclistas - 1; i++) {
        for (int j = i + 1; j < quantidadeMotociclistas; j++) {
            if (motociclistas[i].tempoMedio > motociclistas[j].tempoMedio) {
                Motociclista temp = motociclistas[i];
                motociclistas[i] = motociclistas[j];
                motociclistas[j] = temp;
            }
        }
    }

    // Exibir classificação
    printf("\nClassificacao dos motociclistas:\n");
    for (int i = 0; i < quantidadeMotociclistas; i++) {
        printf("%d. Motociclista: %s, Tempo Medio: %.2f segundos\n", i + 1, motociclistas[i].nome, motociclistas[i].tempoMedio);
    }

    // Liberar a memória alocada
    free(motociclistas);

    return EXIT_SUCCESS;
}

