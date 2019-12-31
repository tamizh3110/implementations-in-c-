#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int *elem,int low,int high){

        int pivot_value=elem[high];
        int arr_size=high;
        int i=low-1;
        for(int j=low;j<arr_size;j++){

                if(elem[j]<=pivot_value){

                        i++;
                        swap(elem[i],elem[j]);
                }

        }
	swap(elem[i+1],elem[arr_size]);

	return (i+1);

}



void quicksort(int *elem,int low,int high){
	

	if(low<high){

		int pivot;
		pivot=partition(elem,low,high);
		quicksort(elem,low,pivot-1);
		quicksort(elem,pivot+1,high);
	}

}

int main(int argc,char *argv[]){

	int *elements;
	int size;
	cout<<"enter number of elements in array"<<endl;
	cin>>size;
	
	elements=(int*)malloc(size*sizeof(int));
	
	cout<<"input elements"<<endl;
	
	for(int i=0;i<size;i++)
	{
		cin>>elements[i];
	}

	quicksort(elements,0,size-1);
	
	cout<<"sorted output"<<endl;

	for(int i=0;i<size;i++){
		cout<<elements[i]<<endl;
	}

	free(elements);
	return(0);

}
