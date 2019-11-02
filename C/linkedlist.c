/*keep constants, macros, system wide global variables, function prototypes
 *in header files
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node *next; //self referencing pointer
}*node;

//typedef struct node_struct *node; // node is a pointer to the datatype node_struct
			   // node isn't a variable of data type node_struct


/* what do you need to know to create a node?
 * okay. node be of type *node
 * so you need to assign a head pointer
 * head pointer have data null
 * and its next point to next node
 */

node create_node(int dat)
{	
	node temp; //a node of type node(node points to *node which is datatype of node_struct)
	temp = (node)malloc(sizeof(node));	// allocate memory to it
	if (temp == NULL)
		exit(1);	
	temp->next = NULL;
	temp->data = dat;
	return temp;
}

node add_node(int dat, node head)
{
	node new_node = create_node(dat);
	if (head == NULL)     //check for empty linkedlist 
		head = new_node;
	else {
		node h = head;
		while (h->next != NULL)
			h = h->next;
		h->next = new_node;    //linking previous node to current node
	 }

	return head;
}

node traversal(node head)
{	
	node temp = head;
	while(temp != NULL)
		temp = temp->next;
		printf("%d", temp->data);
	return temp;
}

node add_first(node head)
{
	node temp = create_node(head->data);  //create a temp node
	temp->next = head;	//link head node to temp
	head = temp;	//make temp as head node
	return head;
}

node insert_after(node head, int key, int dat)
{
	node h = head;
	node temp = create_node(dat);
	while (h->next != NULL && h->data != key)
		h = h->next; 
	if (h->data == key) {
			node after = h->next;
			h->next = temp;
			temp->next = after;
			return temp;
	}
	else
		printf("no node found");
}

node insert_before(node head, int key, int dat)
{
	node temp = create_node(dat);
	node prev = head;
	node cur = head->next;
	while (prev->next != NULL && cur->next != NULL && cur->data != key) {
		prev = prev->next;
		cur = cur->next;
	}
	if (cur->data == key) {
		prev->next = temp;
		temp->next = cur;
		return temp;
	}
	else
		printf("No such node found");
}

node_delete(node head, int key)
{
	node prev = head;
	node cur = head->next;
	while (prev->next != NULL && cur->next != NULL && cur->data != key) {
		prev = prev->next;
		cur = cur->next;
	}
	if (cur->data == key){
		prev->next = cur->next;
		free(cur);
	}
}

int main() {
	 node obj = create_node(8);
	 //printf("%d", obj->data);
	 //add_node(9, obj);
	 //add_node(10, obj);
	 //add_node(20, obj);
	 //add_node(11, obj);
	 //node_delete(obj, 20); 
	 //traversal(obj);
	 return 0;
}






