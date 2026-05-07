#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MB (1024 * 1024)
#define MAX_BLOCOS 65536

static int **blocos = NULL;
static long long total_alocado = 0;

void liberar_tudo(int sig) {
    (void)sig;  // parâmetro exigido pela assinatura do signal(), mas não usado
    printf("\n\nLiberando %lld MB de memoria...\n", total_alocado);
    for (long long i = 0; i < total_alocado; i++)
        free(blocos[i]);
    free(blocos);
    exit(0);
}

int main() {
    blocos = malloc(MAX_BLOCOS * sizeof(int *));
    if (!blocos) {
        fprintf(stderr, "Falha ao alocar vetor de ponteiros.\n");
        return 1;
    }

    signal(SIGINT, liberar_tudo);

    printf("Iniciando teste de stress de memoria...\n");
    printf("Pressione Ctrl+C para parar a qualquer momento.\n\n");

    while (total_alocado < MAX_BLOCOS) {
        int *ptr = malloc(MB);

        if (!ptr) {
            printf("\n[ERRO] Memoria esgotada apos %lld MB.\n", total_alocado);
            break;
        }

        memset(ptr, 0, MB);

        blocos[total_alocado++] = ptr;
        printf("Memoria alocada: %lld MB\r", total_alocado);
        fflush(stdout);
    }

    liberar_tudo(0);
    return 0;
}