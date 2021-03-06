/*
 * binSearch.c
 *
 * prototype for binary search
 */

#include <stdio.h>
#include <cs50.h>

// define divider for recursion
#define DIVIDER 2

int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("usage: ./binSearch needle\n");
        return 1;
    }
    
    // get needle
    int needle = atoi(argv[1]);

    // fil the haystack
    int haystack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // define start of the array
    int start = 0;
    
    // define end of the array (size of array - 1)
    int end = 14;

    printf("needle is %i\n", needle);

    // define midpoint variable
    int midpoint;

    do
    {
        //calculate midpoint
        if((start + end) % DIVIDER == 1)
        {
            // calculate midpoint for odd size haystack
            midpoint = ((start + end - 1) / DIVIDER);
            printf("midpoint is %i\n", midpoint);
        }
        else
        {
            // calculate midpoint for even size haystack
            midpoint = ((start + end) / DIVIDER);
            printf("midpoint is %i\n", midpoint);
        }        
        
        // search the haystack
        if(haystack[midpoint] == needle)
        {
            printf("needle found! at index %i\n", midpoint);
            return 0;
        }
        else
        {
            if(needle < haystack[midpoint])
            {
                // TODO look to the left
                end = midpoint - 1;
                printf("new start is %i end is %i\n", start, end);
            }
            else
            {
                // TODO look to the right
                start = midpoint + 1;
                printf("new start is %i and end is %i\n", start, end);
            }
        } 
    }
    while(end >= start);
    
    printf("needle not found :(\n");
    return 0;
}