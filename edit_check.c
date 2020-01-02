#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int check_edits(char *str_one,char *str_two){
	
	size_t size_one=strlen(str_one);
	size_t size_two=strlen(str_two);

	int *arr;	

	if(size_one>=size_two){

		arr=(int*)malloc(sizeof(int)*size_one);

		for(int i=0;i<size_one;i++){

			int counter=1;
			
			char temp=str_one[i];

			for(int j=0;j<size_two;j++){
				
				if(temp==str_two[j]){
				
					counter=0;
				}
			
			}

			if(!counter){
			
				arr[i]=0;
			}else{
				arr[i]=1;
			}
		}

		
	}else if(size_one<size_two){
	
		arr=(int*)malloc(sizeof(int)*size_two);

		for(int i=0;i<size_two;i++){

                        int counter=1;

                        char temp=str_two[i];

                        for(int j=0;j<size_one;j++){

                                if(temp==str_one[j]){

                                        counter=0;
                                }

                        }

                        if(!counter){

                                arr[i]=0;
                        }else{
                                arr[i]=1;
                        }

		}
	}

	int sum_val=0;

	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
			
		sum_val+=arr[i];

	
	}

	free(arr);


	if(sum_val>1){
		
		return 0;	
	
	}
	
	
	return 1;

}



int main(int argc,char *argv[]){
	
	char *str_one;
	char *str_two;

	int size_one;
	int size_two;

	printf("provide number of characters for your input string one\n");

	scanf("%d",&size_one);

	printf("provide number of characters for your input string two\n");

	scanf("%d",&size_two);
	
	str_one=(char*)malloc((size_one+1)*sizeof(str_one));
	str_two=(char*)malloc((size_two+1)*sizeof(str_two));
	
	printf("enter string\n");
	
	scanf("%s",str_one);
	
	scanf("%s",str_two);


	int res=check_edits(str_one,str_two);
	
	
		
	if(res){
	
		printf("zero or single edits needed\n");
	}else{
	
		printf("more than single edits\n");
	}

	free(str_one);
	free(str_two);

	return(0);
}
