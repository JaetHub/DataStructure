#include "ADT_stack.h"
#include <stdlib.h>
#include <stdio.h>

STACK* create_stack() {

	STACK* stack =(STACK*)malloc(sizeof(STACK));

	if(stack == NULL) {
		printf("fail to create stack\n");
		return NULL;
	}

	stack->count = 0;
	stack->top = NULL;
	return stack;
}

bool push(STACK* stack, void* in){
	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	
	if(new_node == NULL){
		printf("create node is failed");
		return false;
	}

	new_node -> data_ptr = in;
	new_node -> link = stack -> top;

	stack -> top = new_node;
	(stack -> count )++;

	return true;
}
void* pop(STACK* stack){
if(stack->count ==0)
    			return NULL;
    		else{
    			STACK_NODE* temp = stack->top;
    			void* data_out = stack->top->data_ptr;
    			stack->top=stack->top->link;
    			free(temp);
    			(stack->count)--;
    			return data_out;
}

}