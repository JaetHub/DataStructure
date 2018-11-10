#include <stdio.h>
#include <stdlib.h>
#include "ADT_llist.h"

LLIST* create_list(int (*cmp_func)(void*x,void*y), void(*print_func)(void*x)){
	LLIST* list = (LLIST*)malloc(sizeof(LLIST));
	if(list)
	{
		int count = 0;
		list->front = NULL;
		list->rear = NULL;
		list->pos = NULL;
		list->cmp_func = cmp_func;
		list->print_func = print_func;

		return list;
	}
	else NULL;
}

bool add_node_at(LLIST* list,unsigned int index,void* data){
	if(index>list->count)
		return false;
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if(!newnode)
		return false;
	
		newnode->data_ptr = data;
		newnode->next = NULL;
	
	if(list->count ==0){
		list->front = newnode;
		list->rear = newnode;
		(list->count)++;
		return true;
	}
	int iter_i=0;
	if(index==0)
	{
		newnode->next = list->front;
		list->front =newnode;
		(list->count)++;
		return true;
	}
	iter_i++;
	list->pos=list->front;
	while(iter_i != index){
		list->pos=list->pos->next;
		iter_i++;
	}
	if(iter_i ==list->count){
		list->pos->next = newnode;
		list->rear = newnode;
		(list->count)++;
		return true;
	}
	else
	{
		newnode->next = list-> pos-> next;
		list->pos->next = newnode;
		(list->count)++;
		return true;
	}
	}
	

bool del_node_at(LLIST* list,unsigned int index){
		if(list->count==0)
			return false;
		else if(index>=list->count)
		return false;
		
		if(list->count==1){
			free(list->front);
			list->front =NULL;
			list->rear =NULL;
			list->count =0;
			return true;
		}
		int iter_i=0;
		list->pos = list->front;
		NODE* pre= NULL;
		while(iter_i!=index){
			pre = list->pos;
			list->pos = list->pos ->next;
			iter_i++;
		}
		if(index==0){
			list->front=list->pos->next;
			free(list->pos);
			list->pos =NULL;
			(list->count)--;
			return true;
		}
		if(index==(list->count-1)){
			list->rear = pre;
			pre->next =NULL;
			free(list->pos);
			list->pos =NULL;
			(list->count)--;
			return true;
		}
		else
		{
			pre->next = list->pos ->next;
			free(list->pos);
			list->pos = NULL;
			(list->count)--;
			return true;
		}
		return false;

	}

void* get_data_at(LLIST* list, unsigned int index){
	if(index>=list->count)
		return NULL;
	list->pos = list->front;

	int iter_i=0;
	while(list->pos!=NULL){
		if(iter_i == index)
			return list->pos->data_ptr;

		list->pos = list->pos->next;
		iter_i++;

	}
	return NULL;
}

int find_data(LLIST* list, void* search_data){
	list->pos = list->front;
	int cmp_result,left,right;
	int iter_i=0;
	while(list->pos!=NULL){
		left=*(int*)(list->pos->data_ptr);
		right=*(int*)(search_data);
		cmp_result = left-right;
		if(cmp_result ==0)
			return iter_i;

		list->pos=list->pos->next;
		iter_i++;
	}
	return -1;
}