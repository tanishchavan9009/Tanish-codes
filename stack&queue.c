#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

// Queue Functions
void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Queue is Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("Customer %d added to queue\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else {
        printf("Customer %d served\n", queue[front]);
        stack[++top] = queue[front];
        front++;
    }
}

// Stack Functions
void pop() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Last served customer removed: %d\n", stack[top--]);
}

void display() {
    int i;
    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\nStack: ");
    for (i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, val;

    do {
        printf("\n1.Add Customer\n2.Serve Customer\n3.Undo Serve\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer number: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                pop();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit\n");
        }
    } while (choice != 5);

    return 0;
}