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

int popStack(Stack* stack, int* number) {
	if (isEmpty(stack)) {
		return 0;
	}
	*number = stack->data[stack->top--];
	return 1;
}


int findMin(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty");
		return INT_MIN;
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

int isEmpty(Stack* stack) {
	return stack->top == -1;
}

void pushPoYb(Stack* stack, int number) {
	if (stack->top >= 0 && number >= stack->data[stack->top]) {
		printf("Order should be po ubyvaniyu\n");
		return;
	}
	else pushStack(stack, number);
}

void pushPoVozr(Stack* stack, int number) {
	if (stack->top >= 0 && number <= stack->data[stack->top]) {
		printf("Order should be po vozrastaniu\n");
		return;
	}
	else pushStack(stack, number);
}

//void pushPoYb(Stack* stack) {
//	int size, number, prev = INT_MAX;
//	printf("Enter size of descending stack: ");
//	scanf_s("%d", &size);
//	initStack(stack, size);
//
//	printf("Enter %d integers in descending order:\n", size);
//	for (int i = 0; i < size; i++) {
//		scanf_s("%d", &number);
//		if (number >= prev) {
//			printf("Error: must be in descending order!\n");
//			i--;
//			continue;
//		}
//		pushStack(stack, number);
//		prev = number;
//	}
//}
//
//void pushPoVozr(Stack* stack) {
//	int size, number, prev = INT_MIN;
//	printf("Enter size of ascending stack: ");
//	scanf_s("%d", &size);
//	initStack(stack, size);
//
//	printf("Enter %d integers in ascending order:\n", size);
//	for (int i = 0; i < size; i++) {
//		scanf_s("%d", &number);
//		if (number <= prev) {
//			printf("Error: must be in ascending order!\n");
//			i--;
//			continue;
//		}
//		pushStack(stack, number);
//		prev = number;
//	}
//}


void mergeStacks(Stack* stack1, Stack* stack2, Stack* stack3) {
	Stack copy1, copy2;
	initStack(&copy1, stack1->Maxsize);
	initStack(&copy2, stack2->Maxsize);
	for (int i = 0; i <= stack1->top; i++) {
		pushStack(&copy1, stack1->data[i]);
	}
	for (int i = 0; i <= stack2->top; i++) {
		pushStack(&copy2, stack2->data[i]);
	}
	int totalSize = copy1.top + 1 + copy2.top + 1;
	int* buffer = (int*)malloc(sizeof(int) * totalSize);
	int index = 0;
	int number;
	while (popStack(&copy1, &number)) buffer[index++] = number;
	while (popStack(&copy2, &number)) buffer[index++] = number;
	while (index > 0) {
		int minIndex = 0;
		for (int i = 1; i < index; i++) {
			if (buffer[i] < buffer[minIndex]) {
				minIndex = i;
			}
		}
		pushStack(stack3, buffer[minIndex]);
		for (int i = minIndex; i < index - 1; i++) {
			buffer[i] = buffer[i + 1];
		}
		index--;
	}
	free(buffer);
	freeStack(&copy1);
	freeStack(&copy2);
}

void FindMinInStack() {
	printf("Task 1: Find min in stack\n");
	int Maxsize;
	printf("Enter Max size: ");
	scanf_s("%d", &Maxsize);

	if (Maxsize <= 0) {
		printf("The stack size must be > than zero.\n");
		return -1;
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
			if (popStack(&stack, &number)) {
				printf("Top element %d deleted\n", number);
			}
			else {
				printf("Stack is empty\n");
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

void ObedinenieDwyxStacks() {
	printf("Task 2: Obedinenie dwyx stacks\n");
	
	int size1, size2;
	printf("Enter size of first stack: ");
	scanf_s("%d", &size1);
	printf("Enter size of second stack: ");
	scanf_s("%d", &size2);

	if (size1 <= 0 || size2 <= 0) {
		printf("Stack sizes must be > than zero.\n");
		return;
	}

	Stack stack1, stack2, stack3;
	initStack(&stack1, size1);
	initStack(&stack2, size2);
	initStack(&stack3, size1 + size2);


	printf("Stack input (from largest to smallest):\n");
	for (int i = 0; i < size1; i++) {
		int number;
		printf("Element %d: ", i + 1);
		scanf_s("%d", &number);
		pushPoYb(&stack1, number);
	}

	printf("Stack input (from smallest to largest):\n");
	for (int i = 0; i < size2; i++) {
		int number;
		printf("Element %d: ", i + 1);
		scanf_s("%d", &number);
		pushPoVozr(&stack2, number);
	}


	int choice;
	do {
		printf("Task 2 Menu:\n");
		printf("1. Show stack(from largest to smallest\n");
		printf("2. Show stack (from smallest to largest)\n");
		printf("3. Create and show merged stack\n");
		printf("4. Exit\n");
		printf("Choose: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Stack (from largest to smallest:\n");
			display(&stack1);
			break;
		case 2:
			printf("Stack (from smallest to largest):\n");
			display(&stack2);
			break;
		case 3:
			freeStack(&stack3);
			initStack(&stack3, size1 + size2);
			mergeStacks(&stack1, &stack2, &stack3);
			printf("Merged stack:\n");
			display(&stack3);
			break;
		case 4:
			printf("Exit\n");
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice != 4);

	freeStack(&stack1);
	freeStack(&stack2);
	freeStack(&stack3);
}
