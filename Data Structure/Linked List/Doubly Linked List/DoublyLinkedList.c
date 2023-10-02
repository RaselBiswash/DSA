#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *pre,*next;
};
typedef struct Node node;

node *head,*tail,*new_node,*temp;
int count=0;

//output function
void output()
{

    temp=head;
    int i=1;
    while(temp!=0)
    {
        printf("Node %d:\n",i);
        printf("Data:%d\n",temp->data);
        temp=temp->next;
        i++;

    }

}
//create node function
void node_create()
{

    head=0;
    int n,i;
    printf("Enter how many node do you add:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("Enter %d node: ",i+1);

        printf("\nEnter Data: ");
        scanf("%d",&new_node->data);
        new_node->pre=0;
        new_node->next=0;
        count++;
        if(head==0)
        {
            head=tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail->pre=tail;
            tail=new_node;
        }
    }

    output();


}
//insert node at beginning
void ins_beg()
{
    new_node=(node*)malloc(sizeof(node));
    printf("Insert node at beginning: ");

    printf("\nEnter Data: ");
    scanf("%d",&new_node->data);
    new_node->pre=0;
    new_node->next=0;
    head->pre=new_node;
    new_node->next=head;
    head=new_node;
    count++;

    printf("\nInsert Node at beganning after result:\n");
    output();



}

//insert node at end

void ins_end()
{
    new_node=(node*)malloc(sizeof(node));
    printf("Insert node at ending: \n");

    printf("\nEnter Data: ");
    scanf("%d",&new_node->data);
    new_node->pre=0;
    new_node->next=0;
    tail->next=new_node;
    new_node->pre=tail;
    tail=new_node;
    count++;

    printf("\nInsert end after result:\n");
    output();

}

//insert node at mid

void ins_mid()
{
    int pos;
    printf("Enter position that you Deleted:");
    scanf("%d",&pos);
    if(pos>count || pos<=0){
        printf("Invalid position");

    }
    else if(pos==1)
    {
        ins_beg();
    }
    else{
       new_node=(node*)malloc(sizeof(node));
        printf("Enter %d node: ",pos);

        printf("\nEnter Data: ");
        scanf("%d",&new_node->data);
        count++;

        temp=head;
        int num=1;
        while(num<pos-1)
        {
            temp=temp->next;
            num++;

        }
        new_node->pre=temp;
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->next->pre=new_node;

    }



}

//delete from beginning

void del_beg()
{
    if(head==0)
    {
        printf("last Node is empty");
    }
    else{
        temp=head;
        head->pre=0;
        temp->next=0;
        free(temp);

    }
}

//delete from end
void del_end(){
    if(tail==0)
    {
        printf("last Node is empty");
    }
    else{
    temp=tail;
       tail=tail->pre;
        tail->next=0;
         free(temp);

    }
}

//Delete from specific position
void del_pos(){

 int pos;
    printf("Enter position that you Deleted:");
    scanf("%d",&pos);



    int num=1;
    temp=head;
    node *temp2;
    while(num<pos)
    {
        temp=temp->next;
        num++;

    }
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;

    free(temp);



 }




//main function start
int main()
{

    node_create();
    ins_beg();
    ins_end();

}
