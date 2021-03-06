/**
 * gof_board_move_func.c
 * 
 * drawes gaming board for Game of 15 with function call
 * to init and draw board with move tile functionality
 * 
 * usage ./gof_board_move_func d
 * 
 * board size is limited to DIM_MIN & DIM_MAX
 * 
 */

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <stdlib.h>

// fixeds
#define DIM_MIN 3
#define DIM_MAX 9
#define EMPTY_TILE 0

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// functions
void clear(void);
void init(int b);
void draw(int b);
bool move(int tile);

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
    
    // initialize the board
    init(d);
    
    while(true)
    {
        // draw the board in current state
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
           
            // initiate last empty tile
            else if(tiles == 0)
            {
                board[row][column] = EMPTY_TILE;                
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
    int row_tile = 0;
    int column_tile = 0;
    int found_tile = 0;

    // find the tile on the board
    for(row_tile = 0; row_tile < d; row_tile++)
    {
        for(column_tile = 0; column_tile < d; column_tile++)
        {
            // end search if found
            if(board[row_tile][column_tile] == tile)
            {
                printf("tile inside found at %i, %i\n", row_tile, column_tile);
                found_tile = 1;
                break;
            }
        }
        
        // end search if found
        if(found_tile == 1)
        {
            break;
        }
    }
    
    printf("tile outside loop found at %i, %i\n", row_tile, column_tile);

    int row_blank = 0;
    int column_blank = 0;
    int found_blank = 0;

    // find the empty tile on the board
    for(row_blank = 0; row_blank < d; row_blank++)
    {
        for(column_blank = 0; column_blank < d; column_blank++)
        {
            // end search if found
            if(board[row_blank][column_blank] == EMPTY_TILE)
            {
                printf("blank tile inside found at %i, %i\n", row_blank, column_blank);
                found_blank = 1;
                break;
            }
        }
        
        // end search if found
        if(found_blank == 1)
        {
            break;
        }
    }
    
    printf("blank tile outside loop found at %i, %i\n", row_blank, column_blank);

    //calculate distance of tile and blank space
    int row_distance = row_tile - row_blank;
    int column_distance = column_tile - column_blank;

    // check whether tile and blank space neighbour correctly
    if(row_distance == 0)
    {
        if(column_distance == -1 || column_distance == 1)
        {
            // move diagonally
            int swap_tmp = board[row_tile][column_blank];
            board[row_tile][column_blank] = board[row_tile][column_tile];
            board[row_tile][column_tile] = swap_tmp;
            return true;
        }
    }
    else if(column_distance == 0)
    {
        if(row_distance == -1 || row_distance == 1)
        {
            // move vertically
            int swap_tmp = board[row_blank][column_tile];
            board[row_blank][column_tile] = board[row_tile][column_tile];
            board[row_tile][column_tile] = swap_tmp;
            return true;
        }
        
    }

    /* old version - bug with row distance
    
    if((row_distance + column_distance) == -1 || (row_distance + column_distance) == 1)
    {
        printf("swap something\n");
        // check whether move vertically or diagonally
        if(row_distance !=0)
        {
            // move vertically
            int swap_tmp = board[row_blank][column];
            board[row_blank][column] = board[row][column];
            board[row][column] = swap_tmp;
        }
        else
        {
            // move diagonally
            int swap_tmp = board[row][column_blank];
            board[row][column_blank] = board[row][column];
            board[row][column] = swap_tmp;
        }
        // tile moved sucesfully
        return true;
    }
    */
    
    // cant move tile
    return false;

// end move
}