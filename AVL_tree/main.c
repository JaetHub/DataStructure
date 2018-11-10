#include "AVL_tree.h"
#define sample_NUM 0

int main(){
	int i;
	int	count_L=0, count_R=0;

	AVL_TREE* tree1= create_avl_tree();
	AVL_TREE* tree2= create_avl_tree();
	int* N = (int*)malloc(sizeof(int)*sample_NUM);
	
	for(i=0; i<sample_NUM; i++)
		{
			*N= sample_NUM -i;
			AVL_insert(tree1, *N);
			AVL_insert(tree2, *N);
			N++;
		}

	while(tree1->root != NULL){
		tree1->root = tree1->root->left;
		count_L++;	
	}
	while(tree2->root != NULL){
		tree2->root = tree2->root->right;
		count_R++;	
	}
	printf("LEFT : %d\n",count_L);
	printf("RIGHT : %d\n",count_R);

	return 0;
}