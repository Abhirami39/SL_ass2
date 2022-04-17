#include<stdio.h>
#include<stddef.h>	//needed to use size_t

char heap[20000];

/*size_t is the size of an object which is usually the processor address size 
which is usually 64 bits
here int isn't used to indicate teh size since signed integers are usually 
32 bits on 64 bit systems which is lesser than trhe size required to store a 
few objects*/

struct metadata{
	size_t size;
	int occ;
	struct metadata *next; 
};

struct metadata *free_list=(void*)heap;

void initialize(){
	free_list->size=20000-sizeof(struct metadata);	//subtracting the size of the metadata since we need to have a metadata block in teh start even though it's empty
	free_list->occ=0;	//occ = 1 ->block is occupied, occ = 0->block isn't occupied
	free_list->next=NULL;
}

void divide(struct metadata *dividing_block,size_t size_req){
 	struct metadata *leftout_free_block=(void*)((void*)dividing_block+size_req+sizeof(struct metadata));
 	leftout_free_block->size=(dividing_block->size)-size_req-sizeof(struct metadata);
 	leftout_free_block->occ=0;
 	leftout_free_block->next=dividing_block->next;
 	dividing_block->size=size_req;
 	dividing_block->occ=1;
 	dividing_block->next=leftout_free_block;
}


void *Allocate(size_t no_of_bytes){
 	struct metadata *current,*prev;
 	void *allocated_block_ptr;
 	if(!(free_list->size)){
  		initialize();
  		printf("Initialized Memory \n");
 	}
 	current=free_list;
 	//this is using first fit method
 	while((((current->size)<(no_of_bytes+sizeof(struct metadata)))||((current->occ)==1))&&(current->next!=NULL)){
  		prev=current;
  		current=current->next;
  		printf("A block has been checked \n");
 	}
 	if((current->size)==no_of_bytes+sizeof(struct metadata)){
  		current->occ=1;
  		allocated_block_ptr=(void*)(++current);
  		printf("Allocated block to exactly fitting free block \n");
  		return allocated_block_ptr;
 	}
 	else if((current->size)>(no_of_bytes+sizeof(struct metadata))){
  		divide(current,no_of_bytes);
  		allocated_block_ptr=(void*)(++current);
  		printf("Allocated memory after splitting free block \n");
  		return allocated_block_ptr;
	}
 	else{
  		allocated_block_ptr=NULL;
  		printf("Eroor. Not enough memory available to allocate\n");
  		return allocated_block_ptr;
 	}
}

void merge(){
	struct metadata *current,*prev;
	current=free_list;
	while(current != NULL && (current->next)!=NULL){
		if((current->occ == 0) && (current->next->occ == 0)){
			current->size+=(current->next->size)+sizeof(struct metadata);
			current->next=current->next->next;
		}
		prev=current;
		current=current->next;
	}
}

void Free(void* block_ptr){
	if(((void*)heap<=block_ptr)&&(block_ptr<=(void*)(heap+20000))){
		struct metadata* current=block_ptr;
		--current;
		current->occ=0;
		merge();
 	}
 	else printf("Error. Enter a valid pointer \n");
}

void print_free_list(){
	struct metadata *current = free_list;
	int i = 1;
	while(current != NULL){
		printf("%d block \nsize = %zu \n", i, current->size);
		if(current->occ == 1){
			printf("occupied status = occupied \n");
		}
		else{
			printf("occupied status = not occupied \n");
		}
		i++;
		current = current->next;
	}
}

int main(){
 
	int *p1=(int)Allocate(400*sizeof(int));
	char *p2=(char)Allocate(150*sizeof(char));
	int *p3=(int)Allocate(1000*sizeof(int));
	Free(p1);
	char *p4=(char)Allocate(600);
	Free(p3);
	int *p5=(int)Allocate(400*sizeof(int));
	printf("Allocation and deallocation is done successfully!");
	
	printf("\n\n");
	print_free_list();
}

//have to implement best fit?
