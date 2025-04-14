#include "Header.h"

void initStack(Stack* stack, int size) {
	stack->data = (int*)malloc(size * sizeof(int));
	if (stack->data == NULL) {
		printf("Memory allocation error");
		exit(1);
	}
	stack->top = -1;
	stack->Maxsize = size;
}

void pushStack(Stack* stack, int number) {
	if (stack->top == stack->Maxsize - 1) {
		printf("Stack overflow. Cannot add element %d", number);
		return;
	}
	stack->top++;
	stack->data[stack->top] = number;
	printf("element %d add in stack.\n", number);
}

int popStack(Stack* stack) {
	if (stack->top > 0) {
		int data = stack->data[stack->top];
		stack->top--;
		return data;
	}
	else {
		printf("Stack is empty");
		return;
	}
}

int findMin(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack is empty");
		return;
	}
	int min = stack->data[0];
	for (int i = 0; min <= stack->top; i++) {
		if (stack->data[i] < min) {
			min = stack->data[i];
		}
	}
	return min;
}

void display(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack is empty\n");
		return;
	}

	printf("Stack (top to bottom):\n");
	for (int i = stack->top; i >= 0; i--) {
		printf("%d\n", stack->data[i]);
	}
}

void freeStack(Stack* stack) {
	free(stack->data);
	stack->data = NULL;
	stack->top = -1;
	stack->Maxsize = 0;
}
