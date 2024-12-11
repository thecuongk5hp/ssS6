#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai báo ngãn x?p
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Kh?i t?o ngãn x?p
void initStack(Stack *s) {
    s->top = -1;
}

// Ki?m tra ngãn x?p ð?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Ki?m tra ngãn x?p r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Thêm ph?n t? vào ngãn x?p
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Ngãn x?p ð? ð?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y ph?n t? t? ngãn x?p
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngãn x?p r?ng!\n");
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

    // Thêm t?ng k? t? vào ngãn x?p
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    // L?y các k? t? ra kh?i ngãn x?p ð? t?o chu?i ð?o ngý?c
    printf("Chuoi dao nguoc: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}

