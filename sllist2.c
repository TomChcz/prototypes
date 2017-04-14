/****************************************************
 *                                                  *
 * Single linked list in c, dynamic version         *
 *                                                  *
 * usage ./sllist2                                  *
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

// function to create first node/list
sllnode* create(int y);

// functin to insert node at the beginning of the list
sllnode* insert(sllnode* head, int n);

// function to search linked list
bool search(sllnode* head, int s);

// function to print linked list
void print(sllnode* head);

/* create pointer to the first node as a global var to be used in entire program
initialize at NULL since points to nothing at this time */
sllnode* root = NULL;

int main(void)
{
    printf("\n####################################################\n");
    printf("# Singly Linked List creator                       #\n");
    printf("# Available functions: create, insert, search      #\n");
    printf("####################################################\n\n");
    printf("Please provide value for the first node: ");
    
    int root_value;
    
    // get user input
    scanf("%d", &root_value);
    
    // create the list (first node in the list)
    root = create(root_value);
    
    // make sure list was created
    if(root != NULL)
    {
        printf("\nFirst node created sucesfully\n\n");
    }
    else
    {
        return 1;
    }

    // variables for user choice
    char answer;
    int another_node;

    do
    {
        printf("Do you wish to insert another node? (Y/N): ");
        scanf(" %c", &answer);
        
        if(answer == 'Y' || answer == 'y')
        {
            printf("Please enter value for another node: ");
            scanf("%i", &another_node);
            
            // insert new node to the list
            root = insert(root, another_node);
        }
    }
    while(answer == 'Y' || answer == 'y');

    
    printf("give me something to search for in the list: ");
    int searched_value;
    scanf("%d", &searched_value);
    
    // search the list
    if(search(root, searched_value) == true)
    {
        printf("\n%i found\n\n", searched_value);
    }
    else
    {
        printf("\nnot found\n\n");
    }
    
    char print_choice;
    printf("Do you want to print the list? (Y/N): ");
    scanf(" %c", &print_choice);
    
    if(print_choice == 'y' || print_choice == 'Y')
    {
        // print list
        print(root);
    }
    else
    {
        printf("\n#program terminated#\n");
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
        fprintf(stderr, "cannot create first node (memory issue)\n");
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

bool search(sllnode* head, int s)
{
    // replicate root node links
    sllnode* trav = head;
    
    // search the list
    while(trav != NULL)
    {
        if(trav->value == s) // if found, return sucess
        {
            return true;
        }
        else // else move to next node and repeat
        {
            trav = trav->next;
        }
    }
    return false; // return false after not found in entire list
    
// end search
}

// this inserts new node right after root node (first)
sllnode* insert(sllnode* head, int n)
{
    // check if list exists
    if(head == NULL)
    {
        fprintf(stderr, "list not found, create list first\n");
        return NULL;
    }
    else
    {
        // create empty node in memory
        sllnode* current = malloc(sizeof(sllnode));
        
        // check for memory errors
        if(current == NULL)
        {
            fprintf(stderr, "memory for node cant be allocated\n");
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

void print(sllnode* head)
{
    if(head == NULL)
    {
        fprintf(stderr, "list does not exist\n");
    }
    
    // node counter
    int counter = 1;
    
    while(head != NULL)
    {
        //print node coordinates
        printf("Node %i address: %p\n", counter, head);
        printf("Node %i value is: %i\n", counter, head->value);
        printf("Node %i points to: %p\n", counter, head->next);
        
        // move to next node
        head = head->next;
        
        // increment counter
        counter ++;
    }
    
// end print
}