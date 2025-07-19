#ifndef CPU_H
#define CPU_H

#include "task.h"

#define QUANTUM 10 // tamanho do time slice

void run(Task *task, int slice);

#endif
