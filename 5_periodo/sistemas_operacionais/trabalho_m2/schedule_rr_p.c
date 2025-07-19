#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "CPU.h"
#include "schedule_rr_p.h"

#define MAX_PRIORITY 5  // número máximo de prioridades (1 é maior prioridade)

static Node *readyQueues[MAX_PRIORITY] = {NULL};  // filas para cada prioridade

static int tid_counter = 1;

// Insere a task na fila correta baseado na prioridade
void add(char *name, int priority, int burst) {
    if (priority < 1) priority = 1;
    if (priority > MAX_PRIORITY) priority = MAX_PRIORITY;

    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->deadline = 0; // não usado aqui
    newTask->tid = tid_counter++;

    // Insere no final da fila da prioridade correta para manter a ordem RR
    append(&readyQueues[priority - 1], newTask);
}

// Remove uma task da fila da prioridade (usa delete de list.c)
void removeTask(Node **head, Task *task) {
    delete(head, task);
}

void printQueues() {
    printf("Estado das filas:\n");
    for (int i = 0; i < MAX_PRIORITY; i++) {
        printf("Prioridade %d: ", i + 1);
        Node *cur = readyQueues[i];
        while (cur != NULL) {
            printf("[%s (burst=%d)] -> ", cur->task->name, cur->task->burst);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void schedule() {
    int done = 0;
    int timeSlice;

    while (!done) {
        printQueues();
        done = 1; // assume que terminou, prova o contrário

        // Percorre prioridades do mais alto (0) para o mais baixo (MAX_PRIORITY-1)
        for (int prio = 0; prio < MAX_PRIORITY; prio++) {
            if (readyQueues[prio] != NULL) {
                done = 0; // ainda tem tarefa a executar

                Node *temp = readyQueues[prio];
                Task *task = temp->task;

                timeSlice = (task->burst > QUANTUM) ? QUANTUM : task->burst;

                run(task, timeSlice);

                task->burst -= timeSlice;

                // Remove a tarefa do início da fila
                removeTask(&readyQueues[prio], task);

                if (task->burst > 0) {
                    // Se ainda tem burst, reinserir no final da fila da mesma prioridade
                    append(&readyQueues[prio], task);
                } else {
                    // Caso contrário, libera memória da task
                    free(task->name);
                    free(task);
                }

                break; // executa uma tarefa por ciclo
            }
        }
    }
}
