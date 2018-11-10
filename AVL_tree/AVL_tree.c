#include "AVL_tree.h"

AVL_TREE* create_avl_tree(){
	AVL_TREE* tree = (AVL_TREE*)malloc(sizeof(AVL_TREE));
	tree -> count =0;
	tree -> root = NULL;
	return tree;
}

bool AVL_insert(AVL_TREE* tree, int data){
	bool taller;
	T_NODE* new_node = (T_NODE*)malloc(sizeof(T_NODE));

	if(new_node == NULL)
		return false;

	new_node -> balance = EH;
	new_node -> right = NULL;
	new_node -> left = NULL;
	new_node -> data = data;

	tree -> root = insert_rotate(tree -> root, new_node, &taller);
	(tree->count)++;
	return true;
}

T_NODE* insert_rotate(T_NODE* root, T_NODE* new_node, bool* taller){
	if(root == NULL){
		root = new_node;
		*taller = true;
		return root;
	}

	if((new_node -> data) < (root -> data)){
		root ->left = insert_rotate(root -> left, new_node, taller);
		if(*taller){
			switch(root -> balance){
			case LH:
				root = balance_left(root, taller);
				break;
			case EH:
				root->balance = LH;
				break;
			case RH:
				root->balance = EH;
				*taller = false;
				break;
			}
		}
		return root;
	}else {
		root -> right = insert_rotate(root -> right, new_node, taller);
		if(*taller){
			switch(root -> balance){
			case LH:
				root ->balance = EH;
				break;
			case EH:
				root->balance = RH;
				break;
			case RH:
				root = balance_right(root, taller);
				break;
			}
		}
		return root;
	}
	return root;

}

T_NODE* balance_left(T_NODE* root, bool* taller){
	T_NODE* right_tree;
	T_NODE* left_tree;

	left_tree = root -> left;
	switch(left_tree -> balance){
		case LH:
		root -> balance = EH;
		left_tree -> balance = EH;
		root = rotate_right(root);
		*taller = false;
		break;
		case EH: break;
		case RH:
		right_tree = left_tree -> right;
		switch(right_tree->balance){
			case LH:
			root -> balance =RH;
			left_tree -> balance = EH;
			break;
			case EH:
			root -> balance = EH;
			left_tree -> balance = EH;
			break;
			case RH:
			root -> balance = EH;
			left_tree -> balance = LH;
			break;
		}
		right_tree -> balance = EH;
		root -> left = rotate_left(left_tree);
		root = rotate_right(root);
		*taller = false;
	}
	return root;
}

T_NODE* balance_right(T_NODE* root, bool* taller){
	T_NODE* right_tree;
	T_NODE* left_tree;

	right_tree = root -> right;
	switch(right_tree -> balance){
		case RH:
		root -> balance = EH;
		right_tree -> balance = EH;
		root = rotate_left(root);
		*taller = false;
		break;
		case EH: break;
		case LH:
		left_tree = right_tree -> left;
		switch(left_tree->balance){
			case LH:
			root -> balance =EH;
			right_tree -> balance = RH;
			break;
			case EH:
			root -> balance = EH;
			right_tree -> balance = EH;
			break;
			case RH:
			root -> balance = LH;
			right_tree -> balance = EH;
			break;
		}
		left_tree -> balance = EH;
		root -> right = rotate_right(right_tree);
		root = rotate_left(root);
		*taller = false;
	}
	return root;
}


T_NODE* rotate_left(T_NODE* root){
	T_NODE* new_root;
	new_root= root->right;
	root-> right = new_root -> left;
	new_root->left = root;

	return new_root;
}

T_NODE* rotate_right(T_NODE* root){
	T_NODE* new_root;
	new_root= root->left;
	root-> left = new_root -> right;
	new_root->right = root;

	return new_root;
}
void traverse_preorder(T_NODE* root){
	if(root != NULL){
		printf("%d ",root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void traverse_postorder(T_NODE* root){
	if(root != NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d,",root->data);
	}
}

void traverse_inorder(T_NODE* root){
	if(root != NULL){
	
		traverse_inorder(root->left);
		printf("%d",root->data);
		traverse_inorder(root->right);

	}
}