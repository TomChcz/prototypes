/**
 * 2Darray.c
 * 
 * drawes gaming board for Game of 15
 * 
 * usage ./2Darray d
 * 
 * board size is limited to DIM_MIN & DIM_MAX
 * 
 */

#include <stdio.h>
#include <cs50.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9


// dimensions
int d;

// board
int board[DIM_MAX][DIM_MAX];

int main(int argc, string argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        printf("usage: 2Darray d\n");
        return 1;
    }
    
    // get dimensions
    d = atoi(argv[1]);
    
    // check dimensions
    if(d < DIM_MIN || d > DIM_MAX)
    {
        printf("board can only be of between: MIN %i x %i and MAX %i x %i\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    
    //initiate tiles
    int tiles =  d * d;
    
    
    // generate board
    for(int x = 0; x < d; x++)
    {
        for(int y = 0; y < d; y++)
        {
            board[x][y] = tiles;
            tiles--;
        }
    }
    
//    board[1][2] = 8;
//    board[2][3] = 9;

    
    // draw the board
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            printf("%i", board[i][j]);
            printf("|");
        }
        printf("\n");
    }

}
