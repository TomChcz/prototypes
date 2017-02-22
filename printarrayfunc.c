/*
 * printarrayfunc.c
 *
 * print array function prototype
 *
 */

#include <stdio.h>
#include <cs50.h>

// declare function
void printarray(int values[], int n);

int main(void)
{
    // define haystack size
    int size = 5; 
    
    // fill the haystack
    int haystack[] = {5, 4, 3, 2, 1};
    
    // call function
    printarray(haystack, size);
}

void printarray(int values[], int n)
{
    // iterate over array and print array elements one by one
    for(int i = 0; i < n; i++)
        {
            printf("%i ", values[i]);
        }
        printf("\n");
        return;
}