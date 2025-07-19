#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"

// Escolha apenas UM para testar de cada vez
#include "schedule_rr_p.h"
// #include "schedule_edf.h"
// #include "schedule_rr.h" // se for criar esse depois

#define SIZE 100

int main(int argc, char *argv[]) {
    FILE *in;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    int deadline;

    if (argc < 2) {
        printf("Uso: %s arquivo_de_tarefas.txt\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (!in) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(task, SIZE, in) != NULL) {
        char *temp = strdup(task);
        char *token;

        // nome
        token = strtok(temp, ",");
        if (token == NULL) {
            free(temp);
            continue;
        }
        name = token;

        // prioridade
        token = strtok(NULL, ",");
        if (token == NULL) {
            free(temp);
            continue;
        }
        priority = atoi(token);

        // burst
        token = strtok(NULL, ",");
        if (token == NULL) {
            free(temp);
            continue;
        }
        burst = atoi(token);

        // deadline (opcional)
        token = strtok(NULL, ",");
        if (token != NULL)
            deadline = atoi(token);
        else
            deadline = 0; // ou valor padrão

        // Passa uma cópia do nome para o add
        add(strdup(name), priority, burst); // Para RR e RR-P
        printf("Tarefa adicionada: %s, prioridade %d, burst %d\n", name, priority, burst);
        free(temp);
    }

    fclose(in);

    // chama o escalonador
    schedule();

    return 0;
}
