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

    int i;
    for (i=0; i<size; i++)
        *(char *)(cur->data + i) = *(char *)(num + i);

    (*temp)    = cur;
}

void display(struct Node *node, void (*fptr)(void *))
{
    while (node->next!= NULL)
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
    struct Node *head = NULL;

    unsigned int_size = sizeof(int);

    int n,n1;

    printf("\nenter no of elements to insert\n");

    scanf("%d",&n);

    int *arr1,i;

    arr1=(int*)malloc(100*sizeof(int));

    printf("\nenter the integers\n");

    for(i=0; i<n; i++)

    {
        scanf("%d",&arr1[i]);
    }

    for (i=n; i>=0; i--)

    insert(&head, &arr1[i], int_size);

    printf("\ninteger linked list is \n");

    display(head, displayInt);

    printf("\n");

    printf("\nenter no of floating point value to insert\n");

    scanf("%d",&n1);

    unsigned float_size = sizeof(float);

    head = NULL;

    float arr2[100];

    printf("\n enter the values\n");

    for(i=0; i<n1; i++)
    {
        scanf("%f",&arr2[i]);
    }
    for (i=n1; i>=0; i--)

    insert(&head, &arr2[i], float_size);

    printf("\n float linked list is \n");

    display(head, displayFloat);

    return 0;
}
