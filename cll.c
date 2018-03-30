#include <stdio.h>
#include <malloc.h>

struct node
{
int  data;
struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
void search();
int count(struct node *);
struct node *start , *x;
int main()
{
int  option;
do
{
printf("\n\n *****MAIN MENU *****");
printf("\n 1:  Create a list");
printf("\n 2:  Add a node at the beginning");
printf("\n 3:  Add a node at the end");
printf("\n 4:  Delete a node from the beginning");
printf("\n 5:  Delete a node from the end");
printf("\n 6:  Delete a node after a given node");
printf("\n 7:  Delete the entire list");
printf("\n 8:  search the list");
printf("\n 9:  count the number of nodes in a linked list");
printf("\n 10: Display the list");
printf("\n 11: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
start = create_cll(start);
start = display(start);
break;

case 2:
start = insert_beg(start);
start = display(start);
break;

case 3:
start = insert_end(start);
start = display(start);
break;

case 4:
start = delete_beg(start);
start = display(start);
break;

case 5:
start = delete_end(start);
start = display(start);
break;

case 6:
start = delete_after(start);
start = display(start);
break;

case 7:
start = delete_list(start);
printf("\n CIRCULAR LINKED LIST DELETED");
break;

case 8:
search(start);
break;

case 9:printf("%d",count(start));
break;

case 10:
start = display(start);
break;
}
}while(option  !=11);
return 0;
}

struct node *create_cll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter –1 to end");
printf("\n Enter the data : ");
scanf("%d", &num);
while(num!=-1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data = num;
if(start == NULL)
{
new_node->next = new_node;
start = new_node;
}
else
{
ptr = start;
while(ptr-> next != start)
ptr=ptr->next;
ptr->next = new_node;
new_node->next = start;
}
printf("\n Enter the data : ");
scanf("%d", &num);
}
return start;
}

struct node *display(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr-> next != start)
{
printf("\t %d", ptr->data);
ptr = ptr-> next;
}
printf("\t %d", ptr-> data);
return start;
}

struct node *insert_beg(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = num;
ptr = start;
while(ptr-> next != start)
ptr = ptr-> next;
ptr-> next = new_node;
new_node-> next = start;
start = new_node;
return start;
}

struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = num;
ptr = start;
while(ptr-> next != start)
ptr = ptr-> next;
ptr-> next = new_node;
new_node-> next = start;
return start;
}

struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr->next != start)
ptr = ptr-> next;
ptr-> next = start->next;
free(start);
start = ptr-> next;
return start;
}

struct node *delete_end(struct node *start)
{
struct node *ptr, *preptr;
ptr = start;
while(ptr-> next != start)
{
preptr = ptr;
ptr = ptr-> next;
}
preptr->next = ptr-> next;
free(ptr);
return start;
}

struct node *delete_after(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr-> data != val)
{
preptr = ptr;
ptr = ptr-> next;
}
preptr-> next = ptr-> next;
if(ptr == start)
start = preptr-> next;
free(ptr);
return start;
}

struct node *delete_list(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr-> next != start)
start = delete_end(start);
free(start);
return start;
}

void search()
{  int val, count=0 , flag=0;
   printf("\nenter the element to search\n");

    scanf("%d", &val);
   if(start ==NULL)
    printf("\n list is empty nothing to search");
   else
    {
     x=start;
     while(x->next!=start)
       {
         if(x->data==val)
          {
           printf("\nthe element is found at %d \n",count);
           flag=1;
           break;
            }
count++;
x=x->next;
}
if (x->data==val)
{
printf("element found at position %d\n", count);
}
if(flag==0)
{
printf("\n element not found");
}
}
}
int count(struct node *start)
{
struct node *ptr;
ptr=start;
int result=0;
if(ptr!=NULL)
{
 do 
   {
    ptr=ptr->next;
    result++;
    }while(ptr!=start);
}
return result;
}

