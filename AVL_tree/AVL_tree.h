#include <stdio.h>
#include <stdlib.h>

#define LH 1
#define EH 0
#define RH -1

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int balance;
}T_NODE;

typedef struct tree{
	int count;
	T_NODE* root;
}AVL_TREE;

AVL_TREE* create_avl_tree();

bool AVL_insert(AVL_TREE* tree, int data);
T_NODE* insert_rotate(T_NODE* root, T_NODE* new_node,bool* taller);

T_NODE* balance_left(T_NODE* root, bool* taller);
T_NODE* balance_right(T_NODE* root, bool* taller);
T_NODE* rotate_left(T_NODE* root);
T_NODE* rotate_right(T_NODE* root);

void traverse_preorder(T_NODE* root);
void traverse_inorder(T_NODE* root);
void traverse_postorder(T_NODE* root);