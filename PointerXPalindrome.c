#include <stdio.h>

int main() {
    char *p1, *p2, str[50];
    p1 = str;
    p2 = str;

    scanf("%s", str);

    while (*p2 != '\0') {
        p2++;
    }
    p2--;

    while (p2 > p1) {
        if (*p1 != *p2) {
            printf("Not Palindrome");
            return 0;
        }

        else {
            p1++;
            p2--;
        }
    }
    printf("Palindrome");
}