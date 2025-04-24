#include "Header.h"

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
		case 1: FindMinInStack(); break;
		case 2: ObedinenieDwyxStacks(); break;
		case 3: printf("Exiting...\n"); break;
		default: printf("Invalid choice\n");
		}
	} while (mainChoice != 3);
}