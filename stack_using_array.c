/*Stack using Array in c 

1. Write a program to insert an element into the
stack using an array (Push Operation).
2. Write a program to delete an element from the
stack using an array (Pop Operation).
3. Write a program to return the value of the
topmost element of the stack (without deleting it
from the stack) using an array (Peep operation).
4. Write a program to display the elements of a
stack using an array.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initialize top to -1 (indicating an empty stack)

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top--]);
    }
}

// Function to return the topmost element of the stack (peep operation)
void peep() {
    if (top == -1) {
        printf("The stack is empty. No topmost element.\n");
    } else {
        printf("The topmost element is %d.\n", stack[top]);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep (Topmost Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
