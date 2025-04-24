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
int popStack(Stack* stack, int* number);
int findMin(Stack* stack);
void display(Stack* stack);
void freeStack(Stack* stack);
void pushPoYb(Stack* stack, int number);
void pushPoVozr(Stack* stack, int number);
void mergeStacks(Stack* stack1, Stack* stack2, Stack* stack3);
void FindMinInStack();
void ObedinenieDwyxStacks();
int isEmpty(Stack* stack);
