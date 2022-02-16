#include <stdio.h>
#include <stdlib.h>

//making changes, added comment

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node* sort(struct node* head){
	struct node* i=head;	//current
	struct node* j = i->next;	//index
	int temp=0;
	
	while(i->next != NULL){
		while(j != NULL){
			if(i->data > j->data){
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j = j->next;
		}
		if(i != NULL){
			i = i->next;
		}
		if(i != NULL){
			j= i->next;
		}
	}
	
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
	temp->prev = NULL;
	return temp;
}

int main(){
	printf("enter data of linked list nodes, enter 0 to quit\n");
	int k=0, K=0;

	struct node* curr,*temp, *prev_node;

	scanf("%d",&k);
	struct node* head=creatnode(k);
	scanf("%d",&k);
	temp=head;
	prev_node = head;

	
	while(k){
		curr=creatnode(k);
		temp->next=curr;
		prev_node = temp;
		temp=temp->next;
		temp->prev = prev_node;
		scanf("%d",&k);
	}
	
	head = sort(head);
	print_list(head);

	return 0;
}
