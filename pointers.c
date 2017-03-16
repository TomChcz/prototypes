#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

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
    printf("memory address of the string is %p\n", s);
    
    int k = 5;
    
    printf("memory address of k is: %p\n\n", &k);
    
    int* pk = NULL; // create a pointer
    pk = &k; // put the addess of k in pk
    
    // show me where the pointers point to and address of k in memory
    printf("memory adress of pk is %p and value at the address is %i and int k is %i and memory address of k is %p\n", pk, *pk, k, &k);
    
    int* b = malloc(sizeof(int));

    if(b == NULL)
    {
        printf("NULL\n\n");
    }
    
    printf("int value is %i and memory adress is %p\n", *b, &b);
    
    
}