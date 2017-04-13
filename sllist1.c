/****************************************************
 *                                                  *
 * Single linked list in c                          *
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

// functin to insert node into existing list
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
    // create the list (first node in the list)
    root = create(6);
    
    // insert new node to the list
    root = insert(root, 7);
    
    // insert another node to the list
    root = insert(root, 8);
    
    // insert another node to the list
    root = insert(root, 155);
    
    // search the list
    if(search(root, 6) == true)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }
    
    // search the list, different syntax
    bool exists = search(root, 7);
    if(exists)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }
    
    // search the list
    if(search(root, 8) == true)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }
    
    // print list
    print(root);

// end main
}

sllnode* create(int y)
{
    // allocate space for new node
    sllnode* head = malloc(sizeof(sllnode));
    
    // check if memory allocated ok
    if(head == NULL)
    {
        fprintf(stderr, "cannot create node (memory issue)\n");
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