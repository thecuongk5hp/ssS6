#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai b�o ng�n x?p
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Kh?i t?o ng�n x?p
void initStack(Stack *s) {
    s->top = -1;
}

// Ki?m tra ng�n x?p �?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Ki?m tra ng�n x?p r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Th�m ph?n t? v�o ng�n x?p
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Ng�n x?p �? �?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y ph?n t? t? ng�n x?p
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ng�n x?p r?ng!\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

int main() {
    Stack stack;
    initStack(&stack);

    char input[MAX];
    printf("Nhap chuoi: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';  // Lo?i b? k? t? xu?ng d?ng

    // Th�m t?ng k? t? v�o ng�n x?p
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    // L?y c�c k? t? ra kh?i ng�n x?p �? t?o chu?i �?o ng�?c
    printf("Chuoi dao nguoc: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}

