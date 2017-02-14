/*
 * lin_search_var.c
 *
 * test file for CS50 problem set3 -> find
 * basic linear search using generated value array
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
    
    // generate the haystack
    for(int i = 0; i < MAX; i++)
    {
        haystack[i] = (i + 1);
    }

    // search the haystack one by one
    for(int n = 0; n < MAX; n++)
    {
        printf("index of %i and value of %i\n", n, haystack[n]);
        if(haystack[n] == needle)
        {
            printf("needle found at index %i!\n", n);
            return 0;
        }
    }
    
    printf("not there :(\n");
}
 

