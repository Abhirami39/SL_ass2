#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* odd_before_even(struct node* head){
	struct node* current=head;
	struct node* prev=head, next_node = head->next;
	int status=0;
	
	//switch even and odd no's
//	prev->current->next_node
//	temp = next_node->next
//	prev->next = next_node
//	next_node->next = current
//	current->next = temp
//	
//	then start comparing from the start agn, if it never has to swap then 
//	get out of the loop
	while(current->next != NULL){
		if(current->data %2 ==0 && current->next->data %2 ==1){
			status= 1;
			struct node* temp = next_node->next
			prev->next = next_node
			next_node->next = current
			current->next = temp
			
			//swapping the pointers
			temp = current;
			current = next_node;
			next_node = current;
		}
	}

	//if i find an even val and the next val is odd, then switch them
	//not very efficient?
	
	while(current)
	
	return head;
}

void print_list(struct node* head){
	struct node* current=head;

	//printf("traversing the list...\n");
	while(current!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
}




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
	
	head = odd_before_even(head);
	print_list(head);

	return 0;
}
