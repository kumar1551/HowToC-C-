#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node * push(struct node *head, int data){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

int is_empty(struct node *head){
	return (head == NULL) ? 1 : 0;
}

struct node pop(struct node *head){
    struct node *temp, popped;
    int data;
    
    if (head ==NULL){
        printf("\nEmpty Stack\n");
    }
    else {
        temp = head;
        data = head->data;
        head = head->next;

		popped.data = data;
		popped.next = head;

        // printf("\nPop Elemtent is %d\n", data);
        free(temp);
    }

	return popped;
    // return head;
}

void top(struct node *head){
	if (head == NULL)
		printf("\nStack Empty\n");
	else
		printf("\ntop Element is %d\n", head->data);
}

int size(struct node *head){
	int s = 0;
	struct node *p = head;
	
	if (head == NULL)
		return 0;
	
	while(p != NULL){
		s += 1;
		p = p->next;
	}
	return s;
}


int main(){
	struct node * stack=NULL, popped;
	int data, action, t;
	
	system("cls");
	
	while(1){

		printf("Choose your action:-\n");
		printf("\n1. Stack Size\n2. Is_Empty\n3. Push\n4. Pop\n5. Top element\n");
		printf("\nEnter Action Number : ");
		
		scanf("%d", &action);
		
		if (action == 1){
			printf("\nStack Size is - %d\n", size(stack));
		}
		else if (action == 2) {
		
			if (is_empty(stack))
				printf("\nStack is Empty\n");
			else
				printf("\nStack in not Empty\n");
		}
		else if (action == 3) {
			printf("\nEnter number to push: ");
			scanf("%d", &data);
			
			stack = push(stack, data);
			
			printf("\nNumber Pushed Successfully\n");
		}
		else if (action == 4) {
			popped = pop(stack);
			stack = popped.next;
			printf("\nPop Elemtent is %d\n", popped.data);
		}
		else if (action == 5) {
			top(stack);
		}
		else{
			printf("Wrong Input !");
		}
		
		printf("\nTo Repeat Press 1 | To exit Press 0: ");
		scanf("%d", &t);
		
		if (t == 1){
			system("cls");
			continue;
		}
		else
			break;
	}
	return 0;
}
