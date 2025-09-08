#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10

typedef struct {
	int items[MAX];
	int top;
} Stack;


Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
void display(Stack* s);
int pop(Stack* s);


void main(){
	Stack* A;
	
	A = initialize();
//	printf("%d", isEmpty(A));
	push(A, 1222);
	push(A, 34);
	push(A, 54);
	push(A, 65);
	push(A, 55);
	push(A, 64445);
	
	display(A);
	printf("popped: %d", pop(A));
	printf("\nAFTER POPPING");
	display(A);
	
}

int pop(Stack* s){
	int currTop;
	if(!isEmpty(s)){
		currTop = s->items[s->top];
		s->top--;
	}
	
	return currTop;
}

void display(Stack* s){
	
	if(!isEmpty(s)){
		int x=s->top;
		for(x;x<MAX && x > -1 ;x--){
			printf("%d \n", s->items[x]);
		}
	}else{
		printf("EMPTY");
	}
}

void push(Stack* s, int value){
	if(!isFull(s)){
		s->top++;
		s->items[s->top] = value;
	}else{
		printf("error");
	}
	
}

bool isEmpty(Stack* s){
	bool resp=false;
	if(s->top == -1){
		resp=true;
	}
	
	return resp;

}


bool isFull(Stack* s){
	bool resp=false;
	if(s->top == MAX - 1){
		resp=true;
	}
	
	return resp;
}

Stack* initialize(){
	Stack* new = malloc(sizeof(Stack));
	
	new->top=-1;
	
	
	return new;
}
