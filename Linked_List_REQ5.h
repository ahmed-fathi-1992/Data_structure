#ifndef LINKED_LIST_REQ5_H_INCLUDED
#define LINKED_LIST_REQ5_H_INCLUDED

#include"STACK_.h"

typedef struct node{
	struct node *next;
	int data;
}ST_node;

typedef struct newlist{
	ST_node *header;
	int counter;
}ST_list;

void createList(ST_list *list_ptr);
ERROR Insert_node_at_First( ST_list *list_ptr, int new_data);
ERROR Insert_node_at_last( ST_list *list_ptr, int new_data);
ERROR insertToList(ST_list *list_ptr, unsigned char position, int new_data);
ERROR deleteFromList(ST_list *list_ptr, unsigned char position);
ST_node* searchIntoList(ST_list *list_ptr, int data);
//void sortList(ST_node *listHead);	//Bonus
//void reverseList(ST_node *listHead);	//Bonus



#endif // LINKED_LIST_REQ5_H_INCLUDED
