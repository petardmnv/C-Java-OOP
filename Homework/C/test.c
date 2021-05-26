#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct list {
    int val;
    struct list * next;
};


struct node
{
	int value;
	struct list * values;
	struct node *left;
	struct node *right;
};

void push_list(struct list * head, int val) {
    struct list * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (struct list *) malloc(sizeof(struct list));
    current->next->val = val;
    current->next->next = NULL;
}

int sum_list(struct list * head) {
	int result = 0;
    struct list * current = head;

    while (current != NULL) {
    	result += current->val;
        current = current->next;
    }

  	return result;
}

void print_list(struct list * head) {
    struct list * current = head;
    printf("List items: ");
    while (current != NULL) {
    	printf("%d  ", current->val);
        current = current->next;
    }
    printf("\n");
}


struct node *newNode(int item) {
	struct node *node = (struct node *)malloc(sizeof(struct node));

	struct list *new_list = (struct list *) malloc(sizeof(struct list));
	new_list->next = NULL;
	new_list->val = item;

	node->value = item;
	node->values = new_list;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void add_item(struct node *root, int item){
	if (item > 100){
		printf("Ur item weight is bigger than 100. It couldn't fit in the basket.\n");
	}
	struct node * current_root = root;
	while(current_root->value > 100){
		if (sum_list(root->left->values) > sum_list(root->right->values)){
			current_root = root->right;
		}else{
			current_root = root->left;
		}
	}


	if(current_root->value + item < 100){
		current_root->value += item;
		push_list(current_root->values, item);
	}
	/*else{
		if(current_root->right == NULL && current_root->left == NULL){
			// Suzdavat se deca i itemite ot parent list se premestvat v decata poravno

			struct list *new_list = (struct list *) malloc(sizeof(struct list));
			new_list->next = NULL;
			new_list->val = 0;

			current_root->left->value = 0;
			current_root->left->values = new_list;
			current_root->left->left = NULL;
			current_root->left->right = NULL;

			current_root->right->value = 0;
			current_root->right->values = new_list;
			current_root->right->left = NULL;
			current_root->right->right = NULL;

			struct list* current = current_root->values;
			while (current != NULL) {
				if (sum_list(current_root->left->values) > sum_list(current_root->right->values)){
					push_list(current_root->right->values, current->val);
				}else{
					push_list(current_root->left->values, current->val);
				}
	        	current = current->next;
	    	}
		}

		// Dobavq se noviq item
		// Promenqt se weights na roditelite
		if(current_root->right->value > current_root->left->value){
			current_root->left->value += item;
			push_list(current_root->left->values, item);
		}else{
			current_root->right->value += item;
			push_list(current_root->right->values, item);
		}

	}*/
}

int main(int argc, char const *argv[]){
	
	struct node *root;
	root = newNode(11);

	add_item(root, 22);
	add_item(root, 33);

	/*add_item(root, 44);
	add_item(root, 55);
	add_item(root, 66);*/

	add_item(root, 120);

	printf("Value: %d\n", root->value);
	print_list(root->values);





	// Evala za zada4ata pi4ove

	return 0;
}