#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Node{
	Node *next;
	int data;
};

class Queue{
	public:
		Node *front;
		Node *tail;
		Node **mover;
		Node **initial_node;
		Queue():front(NULL),tail(NULL),mover(&tail),initial_node(&front){
		
		}
		void enqueue(int data);
		int dequeue();
		bool isEmpty();
		Node* getTail();
		Node* getFront();
		Node** getMover();
		Node** getInitial();
};

Node** Queue::getMover(){
	
	return mover;

}

Node* Queue::getTail(){
	return tail;

}

Node** Queue::getInitial(){

	return initial_node;
}
Node* Queue::getFront(){
	return front;
}


void Queue::enqueue(int data){

	Node **currentMover=getMover();
	Node **front=getInitial();
	Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	if(*currentMover==NULL){

		newNode->data=data;
		newNode->next=NULL;
		*currentMover=newNode;
		*front=newNode;
	
	}else{
		newNode->data=data;
		(*currentMover)->next=newNode;
		newNode->next=NULL;
		*currentMover=newNode;

	}

}

int Queue::dequeue(){

	Node **init_node=getInitial();
	Node **rear_node=getMover();
	Node *next_node=(*init_node)->next;
	int data=(*init_node)->data;
	
	if((*init_node)==(*rear_node)){
	
		free(*init_node);
		*init_node=NULL;
		*rear_node=NULL;
	}else{
		free(*init_node);
		*init_node=NULL;
		*init_node=next_node;
	}

	return data;

}

bool Queue::isEmpty(){


	Node **front=getInitial();
	if((*front)==NULL){
		cout<<"yes empty"<<endl;
		return true;
	}else{
		cout<<"not yet empty"<<endl;
		return false;
	}
}





int main(){
	Queue *q=new Queue();
	q->enqueue(10);
	q->enqueue(20);
	q->enqueue(30);
	q->enqueue(40);
	//q->dequeue();
	//int popped=q->dequeue();
	//cout<<popped<<endl;
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->isEmpty();
	return(0);
	
}

	
