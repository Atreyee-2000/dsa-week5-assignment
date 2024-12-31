/*Stack using Linked List: Assignments
Assignments:
1. Write a program to insert an element into the
stack using linked list (Push Operation).
2. Write a program to delete an element from the
stack using linked list (Pop Operation).
3. Write a program to return the value of the
topmost element of the stack (without deleting it
from the stack) using linked list (Peep operation).
4. Write a program to display the elements of a
stack using linked list .
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack's nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; // Initialize the top of the stack to NULL

// Function to push an element onto the stack
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow! Cannot push %d.\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    Node* temp = top;
    printf("%d popped from the stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Function to return the topmost element of the stack (peep operation)
void peep() {
    if (top == NULL) {
        printf("The stack is empty. No topmost element.\n");
    } else {
        printf("The topmost element is %d.\n", top->data);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
