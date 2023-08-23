// 18. Write a program to check whether the given string is anagram or not.
#include <stdio.h>

int check_anagram (char [], char []);

int main()
{
    char arr1[50], arr2[50];
    printf("Enter the first string: ");
    scanf(" %s", &arr1);

    printf("Enter the second string: ");
    scanf(" %s", &arr2);

    if (check_anagram(arr1, arr2) == 1) {printf("Anagram"); }
    else {printf("Not Anagram"); }

    return 0;
}

int check_anagram (char arr1[], char arr2[])
{
    int num1[26] = {0}, num2[26] = {0}, i = 0;

    while (arr1[i] != '\0')
    {
        num1[arr1[i] - 'a']++;
        i++;
    }

    i = 0;
    while (arr2[i] != '\0')
    {
        num2[arr2[i] - 'a']++;
        i++;
    }

    for (i = 0; i < 26; i++) {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}