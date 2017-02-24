/*
 * bubbleSort.c
 *
 * prototype for bubble sort using fixed array
 *
 */
 
#include <stdio.h>
#include <cs50.h>

// declare swap function

int main(void)
{
    // fill haystack
    int size = 7; // smaler than haystack size to avoid segmentation fault (out of bounds error)
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
            // prevent array overflow
            if(i < (size - 1))
            {            
                // check if following element bigger
                if(haystack[i] > haystack[i + 1])
                {
                    //store sorted haystack
                    int tmp = haystack[i];
                    // swap straws
                    haystack[i] = haystack[i + 1];
                    haystack[i + 1] = tmp;
                
                    swapCounter++;
                }
            }
        }
        printf("counter %i\n", swapCounter);
    }
    while(swapCounter > 0);
    
    // print haystack values
    printf("sorted haystack: ");
    
    for(int x = 0; x < size; x++)
        {
            printf("%i ", haystack[x]);
        }

        printf("\n");
}


