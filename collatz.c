/* the collatz conjecture
 *
 * usage: ./collatz number
 *
 */

#include <stdio.h>
#include <stdlib.h>

int collatz(int n);

int main(int argc, char* argv[])
{
    // ensure correct usage
    if(argc != 2)
    {
        printf("usage: ./collatz number\n");
        return 1;
    }
    
    // remember number to check with collatz
    int x = atoi(argv[1]);
    
    printf("nr of steps needed: %i\n", collatz(x));
}

int collatz(int n)
{
    if(n == 1)
        return 0;
    
    else if(n % 2 == 0)
        return 1 + collatz(n / 2);
        
    else
        return 1 + collatz(3*n + 1);
}