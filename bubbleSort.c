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
    int size = 1; // smaler than haystack size to avoid segmentation fault (out of bounds error)
    int haystack[] = {6, 2};
    
    // look in haystack
    for(int i = 0; i < size; i++)
    {
        // check if following element bigger
        if(haystack[i] > haystack [i + 1])
        {
            printf("pass nr %i ready to swap %i with %i\n", i, haystack[i], haystack[i + 1]);
            
            // need to create a function for this
            
            //store sorted haystack
            int tmp = haystack[i];
            // swap straws
            haystack[i] = haystack[i + 1];
            haystack[i + 1] = tmp;

       
            /*  pseudocode for swap of positions in array
            haystack[i] = haystack[i+1], haystack[i + 1] = haystack[i]
            need to figure out, how to mark element as sorted (index at zero and start for loop by size+1?)
            */
            
        }
        
        // print haystack values
        for(int x = 0; x < size + 1; x++)
        {
            printf("array index %i holds value of %i\n", x, haystack[x]);
        }
        
    }
}
