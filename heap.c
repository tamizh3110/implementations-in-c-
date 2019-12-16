//MIN HEAP


#include<stdio.h>
#include<math.h>
#include<stdlib.h>


#define HEAP_SIZE 5

struct heap{
	
	int *array_holder;
	int indexer;

};

struct heap* initializer(struct heap*,int);
void insert(struct heap*,int);
void heapify(struct heap*,int);
void delete(struct heap*,int);
int parent(struct heap*,int);
int left_child(struct heap*,int);
int right_child(struct heap*,int);
void swap(int*,int*);
void destroyer(struct heap*);

int main(int argc,char *argv[]){

	struct heap *h;
	h=initializer(h,0);
	insert(h,30);
	insert(h,20);
	insert(h,1);
	insert(h,15);
	insert(h,17);
	for(int i=0;i<HEAP_SIZE;i++){
		printf("%d\n",h->array_holder[i]);
	}
	destroyer(h);
	return(0);


}

void destroyer(struct heap *h){
	
	free(h->array_holder);
	free(h);
	h=NULL;

}


struct heap* initializer(struct heap *h,int indexer){
	h=(struct heap*)malloc(sizeof(struct heap));
	h->array_holder=(int*)malloc(HEAP_SIZE*sizeof(int));
	h->indexer=indexer;
	return h;

}

void insert(struct heap *h,int key){

	int parent_index=parent(h,h->indexer);
	h->array_holder[h->indexer]=key;

	if(h->array_holder[h->indexer]<h->array_holder[parent_index]){
	
		heapify(h,h->indexer);
	
	}
	(h->indexer)++;


}

void heapify(struct heap *h,int indexer){
	int parent_index=parent(h,indexer);
	if(h->array_holder[indexer]<h->array_holder[parent_index]){
	
		swap(&(h->array_holder[indexer]),&(h->array_holder[parent_index]));
		heapify(h,indexer-1);
		
	
	}


}

int parent(struct heap *h,int indexer){

	return (floor((indexer-1)/2));

}
void swap(int *a,int *b){
	
	int t=*a;
	*a=*b;
	*b=t;

}
