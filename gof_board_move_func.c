/**
 * gof_board_move_func.c
 * 
 * drawes gaming board for Game of 15 with function call
 * to init and draw board with move tile functionality
 * 
 * usage ./gof_board_func d
 * 
 * board size is limited to DIM_MIN & DIM_MAX
 * 
 */

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <stdlib.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define EMPTY_TILE 99

// dimensions
int d;

// functions
void clear(void);
void init(int b);
void draw(int b);
bool move(int tile);


// board
int board[DIM_MAX][DIM_MAX];

int main(int argc, string argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        printf("usage: ./gof_board_move_func d\n");
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
    
    while(true)
    {
        draw(d);
        
        // get tile to move from user
        
        printf("Tile to move:");
        
        int tile = get_int();
        
        if(!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);        
        }
    }

// end main
}

void init(int b)
{
    //initiate tiles except last tile that has to remain empty
    int tiles =  (b * b - 1 );
    
    // generate tiles line by line, column by column
    for(int row = 0; row < b; row++)
    {
        for(int column = 0; column < b; column++)
        {
            // make sure last tile is not initiated (left blank)
            if(tiles > 0)
            {
                board[row][column] = tiles;
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
    
    // initiate empty tile
    board[b - 1][b - 1] = EMPTY_TILE;

// end init
}
    
void draw(int b)
{
    // draw the board line by line
    for(int row = 0; row < b; row++)
    {
        for(int column = 0; column < b; column++)
        {
            // print board except final empty tile (empty array value)
            if(board[row][column] == EMPTY_TILE)
            {
                // print _ for final empty tile - should be automated for numbers with 3 decimals and more
                printf(" _");
            }
            else
            {
               // print each tile, blank space for single digit numbers
                printf("%2i", board[row][column]);
            }

            // print tile divider
            printf("|");
        }
    // new row
    printf("\n");        
    }    

// end draw
}

bool move(int tile)
{
    int row;
    int column;

    // find the tile on the board
    
    for(row = 0; row < d; row++)
    {
        for(column = 0; column < d; column++)
        {
            if(board[row][column] == tile)
                {
                    break;
                }
        }
        
        if(board[row][column] == tile)
        {
            break;
        }
    }

    int row_blank;
    int column_blank;

    // find the empty tile on the board
    
    for(row_blank = 0; row_blank < d; row_blank++)
    {
        for(column_blank = 0; column_blank < d; column_blank++)
        {
            if(board[row_blank][column_blank] == EMPTY_TILE)
                {
                    break;
                }
        }
        
        if(board[row_blank][column_blank] == EMPTY_TILE)
        {
            break;
        }
    }
    printf("row: %i, column: %i\n", row, column);
    printf("row_blank: %i, column_blank: %i\n", row_blank, column_blank);
    return 0;

}

