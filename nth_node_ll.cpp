#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

struct Node{

	int data;
	Node *next;

	Node(int newdata):next(NULL){
	
		data=newdata;
	}

};

class LinkedList{
	public:
		Node *head;

		LinkedList():head(NULL){
		
		}

		int countNodes(Node **current_head);
		void find_nth_node(Node **current_head,int total_nodes,int nth); 

};

int LinkedList::countNodes(Node **current_head){
	Node *node=(*current_head);
	int count=0;
	while(node!=NULL){
		
		count=count+1;
		node=node->next;
	}
	
	return count;


}

void LinkedList::find_nth_node(Node **current_head,int total_nodes,int nth){


	int counter=(total_nodes-nth);
	
	int count=0;

	Node *node=*current_head;

	while(node!=NULL){
		
		if(count==counter){
		
			cout<<"node data value is "<<node->data<<endl;
			return;
		}else{
			count=count+1;
			node=node->next;
		}
		
	}
}


int main(int argc,char *argv[]){
	LinkedList *l=new LinkedList();
	Node **mover;
	l->head=new Node(100);
	mover=&(l->head);
	Node *l2=new Node(80);
	Node *l3=new Node(120);
	Node *l4=new Node(20);
	l->head->next=l2;
	l2->next=l3;
	l3->next=l4;
	int nth=0;
	cout<<"enter nth node"<<endl;
	cin>>nth;
	int count_node=l->countNodes(mover);
	l->find_nth_node(mover,count_node,nth);
	delete(l->head);
	delete(l2);
	delete(l3);
	delete(l4);
	delete(l);
	return(0);
}
