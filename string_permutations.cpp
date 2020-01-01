//This problem is from Cracking the coding interview pg 90 problem 1.2

#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX_SIZE 4 //JUST THE NUMBER OF CHARACTERS EXCLUDING NULL CHARACTER

using namespace std;

void swap(char *a,char *b){
	char t;
	t=*a;
	*a=*b;
	*b=t;
}

void backtrack(char *arr,int lower,int upper){
	if(lower==upper){
		cout<<arr<<endl;
		
	}else{


		for(int i=lower;i<upper;i++){
	
			swap(arr[lower],arr[i]);

			backtrack(arr,lower+1,upper);

			swap(arr[lower],arr[i]);
		}
	}

}



int main(int argc,char *argv[]){
	
	char *elem;
	char input[MAX_SIZE+1];
	elem=(char*)malloc((MAX_SIZE+1)*sizeof(char));
	cout<<"enter input"<<endl;
	cin>>input;
	strcpy(elem,input);
	backtrack(elem,0,MAX_SIZE);
	free(elem);
	return(0);

}

