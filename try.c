#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *createList();
node *Insert_beg(node *head, int x);
node *Insert_end(node *head, int x);
node *Insert_mid(node *head, int x);
node *Delete_beg(node *head);
node *Delete_end(node *head);
node *Delete_mid(node *head);
void PrintList(node *head);
void main()
{
    int choice, insert_option, delete_option, x;
    node *head = NULL;
    printf("Welcome to the implementation of the doubly linked list ! \n");
    do
    {
        printf("Please select an operation to perform from the below list \n");
        printf(" 1. Create a List \n 2. Insert a node \n 3. Delete a node \n 4. Print the existing list \n 5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n \n");
        switch (choice)
        {
        case 1:
            head = createList();
            break;
            default:
            printf("Please enter a valid choide: 1, 2, 3, 4, 5");
        case 2:
            do
            {
                printf("Select a position where you to want to insert new node \n");
                printf(" 1. Beginning of the List \n 2. At the end of the list \n 3. Insert in between \n 4. Exit the insert operation \n");
                printf("Enter your choice: ");
                scanf("%d", &insert_option);
                switch (insert_option)
                {
                case 1:
                    printf("Enter the data to be inserted: ");
                    scanf("%d", &x);
                    head = Insert_beg(head, x);
                    break;
                case 2:
                    printf("Enter the data to be inserted: ");
                    scanf("%d", &x);
                    head = Insert_end(head, x);
                    break;
                case 3:
                    printf("Enter the data to be inserted: ");
                    scanf("%d", &x);
                    //head = Insert_mid(head, x);
                    break;
                case 4:
                    printf("Insert operation Exit");
                    break;
                default:
                    printf("Please enter a valid choide: 1, 2, 3, 4");
                }
             }
        while ((insert_option) != 4);
        break;
         case 4:
            PrintList(head);
             break;
             }
             }
    while (choice != 5);
}

node *createList()
{
    node *head, *r, *l;
    int i, n;
    head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for (i = 0; i <= n - 1; i++)
    {
        if (head == NULL)
        {
            r = head = (node *)malloc(sizeof(node));
        }
        else
        {
            r->next = (node *)malloc(sizeof(node));
            r = r->next;
        }
        r->next = NULL;
        scanf("%d", &(r->data));
    }
    printf("\n \n");
    return (head);
}
node *Insert_beg(node *head, int x)
{
    node *r;
    r = (node *)malloc(sizeof(node));
    r->data = x;
    r->next = head;
    head = r;
    return (head);
}
node *Insert_end(node *head, int x)
{
    node *r, *q;
    r = (node *)malloc(sizeof(node));
    r->data = x;
    r->next = NULL;
    if (head == NULL)
        return (r);
    for (q = head; q->next != NULL; q = q->next)
        ;
    q->next = r;
    return (head);
}
void PrintList(node *head)
{
    node *p;
    printf("[ ");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%d \t", p->data);
    }
    printf(" ]");
    printf("\n \n");
}
