#include "Header.h"


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