#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
	
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;

   //if list is empty
   if(head == NULL) {
      return 0;
   }

   current = head->next;

   while(current != head) {
      length++;
      current = current->next;   
   }
	
   return length;
}

/* getLastNode()
 * return pointer to last node of the list so that its next pointer
 * can point to the new head node in case of insertion/deletion */
struct node *getLastNode()
{
    struct node *current = head;
    //if list is empty
   if(head == NULL) {
      return NULL;
   }
   while(current->next != NULL) {
      current = current->next;   
   }
	
   return current;
}

//insert link at the first location
void insertFirst(int key, int data) {
   struct node *last_node = getLastNode();
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if (isEmpty()) {
      head = link;
      head->next = head;
   } else {
      //point it to old first node
      link->next = head;
		
      //point first to new first node
      head = link;
      last_node->next = head;
   }    
}

//delete first item
struct node * deleteFirst() {
   struct node *last_node = getLastNode();
   //save reference to first link
   struct node *tempLink = head;
	
   if(head->next == head) {  
      head = NULL;
      return tempLink;
   }     

   //mark next to first link as first 
   head = head->next;
   last_node->next = head;
	
   //return the deleted link
   return tempLink;
}

//display the list
void printList() {

   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while (ptr != NULL) {
	   printf("(%d,%d) ",ptr->key,ptr->data);
	   if (ptr->next == head) {
		   break;
	   }
	   ptr = ptr->next;
   }	
   printf(" ]");
}

void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");  
      printf("(%d,%d) ",temp->key,temp->data);
   }   
	
   printf("\nList after deleting all items: ");
   printList();   
}
