#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<iterator>


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
		void removeDuplicates(Node **head_value);
		

};

void LinkedList::removeDuplicates(Node **head_value){

	Node *currentNode=(*head_value);
	map<int,int> myList;
	map<int,int>::iterator i;
	int count=0;
	Node *init_pointer=NULL;
	Node **mover=&(init_pointer);
	
	while(currentNode!=NULL){

		if(init_pointer==NULL){

			init_pointer=new Node(currentNode->data);
			currentNode=currentNode->next;
			count=count+1;
			cout<<"printing the nodes that have been inserted into our new buffer"<<endl;
			cout<<(*mover)->data<<endl;
			myList.insert(pair<int,int>(count,(*mover)->data));
		
		}else{
			bool counter=true;

			for(i=myList.begin();i!=myList.end();i++){
			
				if((i->second)==(currentNode->data)){
					
					counter=false;

					
				}
			}
			if(counter){
				
				
				Node *temp=new Node(currentNode->data);
				(*mover)->next=temp;
				(*mover)=(*mover)->next;
				count=count+1;
				myList.insert(pair<int,int>(count,(*mover)->data));
				currentNode=currentNode->next;
				cout<<"printing the nodes that have been inserted into our new buffer"<<endl;
                        	cout<<(*mover)->data<<endl;
				


			}else{
			
				currentNode=currentNode->next;
			}

		
		}

	}
	
}


int main(int argc,char *argv[]){

	LinkedList *l=new LinkedList();
	
	struct Node **mover;
	
	l->head=new Node(100);
	
	mover=&(l->head);

	struct Node *l2=new Node(80);

	l->head->next=l2;

	struct Node *l3=new Node(80);
	
	l2->next=l3;

	struct Node *l4=new Node(120);

	l3->next=l4;

	struct Node *l5=new Node(120);

	l4->next=l5;

	/*
	cout<<"print output"<<endl;
	while((*mover)!=NULL){
	
		cout<<(*mover)->data<<endl;
		*mover=(*mover)->next;
	}
	*/

	l->removeDuplicates(mover);

	delete(l5);
	delete(l4);
	delete(l3);
	delete(l2);
	delete(l->head);
	delete(l);

	return(0);
}

