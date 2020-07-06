/*
 * 
 * Title:       Reversing elements in a linked list
 * Description: To reverse elements of linked list
 * Author:      Puja Kumari
 * GitHub:      https://github.com/pujakumari19
 * LinkedIn:    https://www.linkedin.com/in/puja-kumari-15732a192/
 *  
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

LinkedListNode* Reverse(LinkedListNode* head) 
{
struct LinkedListNode *prev,*ptr,*link;
    prev=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        link=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=link;
    }
    head=prev;
    return head;
}


int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    LinkedListNode* res;
    int head_size = 0;
	int i;
    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;
    printf("Enter the size:\n");
    scanf("%d\n", &head_size);
    for(i = 0; i < head_size; i++)
	 {
        int head_item;
        scanf("%d", &head_item);
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    res = Reverse(head);
    while (res != NULL) 
	{
        fprintf(f, "%d ", res->val);

        res = res->next;
    }

    fclose(f);
    return 0;
}

/*sample input
---------------------------------------
Enter the size:
5
1 2 3 4 5

Sample output
----------------------------------------
5 4 3 2 1

*/

