#include <stdio.h>
#include <cs50.h>

// define recursive function

int fact(int n);

int main(int argc, string argv[])
{
    // check for user input
    if(argc != 2)
    {
        printf("usage: ./recursion int\n");
        return 1;
    }
    
    // remember user input   
    int x = atoi(argv[1]);
    
    // call recursion
    printf("factorial of %i is: %i\n", x, fact(x));
    return 0;
    
// end main
}

int fact(int n)
{
    // base case (recursion stops here)
    if (n == 1)
        return 1; // without {} since the conditions only contains 1 line of code            

    // recursion    
    else
        return n * fact(n - 1);        

//end fact
}