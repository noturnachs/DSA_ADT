#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10


typedef struct {
	int items[MAX];
	int count;
} List;

typedef struct {
	List list;
	int front;
	int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
void display(Queue* q);
int front(Queue* q);

void main(){
	Queue * A;
	A = initialize();
	
	enqueue(A, 1);
	enqueue(A, 65);
	enqueue(A, 87);
	enqueue(A, 155);
	
	display(A);
	dequeue(A);
	printf("\n=========== after deq ============\n");
	display(A);
	
	printf("\nFRONT: %d", front(A));
	
}
int front(Queue* q){
	int resp = -1;
	if(!isEmpty(q)){
		resp = q->list.items[q->front];
	}
	
	return resp;
}

int dequeue(Queue* q){
	int frontHolder;
	if(!isEmpty(q)){
		frontHolder = q->list.items[q->front];
		if(q->rear == MAX){
			q->front=0;
			q->rear=0;
		}else{
			q->front=(q->front+1)%MAX;
		}
		
		q->list.count--;
	}
	
	return frontHolder;
}

void enqueue(Queue* q, int value){
	if(!isFull(q)){
		if(isEmpty(q)){
			q->front=0;
			q->rear=0;
		}else{
			q->rear=(q->rear+1)%MAX;
		}
		
		q->list.items[q->rear] = value;
		q->list.count++;
	}
}


void display(Queue* q){
	if(!isEmpty(q)){
		int trav = q->front;
		for(trav;trav <= q->rear;trav = (trav+1) % MAX){
			printf("%d \n", q->list.items[trav]);
		}
	}
}



bool isEmpty(Queue* q){
	bool resp=false;
	if(q->list.count == 0){
		resp=true;
	}
	
	return resp;
}

bool isFull(Queue* q){
	bool resp=false;
	if(q->list.count == MAX){
		resp=true;
	}
	
	return resp;
}

Queue* initialize(){
	Queue * new = malloc(sizeof(Queue));
	
	new->list.count = 0;
	new->front=-1;
	new->rear=-1;
	
	return new;
	
}













