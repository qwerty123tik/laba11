#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int Maxsize;
	int top;
	int *data ;
} Stack;

void initStack(Stack* stack, int size) {
	stack->data = (int*)malloc(size * sizeof(int));
	if (stack->data == NULL) {
		printf("Memory allocation error");
		exit (1) ; 
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

int peekStack(Stack* stack) {
	if (stack->top == -1) {
		return -1;
	}
	return stack->data[stack->top];
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

void displayStack(Stack* stack) {
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


int main() {
	int Maxsize;
	printf("Enter Max size: ");
	scanf_s("%d", &Maxsize);

	if (Maxsize <= 0) {
		printf("The stack size must be > than zero.\n");
		return EXIT_FAILURE;
	}

	Stack stack;
	initStack(&stack, Maxsize);

	int choice, number;
	do {
		printf("\nMenu:\n");
		printf("1. Add elements (push)\n");
		printf("2. Delete element  (pop)\n");
		printf("3. Find min element\n");
		printf("4. Show stack\n");
		printf("5. exit\n");
		printf("Choose choice: ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("Add element: ");
			scanf_s("%d", &number);
			pushStack(&stack, number);
			break;
		case 2:
			number = popStack(&stack);
			if (number != -1) {
				printf("Top elemrnt %d deleted %d\n", number);
			}
			break;
		case 3:
			number = findMin(&stack);
			if (number != -1) {
				printf("min element in stack: %d\n", number);
			}
			break;
		case 4:
			display(&stack);
			break;
		case 5:
			printf("Exit.\n");
			break;
		default:
			printf("Wrong choise, try again\n");
		}
	} while (choice != 5);
	freeStack(&stack);
}