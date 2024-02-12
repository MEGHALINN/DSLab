
#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }

    int i;
    for (i = top; i >= 0; i--) {
        if (stack[i] > value) {
            stack[i + 1] = stack[i];
        } 
        else {
            break;
        }
    }

    stack[i + 1] = value;
    top++;
}

int main() {
    push(3);
    push(1);
    push(4);
    push(2);

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
