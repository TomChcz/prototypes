/****************************************************
 *                                                  *
 * Hash table in c                                  *
 *                                                  *
 * usage ./hashtable                                *
 *                                                  *
 ****************************************************/

// need to correct how array is defined (not a pointer at this time)

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
hashnode* create(char* str);
void print(hashnode* hashtable[]);
bool search(hashnode* hashtable[], char* searchString);


#define HASH_MAX 5
#define NAMELENGTH_MAX 45

int main(void)
{
    // space fo user input including space for terminator
    char* name = malloc(NAMELENGTH_MAX * sizeof(char) + 1);
    // check for errors
    if(name == NULL)
    {
        fprintf(stderr, "\nMemory could not be allocated\n");
        return 1;
    }

    // open source file
    FILE* infilePtr = fopen("text.txt", "r");

    // create hashtable
    hashnode* hashtable[HASH_MAX];

    // placeholder for hash code
    unsigned int hash_code;    
    
    // placeholder for words
    char word[NAMELENGTH_MAX+1];
    
    while(fgets(word, NAMELENGTH_MAX+1, infilePtr) != NULL)
    {
        printf("word before lowercase conversion: %s\n", word);
        // change first char to lowercase. Assumes uppercase only for first char in word does not handle middle-word uppercase chars (e.g eBook)
        word[0] = word[0] | 0x20; // make sure this works if first char is already lowercase
        
        // remove trailing newline
        if(word[strlen(word) - 1] == '\n')
        {
            printf("newline found, removing...\n");
            word[strlen(word) - 1] = '\0';
        }
        
        hash_code = hash(word);
        printf("word %s hash code %i\n", word, hash_code);
        printf("word lentgh %lu\n", strlen(word));
        
        // create node and put pointer into slot in hashtable (array)
        hashtable[hash_code] = create(word);
    }

    // hashtable array print check
    for(int i = 0; i < HASH_MAX; i++)
    {
        printf("hashtable[%i] address %p -> ", i, hashtable[i]);
        printf("%s\n", hashtable[i]->string);
    }

    // prints the table
    print(hashtable);
    
    char searchString[NAMELENGTH_MAX + 1];
    
    // prompt user for search
    printf("Search: ");
    scanf("%s", searchString);
    
    // look for string
    search(hashtable, searchString);

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
hashnode* create(char* str)
{
    // TODO resolve collisions - not handled in this version
    
    // create empty node
    hashnode* newNode = malloc(sizeof(hashnode));
    // check for memory errors
    if(newNode == NULL)
    {
        fprintf(stderr, "\nMemory could not be allocated\n");
    }
    
    // allocate space for string
    newNode->string = malloc(strlen(str) * sizeof(char) + 1);
    
    // place user input in string member
    strcpy(newNode->string, str);
    
    // set next pointer to NULL
    newNode->next = NULL;
    
    // return pointer
    return newNode;
    
// end create  
}

void print(hashnode* hashtable[])
{
    printf("\nHASHTABLE SUMMARY\n\n");
    for(int j = 0; j < HASH_MAX; j++)
    {
        printf("Hashtable[%2i] -> %p string %s ->next %p\n", j, hashtable[j], hashtable[j]->string, hashtable[j]->next);
    }
    
// end print
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
    printf("Hashtable[%i] string %s\n", hashCode, hashtable[hashCode]->string);
    
    if(strcmp(hashtable[hashCode]->string, searchString) == 0)
    {
        printf("\nFOUND\n");
        return true;
    }
    else
    {
        printf("\nNOT FOUND\n");
        return false;
    }
    
// end search
}