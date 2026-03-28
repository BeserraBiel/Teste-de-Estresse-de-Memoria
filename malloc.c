#include <stdio.h>
#include <stdlib.h>

int main() {
    long long total_alocado = 0;

    printf("Iniciando teste de stress de memoria...\n");
    printf("Pressione Ctrl+C para parar a qualquer momento.\n\n");

    while(1) {
        int *ptr = (int *) malloc(1024 * 1024) ;

        if (ptr == NULL) {
            printf("\n[ERRO] A memoria RAM acabou! O sistema nao permite mais alocacoes.\n");
            break;
        }
        
        for (int i = 0; i < (1024 * 1024) / sizeof(int); i++  )
            ptr[i] = 0;
        
        total_alocado++;
        printf("Memoria alocada: %lld MB\r", total_alocado);
        fflush(stdout);
    }

    return 0;
}