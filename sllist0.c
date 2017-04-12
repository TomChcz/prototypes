/****************************************************
 *                                                  *
 * Single linked list in c                          *
 *                                                  *
 * usage ./sllist0                                   *
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

// function to create first node
sllnode* create(int y);

// function to search linked list
bool search(sllnode* head, int s);

// create pointer to the first node, itialize at NULL since points to nothing at this time
sllnode* root = NULL;

int main(void)
{
    // create first node
    sllnode* head = create(7);

    // allocate memory for root
    root = malloc(sizeof(sllnode));
    if(root == NULL)
    {
        fprintf(stderr, "cant allocate memory\n");
        return 1;
    }
    // point root to head node
    root->next = head;
    
    sllnode* head1 = create(8);
    
    head->next = head1;
    
    printf("address of root is %p\n", root);
    printf("root points to %p\n", root->next);
    printf("address of head is %p\n", head);
    printf("head points to %p\n", head->next);
    printf("address of head 1 is %p\n", head1);
    
    printf("head1 points to %p\n", head1->next);
    
    // search the list
    if(search(root, 7) == true)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }
        

// end main
}

sllnode* create(int y)
{
    // allocate space for new node
    sllnode* first = malloc(sizeof(sllnode));
    // check if memory allocated ok
    if(first == NULL)
    {
        fprintf(stderr, "cannot create node (memory issue)\n");
        return NULL;
    }
    else
    {
        // add value to new node
        first->value = y;
    
        // add value to the pointer
        first->next = NULL;
        
        return first;
    }
    
// end create   
}

bool search(sllnode* head, int s)
{
    while(head != NULL)
    {
        if(head->value == s)
        {
            return true;
        }
        else
        {
            head = head->next;
        }
    }
    return false;
    
// end search
}