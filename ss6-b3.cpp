#include <stdio.h>

#define MAX 100

// Khai b�o ng�n x?p
typedef struct {
    int arr[MAX];
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

// Th�m ph?n t? v�o ng�n x?p
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Ng�n x?p �? �?y!\n");
        return;
    }
    s->arr[++(s->top)] = value;
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

    if (isEmpty(&stack)) {
        printf("Ngan xep rong\n");
    } else {
        printf("Ngan xep khong rong\n");
    }

    return 0;
}

