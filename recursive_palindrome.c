/////////////////////////////////
// version check ทั้งตัวใหญ่ตัวเล็ก //
////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Palindrome(char word[], int start, int end)
{
    if (start >= end)
        return 1;

    if (tolower(word[start]) != tolower(word[end]))
        return 0;

    return Palindrome(word, start + 1, end - 1);
}

int main()
{
    char word[10001];
    scanf("%s", word);

    if (Palindrome(word, 0, strlen(word) - 1))
        printf("Palindrome");
    else
        printf("Not Palindrome");
}