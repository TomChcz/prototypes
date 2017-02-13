/*
 * bubbleSort.c
 *
 * prototype for bubble sort using fixed array
 *
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // fill haystack
    int size = 5;
    int haystack[] = {6, 5, 4, 3, 2, 1};
    
    for(int i = 0; i < size; i++)
    {
        // check if following element bigger
        if(haystack[i] > haystack [i + 1])
        {
            printf("ready to swap %i with %i\n", haystack[i], haystack[i + 1]);
        }
    }
}