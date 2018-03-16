#include<stdio.h>
#include<stdlib.h>
struct Node
{
    void  *data;
    struct Node *next;
};
void insert(struct Node** temp, void *num, size_t size)
{

    struct Node* cur= (struct Node*)malloc(sizeof(struct Node));

    cur->data  = malloc(size);
    cur->next = (*temp);

    memcpy(cur->data,num,size);

    (*temp)    = cur;
}

void display(struct Node *node, void (*fptr)(void *))
{
    while (node!= NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}


void displayInt(void *n)
{
    printf(" %d", *(int *)n);
}


void displayFloat(void *f)
{
    printf(" %.4f", *(float *)f);
}


int main()
{
    struct node *head=NULL;
    int integer,ch;
    char choice;
    unsigned int_size = sizeof(int);
    unsigned float_size = sizeof(float);
    float float_value;
    printf("you wanted to insert interger(i) or floating points(f) \n");
    printf("i OR f\n");
    scanf("%c",&choice);
    if(choice=='i')
    {

        while(1)
        {

            printf("\n1 for inserting integers\n");
            printf("\n2 for display integer\n");
            printf("\n3 for exit\n");
            printf("\nenter the choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("enter the element to insert\n");
                scanf("%d",&integer);
                insert(&head,&integer,int_size);
                break;
            case 2:
                display(head,displayInt);
                break;
            case 3:
                exit(0);

            }
        }
    }
    else if(choice=='f')
    {
        head=NULL;
        while(1)
        {

            printf("\n1 for inserting floating points\n");
            printf("\n2 for display \n");
            printf("\n3 for exit\n");
            printf("\nenter the choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("enter the element to insert\n");
                scanf("%f",&float_value);
                insert(&head,&float_value,float_size);
                break;
            case 2:
                display(head,displayFloat);
                break;
            case 3:
                exit(0);

            }
        }
    }


    return 0;
}



