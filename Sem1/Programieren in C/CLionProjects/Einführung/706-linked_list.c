/* Linked list.c 

   The (linked/chained) list is a very important concept to manage sets of items dynamically:
   - The maximum number of elements does not need to be known in advance
   - Elements can have different sizes
   - Elements can be added and removed flexibly 

   Key concepts:
   - Each data item is stored in its own section of memory
   - There is a pointer to the first data item (or NULL, when the list is empty)
   - Each data item has a pointer to the next item in the list (or to NULL, if it's the last item in the list)
   
   The code below already contains some important definitions and functions.

✓  TO DO 1: Have a look at the program, get it to run and try to understand how it works.
            - Print out pointer values to keep track of what the program does.
			- At what position is a new item added to the list: beginning or end?           Answer: Beginning
✓  TO DO 2: Extend the main function such that more items are added to the list
✓  TO DO 3: Complete the function print_items to print for each item in the list:
			- the name, the address in memory and the address of its successor
            In addition, calculate the sum of all data payloads.
✓  TO DO 4: Write a function find_item(...) that searches the list for an item with a given guid.
✓  TO DO 5: Change the program such that the memory required for 'data' can be allocated flexibly:
            in struct: unsigned char *data;
	        ptr->data=malloc(ptr->size*sizeof(unsigned char)); // Remember to check for NULL Pointer
✓  TO DO 6: (optional) Write a function delete_item(...) to delete an item from the list.
   TO DO 7: (optional) Experiment with 'memory leaks': 
            - Increase the size of the payload. 
			- 'Forget' in the delete function to free the memory correctly.
			- Add and remove items frequently in a big loop.
			- Use the task manager to see what happens with memory.
*/

#include <stdio.h>
#include <stdlib.h>

// Data structure of the individual items in the list.
struct myListItemStruct {
    int guid;                               // a unique id to identify the list item
    char name[128];                         // a name to represent the item
    unsigned char *data;                    // arbitrary data 'payload'
    int size;                               // size of data
    struct myListItemStruct *next_item;     // pointer to next item
};

// Define an own type for shorter declarations
typedef struct myListItemStruct itemType;

// create_item:
// Creates and initializes a new item, or returns NULL, if it could not allocate memory.
itemType *create_item() {
    static int guid_ctr = 0; // static counter to create unique ids
    itemType *ptr;

    ptr = malloc(sizeof(itemType)); // Allocate memory for the list item
    if (ptr != NULL) {
        ptr->guid = guid_ctr++; // Generate a unique ID
        printf("Enter name:");
        scanf("%s", ptr->name); // Enter a name
        ptr->data = malloc(10000 * sizeof(unsigned char)); // Allocate memory for the data payload
        if (ptr->data == NULL) {
            free(ptr); // Free the memory of the list item
            return NULL; // Return NULL, if memory allocation failed
        }
        printf("Enter Data:");
        scanf("%s", ptr->data); // Enter data
        //get the size of the data by iterating through the data to find the null terminator
        for (ptr->size = 0; ptr->data[ptr->size] != '\0'; ptr->size++) {}

        ptr->next_item = NULL; // Initialize the pointer to the next item

    }
    return ptr; // Return pointer to the new item
}

// Insert_item:
// Inserts an existing item into the (potentially empty) list
void insert_item(itemType *new_item, itemType **list_ptr) {
    new_item->next_item = *list_ptr; // Append existing list to new item
    *list_ptr = new_item; // Set list_ptr to points to new item
}


// print all items
void print_items(itemType *list_start) {
    itemType *current = list_start;
    long sum = 0;
    while (current != NULL) {
        printf("GUID: %d; ", current->guid);
        printf("NAME: %s; ", current->name);
        printf("DATA: ");
        for (int i = 0; i < current->size; ++i) printf("%c", current->data[i]);
        printf("; ADDRESS: %p; ", current);
        current->next_item == NULL ? printf("END\n") : printf("NEXT: %p\n", current->next_item);
        sum += current->size;
        current = current->next_item;
    }
    printf("Sum of all data sizes: %ld\n", sum);
}

// Finds an item with guid in the list (linear search)
itemType *find_item(int guid, itemType *list_start) {
    itemType *current = list_start;
    while (current != NULL) {
        if (current->guid == guid) return current;
        current = current->next_item;
    }
    return NULL;
}

// Deletes an item and returns the successor of the deleted item
// The chaining of the previous and next element has to be done
// by the caller.
itemType *simple_delete_item(itemType *item) {
    itemType *next = item->next_item;
    free(item->data); // Free the memory of the data payload
    free(item); // Free the memory of the list item
    return next;
}

// Complete delete item
// Deletes item 'to_delete' from the 'list'
// return 0, if the item does not exist in the list, otherwise 1
int delete_item(itemType *to_delete, itemType **list_ptr) {
    if (*list_ptr == NULL) return 0;
    if (*list_ptr == to_delete) {
        *list_ptr = simple_delete_item(to_delete);
        return 1;
    }
    itemType *current = *list_ptr;
    while (current->next_item != NULL) {
        if (current->next_item == to_delete) {
            current->next_item = simple_delete_item(to_delete);
            return 1;
        }
        current = current->next_item;
    }
}


int main() {
    itemType *my_list = NULL;
    itemType *current;

    current = create_item();
    insert_item(current, &my_list);
    current = create_item();
    insert_item(current, &my_list);
    current = create_item();
    insert_item(current, &my_list);

    print_items(my_list);

    printf("delete item with guid: ");
    int guid;
    scanf("%d", &guid);
    printf("Deleting item with guid %d\n", guid);
    current = find_item(guid, my_list);
    printf("Item found: %p\n", current);
    delete_item(current, &my_list);
    print_items(my_list);

}
