/**
 * gof_board_func.c
 * 
 * drawes gaming board for Game of 15 with function call
 * to init and draw board
 * 
 * usage ./gof_board_func d
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

// functions
void init(int b);
void draw(int b);

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
    
    init(d);
    
    draw(d);
    
    
// end main
}
    
void init(int b)
{
    //initiate tiles except last tile that has to remain empty
    int tiles =  (b * b - 1 );
    
    // fgenerate tiles line by line, column by column
    for(int x = 0; x < b; x++)
    {
        for(int y = 0; y < b; y++)
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
    if(b % 2 != 1)
    {
        int tmp = board[b - 1][b - 2];
        board[b - 1][b - 2] = board[b - 1][b - 3];
        board[b - 1][b - 3] = tmp;
    }    

// end init
}
    
void draw(int b)
{
    // draw the board line by line
    for(int row = 0; row < b; row++)
    {
        for(int column = 0; column < b; column++)
        {
            //print padding for single digit tiles
            if(board[row][column] < 10)
            {
                printf(" ");
            }
            
            // print board except final empty tile (empty array value)
            if(board[row][column] == 0)
            {
                // print _ for final empty tile
                printf("_");
            }
            else
            {
                printf("%i", board[row][column]);
            }

            // print tile divider
            printf("|");
        }
    // new row
    printf("\n");        
    }    

// end draw
}
