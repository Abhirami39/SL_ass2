/*
check if prev.val < cur.val && cur.val> cur->next->val
mark that as peak1, and start couting from there

when the condn is met agn, max_dist = count
then reset count and make the node peak1 and search for the next peak

while(cur->next != NULL){
	if(prev.val < cur.val && cur.val> cur->next->val && status == 0){ //status =0, first time condn is met
		peak1 = cur;
		status =1;
	}
	
	if(status ==1){
		count++;
	}
	
	if(prev.val < cur.val && cur.val> cur->next->val && status == 1){
		if(count> max_dist){
			max_dist = count;
		}
		status = 0
		count =0;
	}
	
	prev = current;
	current = current->next
}
return max_dist
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
/*mid = 2, current =3; mid 3, cur=5; mid=4, cur = null*/
/*mid=2, cur=3; mid=3, cur=5*/
/*so if cur->next == null, then odd; cur->next->next == null, then even*/

void max_peak_dist(struct node* head){
	printf("entered the max_peak_dist function \n");
	int status = 0, count = 0, max_dist = 0;
	struct node* prev=head;
	struct node* current=head;
	
	while(current->next != NULL){
		if(prev->data < current->data && current->data> current->next->data && status == 0){ //status =0, first time condn is met
			printf("peak 1 reached \n");
			printf("current->data = %d ; prev->data = %d \n", current->data, prev->data);
			//peak1 = current;
			status =1;
		}
		else if(prev->data < current->data && current->data> current->next->data && status == 1){
			printf("reached second peak \n");
			printf("current->data = %d ; prev->data = %d \n", current->data, prev->data);
			if(count> max_dist){
				max_dist = count;
				printf("max_dist = %d \n", max_dist);
			}
			//status = 0;
			count = 0;
		}
	
		if(status == 1){
			count++;
			printf("count = %d \n", count);
			printf("current->data = %d ; prev->data = %d \n", current->data, prev->data);
		}
	
		prev = current;
		current = current->next;
	}
	
	printf("max distance = %d \n", max_dist-1);
}

//void print_list(struct node* head){
//	struct node* current=head;
//
//	//printf("traversing the list...\n");
//	while(current!=NULL){
//		printf("%d ",current->data);
//		current=current->next;
//	}
//}




struct node* creatnode(int d){
	struct node* temp=malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}

int main(){
	printf("enter data of linked list nodes, enter 0 to quit\n");
	int k,count=1,x;

	struct node* curr,*temp;

	scanf("%d",&k);
	struct node* head=creatnode(k);
	scanf("%d",&k);
	temp=head;

	
	while(k){
		curr=creatnode(k);
		temp->next=curr;
		temp=temp->next;
		scanf("%d",&k);
	}
	
	max_peak_dist(head);

	return 0;
}
