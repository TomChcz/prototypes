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
    int size = 5; // smaler than haystack size to avoid segmentation fault (out of bounds error)
    int haystack[] = {6, 5, 4, 3, 2, 1};
    
    // look in haystack
    for(int i = 0; i < size; i++)
    {
        // check if following element bigger
        if(haystack[i] > haystack [i + 1])
        {
            printf("ready to swap %i with %i\n", haystack[i], haystack[i + 1]);
            
            /*  pseudocode for swap of positions in array
            haystack[i] = haystack[i+1], haystack[i + 1] = haystack[i]
            need to figure out, how to mark element as sorted (index at zero and start for loop by size+1?)
            */
            
        }
    }
}