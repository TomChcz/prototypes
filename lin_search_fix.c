/*
 * lin_search_fix.c
 *
 * test file for CS50 problem set3 -> find
 * basic linear search using fixed value array
 *
 */
 
#include <stdio.h>
#include <cs50.h>

// define maximum size of array to search
#define MAX 5

int main(void)
{
    // get needle from user
    printf("what are you looking for: ");
    int needle = get_int();

    // fill the haystack manually
    int haystack[] = {5, 4, 3, 2, 1};

    // search the haystack one by one
    for(int n = 0; n < MAX; n++)
    {
        if(haystack[n] == needle)
        {
            printf("needle found at index %i!\n", n);
            return 0;
        }
    }
    
    printf("not there :(\n");
}
 

