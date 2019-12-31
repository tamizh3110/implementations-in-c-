#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

void merge(int *array,int start_index,int mid,int end_index){

        int new_array[end_index-start_index+1];

        int i=start_index;

        int j=mid+1;

        int k=0;


        while(i <= mid && j <= end_index){

                if(array[i]<array[j]){

                        new_array[k++]=array[i++];

                }else{
                        new_array[k++]=array[j++];
                }


        }


        while(i<=mid){

                new_array[k++]=array[i++];
        }
        while(j<=end_index){

                new_array[k++]=array[j++];
        }

        for(i=start_index;i<=end_index;i++){

                array[i]=new_array[i-start_index];


        }

}



void merge_sort(int *array,int start_index,int end_index){
	
	if(start_index<end_index){
		
		int mid=(start_index+end_index)/2;
			
		merge_sort(array,start_index,mid);
		
		merge_sort(array,mid+1,end_index);

		merge(array,start_index,mid,end_index);

	
	}




	

}





int main(int argc,char *argv[]){

	int *input_array;
	int size=0;

	cout<<"enter input array input size"<<endl;
	cin>>size;
	cout<<endl;

	cout<<"Allocating memory"<<endl;
	input_array=(int*)malloc(size*sizeof(int));


	cout<<"enter array input contents"<<endl;
	
	for(int i=0;i<size;i++){
	
		cin>>input_array[i];
	}
	
	int start_index=0,end_index=size-1;

	merge_sort(input_array,start_index,end_index);
	
	//print output
	cout<<"output after sort is"<<endl;
	for(int i=0;i<size;i++){
	
		cout<<input_array[i]<<endl;
	}
	free(input_array);

	return(0);
}

