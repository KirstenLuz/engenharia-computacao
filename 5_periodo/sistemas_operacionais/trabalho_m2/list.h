#ifndef LIST_H
#define LIST_H

#include "task.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    Task *task;
    struct node *next;
} Node;

void insert(Node **head, Task *newTask);
void delete(Node **head, Task *task);
void traverse(Node *head);
void append(Node **head, Task *newTask);

#endif
