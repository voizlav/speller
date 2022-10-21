// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0] - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open the input file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        print("Could not open file.");
        return false;
    }

    for (int i = 0; i <= N; i++)
    {
        table[i]->next = NULL;
        strcpy(table[i]->word, i);
    }
    
    char tmp[LENGTH + 1];

    // Iterate through the entire input file
    while (fscanf(input, "%s", tmp) != EOF)
    {
        // Create a new node for each word
        node *map_word = malloc(sizeof(node));
        if (map_word == NULL)
        {
            print("Could not allocate memory.\n");
            return false;
        }
        // Copy the word into the node
        strcpy(map_word->word, tmp);
        map_word->next = NULL;

        // Hash word to obtain hash value
        unsigned int to_hash = hash(tmp);

        // Insert node at the hash table at that location
        if (table[to_hash] == NULL)
        {
            map_word->next = table[to_hash];
        }
        else
        {
            // TODO
            map_word->next = table[to_hash]->next;
        }   
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
