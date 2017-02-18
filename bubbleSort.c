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
    int size = 6; // smaler than haystack size to avoid segmentation fault (out of bounds error)
    // worst case  int haystack[] = {60, 40, 30, 5, 4, 3, 2};
    int haystack[] = {60, 40, 70, 80, 75, 90, 100};
    // best case int haystack[] = {2, 3, 4, 5, 30, 40, 60};
    
    // initiate swap counter
    int swapCounter;
    
    // search the haystack
    do
    {
        swapCounter = 0;
        for(int i = 0; i < size; i++)
        {
            // check if following element bigger
            if(haystack[i] > haystack [i + 1])
            {
                // swap: need to create a function for this
            
                //store sorted haystack
                int tmp = haystack[i];
                // swap straws
                haystack[i] = haystack[i + 1];
                haystack[i + 1] = tmp;
                
                swapCounter++;
            }
        }
        printf("counter %i\n", swapCounter);
    }
    while(swapCounter > 0);
    
    // print haystack values
    printf("sorted haystack: ");
    
    for(int x = 0; x < size + 1; x++)
        {
            printf("%i ", haystack[x]);
        }

        printf("\n");
}
