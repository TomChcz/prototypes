#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int* a; // declare pointer without value - points to memory space in stack (empty)
    int* b = malloc(sizeof(int)); // declare pointer b and allocate block of memory in heap (empty)
    a = &m; // a now points to memory adress of b, need to add & for non pointers, aka integers
    a = b; // a now points to block of memory in heap at the address of b
    m = 10; // value of m is now 10, nothing points to m address at this time
    *b = m + 2; // put 12 at the adress where b is
    
    printf("mem adr of *b is %p and value is %i\n", b, *b);
    
    free(b); // empty allocated memory block (remove value)

    printf("mem adr of *b is %p and value is %i\n", b, *b);
    
    *a = 11; // puts 11 at the adress of a - should invoke seg fault since block of memory at b is freed
    
    printf("pointer *a points to address %p and value there is %i\n", a, *a);
    
}