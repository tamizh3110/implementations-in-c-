#include<stdio.h>
#include<stdlib.h>
struct stack{
	
	int *arr;
	int top;
	int min_value;
	
};


void find_min_stack(struct stack *s){
	
	if(s->top==1){
	
		s->min_value=s->arr[(s->top)];
	}else{
	
		if((s->min_value)>=s->arr[(s->top)]){
	
			s->min_value=s->arr[(s->top)];
		}
	}

}

void push(struct stack *s,int data,int size){
	if((s->top)>size){
	
		printf("overflow\n");
	}else{
	
		
		s->arr[(s->top)]=data;
		find_min_stack(s);
		(s->top)++;
		
	}

}
int pop(struct stack *s){
	int data;
	if((s->top)<=0){
		
		printf("empty\n");
		return;
	
	}else{
		
		data=s->arr[(s->top)--];
	}	

	return data;

}


int main(int argc,char *argv[]){

	struct stack *s;
	int size=0;
	s=(struct stack*)malloc(sizeof(struct stack));
	
	s->top=0;

	printf("enter input size\n");
	scanf("%d",&size);
	
	s->arr=(int*)malloc(size*sizeof(int));

	push(s,100,size);
	push(s,20,size);
	push(s,2,size);
	push(s,150,size);
	push(s,250,size);

	printf("min value is=%d",(s->min_value));
	
	free(s->arr);
	free(s);
	return(0);
}
