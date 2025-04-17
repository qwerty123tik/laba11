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
	for (int i = 0; i <= stack->top; i++) {
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



int peek(Stack* stack) {
	if (stack->top == -1) {
		return -1;
	}
	return stack->data[stack->top];
}

void pushPoYb(Stack* stack, int number) {
	if (stack->top >= 0 && number >= stack->data[stack->top]) {
		printf("orde should be po yb\n");
		return;
	}
	else pushStack(stack, number);
}

void pushPoVozr(Stack* stack, int number) {
	if (stack->top >= 0 && number <= stack->data[stack->top]) {
		printf("orde should be po vozr\n");
		return;
	}
	else pushStack(stack, number);
}

//void mergeStacks(Stack* stack1, Stack* stack2, Stack* stack3) {
//	while (stack1->top != -1 || stack2->top != -1) {
//		if (stack1->top == -1) { 
//			push(stack3, pop(stack2));
//		}
//		else if (stack2->top == -1) {
//			push(stack3, pop(stack1));
//		}
//		else {
//			int top1 = peek(stack1);
//			int top2 = peek(stack2);
//
//			if (top1 < top2) {
//				push(stack3, pop(stack1));
//			}
//			else {
//				push(stack3, pop(stack2));
//			}
//		}
//	}
//}

void Obedin(Stack* stack1, Stack* stack2, Stack* stack3) {
	Stack temp1, temp2;
	initStack(stack1, stack1->Maxsize);
	initStack(stack2, stack2->Maxsize);

	for (int i = 0; i <= stack1->top; i++) {
		pushStack(&temp1, stack1->data[i]);
	}
	for (int i = 0; i <= stack2->top; i++) {
		pushStack(&temp2, stack2->data[i]);
	}
	while ((temp1.top != -1) && (temp2.top != -1)) {
		if (peek(&temp1) < peek(&temp2)) {
			pushStack(stack3, popStack(&temp1));
		}
		else pushStack(stack3, popStack(&temp2));
	}
	while ((temp1.top != -1)) {
		pushStack(stack3, popStack(&temp1));
	}
	while ((temp2.top != -1)) {
		pushStack(stack3, popStack(&temp2));
	}

	freeStack(&temp1);
	freeStack(&temp2);
}