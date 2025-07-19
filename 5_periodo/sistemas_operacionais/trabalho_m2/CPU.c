#include <stdio.h>
#include "CPU.h"

void run(Task *task, int quantum) {
    printf("Running task [%s] (TID %d) for %d units.\n", task->name, task->tid, quantum);
}
