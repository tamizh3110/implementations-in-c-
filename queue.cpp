#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX_SIZE 5
using namespace std;
struct queue{
	int front;
	int rear;
	int myitems[MAX_SIZE];
	queue(){

		front=0;
		rear=0;
	}

	void enqueue(int data);
	int dequeue();
	int peek();
};

int main(int argc, char* argv[]){
	queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	int j=q.peek();
	cout<<"rear value is= "<<j<<endl;

	for(int i=q.front;i<q.rear;i++){
		cout<<q.myitems[i]<<endl;
	}	


	return(0);
}

void queue::enqueue(int data){
	if(rear>MAX_SIZE){
		printf("%s","overflow");

	}else{
		myitems[rear++]=data;
	}
	
}

int queue::dequeue(){
	if(front>rear){
		printf("%s","underflow");
		return(0);
	}else{
		int val=myitems[front++];
		return val;
	}
}

int queue::peek(){
	return myitems[rear-1];
}



