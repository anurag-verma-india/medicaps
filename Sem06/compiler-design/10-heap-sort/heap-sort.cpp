#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a memory block in our heap
typedef struct Block {
    int id;             // Block identifier
    int size;           // Size of the block
    bool allocated;     // Whether block is allocated or free
    struct Block* next; // Pointer to the next block
} Block;

// Global variables
Block* heap = NULL;     // Head of our heap linked list
int nextId = 1;         // ID for the next block to be created

// Function to create the initial heap
void createHeap(int size) {
    // Free the existing heap if any
    Block* current = heap;
    while (current != NULL) {
        Block* temp = current;
        current = current->next;
        free(temp);
    }
    
    // Create a new heap with a single free block
    heap = (Block*)malloc(sizeof(Block));
    if (heap == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    heap->id = 0;
    heap->size = size;
    heap->allocated = false;
    heap->next = NULL;
    
    printf("Heap created with size %d\n", size);
}

// First-fit allocation strategy
void allocateBlock(int requestSize) {
    Block* current = heap;
    Block* newBlock;
    
    while (current != NULL) {
        // Find the first free block that's large enough
        if (!current->allocated && current->size >= requestSize) {
            // If the block is much larger than needed, split it
            if (current->size > requestSize + sizeof(Block)) {
                newBlock = (Block*)malloc(sizeof(Block));
                if (newBlock == NULL) {
                    printf("Memory allocation failed\n");
                    return;
                }
                
                newBlock->id = nextId++;
                newBlock->size = current->size - requestSize;
                newBlock->allocated = false;
                newBlock->next = current->next;
                
                current->size = requestSize;
                current->next = newBlock;
            }
            
            current->allocated = true;
            current->id = nextId++;
            printf("Allocated block ID %d of size %d\n", current->id, current->size);
            return;
        }
        current = current->next;
    }
    
    printf("Failed to allocate block of size %d: No suitable free space\n", requestSize);
}

// Function to deallocate a block
void deallocateBlock(int id) {
    Block* current = heap;
    Block* prev = NULL;
    
    // Find the block with the given ID
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Block with ID %d not found\n", id);
        return;
    }
    
    // Mark the block as free
    current->allocated = false;
    printf("Deallocated block ID %d\n", id);
    
    // Coalesce with next block if it's free
    if (current->next != NULL && !current->next->allocated) {
        Block* nextBlock = current->next;
        current->size += nextBlock->size;
        current->next = nextBlock->next;
        free(nextBlock);
    }
    
    // Coalesce with previous block if it's free
    if (prev != NULL && !prev->allocated) {
        prev->size += current->size;
        prev->next = current->next;
        free(current);
    }
}

// Function to display the current state of the heap
void displayHeap() {
    Block* current = heap;
    int blockCount = 0;
    
    if (current == NULL) {
        printf("Heap is empty\n");
        return;
    }
    
    printf("\nCurrent Heap State:\n");
    printf("-------------------\n");
    printf("ID\tSize\tStatus\n");
    printf("-------------------\n");
    
    while (current != NULL) {
        printf("%d\t%d\t%s\n", current->id, current->size, 
               current->allocated ? "Allocated" : "Free");
        current = current->next;
        blockCount++;
    }
    
    printf("-------------------\n");
    printf("Total blocks: %d\n\n", blockCount);
}

// Main function with menu
int main() {
    int choice, size, id;
    
    do {
        printf("\nHeap Storage Allocation Menu:\n");
        printf("1. Create Heap\n");
        printf("2. Allocate Block\n");
        printf("3. Deallocate Block\n");
        printf("4. Display Heap\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter heap size: ");
                scanf("%d", &size);
                createHeap(size);
                displayHeap();
                break;
                
            case 2:
                printf("Enter block size to allocate: ");
                scanf("%d", &size);
                allocateBlock(size);
                displayHeap();
                break;
                
            case 3:
                printf("Enter block ID to deallocate: ");
                scanf("%d", &id);
                deallocateBlock(id);
                displayHeap();
                break;
                
            case 4:
                displayHeap();
                break;
                
            case 0:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    // Clean up the heap before exiting
    Block* current = heap;
    while (current != NULL) {
        Block* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

