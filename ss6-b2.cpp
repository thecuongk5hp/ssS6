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

// Ki?m tra ngãn x?p ð?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Ki?m tra ngãn x?p r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Thêm ph?n t? vào ngãn x?p
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Ngãn x?p ð? ð?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// L?y ph?n t? t? ngãn x?p
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngãn x?p r?ng!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Hi?n th? các ph?n t? trong ngãn x?p
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngãn x?p r?ng!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int n, value;
    printf("Nhap so luong phan tu (toi da %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("So luong phan tu vuot qua kich thuoc toi da!\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("Thuc hien thao tac pop...\n");
    if (!isEmpty(&stack)) {
        int poppedValue = pop(&stack);
        printf("Phan tu bi xoa: %d\n", poppedValue);
    } else {
        printf("Khong co phan tu de xoa!\n");
    }

    printf("Cac phan tu trong ngan xep con lai:\n");
    display(&stack);

    return 0;
}

