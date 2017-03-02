/**
 * gof_board.c
 * 
 * drawes gaming board for Game of 15
 * 
 * usage ./gof_board d
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
        printf("Board can only be of between: MIN %i x %i and MAX %i x %i\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    
    //initiate tiles
    int tiles =  (d * d - 1 );
    
    // initiate board except last empty slot

    for(int x = 0; x < d; x++)
    {
        for(int y = 0; y < d; y++)
        {
            // make sure last tile is not initiated (left blank)
            if(tiles > 0)
            {
                board[x][y] = tiles;
                tiles--;
            }
        }
    }
    
    // swap last two tiles for even board dimensions
    if(d % 2 != 1)
    {
        int tmp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = tmp;
    }

    // draw the board
    for(int row = 0; row < d; row++)
    {
        for(int column = 0; column < d; column++)
        {
            //print padding for single digit tiles
            if(board[row][column] < 10)
            {
                printf(" ");
            }
            
            // print board
            if(board[row][column] == 0)
            {
                printf("_");
            }
            else
            {
                printf("%i", board[row][column]);
            }

            printf("|");

        }
    // new row
    printf("\n");        
    }


    

}
