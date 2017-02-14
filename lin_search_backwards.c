/*
 * lin_search_backwards.c
 *
 * test file for CS50 problem set3 -> find
 * basic linear search using backwards (10 -> 1) generated value array
 *
 */

#include <stdio.h>
#include <cs50.h>

// define maximum size of array to search
#define MAX 10

int main(void)
{
    // get needle from user
    printf("what are you looking for: ");
    int needle = get_int();
    int haystack[MAX];
    
    // generate haystack, generate index correctly by substracting #iteration from haystack size
    for(int i = MAX; i > 0; i--)
    {
        haystack[(MAX - i)] = i;
        printf("index is %i and value is %i\n", (MAX - i), i);
    }

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