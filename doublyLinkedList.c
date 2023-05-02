#include <stdio.h>
#include <stdlib.h>


//LinkedList node
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node_L;

//method which allocates space for node and sets values
node_L make_node (int value, node_L* next, node_L* prev){
    struct node* newNode = (node_L*) malloc(sizeof(node_L));
    newNode->value = value;
    newNode->next = next;
    newNode->prev = prev;

    return *newNode;

    // node_L node = make_node(value, next, prev);  //poaaibly incorrect??
}


// add back function
void add_back(node_L** list, int value) {
    if(*list == NULL) {
        make_node(value, NULL, NULL);
    }
    else {
        node_L* cur = *list;
        while (cur != NULL){
            cur = cur->next;
        }

        node_L list = make_node(value, NULL, cur);
    }
}

// print the linked list
void print_list(struct node* list, int backwards) {
    struct node* cur = list;
    //cur = list;
    if (backwards == 0) {
        while (cur != NULL) {
            printf("%d ", cur->value);
            cur = cur->next;
        }
        printf("\n");
    }

}

// remove a node
void remove_node(struct node** list, int value) {

}


//main
int main(int argc, char** argv) {
	struct node* list = NULL;        // initially the tree is NULL
	add_back(&list, 42);
	add_back(&list, 13);
	add_back(&list, 50);
	add_back(&list, 15);
	add_back(&list, 2);
	print_list(list, 0);                // 42, 13, 50, 15, 2
  //print_list(list, 1);

	//remove_node(&list, 15);
	//remove_node(&list, 13);
	//remove_node(&list, 42);
	//print_list(list, 0);                // 50, 2
}
