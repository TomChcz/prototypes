/*
 * binSearch.c
 *
 * prototype for binary search
 */

#include <stdio.h>
#include <cs50.h>

// devine divider for recursion
#define DIVIDER 2

int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("usage: ./binSearch needle\n");
        return 1;
    }
    
    /* pseudocode
     * look at midpoint (modulus/2 -1 for even array size), if match exit, if higher, look to the left, if lower, look to the right
     * repat until array portion of size 1
     */
     
    // fil the haystack
    int size = 7;
    int haystack[] = {1, 2, 3, 4, 5, 6, 7};
    // int haystack[] = {1, 2, 3, 4, 5, 6};
    
    // define counter for recursion
    int counter;
     
    // get needle
    int needle = atoi(argv[1]);
    printf("needle is %i\n", needle);
     
    do
    {
        counter = 0;

        int midpoint;
         
        //find midpoint
        if(size % DIVIDER == 1)
        {
            // define midpoint and substract 1 to get array position
            midpoint = ((size - 1) / DIVIDER) - 1;
            printf("haystack is of odd size\n");
        }
        else
        {
            // define midpoint and substract 1 to get array position
            midpoint = (size / DIVIDER) -1;
            printf("haystack is of even size\n");
        }
         
        // search the haystack
        if(haystack[midpoint] == needle)
        {
            printf("needle found!\n");
        }
        else
        {
            // counter++;
            if(haystack[midpoint] > needle)
            {
                // TODO look to the left
                printf("look left\n");
            }
            else
            {
                // TODO look to the right
                printf("look right\n");
            }
        } 
    }
    while(counter > 0);
}