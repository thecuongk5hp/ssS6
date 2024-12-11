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

// Ki?m tra ng�n x?p r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Ki?m tra ng�n x?p �?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Th�m ph?n t? v�o ng�n x?p
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Ng�n x?p �? �?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y ph?n t? ra kh?i ng�n x?p
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Tr? v? k? t? null n?u ng�n x?p r?ng
    }
    return s->arr[(s->top)--];
}

// Ki?m tra c?p d?u ngo?c
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// H�m ki?m tra t�nh h?p l? c?a d?u ngo?c
int isValidExpression(char *expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // N?u l� d?u ngo?c m?, th�m v�o ng�n x?p
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // N?u l� d?u ngo?c ��ng, ki?m tra v?i ng�n x?p
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0; // Kh�ng c� d?u ngo?c m? t��ng ?ng
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, ch)) {
                return 0; // C?p d?u ngo?c kh�ng kh?p
            }
        }
    }

    // N?u ng�n x?p c?n ph?n t?, d?u ngo?c kh�ng h?p l?
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];
    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Lo?i b? k? t? xu?ng d?ng

    if (isValidExpression(expr)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}

