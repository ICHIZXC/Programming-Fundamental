#include <stdio.h>

int main() {
    int size;
    int row = 1;
    scanf("%d", &size);

    for (row = 1; row <= size; row++) {
        
        for (int space = 1; space <= size - row; space++) {
            printf(" ");
        }

        for (int star = 1; star <= (2*row) - 1; star++) {
            printf("*");
        }

        printf("\n");
    }

    for (int row2 = 1; row2 < size; row2++) {

        for (int space = 1; space <= row2; space++) {
            printf(" ");
        }

        for (int star = 1; star < 2*(size - row2); star++) {
            printf("*");
        }

        printf("\n");
    }

}
