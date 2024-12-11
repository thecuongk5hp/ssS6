#include <stdio.h>

#define MAX 100

// Khai báo ngãn x?p
typedef struct {
    int arr[MAX];
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
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Ngãn x?p ð? ð?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y giá tr? ph?n t? trên cùng mà không xóa (peek)
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngãn x?p r?ng!\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack stack;
    initStack(&stack);

    int n, value;
    printf("Nhap so luong phan tu (toi da %d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    if (n > 0) {
        printf("Nhap cac phan tu:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            push(&stack, value);
        }
    }

    if (!isEmpty(&stack)) {
        int topValue = peek(&stack);
        printf("Phan tu tren cung: %d\n", topValue);
    } else {
        printf("Ngãn x?p r?ng!\n");
    }

    return 0;
}

