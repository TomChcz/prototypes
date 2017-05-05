/****************************************************
 *                                                  *
 * Hash table in c                                  *
 *                                                  *
 * usage ./hashtable5                               *
 *                                                  *
 ****************************************************/

// count collisions to balance the hashtable??

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// definition of linked list node
typedef struct _hashnode
{
    char* string;
    struct _hashnode* next;
}
hashnode;

 

// function prototypes
unsigned int hash(char* input);
hashnode* create(hashnode* head, char* str);
void print(hashnode* hashtable[]);
void fileSave(hashnode* hashtable[]);
bool search(hashnode* hashtable[], char* searchString);

#define HASH_MAX 1000
#define NAMELENGTH_MAX 45

int main(void)
{
    // space fo user input including space for terminator \0
    char* name = malloc(NAMELENGTH_MAX * sizeof(char) + 1);
    // check for errors
    if(name == NULL)
    {
        fprintf(stderr, "\nMemory could not be allocated\n");
        return 1;
    }

    // open source file
    FILE* infilePtr = fopen("dictionary.txt", "r");
    // check for errors
    if(infilePtr == NULL)
    {
        fprintf(stderr, "File could not be opened\n");
        return 1;
    }

    // create hashtable
    hashnode* hashtable[HASH_MAX];
    
    // set all pointers in hashtable to NULL
    for(int x = 0; x < HASH_MAX; x++)
    {
        hashtable[x] = NULL;
    }
    
    // placeholder for hash code
    unsigned int hash_code; 
    
    // placeholder for words
    char word[NAMELENGTH_MAX+1];
    
    // read the input file until end
    while(fgets(word, NAMELENGTH_MAX+1, infilePtr) != NULL)
    {
        /* change first char to lowercase. Assumes uppercase only for first char in word does not handle 
        middle-word uppercase chars (e.g eBook). For that, build the word char by char using fgetc */
        word[0] = word[0] | 0x20; // always make sure this works even if first char is already lowercase
        
        // remove trailing newline
        if(word[strlen(word) - 1] == '\n')
        {
            word[strlen(word) - 1] = '\0';
        }
        
        // hash the word
        hash_code = hash(word);

        // collision check at insert to hashtable
        printf("hash_code[%i] %p\n", hash_code, hashtable[hash_code]);
        hashtable[hash_code] = create(hashtable[hash_code], word);
        
    // done reading file
    }
    
    // print the table
    print(hashtable);
    
    // save the table
    fileSave(hashtable);

    //placeholder for searched value
    char searchString[NAMELENGTH_MAX + 1];
    
    // prompt user for search
    printf("Search: ");
    scanf("%s", searchString);
    
    // look for string
    search(hashtable, searchString);

    // close input file
    fclose(infilePtr);

    return 0;
// end main
}

// hashes input and returns hash code
unsigned int hash(char* input)
{
    // TODO optimize to allocate codes in a balanced way to avoid long linked lists
    int sum = 0;
    
    for(int j = 0; input[j] != '\0'; j ++)
    {
        // add ascii value of string's j'th char to sum
        sum += input[j];
    }
    
    // return hash code witin hash size
    return sum % HASH_MAX;
    
// end hash
}

// creates node in linked list and returns its pointer
hashnode* create(hashnode* head, char* str)
{
    // create empty node
    hashnode* newNode = malloc(sizeof(hashnode));
    // check for memory errors
    if(newNode == NULL)
    {
        fprintf(stderr, "\nMemory could not be allocated\n");
        return NULL;
    }
    
    // allocate space for string
    newNode->string = malloc(strlen(str) * sizeof(char) + 1);
    
    // place user input in string member
    strcpy(newNode->string, str);
    
    // insert new node correctly
    if(head != NULL)
    {
        // keep the linked list connected
        newNode->next = head;
    }
    else
    {
        // no following node at this time
        newNode->next = NULL;
    }
    
    // return new node
    return newNode;
    
// end create  
}

void print(hashnode* hashtable[])
{
    printf("\nprint function HASHTABLE SUMMARY\n\n");
    
    // iterate over hashtable
    for(int j = 0; j < HASH_MAX; j++)
    {
        if(hashtable[j] == NULL)
        {
            // print that this hashtable position is empty
            printf("hashtable[%i] %p", j, hashtable[j]);
        }
        else
        {
            // initiate collision counter
            int collision = 0;
            
            // initiate trav node
            hashnode* trav = hashtable[j];
            
            // print the entire linked list and contents
            while(trav != NULL)
            {
                printf("hashtable[%i_%i] %p %s -> ", j, collision, trav, trav->string);
                // move to the next node
                trav = trav->next;
                // increment colission count
                collision++;
            }
        }
        printf("\n");
    }
    
// end print
}

void fileSave(hashnode* hashtable[])
{
    // open export file
    FILE* outptr = fopen("export.txt", "w");
    // check for memory errors
    if(outptr == NULL)
    {
        fprintf(stderr, "\nMemory could not be allocated\n");
    }
    else
    {
        fprintf(outptr, "\nfileSave function HASHTABLE SUMMARY\n\n");
        // iterate over hashtable
        for(int j = 0; j < HASH_MAX; j++)
        {
            if(hashtable[j] == NULL)
            {
                // print that this hashtable position is empty
                fprintf(outptr, "hashtable[%i] %p", j, hashtable[j]);
            }
            else
            {
                // initiate collision counter
                int collision = 0;
                
                // initiate trav node
                hashnode* trav = hashtable[j];
                
                // print the entire linked list and contents
                while(trav != NULL)
                {
                    // save contents of the node
                    fprintf(outptr, "hashtable[%i_%i] %p %s -> ", j, collision, trav, trav->string);
                    
                    // move to the next node
                    trav = trav->next;
                    // increment colission count
                    collision++;
                }
            }
            fprintf(outptr, "\n");
        }
    }
    fclose(outptr);
    
// end fileSave
}

bool search(hashnode* hashtable[], char* searchString)
{
    // remove trailing newline
    if(searchString[strlen(searchString) - 1] == '\n')
    {
        printf("newline found, removing...\n");
        searchString[strlen(searchString) - 1] = '\0';
    }

    // placeholder for hash code
    int hashCode;
    
    // hash the searchString
    hashCode = hash(searchString);
    printf("hash code of searchString is %i\n", hashCode);
    printf("Hashtable[%i] string %s\n", hashCode, hashtable[hashCode]->string); // TODO dodelat kontrolu
    
    // iterate over linked list
    if(hashtable[hashCode] == NULL)
    {
        printf("\nNOT FOUND1\n");
        return false;
    }
    else
    {
        // trav node
        hashnode* trav = hashtable[hashCode];
        
        // loop through linked list that begins at position [hashCode]
        while(trav != NULL)
        {
            // check node contents with searched value
            if(strcmp(trav->string, searchString) == 0)
            {
                printf("\nFOUND\n");
                return true;
            }
            else
            {
                // move to the next node
                trav = trav->next;
            }
        }
        
        printf("\nNOT FOUND\n");
        return false;

    }
    
// end search
}