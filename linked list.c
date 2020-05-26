#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};

//Functions.....
struct node *addatbeg(struct node *head,int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}
void display(struct node *head)
{
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nList is\n");
        while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    }
}
void addatend(struct node *head,int x)
{
    struct node *p,*temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=x;
    p=head;
    while(p->next)
        p=p->next;
    p->next=temp;
    temp->next=NULL;
}
struct node *del(struct node *head,int num)
{
    struct node *p, *temp;
    if(head==NULL)
    {
        printf("\nList is Empty");
        return head;
    }
    if(head->data==num)
    {
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    p=head;
    while(p->next)
    {
        if(p->next->data==num)
        {
            temp=p->next;
            p->next=temp->next;
            free(temp);
            return head;
        }
        p=p->next;
    }
    printf("\n The number is not present in the list\n");
    return head;
}
void searchnum(struct node *head,int num)
{
    struct node *p;
    int count=1;
    p=head;
    while(p->data!=num)
    {
        count++;
        p=p->next;
    }
    printf("\nThe number is at position %dth",count);

}
void counter(struct node *head)
{
    struct node *p;
    p=head;
    if(head==NULL)
       {
            printf("\nList is empty");
            return;
       }
    int count=1;
    while(p->next)
    {
        count++;
        p=p->next;
    }
    printf("\nThe number of nodes are=%d",count);
}
void addafter(struct node *head,int num,int num2)
{
    struct node *p,*temp;
    p=head;
    while(p)
    {
        if(p->data==num2)
            {
                temp=(struct node *)malloc(sizeof(struct node*));
                temp->data=num;
                temp->next=p->next;
                p->next=temp;
                return;
            }
        p=p->next;
    }
    printf("\nSorry!!,We couldn't find the number %d",num2);

}
struct node *addbefore(struct node *head,int num,int num2)
{
    struct node *p,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    p=head;
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }

    else if(head->data==num2)
    {
        temp->data=num;
        temp->next=head;
        head=temp;
        return head;
    }
    else
    {
        while(p->next)
        {
            if(p->next->data==num2)
            {
                temp->data=num;
                temp->next=p->next;
                p->next=temp;
                return head;
            }
            p=p->next;
        }
    }
    printf("\nSorry!!,We couldn't find the number %d",num2);
}
struct node *reverselist(struct node *curr)
{
    struct node *prev=NULL,*NN=NULL;
    while(curr)
    {
        NN=curr->next;
        curr->next=prev;
        prev=curr;
        curr=NN;
    }
    return prev;
}

//Main Program Starts here.....
void main()
{
    struct node *head=NULL;
    int choice,num,num2;
    while(1)
    {
        printf("\n\t\t***********************Main Menu************************");
        printf("\n\t\t*\t1.Display                                      *");
        printf("\n\t\t*\t2.Add node to empty list/add at beginning      *");
        printf("\n\t\t*\t3.Add at end                                   *");
        printf("\n\t\t*\t4.Delete from list                             *");
        printf("\n\t\t*\t5.Search                                       *");
        printf("\n\t\t*\t6.Count no. of nodes                           *");
        printf("\n\t\t*\t7.Add after node                               *");
        printf("\n\t\t*\t8.Add before node                              *");
        printf("\n\t\t*\t9.Reverse List                                 *");
        printf("\n\t\t*\t10.exit                                        *");
        printf("\n\t\t********************************************************\n->");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                display(head);
                break;
            }
        case 2:
            {
                printf("\nEnter the value to be inserted->");
                scanf("%d",&num);
                head=addatbeg(head,num);
                break;
            }
        case 3:
            {
                printf("\nEnter the value to be inserted->");
                scanf("%d",&num);
                addatend(head,num);
                break;
            }
        case 4:
            {
                printf("\nEnter the number you want to delete->");
                scanf("%d",&num);
                head=del(head,num);
                break;
            }
        case 5:
            {
                printf("\nEnter the number to be searched->");
                scanf("%d",&num);
                searchnum(head,num);
                break;
            }
        case 6:
            {
                counter(head);
                break;
            }
        case 7:
            {
                printf("\nEnter the number to be inserted->");
                scanf("%d",&num);
                printf("\nEnter the number after which number is to be inserted->");
                scanf("%d",&num2);
                addafter(head,num,num2);
                break;
            }
        case 8:
            {
                printf("\nEnter the number to be inserted->");
                scanf("%d",&num);
                printf("\nEnter the number before which number is to be inserted->");
                scanf("%d",&num2);
                head=addbefore(head,num,num2);
                break;
            }
        case 9:
            {
                 head=reverselist(head);
                 break;
            }
        case 10:
            {
                exit(1);
            }
        default :
            printf("\nInvalid Choice");
        }
    }
}
