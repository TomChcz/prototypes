/****************************************************
 *                                                  *
 * Single linked list in c, dynamic version         *
 *                                                  *
 * usage ./sllist3                                  *
 *                                                  *
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define list node
typedef struct sllist
{
    int value; // value of the node
    struct sllist* next; // pointer to the next node
}
sllnode;

// function prototypes
sllnode* create(int y);
sllnode* insert(sllnode* head, int n);
bool search(sllnode* head, int n);
void print(sllnode* head);
sllnode* destroy(sllnode* head);

/* create pointer to the first node as a global var to be used in entire program
initialize at NULL since points to nothing at this time */
sllnode* root = NULL;

int main(void)
{
    // switch variable
    int choice = 0;
    
    // placeholdder
    int switch_value;
    
    // display main menu until terminated by user
    mainMenu: while(choice !=6)
    {
        printf("\n####################################################\n");
        printf("# Singly Linked List creator, please choose        #\n");
        printf("#                                                  #\n");
        printf("# 1. Create list                                   #\n");
        printf("# 2. Insert node to the list                       #\n");
        printf("# 3. Search the list                               #\n");
        printf("# 4. Print the list                                #\n");
        printf("# 5. Delete the list                               #\n");
        printf("# 6. Exit                                          #\n");
        printf("#                                                  #\n");
        printf("####################################################\n");
        printf("\nYour choice: ");
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Please provide value for the first node: ");                
                
                // get user input
                scanf("%d", &switch_value);
                
                // create the list (first node in the list)
                root = create(switch_value);
    
                // make sure list was created
                if(root != NULL)
                {
                    printf("\nFirst node created sucesfully\n\n");
                }
                else
                {
                    return 1;
                }
                break;
                
            case 2:
                printf("Please enter value for another node: ");
                scanf("%d", &switch_value);
                
                // insert new node to the list
                root = insert(root, switch_value);
                // make sure node was added
                if(root != NULL)
                {
                    printf("\nNode added sucesfully\n\n");
                }
                else
                {
                    // show main menu again
                    goto mainMenu;
                }
                break;            
           
            case 3:
                printf("\nWhat do you want to find: ");
                scanf("%d", &switch_value);
                
                // search the list
                search(root, switch_value);
                break;

            case 4:
                // print list
                print(root);
                break;
                
            case 5:
                // delete list
                root = destroy(root);
                break;
            
            case 6:
                printf("Thanks for using, shutting down ...\n");
                // delete list and free up memory
                root = destroy(root);
                exit(0);
                break;
        }
    // end choice menu
    }

return 0;
// end main
}

sllnode* create(int y)
{
    // allocate space for new node
    sllnode* head = malloc(sizeof(sllnode));
    
    // check if memory allocated ok
    if(head == NULL)
    {
        fprintf(stderr, "\nCannot create first node (memory issue)\n");
        return NULL;
    }
    else
    {
        // add value to new node
        head->value = y;
    
        // add value to the pointer
        head->next = NULL;
        
        return head;
    }
    
// end create   
}

// this inserts new node right after root node (first)
sllnode* insert(sllnode* head, int n)
{
    // check if list exists
    if(head == NULL)
    {
        fprintf(stderr, "\nList not found, create list first\n");
        return NULL;
    }
    else
    {
        // create empty node in memory
        sllnode* current = malloc(sizeof(sllnode));
        
        // check for memory errors
        if(current == NULL)
        {
            fprintf(stderr, "\nMemory for node cant be allocated\n");
            return NULL;
        }

        // add value to the current node
        current->value = n;
        
        // pointer now points where head points
        current->next = head;

        // link the head to link to following node (or null)
        head = current;
        
        //success
        printf("\nNode with value %i created successfully\n\n", n);
        
        return current;
    }

// end insert
}

// searches the list for value
bool search(sllnode* head, int n)
{
    if(head == NULL)
    {
        fprintf(stderr, "\nList does not exist, create list first\n");
        return false;
    }
    else
    {
        // replicate root node links
        sllnode* trav = head;
        
        // search the list
        while(trav != NULL)
        {
            if(trav->value == n) // if found, return sucess
            {
                printf("\n%i found in the list\n", n);
                return true;
            }
            else // else move to next node and repeat
            {
                trav = trav->next;
            }
        }
        printf("\n%i not found in the list\n", n);
        return false; // return false after not found in entire list
    }

// end search
}

// prints the entire list
void print(sllnode* head)
{
    if(head == NULL)
    {
        fprintf(stderr, "\nList does not exist, create list first\n");
    }
    else
    {
        // node counter
        int counter = 1;
        printf("\nList summary\n");        
        while(head != NULL)
        {
            //print node contents

            printf("Node %i address: %p\n", counter, head);
            printf("Node %i value is: %i\n", counter, head->value);
            printf("Node %i ->: %p\n\n", counter, head->next);
            
            // move to next node
            head = head->next;
            
            // increment counter
            counter ++;
        }
    }
    
// end print
}

// deletes entire list
sllnode* destroy(sllnode* head)
{
    // recursively loop until last node
    if(head->next != NULL)
    {
        // delete rest of the list
        destroy(head->next);
    }

    // reset pointer to next node
    head->next = NULL;
    // free current node
    free(head);
    return NULL;
    
// end destroy
}