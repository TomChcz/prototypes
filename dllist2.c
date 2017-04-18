/****************************************************
 *                                                  *
 * Doubly linked list in c, dynamic version         *
 *                                                  *
 * usage ./dllist1                                  *
 *                                                  *
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxNameSize 40

// node model
typedef struct dllist
{
    char* string; // value
    struct dllist* next; // -> next node
    struct dllist* prev; // <- previous node
}
dllnode;

// function prototypes
dllnode* create(dllnode* head, char* s);
dllnode* insert(dllnode* head, char* s);
bool search(dllnode* head, char* s);
void print(dllnode* head);
// TODO file export function
dllnode* deleteNode(dllnode* head, char* s);
dllnode* deleteList(dllnode* head);

// initiate global root pointer
dllnode* root = NULL;

int main(void)
{
    // menu variable
    int choice = 0;
    
    // placeholdder
    char switch_value[maxNameSize];
    
    // display main menu until terminated by user
    while(choice !=8)
    {
        printf("\n####################################################\n");
        printf("# Doubly Linked List creator, please choose        #\n");
        printf("#                                                  #\n");
        printf("# 1. Create list                                   #\n");
        printf("# 2. Insert node to the list                       #\n");
        printf("# 3. Search the list                               #\n");
        printf("# 4. Print the list                                #\n");
        printf("# 5. Save the list to a file                       #\n");
        printf("# 6. Remove node from the list                     #\n");
        printf("# 7. Delete the list                               #\n");
        printf("# 8. Exit                                          #\n");
        printf("#                                                  #\n");
        printf("####################################################\n");
        printf("\nYour choice: ");
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nPlease enter value for first node: ");
                scanf(" %[^\n]s", switch_value); // avoid newline
                printf("\nYou have entered %s\n", switch_value);
                printf("\nPointer %p", switch_value);
                root = create(root, switch_value);
                break;
                
            case 2:
                printf("\nPlease enter value for node: ");
                scanf(" %[^\n]s", switch_value); // avoid newline
                printf("\nYou have entered %s\n", switch_value);
                root = insert(root, switch_value);
                break;
                
            case 3:
                printf("\nWhat do you want to find: ");
                scanf(" %[^\n]s", switch_value);
                printf("\nYou are searching for: %s\n", switch_value);
                search(root, switch_value);
                break;
            
            case 4:
                print(root);
                break;
                
            case 6:
                printf("\nWhat do you want to delete: ");
                scanf(" %[^\n]s", switch_value);
                printf("\nYou want to delete: %s\n", switch_value);
                root = deleteNode(root, switch_value);
                break;

            case 7:
                root = deleteList(root);
                break;
            
            case 8:
                printf("\nThanks for using, shutting down ...\n");

                // check if list exists
                if(root != NULL)
                {
                    // delete list and free up memory
                    root = deleteList(root);
                }
                exit(0);
                break;
        }
    }

return 0;
// end main
}

// creates first node
dllnode* create(dllnode* head, char* s)
{
    // check if list exists
    if(head != NULL)
    {
        printf("\nList already exists, use insert function instead\n");
        return head;
    }
    else
    {
        // allocate space for node
        dllnode* newRoot = malloc(sizeof(dllnode));
        
        // check for memory errors
        if(newRoot == NULL)
        {
            fprintf(stderr, "Memory for first node could not be allocated\n");
            return NULL;
        }
        else
        {
            // allocate memory for node value
            newRoot->string = malloc(maxNameSize * sizeof(char) + 1);
            
            // add check - best as function
            
            // put value in node
            strcpy(newRoot->string, s);
            // newRoot->string = s;
            newRoot->prev = NULL;
            newRoot->next = NULL;
            
            printf("\nFirst node created OK\n");
            
            return newRoot;
        }        
    }

// end create
}

// adds node to the list
dllnode* insert(dllnode* head, char* s)
{
    // check if list exists
    if(head == NULL)
    {
        printf("\nList does not exist, create first node using create function\n");
        return NULL;
    }
    else
    {
        // create empty node
        dllnode* current = malloc(sizeof(dllnode));
        
        // check for memory errors
        if(current == NULL)
        {
            fprintf(stderr, "\nMemory for node could not be allocated\n");
            return NULL;
        }
        else
        {
            current->string = malloc(maxNameSize * sizeof(char) + 1);
            
            // put value in node
            strcpy(current->string, s);
            // current->string = s;
            
            current->next = head;
            
            current->prev = NULL;
            
            // update backlink of head
            head->prev = current;
            
            // link previous head to this node
            head = current;
            
            printf("\nNode created OK\n");
            
            return current;
        }
    }
    
// end insert
}

bool search(dllnode* head, char* s)
{
    // check if list exists
    if(head == NULL)
    {
        printf("\nList does not exist, create first node using create function\n");
        return false;
    }
    else
    {
        // trav pointer
        dllnode* trav = head;
        
        // search the list
        while(trav != NULL)
        {
            // compare strings
            if(strcmp(trav->string, s) == 0)
            {
                printf("\nFound\n");
                return true;
            }
            else
            {
                trav = trav->next;
            }
        }
        
        printf("\nNot found\n");
        return false;
    }

// end search
}

// print the list
void print(dllnode* head)
{
    if(head == NULL)
    {
        printf("\nList does not exist, create first node using create function\n");
    }
    else
    {
        // node for traversing
        dllnode* trav = head;
        
        // go through to the end of the list
        while(trav != NULL)
        {
            printf("\nAddress: %p\n", trav);
            printf("Value: %s\n", trav->string);
            printf("String ptr: %p\n", trav->string);
            printf("Prev: %p\n", trav->prev);
            printf("Next: %p\n", trav->next);
            
            trav = trav->next;
        }
    }
    
// end print
}

// deletes single node specified by the user

dllnode* deleteNode(dllnode* head, char* s)
{
    if(head == NULL)
    {
        printf("\nList does not exist, cant delete node\n");
        return NULL;
    }
    else
    {
        // remember position of first node
        dllnode* rootAnchor = head;
        // dllnode* trav = head;
        
        while(head != NULL)
        {
            // if string for deletion found
            if(strcmp(head->string, s) == 0)
            {
                if(head->prev == NULL) // check if first node
                {
                    printf("\nNode for deletion found\n");
                    // delete string contents
                    
                    free(head->string);
                    free(head->prev);
                    
                    // check if has following node and change its -> prev pointer to null
                    // returns pointer to next node (if pointed to) or NULL if there is no following pointer
                    return head->next;
                }
                else if(head->next == NULL && head->prev != NULL) // check if last node
                {
                    //delete last node and return pointer to begging of the list (rootAnchor)
                    head->string = NULL;
                    free(head->string);
                    
                    // reroute ->next pointer of previous node
                    head->prev->next = NULL;
                    
                    // reset pointer to previous node
                    head->prev = NULL;
                    free(head);
                    return rootAnchor;
                }
                else
                {
                    free(head->string);
                    // reroute previous node
                    head->prev->next = head->next;
                    // reroute next node
                    head->next->prev = head->prev;
                    return rootAnchor;
                }
 
            }
            else
            {
                // move to the next node
                head = head->next;
            }
        }
        
        // not found, cant delete
        printf("\nNode for deletion cant be found, aborted\n");
        return NULL;
    }
    
// end deleteNode
}

// deletes entire list
dllnode* deleteList(dllnode* head)
{
    if(head == NULL)
    {
        printf("\nList does not exist, cant delete\n");
        return NULL;
    }
    else
    {
        if(head->next != NULL)
        {
            // delete rest of the list
            deleteList(head->next);
        }
        
        // reset pointer to next node
        head->next = NULL;
        head->prev = NULL;
        // free current node
        free(head->string);
        free(head);
        return NULL;
    }

// end deleteList
}