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

// Ki?m tra ngãn x?p r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Ki?m tra ngãn x?p ð?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Thêm ph?n t? vào ngãn x?p
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Ngãn x?p ð? ð?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y ph?n t? ra kh?i ngãn x?p
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Tr? v? k? t? null n?u ngãn x?p r?ng
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

// Hàm ki?m tra tính h?p l? c?a d?u ngo?c
int isValidExpression(char *expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // N?u là d?u ngo?c m?, thêm vào ngãn x?p
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // N?u là d?u ngo?c ðóng, ki?m tra v?i ngãn x?p
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0; // Không có d?u ngo?c m? týõng ?ng
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, ch)) {
                return 0; // C?p d?u ngo?c không kh?p
            }
        }
    }

    // N?u ngãn x?p c?n ph?n t?, d?u ngo?c không h?p l?
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

