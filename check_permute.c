#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE_ONE 4
#define SIZE_TWO 4





int main(int argc,char *argv[]){
	
	char *one;
	char *two;

	one=(char*)malloc((SIZE_ONE+1)*sizeof(char));
	two=(char*)malloc((SIZE_TWO+1)*sizeof(char));
	
	
	printf("%s\n","enter first input");
	scanf("%s",one);
	printf("%s\n","enter second input");
	scanf("%s",two);

	size_t one_len=strlen(one);
	size_t two_len=strlen(two);
	int breaker=0;

	if(one_len==two_len){
		for(int i=0;i<one_len;i++){
			breaker=0;
			char temp=one[i];
			for(int j=0;j<two_len;j++){
				if(temp==two[j]){
					breaker=1;
				}
			}
		}
		
	}else{
		printf("%s\n","they are not permutation of each other");
	}

	if(breaker){
		printf("%s","they are permutation of each other");
	}else{
		printf("%s","they are not permutation of each other");
	}

	free(one);
	free(two);
	return(0);
}

