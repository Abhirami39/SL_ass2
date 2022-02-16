//sum of diagonal elements

//making changes
#include<stdio.h>
int diagonal_value_addition(int r, int c, int A[][c]){
	int i, j, sum;
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(i==j){
				sum +=A[i][j];
			}
		}
	}
	return sum;
}

main(){
	int r,c;
	printf("Enter the number of rowns and columns of the matrix");
	scanf("%d %d", &r, &c);
	
	int i, j, A[r][c];
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	
	int ans= diagonal_value_addition(r,c,A);
	printf("the sum of the diagonal elements of the given matrix is : %d", ans);
}
