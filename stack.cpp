#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
static int max_size=0;

struct stack{
	int *items;
	int top;
	stack(){
		top=0;
	}
	void create_array();
	void delete_memory();
	void push(int data);
	int pop();
	void set_size(int size);
	int peek();
};

void stack::create_array(){
	
	items=(int*)malloc(max_size*sizeof(int));

}
void stack::delete_memory(){

	free(items);
	items=NULL;

}

void stack::set_size(int size){
	max_size=size;

}

void stack::push(int data){
	if(top>max_size){
		printf("%s","overflow");
	}else{
		items[top++]=data;
	}
}

int stack::pop(){
	if(top<=-1){
		printf("%s","underflow");
		return 0;
	}else{
	
		int val=items[--top];
		return val;
	}
}

int stack::peek(){
	return items[top-1];
}

int main(int argc,char* argv[]){
	stack s;
	s.set_size(10);
	s.create_array();
	s.push(10);
	s.push(20);	
	s.push(30);
	s.push(40);
	s.push(50);
	cout<<"Popped element is "<<s.pop()<<endl;
	for(int i=0;i<s.top;i++){
		cout<<s.items[i]<<endl;
	}
	s.delete_memory();
	return(0);
}

