#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      
    int top;       
    int Maxsize;   
} Stack;

void initStack(Stack* stack, int size);
void pushStack(Stack* stack, int number);
int popStack(Stack* stack);
int findMin(Stack* stack);
void display(Stack* stack);
void freeStack(Stack* stack);