#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void insertion_sort(int *elem,int size){
	int i,j,k;
	for(k=1;k<size;k++){
		j=k;
		i=j-1;
		while(i>=0 && j>0){
			
			if(elem[i]>elem[j]){
				swap(elem[i],elem[j]);

			}
			i--;
			j--;
			
		}
	}
}

int main(){

	int size,*elements;
	cout<<"enter size"<<endl;
	cin>>size;
	elements=(int*)malloc(size*sizeof(int));
	cout<<"enter elements"<<endl;
	for(int i=0;i<size;i++){
		cin>>elements[i];
	}

	insertion_sort(elements,size);

	for(int i=0;i<size;i++){
		cout<<elements[i]<<endl;
	}

	return(0);

}
