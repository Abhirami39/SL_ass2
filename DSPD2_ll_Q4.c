#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void palindrome(struct node* head){
	struct node* current1=head;
	struct node* middle=head;
	int retval=1, status=1, count=0;
	
	while(current1->next != NULL && current1->next->next != NULL){
		current1 = current1->next->next;
		middle = middle->next;
	}
	
	//now that we have the middle and current node, we will reverse the later
	//half of the linked list
	
	struct node* current2=middle;
	struct node* prev=NULL;
	struct node* next_node=NULL;
	
	while(middle != NULL){
		next_node = middle->next;
		middle->next = prev;
		prev = middle;
		middle = next_node;
	}
	
	struct node* current3=head;
	while(current3 != NULL && prev != NULL && status ==1){
		if(current3->data != prev->data){
			retval = 0;
			status =0;
		}
		current3 = current3->next;
		prev = prev->next;
		count++;
	}
	
	if(retval==0){
		printf("it isn't a palindrome");
	}
	else{
		printf("it is a palindrome \n");
		if(current3 != prev){
			count *=2;
			printf("max count = %d", count);
		}
		else if(current3 == prev){
			count *=2;
			count--;
			printf("max count = %d", count);
		}
	}
}

struct node* createnode(int d){
	struct node* temp=malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}

int main(){
	printf("enter data of linked list nodes, enter -1 to quit\n");
	int k,count=1,x;

	struct node* curr,*temp;

	scanf("%d",&k);
	struct node* head=createnode(k);
	scanf("%d",&k);
	temp=head;

	
	while(k != -1){
		curr=createnode(k);
		temp->next=curr;
		temp=temp->next;
		scanf("%d",&k);
	}
	
	palindrome(head);

	return 0;
}
