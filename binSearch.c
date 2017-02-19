/*
 * binSearch.c
 *
 * prototype for binary search
 *
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* pseudocode
     * look at midpoint (modulus/2 -1 for even array size), if match exit, if higher, look to the left, if lower, look to the right
     * repat until array portion of size 1
     */
     
     // fil the haystack
     int size = 7;
     int haystack[] = {1, 2, 3, 4, 5, 6, 7};
     // int haystack[] = {1, 2, 3, 4, 5, 6};
     
     // search the haystack
     int counter;

     do
     {
         counter = 0;
         //define midpoint

         if(size % 2 == 1)
         {
             int midpoint = (size - 1) / 2;
             printf("midpoint is %i\n", midpoint);
             printf("haystack is of odd size\n");
         }
         else
         {
             int midpoint = size / 2;
             printf("midpoint is %i\n", midpoint);
             printf("haystack is of even size\n");
         }
         
         printf("haystack tmp %i\n", haystack[0]);
     }
     while(counter > 0);
}