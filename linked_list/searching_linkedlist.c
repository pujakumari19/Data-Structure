/*
 * 
 * Title:       Searching element in linked list
 * Description: To search whether an element is present a in linked list
 * Author:      Puja Kumari
 * GitHub:      https://github.com/pujakumari19
 * LinkedIn:    https://www.linkedin.com/in/puja-kumari-15732a192/
 *  
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insertatend(int data) //to insert the elements 
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        struct node *x;
        x=head;
        while(x->next!=NULL)
        {
            x=x->next;
        }
            x->next=temp;
    }
    
}
int search(int key) // searching an element in the list
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("yes, the key is present");
            return 1;
        }
        temp=temp->next;
    }
    printf("no,the key is not present");
    return 0;
}
int main() {
    int n,i,k;
    printf("Enter the size:\n");
    scanf("%d",&n);
    printf("Enter the elements of linked list:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        insertatend(k);
    }
    int key;
    printf("enter the key to be searched:\n");
    scanf("%d",&key);
    search(key);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

/*

Sample input
------------------------------------------------------------------------
Enter the size:
4
Enter the elements of linked list:
1 3 4 8
enter the key to be searched:
9

Sample Output
--------------------------------------------------------------------------
no,the key is not present

*/

