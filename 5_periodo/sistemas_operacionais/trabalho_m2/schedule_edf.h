#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"
#include "CPU.h"

struct node *taskList = NULL;

void add(char *name, int priority, int burst, int deadline) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->deadline = deadline;

    insert(&taskList, newTask);
}

void schedule() {
    struct node *temp;

    while (taskList != NULL) {
        temp = taskList;
        struct node *earliest = temp;

        // seleciona a task com menor deadline
        while (temp != NULL) {
            if (temp->task->deadline < earliest->task->deadline) {
                earliest = temp;
            }
            temp = temp->next;
        }

        run(earliest->task, earliest->task->burst);
        delete(&taskList, earliest->task);
    }
}
