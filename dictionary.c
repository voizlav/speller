// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
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

// Count words in dictionary
int word_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash input word
    unsigned int to_hash = hash(word);

    node *checker = table[to_hash];
    if (checker == NULL)
    {
        return false;
    }

    // Traverse through linked list in table
    while (checker != NULL)
    {
        // Compare input word with the word from the list
        if (strcasecmp(checker->word, word) == 0)
        {
            return true;
        }

        // Keep moving
        checker = checker->next;
    }

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
        print("Could not open file.\n");
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
        word_counter++;
        // Create a new node for each word
        node *map_word = malloc(sizeof(node));
        if (map_word == NULL)
        {
            print("Could not allocate memory for map_word.\n");
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
            table[to_hash]->next = map_word;
        }
        else
        {
            map_word->next = table[to_hash]->next;
            table[to_hash]->next = map_word;
        }   
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *checker = table[i];

        while (checker != NULL)
        {
            node *tmp = checker;
            checker = checker->next;
            free(tmp);
        }
        
        return true;
    }
    
    return false;
}
