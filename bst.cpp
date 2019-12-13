#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node{
	node *left;
	node *right;
	int key;
	node(int data){
		key=data;
	
	}
};

class BST{
	public:
		struct node *root;
		BST(){
			root=NULL;
		}
		~BST(){
			clear_nodes(root);
		}	

		void create_tree(int,struct node**);
		void traversal(struct node**);
		void inorder(struct node**);
		void postorder(struct node**);
		void get_node_count(struct node**,int);
		void is_in_tree(struct node**,int);
		void getMin(struct node**,int);
		void getMax(struct node**,int);
		void preorder(struct node**);
		void breadth_first_search(struct node**);
		void clear_nodes(struct node*);
		int getheight(struct node**,int,int);
		void print_levels(struct node**,int);
};


int main(int argc, char* argv[]){
	BST *b=new BST();
	struct node **h=NULL;
	h=&(b->root);
	b->create_tree(10,h);
	b->create_tree(20,h);
	b->create_tree(2,h);
	b->create_tree(4,h);
	b->create_tree(25,h);
	b->create_tree(1,h);
	cout<<"inorder"<<endl;
	b->inorder(h);
	cout<<"preorder"<<endl;
	b->preorder(h);
	cout<<"postorder"<<endl;
	b->postorder(h);
	cout<<"level order traversal(BFS)"<<endl;
	b->breadth_first_search(h);
	cout<<"node count"<<endl;
	b->get_node_count(h,1);
	cout<<"check node in tree"<<endl;
	b->is_in_tree(h,25);
	cout<<"get max"<<endl;
	b->getMax(h,(*h)->key);
	cout<<"get min"<<endl;
	b->getMin(h,(*h)->key);
	delete(b);
	return(0);
}
void BST::get_node_count(struct node **root,int counter)
{
	if((*root)->left!=NULL){
		counter=counter+1;
		get_node_count(&((*root)->left),counter);
	}if((*root)->right!=NULL){
		counter=counter+1;
		get_node_count(&((*root)->right),counter);
	}	       
		
}

void BST::is_in_tree(struct node **root,int key){
	if((*root)->key<key){
		if((*root)->right!=NULL){
			is_in_tree(&((*root)->right),key);
		}
	}else if((*root)->key>key){
		if((*root)->left!=NULL){
			is_in_tree(&((*root)->left),key);
		}
	
	}else if((*root)->key==key){
		cout<<"key present in BST"<<endl;
	}else{
		cout<<"key not present in BST"<<endl;
	
	}
}

void BST::getMin(struct node **root,int min_val){

	if((*root)->left!=NULL){
		if((*root)->left->key<min_val){
			min_val=(*root)->left->key;
			getMin(&((*root)->left),min_val);
		}
	}else{
		cout<<"Minimum Value in BST is "<<min_val<<endl;
	}

}

void BST::getMax(struct node **root,int max_val){
	if((*root)->right!=NULL){
		if((*root)->right->key>max_val){
			max_val=(*root)->right->key;
			getMax(&((*root)->right),max_val);
		}
	}else{
		cout<<"Maximum value in BST is "<<max_val<<endl;
	}
}

void BST::create_tree(int data,struct node **root){
	if(*root==NULL){
		*root=(struct node*)malloc(sizeof(struct node));
		(*root)->left=NULL;
		(*root)->right=NULL;
		(*root)->key=data;
	}else{
		if((*root)->key>data){
			if((*root)->left!=NULL){
				create_tree(data,&((*root)->left));
			}else{	
				(*root)->left=(struct node*)malloc(sizeof(struct node));
				(*root)->left->key=data;
				(*root)->left->left=NULL;
				(*root)->left->right=NULL;
			}
		}else if((*root)->key<data){
			if((*root)->right!=NULL){
				create_tree(data,&((*root)->right));
			}else{
				(*root)->right=(struct node*)malloc(sizeof(struct node));
				(*root)->right->key=data;
				(*root)->right->right=NULL;
				(*root)->right->left=NULL;
			}	
		}
	}
}

void BST::preorder(struct node **root){
	if (*root==NULL){
		return;
	}
	cout<<(*root)->key<<endl;
	preorder(&((*root)->left));
	preorder(&((*root)->right));
	
}
void BST::postorder(struct node **root){
	if(*root==NULL){
		return;
	}
	postorder(&((*root)->left));
	postorder(&((*root)->right));
	cout<<(*root)->key<<endl;
}
void BST::inorder(struct node **root){
	if(*root==NULL){
		return;
	}
	inorder(&((*root)->left));
	cout<<(*root)->key<<endl;
	inorder(&((*root)->right));
}


void BST::clear_nodes(struct node *root){
	if(root!=NULL){
		clear_nodes(root->left);
		clear_nodes(root->right);
		free(root);
		root=NULL;
	}
}

void BST::breadth_first_search(struct node **root){

	int h=getheight(root,0,0);
	cout<<"height is "<<h<<endl;
	for(int i=0;i<h;i++){
		print_levels(root,i);
	}

}

void BST::print_levels(struct node **root,int count){
	
	if(count==0){
		cout<<(*root)->key<<endl;
	}else{
		if((*root)->left!=NULL){
			print_levels(&((*root)->left),count-1);
		}
		if((*root)->right!=NULL){
			print_levels(&((*root)->right),count-1);
		}
	}
	

}

int BST::getheight(struct node **root,int count_left,int count_right){
	if((*root)->left!=NULL){
		count_left=count_left+1;
		getheight(&((*root)->left),count_left,count_right);
	}
	if((*root)->right!=NULL){
		count_right=count_right+1;
		getheight(&((*root)->right),count_left,count_right);
	}

	return(1+count_right+count_left);
}


















		
		




