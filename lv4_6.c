// เขียนโปรแกรมวาด * เป็นรูปตัว M ตามขนาดที่กำหนด

#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= (2 * n) - 1; col++) {
            if (col == row || col == 1 || col == (2 * n) - 1 || row + col == n * 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

