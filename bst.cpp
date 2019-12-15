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
		int get_node_count(struct node**);
		void is_in_tree(struct node**,int);
		struct node* getMin(struct node**);
		struct node* getMax(struct node**);
		void preorder(struct node**);
		void breadth_first_search(struct node**);
		void clear_nodes(struct node*);
		int getheight(struct node**);
		void print_levels(struct node**,int);
		struct node* delete_node(struct node**,int,BST *);
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
	struct node *deleted_node=b->delete_node(h,2,b);
	cout<<"level order traversal(BFS)"<<endl;
	b->breadth_first_search(h);
	cout<<"node count"<<endl;
	int node_count=b->get_node_count(h);
	cout<<node_count<<endl;
	cout<<"check node in tree"<<endl;
	b->is_in_tree(h,25);
	cout<<"get max"<<endl;
	struct node *max_val=b->getMax(h);
	cout<<(max_val->key)<<endl;	
	cout<<"get min"<<endl;
	struct node *min_val=b->getMin(h);
	cout<<(min_val->key)<<endl;
	delete(b);
	return(0);
}

struct node* BST::delete_node(struct node **root,int key,BST *b){

//traverse the node to find the key then decide upon deletion based on the number of children the node to be deleted has
	if((*root)==NULL){
		return *root;
	}else if((*root)->key>key){
		(*root)->left=delete_node(&((*root)->left),key,b);
	}else if((*root)->key<key){
		(*root)->right=delete_node(&((*root)->right),key,b);
	}else if((*root)->key==key){
	
		if((*root)->right==NULL && (*root)->left==NULL){

			free(*root);
			*root=NULL;
		
		}else if((*root)->right!=NULL && (*root)->left==NULL){

			struct node *temp=*root;
			*root=(*root)->right;
			free(temp);
			temp=NULL;

		
		}else if((*root)->left!=NULL && (*root)->right==NULL){
		
			struct node *temp=*root;
			*root=(*root)->left;
			free(temp);
			temp=NULL;

		}else if((*root)->left!=NULL && (*root)->right!=NULL){
			struct node *temp=b->getMin(&((*root)->right));
			(*root)->key=(temp)->key;
			(*root)->right=delete_node(&((*root)->right),(temp)->key,b);
		}
	
	}
	return *root;
}


int BST::get_node_count(struct node **root)
{
	if((*root)==NULL){
		return 0;
	}else{
	
		int val_1=get_node_count(&((*root)->left));
		int val_2= get_node_count(&((*root)->right));
		
		return 1+val_1+val_2;
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

struct node* BST::getMin(struct node **root){
	


	while((*root)->left!=NULL){
		*root=(*root)->left;
	}




	//cout<<"Minimum Value in BST is "<<(*root)->key<<endl;
	return *root;
	

}

struct node* BST::getMax(struct node **root){
	while((*root)->right!=NULL){
		*root=(*root)->right;
	}
	
	//cout<<"Maximum value in BST is "<<(*root)->key<<endl;
	return *root;
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

	int h=getheight(root);
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

int BST::getheight(struct node **root){
	/*if((*root)->left!=NULL){
		count_left=count_left+1;
		getheight(&((*root)->left),count_left,count_right);
	}
	if((*root)->right!=NULL){
		count_right=count_right+1;
		getheight(&((*root)->right),count_left,count_right);
	}
	*/
	if((*root)==NULL){
		return 0;
	}else{
	
		int ld=getheight(&((*root)->left));
		int rd= getheight(&((*root)->right));
		if(ld>rd){
			return ld+1;
		}else{
			return rd+1;
		}
	
	}
}





















		
		




