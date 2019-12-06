#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX_SIZE 5
using namespace std;

struct stack{
	int items[MAX_SIZE];
	int top;
	stack(){
		top=0;
	}
	void push(int data);
	int pop();
	int peek();
};


void stack::push(int data){
	if(top>MAX_SIZE){
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
		int val=items[top--];
		return val;
	}
}

int stack::peek(){
	return items[top-1];
}

int main(int argc,char* argv[]){
	stack s;
	s.push(10);
	s.push(20);	
	s.push(30);
	s.push(40);
	s.push(50);
	//s.pop();
	for(int i=0;i<s.top;i++){
		cout<<s.items[i]<<endl;
	}
	return(0);
}

