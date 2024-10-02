#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 10000
#define ALPHABET_SIZE 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void Boyer_Moore(char *text, char *pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int badChar[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        badChar[(int)pattern[i]] = i;
    }

    int s = 0;
    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            printf("Found keyword at index : %d\n", s);
            s += (s + m < n) ? m - badChar[(int)text[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[(int)text[s + j]]);
        }
    }
}

int main()
{
    char text[MAX_TEXT_LENGTH], keyword[100];

    FILE *file = fopen("boyer-moore.txt", "r");

    fread(text, sizeof(char), MAX_TEXT_LENGTH, file);
    fclose(file);

    printf("Input keyword: ");
    scanf("%s", keyword);

    Boyer_Moore(text, keyword);

    return 0;
}
