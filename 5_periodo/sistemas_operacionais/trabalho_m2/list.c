#include "list.h"

// Insere no início da lista (simplificado)
void insert(Node **head, Task *newTask) {
    Node *newNode = malloc(sizeof(Node));
    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

// Deleta o nó que contém a tarefa
void delete(Node **head, Task *task) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->task != task) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // não encontrado

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Percorre a lista imprimindo as tarefas
void traverse(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("Task %s with priority %d\n", temp->task->name, temp->task->priority);
        temp = temp->next;
    }
}

// Insere no final da lista (fila FIFO)
void append(Node **head, Task *newTask) {
    Node *newNode = malloc(sizeof(Node));
    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
