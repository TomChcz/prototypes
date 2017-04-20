/****************************************************
 *                                                  *
 * Doubly linked list in c, dynamic version         *
 *                                                  *
 * usage ./dllist3                                  *
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
void fileSave(dllnode* head);
dllnode* deleteNode(dllnode* head, char* s);
dllnode* deleteList(dllnode* head);
void memError();
void listError();

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
                printf("\nPointer %p\n", switch_value);
                root = create(root, switch_value);
                break;
                
            case 2:
                printf("\nPlease enter value for node: ");
                scanf(" %[^\n]s", switch_value); // avoid newline
                printf("\nYou have entered %s\n", switch_value);
                printf("\nPointer %p\n", switch_value);
                root = insert(root, switch_value);
                break;
                
            case 3:
                printf("\nWhat do you want to find: ");
                scanf(" %[^\n]s", switch_value);
                printf("\nYou are searching for: %s\n", switch_value);
                printf("\nPointer %p\n", switch_value);
                search(root, switch_value);
                break;
            
            case 4:
                print(root);
                break;
                
            case 5:
                fileSave(root);
                break;
                
            case 6:
                printf("\nWhat do you want to delete: ");
                scanf(" %[^\n]s", switch_value);
                printf("\nYou want to delete: %s\n", switch_value);
                printf("\nPointer %p\n", switch_value);
                root = deleteNode(root, switch_value);
                break;

            case 7:
                root = deleteList(root);
                break;
            
            case 8:
                // check if list exists
                if(root != NULL)
                {
                    // delete list and free up memory
                    root = deleteList(root);
                }
                printf("\nThanks for using, shutting down ...\n");
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
        
        // check for memory error
        if(newRoot == NULL)
        {
            memError();
            return NULL;
        }
        else
        {
            // allocate memory for node value, add 1 byte for string terminator
            newRoot->string = malloc(maxNameSize * sizeof(char) + 1);
            
            // check for memory error
            if(newRoot->string == NULL)
            {
                memError();
                return NULL;
            }
            else
            {
                // put value in node
                strcpy(newRoot->string, s);
                newRoot->prev = NULL;
                newRoot->next = NULL;
                
                printf("\nFirst node created OK\n");
                
                return newRoot;
            }
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
        listError(); //printf("\nList does not exist, create first node using create function\n");
        return NULL;
    }
    else
    {
        // create empty node
        dllnode* current = malloc(sizeof(dllnode));
        
        // check for memory error
        if(current == NULL)
        {
            memError();
            return NULL;
        }
        else
        {
            // allocate memory for node value, add 1 byte for string terminator
            current->string = malloc(maxNameSize * sizeof(char) + 1);
            
            // check for memory error
            if(current->string == NULL)
            {
                memError();
                return NULL;
            }
            else
            {
                // put value in node
                strcpy(current->string, s);
                
                // link ->next pointer to head
                current->next = head;
                
                // set ->prev pointer to NULL since current becomes the head of the list
                current->prev = NULL;
                
                // update backlink of head, since it moves after 
                head->prev = current;
                
                // make current had of the list
                head = current;
                
                printf("\nNode created OK\n");
                
                return current;
            }
        }
    }
    
// end insert
}

bool search(dllnode* head, char* s)
{
    // check if list exists
    if(head == NULL)
    {
        listError();
        // printf("\nList does not exist, create first node using create function\n");
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
                // move to the next node
                trav = trav->next;
            }
        }
        
        printf("\nNot found\n");
        
        // release memory
        free(trav);
        
        return false;
    }

// end search
}

// print the list
void print(dllnode* head)
{
    if(head == NULL)
    {
        listError();
        // printf("\nList does not exist, create first node using create function\n");
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
        // release memory
        free(trav);
    }

// end print
}

// saves list into a file
void fileSave(dllnode* head)
{
    // check if list exists
    if(head == NULL)
    {
        listError();
    }
    else
    {
        // open file for writing
        FILE *outfile = fopen("nodes.csv", "w");

        // traverse node
        dllnode* trav = head;
        
        while(trav != NULL)
        {
            // write node to file
            fwrite(trav->string, strlen(trav->string), 1, outfile);
            
            // save csv delimiter
            if(trav->next != NULL)
            {
                fputc(',', outfile);
            }
            
            // move to the next node in the list
            trav = trav->next;
        }
        
        // close file
        fclose(outfile);
        
        // prevent memory leak
        free(trav);
    }
    
// end fileSave
}

// deletes single node specified by the user

dllnode* deleteNode(dllnode* head, char* s)
{
    // check if list exists
    if(head == NULL)
    {
        listError();
        // printf("\nList does not exist, cant delete node\n");
        return NULL;
    }
    else
    {
        // remember position of first node
        dllnode* rootAnchor = head;

        // USE SEARCH FUNCTION INSTEAD??
        
        while(head != NULL)
        {
            // if string for deletion found
            if(strcmp(head->string, s) == 0)
            {
                if(head->prev == NULL) // check if node is the head of the list
                {
                    printf("\nNode for deletion found\n");
                    // delete string contents
                    free(head->string);
                    
                    // check if has following node and change its -> prev pointer to null
                    if(head->next != NULL)
                    {
                        // change prev pointer of next node to null since head is being deleted
                        head->next->prev = NULL;
                    }
                    
                    // returns pointer to next node (if pointed to) or NULL if there is no following pointer
                    rootAnchor = head->next;
                    
                    // delete node
                    free(head);
                    
                    return rootAnchor;

                }
                else if(head->next == NULL && head->prev != NULL) // check if node is the last node
                {
                    // delete string contents
                    free(head->string);
                    
                    // reroute ->next pointer of previous node
                    head->prev->next = NULL;
                    
                    // reset pointer to previous node
                    head->prev = NULL;
                    
                    // delete pointers
                    head->next = NULL;
                    
                    // delete node
                    free(head);
                    
                    // return pointer to unchanged beginning of the list
                    return rootAnchor;
                }
                else // aka middle node (->prev and ->next != NULL)
                {
                    // delete string contents
                    free(head->string);
                    
                    // reroute previous node
                    head->prev->next = head->next;
                    
                    // reroute next node
                    head->next->prev = head->prev;
                    
                    // delete pointers
                    head->prev = NULL;
                    head->next = NULL;
                    
                    // delete node
                    free(head);
                    
                    // return pointer to unchanged beginning of the list
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
        return rootAnchor;
    }
    
// end deleteNode
}

// deletes entire list
dllnode* deleteList(dllnode* head)
{
    if(head == NULL)
    {
        listError();
        // printf("\nList does not exist, cant delete\n");
        return NULL;
    }
    else
    {
        if(head->next != NULL)
        {
            // delete rest of the list recursively
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

// memory error message
void memError()
{
    fprintf(stderr, "\nMemory could not be allocated\n");
}

// error message
void listError()
{
    printf("\nList does not exist, create one first\n");
}