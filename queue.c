#include <stdio.h>
#define MAX_ELEMENTS 100
int queue[MAX_ELEMENTS];
int count = 0;

void display() {
    if (count == 0) {
        printf("The queue is empty.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void enqueue() {
    if (count < MAX_ELEMENTS) {
        int element;
        printf("Enter element : ");
        scanf("%d", &element);
        queue[count] = element;
        count++;
        printf("Element inserted\n");
    } else {
        printf("The queue is full.\n");
    } 
}

void dequeue() {
    if (count == 0) {
        printf("The queue is empty.\n");
    } else {
        for (int i = 0; i < count - 1; i++) {
            queue[i] = queue[i+1];
        }
        count--;
        printf("Element deleted\n");
    } 
}

void peek() {
    if (count == 0) {
        printf("The queue is empty.\n");
    } else {
        printf("The first element of the queue is: %d\n", queue[0]);
    }
}

int main() {
    int choice, running = 1;
    while (running == 1) {
        printf("Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to peek, 5 to exit : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                running = 0;
                break; 
        }
    }
    return 0; 
}