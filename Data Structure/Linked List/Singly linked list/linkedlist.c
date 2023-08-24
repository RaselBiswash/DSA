#include<stdio.h>
#include<stdlib.h>

//structure create

struct Node
{
    int data;
    struct Node *next;


};
typedef struct Node node;
//global variable deceleration
node *head, *new_node,*temp;
int count=0;
//inserting node start
//node creation function
void node_create()
{
    head=0;
    int n,i;
    printf("Enter How many node do you add: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("Enter %d Node:\n",i+1);

        printf("Enter Data:");
        scanf("%d",&new_node->data);
        new_node->next=0;

        count++;

        if(head==0)
        {
            head=temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;



        }
    }
    printf("Creating list after output: \n");
    output();

}

//insert node at beginning
void  ins_beg()
{
    new_node=(node*)malloc(sizeof(node));
    printf("Insert Node at beginning: \n");
    printf("Enter Data:");
    scanf("%d",&new_node->data);
    new_node->next=head;
    head=new_node;


    count++;

    printf("Insert node at beginning after output: \n");
    output();

}
//insert node at end
void ins_end()
{
    new_node=(node*)malloc(sizeof(node));
    printf("Insert Node at ending: \n");

    printf("Data:");
    scanf("%d",&new_node->data);
    new_node->next=0;

    count++;

    temp=head;
    while(temp->next != 0)
    {
        temp=temp->next;

    }
    temp->next=new_node;
    temp=new_node;

    printf("Insert node at Ending after output: \n");
    output();


}

//insert node at any position
void ins_mid()
{
    int position;
    printf("Enter position you want to add node:");
    scanf("%d",&position);

    if(position>count || position<=0)
    {
        printf("Invalid Position");
    }
    else
    {
        new_node=(node*)malloc(sizeof(node));
        temp=head;
        int m=1;
        while(m<position-1)
        {
            temp=temp->next;
            m++;

        }

        printf("Enter data:");
        scanf("%d",&new_node->data);
        new_node->next=temp->next;
        temp->next=new_node;

    }
    printf("Insert node at Ending after output: \n");
    output();
}

//inserting node end



//Deleting node start

//deleting node at beginning
void del_beg()
{
    temp=head;
    head=temp->next;
    free(temp);

    printf("Delete Beginning node after output:\n");
    output();

}
        {

//deleting node at ending
void del_end()
{
    temp=head;
    node *temp2;
    while(temp->next != 0)
    {
        temp2=temp;
        temp=temp->next;

    }


    temp2->next=0;



    free(temp);

    printf("Delete node at Ending after output: \n");
    output();

}

//deleting node at middle position
void del_mid()
{
    int position;
    printf("Enter position you want to add node:");
    scanf("%d",&position);

    temp=head;
    node *temp2;
    int m=1;
    while(m<position-1)
    {

        temp=temp->next;
        m++;

    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    printf("Delete node at middle point after output: \n");
    output();



}

//deleting node end


//Output function start
void output()
{
    temp=head;
    int j=1;
    while(temp!=0)
    {
        printf("Node %d output:\n",j);
        printf("Data:%d\n",temp->data);
        temp=temp->next;
        j++;

    }


}
//main function start
int main()
{
    node_create();
    ins_beg();
    ins_end();
    ins_mid();
    del_beg();
    del_end();
    del_mid();



    return 0;
}
