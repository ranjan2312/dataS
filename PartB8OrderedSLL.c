/*
 @Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT, Bangalore
 Purpose: This program does the following:
 a) Creates a Single Link with each node having values that defines an integer value and pointer to next such 'List' node
 b) Ensures that Single Linked List is ordered in Descending Value of integer data. This means:
 --- 'head' node always has the term with the HIGHEST value of data
 --- tail or last node always has the term with the LOWEST value of data
 --- It is allowed to have duplicate values for the data value. This just means that there will be many items with the same data.
 
 NOTE: This program is a simple program that takes as input an integer value only.
 
 
 c) Possible VIVA Q: You may be asked to:
 --- Display in Ascending Order
 --- Not allow duplicate entry for data
 */

#include <stdio.h>
#include<stdlib.h> //for malloc


typedef struct OrderedSLL
{
    int data;
    struct OrderedSLL *next;
}OrderedSLL;

OrderedSLL *head;

//Creating the Ordered SLL - Descending Order
void createOrderedSLL()
{
    OrderedSLL *ptr, *newnode, *prev;
    ptr = newnode = prev = NULL;
    int datavalue;
    
    
    printf("Enter Data for Ordered Single Linked List\n");
    scanf("%d", &datavalue);
    
    
    newnode = (OrderedSLL *)malloc(sizeof(OrderedSLL));
    
    newnode->data = datavalue;
    
    newnode->next = NULL; //As it is the 'head' node its link must be NULL
    if(head == NULL) //'head' == NULL initially
        head = newnode ; /* If 'head' is NULL, then there is no list, so newnode is the head Node inserted */
    else //If the list has some nodes
    {
        //'head' node always has the term with the HIGHEST value of price of bakery item
        if(newnode->data > head->data)//newnode's price value is larger than head node's price
        {
            newnode->next = head;
            head = newnode; //Newnode becomes head
        }
        else
        {
            ptr = head;
            //Keep traversing until the newnode's price value is less than current node's price
            // This is to insert the newnode in the current descending order of price
            //It is allowed to have duplicate terms for the price value. This is the reason it is
            //checked as 'newnode->price  < ptr->price' and NOT 'newnode->price  <= ptr->price'
            while( (ptr!= NULL) && (newnode->data  < ptr->data) )
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)    //When current last node is reached
            {
                prev->next = newnode;///current lastnode's next value is assigned to newnode address
                newnode->next = ptr; //newnode becomes last node
            }
            else //For newnode has intermediate price values
            {
                prev->next = newnode;//newnode price value is greater than OR equal to current node
                newnode->next = ptr;
            }
        }
    }
    
}//end of createOrderedSLL function

//Display Function
void displayOrderedSLL()
{
    OrderedSLL *ptr;
    if(head == NULL)
    {
        printf("\nEmpty Bakery \n");
        return;
    }
    ptr = head; int count = 0;
    while(ptr!= NULL) //Traversing the single linked list till last node
    {
        printf("\nNode#%d. Data is: %d-->", ++count,ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    int choice;
    for(;;)
    {
        printf("\n\n***MENU OPTIONS***\n1.Create Ordered SLL\n2.Display In descending order\n3.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createOrderedSLL();
                printf("\nUse Option 3 to display the Ordered SLL After Creation");
                break;
            case 2:
                printf("\n Ordered SLL Items in descending order of price are ");
                displayOrderedSLL();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    }
}



