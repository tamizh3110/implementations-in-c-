#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STRING_SIZE 3

void swap(char *a,char *b){

	char t=*a;
	*a=*b;
	*b=t;
}

int check_permutation(char *elements){

	char *begin;
	char *end;

	int counter=1;


	begin=elements;
	end=elements;

	//check permute
	
	for(int i=0;i<strlen(elements)-1;i++){
	
		end++;
	}



	while(begin!=end){
		
	

		if((*begin)!=(*end)){
			
			counter=0;
			break;
			
		}

		begin++;
		end--;
	
	}

	return counter;


}

void backtrack(char *elements,int lower,int upper){
	
	if(lower==upper){
	
		int setup=check_permutation(elements);

		if(setup==0){
		
			printf("%s\n","this is not a palindrome permute");
		}else if(setup==1){
			printf("%s\n","this is a palindrome permute");
		}
	}else{
	
		for(int i=lower;i<upper;i++){
		
			swap(&elements[i],&elements[lower]);
			backtrack(elements,lower+1,upper);
			swap(&elements[i],&elements[lower]);
		}
	
	}

}

int main(int argc,char *argv[]){
	
	char *elements;

	elements=(char*)malloc((STRING_SIZE+1)*sizeof(char));
	
	
	fgets(elements,STRING_SIZE+1,stdin);

	
	//remove spaces
	char *new_elements=(char*)malloc((STRING_SIZE+1)*sizeof(char));
	
	int i=0,j=0;

	while(elements[i]!='\0'){
		
		if(elements[i]!=' '){
		
			new_elements[j]=elements[i];
			j++;
		}
		i++;
	
	}
	new_elements[j]='\0';

        printf("%s\n","after removing space");

        puts(new_elements);

	size_t len_new=strlen(new_elements);

	
	backtrack(new_elements,0,len_new);
	
	free(new_elements);
	free(elements);

	
	return(0);
}
