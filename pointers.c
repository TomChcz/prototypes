#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char* s = get_string();
    if (s == NULL)
    {
        return 1;
    }
    
    // print length (size) of a string
    printf("string length is: %lu\n", strlen(s));
    

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // go to address and print value (this time char), increments i every iteration and moves to next byte in string
        printf("%c\n", *(s+i));
    }
    
    // show me where the string begins in memory
    printf("memory address of the string is %p\n", &s);
    

    
    
}