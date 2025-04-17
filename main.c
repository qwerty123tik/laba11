#include "Header.h"

void Task1() {
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
			number = popStack(&stack);
			if (number != -1) {
				printf("Top elemrnt %d deleted\n", number);
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

void Task2() {
	printf("Task 2: Obedinenie dwyx stacks\n");
	int Maxsize;
	printf("Enter Max size: ");
	scanf_s("%d", &Maxsize);

	if (Maxsize <= 0) {
		printf("The stack size must be > than zero.\n");
		return -1;
	}
	Stack stack1, stack2, stack3;
	initStack(&stack1, Maxsize);
	initStack(&stack2, Maxsize);
	initStack(&stack3, Maxsize * 2);

	printf("Stack input (from largest to smallest):\n");
	for (int i = 0; i < Maxsize; i++) {
		int number;
		printf("Element %d: ", i + 1);
		scanf_s("%d", &number);
		pushPoYb(&stack1, number);
	}

	printf("Stack input (from smallest to largest):\n");
	for (int i = 0; i < Maxsize; i++) {
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
			display(&stack1);
			break;
		case 2:
			display(&stack2);
			break;
		case 3:
			Obedin(&stack1, &stack2, &stack3);
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

int main() {
	int mainChoice;
	do {
		printf("Main Menu:\n");
		printf("1. Task 1: Find min in stack\n");
		printf("2. Task 2:  Obedinenie dwyx stacks\n");
		printf("3. Exit\n");
		printf("Choose: ");
		scanf_s("%d", &mainChoice);

		switch (mainChoice) {
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: printf("Exiting...\n"); break;
		default: printf("Invalid choice\n");
		}
	} while (mainChoice != 3);
}