#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"
#include "CPU.h"

struct node *taskList = NULL;

void add(char *name, int priority, int burst) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->deadline = 0;

    insert(&taskList, newTask);
}

void schedule() {
    struct node *curr;

    while (taskList != NULL) {
        curr = taskList;

        while (curr != NULL) {
            Task *t = curr->task;
            int slice = (t->burst > QUANTUM) ? QUANTUM : t->burst;
            run(t, slice);
            t->burst -= slice;

            if (t->burst <= 0) {
                struct node *next = curr->next;
                delete(&taskList, t);
                curr = next;
            } else {
                curr = curr->next;
            }
        }
    }
}
