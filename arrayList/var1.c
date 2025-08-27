#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;




List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
void display(List L);

void main(){
    List L;

    L = initialize(L);
	
    L = insertPos(L,1,0);
    L = insertPos(L,2,1);
    L = insertPos(L,3,2);
	L = insertPos(L,4,3);
	L = insertPos(L,5,4);

//	L = insertPos(L,66,1);
	
//	L = deletePos(L, 3);
	
    
    display(L);
    printf("Finding Data 3, Index: %d", locate(L, 3));


}

int locate(List L, int data) {
	int i, res=-1;
	for(i=0; i<L.count; i++){
		if(L.elem[i] == data){
			res=i;
		}
	}
	
	return res;
}


List deletePos(List L, int position){
	if(position <= L.count){
		int i;
		for(i=position; i < L.count-1; i++){
			L.elem[i] = L.elem[i+1];
		}
		
		L.count--;
	}
	return L;
}


void display(List L){
	int i;
    for(i=0;i < L.count; i++){
    	printf("%d \n", L.elem[i]);
	}
}



List initialize(List L){
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
	
	if (position <= L.count && L.count <= MAX){
		int i;
		for(i=L.count; i >= position; i--){
			L.elem[i] = L.elem[i-1];
		}
		
		L.elem[position] = data;
		L.count++; 
		
	}
	
	return L;
	
}
