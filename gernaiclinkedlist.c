#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    void *data;
    struct node *next;
} node;
void insert(node **temp,void *num)
{

    node *cur;

    cur=(struct node*)malloc(sizeof(struct node));
    cur->data=num;
    cur->next=NULL;
    if(*temp==NULL)
    {
        *temp=cur;
    }
    else
    {
        node *p;
        p=*temp;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=cur;

    }
}
void display(node **temp,void(*vp)(void *))
{

    node *p;
    p=*temp;
    while(p!=NULL)
    {
        (*vp)(p->data);
        p=p->next;
    }

}
void dispay_n(void *n)
{
    printf("%d ",(int*)n);

}
void dispay_f(void *f)
{
    printf("%f ",*(float *)f);
}
void display_c(void *c)
{
    printf("%c ",(char *)c);
}
int main()
{
    struct node *head=NULL;

    int value,i;

    int *array;

    array=(int *)malloc(1000*sizeof(int));

    printf("\nenter no of integers to insert\n");

    scanf("%d",&value);

    printf("\nenter the value\n");

    for(i=0; i<value; i++)
    {
        scanf("%d",&array[i]);
    }

    for(i=0; i<value; i++)
    {
        insert(&head,array[i]);
    }

    printf("\nHere the created linked list of integers\n");

    display(&head,dispay_n);

    printf("\n");

    int value1;

    printf("\nenter the no of elements to insert\n");

    scanf("%d",&value1);

    float *array1;

    array1=(float *)malloc(1000*sizeof(float));

    printf("\nenter the values\n");

    for(i=0; i<value1; i++)
    {
        scanf("%f",&array1[i]);
    }

    head=NULL;

    for(i=0; i<value1; i++)
    {
        insert(&head,&array1[i]);
    }

    printf("\nHere the created linked list of floating points\n");

    display(&head,dispay_f);
    return 0;
}
