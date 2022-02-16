#include<stdio.h>

main(){
	int length,i=0, j=0,count=0;
	printf("Enter the length of array");
	scanf("%d", &length);
	
	int A[length];
	
	printf("ENter the elements of teh array");
	for(int k=0; k<length; k++){
		scanf("%d", &A[k]);
	}
	
	for(i=0; i<length; i++){
		for(j=0;j<length; j++){
			int val=(i-j)%2;
			printf("\n A[%d] = %d(i); \n A[%d]= %d(j)", i, A[i], j, A[j]);
			if(val==0 && A[i]>A[j] && i<j){
				count++;
			}
		}
	}
	printf("the number of even-spaced inversions are: %d", count);
}
