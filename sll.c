#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *count_node(struct node *);
struct node *search_list(struct node *);

int main(int argc, char *argv[])
{
int option;
do
{
printf("\n\n *****MAIN MENU *****");
printf("\n 1:  Create a list");
printf("\n 2:  Add a node at the beginning");
printf("\n 3:  Add a node at the end");
printf("\n 4:  Add a node before a given node");
printf("\n 5:  Add a node after a given node");
printf("\n 6:  Delete a node from the beginning");
printf("\n 7:  Delete a node from the end");
printf("\n 8:  Delete a given node");
printf("\n 9:  Delete a node after a given node");
printf("\n 10: Delete the entire list");
printf("\n 11: Search a node with given value");
printf("\n 12: Count the total number of nodes in the list");
printf("\n 13: Traverse the list");
printf("\n 14: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: start = create_ll(start);
        start = display(start);
break;

case 2: start = insert_beg(start);
        start = display(start);
break;
case 3: start = insert_end(start);
        start = display(start);
break;
case 4: start = insert_before(start);
        start = display(start);
break;
case 5: start = insert_after(start);
        start = display(start);
break;
case 6: start = delete_beg(start);
        start = display(start);
break;
case 7: start = delete_end(start);
        start = display(start);
break;
case 8: start = delete_node(start);
        start = display(start);
break;
case 9: start = delete_after(start);
         start = display(start);
break;
case 10: start = delete_list(start);
         start = display(start);
printf("\n LINKED LIST DELETED");
break;

case 11: start = search_list(start);
break;

case 12: start=count_node(start);
         start = display(start);
break;

case 13: start = display(start);
break;
}
}while(option !=14);
return 0;
}

//create a linked list
struct node *create_ll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data : ");
scanf("%d", &num);
while(num!=-1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data=num;
if(start==NULL)
{
new_node -> next = NULL;
start = new_node;
}
else
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = new_node;
new_node->next=NULL;
}
printf("\n Enter the data : ");
scanf("%d", &num);
}
return start;
display(start);
}

//display the linked list
struct node *display(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr != NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
return start;
}

//insert in the beginning of linked list
struct node *insert_beg(struct node *start)
{
struct node *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
new_node -> next = start;
start = new_node;
return start;
}

//insert at the end of linked list
struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
new_node -> next = NULL;
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
return start;
}

//insert before a given node
struct node *insert_before(struct node *start)
{
struct node *new_node, *ptr, *preptr;
int num, val;
printf("\n Enter the data : ");
scanf("%d", &num);
printf("\n Enter the value before which the data has to be inserted : ");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = new_node;
new_node -> next = ptr;
return start;
}

//insert after a given node
struct node *insert_after(struct node *start)
{
struct node *new_node, *ptr, *preptr;
int num, val;
printf("\n Enter the data : ");
scanf("%d", &num);
printf("\n Enter the value after which the data has to be inserted : ");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
preptr = ptr;
while(preptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next=new_node;
new_node -> next = ptr;
return start;
}

//delete from the beginning of linked list
struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
start = start -> next;
free(ptr);
return start;
}

//delete from end of linked list
struct node *delete_end(struct node *start)
{
struct node *ptr, *preptr;
ptr = start;
while(ptr -> next != NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = NULL;
free(ptr);
return start;
}

//delete a given node
struct node *delete_node(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value of the node which has to be deleted : ");
scanf("%d", &val);
ptr = start;
if(ptr -> data == val)
{
start = delete_beg(start);
return start;
}
else
{
while(ptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
return  start;
}
}

//delete after a given node
struct node *delete_after(struct node *start) 
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next=ptr -> next;
free(ptr);
return start;
}

//delete the entire list
struct node *delete_list(struct node *start)
{
struct node *ptr;
if(start!=NULL)
{
ptr=start;
while(ptr != NULL)
{
printf("\n %d is to be deleted next", ptr -> data);
start = delete_beg(ptr);
ptr = start;
}
}
return start;
}
 
//count the number of nodes
struct node *count_node(struct node *start)
{
int count=0;
struct node *ptr;
if(start!=NULL)
{
ptr=start;
while(ptr!=NULL)
{
count=count+1;
ptr=ptr->next;
}
printf("\n total number of nodes are: %d \n" , count);
}
return start;
}

//search the linked list
struct node *search_list(struct node *start)
{
int val;
printf("\n Enter the value of the node which is to be searched : ");
scanf("%d", &val);
struct node *ptr , *pos;
ptr=start;
while(ptr!=NULL)
{
 if(ptr->data==val)
  {   pos=ptr;
     printf("value found\n");
       }   
     ptr=ptr->next;
    }

      pos=NULL;
printf("value not found\n");


}


