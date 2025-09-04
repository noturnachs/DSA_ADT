#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
}Node;

typedef struct {
	Node *head;
	int count;
}List;


List * initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void display(List *list);


void main(){
	List *L;
	L = initialize();
	insertFirst(L, 2);
	insertFirst(L, 67);
	
//	display(L);
	insertLast(L, 99);
	display(L);

	
	
}

void insertPos(List *list, int data, int index){
	if(index != list->count){
		
	}
}

void insertLast(List *list, int data){
	Node * trav;
	Node * new = malloc(sizeof(Node));
	
	new->data=data;
	new->next=NULL;
	
	if(list->head != NULL){
			for(trav=list->head; trav->next != NULL; trav=trav->next){
			}
			trav->next=new;
	}
	else{
		list->head=new;
	}
	
	list->count++;

	
}

void display(List *list){
	Node * trav;

	for(trav=list->head;trav != NULL;trav=trav->next){
		printf("%d \n", trav->data);
	}
	
	

}


List* initialize(){
	List* new = malloc(sizeof(List));
	
	if(new != NULL){
			new->head = NULL;
			new->count = 0;
	}
	
	return new;
	
}

void empty(List *list){
	Node *trav, *temp;
	for(trav = list->head; trav != NULL; trav=temp){
		temp = trav->next;
		free(trav);
	}
	list->head = NULL;
	list->count = 0;
}

void insertFirst(List *list, int data){
	Node* temp = malloc(sizeof( Node ));
	
	temp->data=data;
	temp->next=list->head;
	list->head = temp;
	list->count+1;
	
}














