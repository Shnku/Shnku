// str rev + strlen using recursion....
#include <stdio.h>
#include <string.h>

int length_of(char *s)
{
    if (*s == '\0')
        return 0;
    return 1 + length_of(s + 1);
}

void string_rev(char *string, int start, int end)
{
    if (start > end)
        return;

    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;
    string_rev(string, start + 1, end - 1);
}

int main()
{
    char str[50];
    printf("\nenter the string: ");
    fgets(str, 50, stdin);
    // str[strcspn(str, "\n")] = '\0'; //remove the '\n at end
    int len = length_of(str);
    printf("\nlength of string is: %d", len);
    // printf("\n"); // not needed if line 27 removed..
    string_rev(str, 0, len - 1);
    fputs(str, stdout);
    return 0;
}

// output..
/*
enter the string: this isb yej

length of string is: 12jey bsi siht
*/

/*
enter the string: this is the str

length of string is: 16
rts eht si siht⏎
*/

//! important...
/*
char str[] = "string"; instead of char *str = "string";.

Using char str[] creates an array of characters on the stack, allowing you to modify its contents.
On the other hand, char *str creates a pointer to a string literal,
which is stored in read-only memory and cannot be modified.
Attempting to modify a string literal, such as reversing it, results in undefined behavior.

By using char str[] = "string";, you create an array that can be modified, and the string_rev function can correctly reverse the characters in the array.
*/
