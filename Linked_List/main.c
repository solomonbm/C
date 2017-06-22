#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S_Node
{
    int key;
    char *value;
    struct S_Node *next;
} Node;

Node *createNode(int key, char *value)
{
  // Allocate memory for the pointers themselves and other elements
  // in the struct.
  Node *n = (Node *)malloc(sizeof(Node));

  n->key = key;
  n->value = strdup(value);
  return n;
}

void printList(Node *start)
{
    Node *currentNode = start;
    int count = 0;

    while (currentNode != NULL)
    {
        count++;
        printf("Node:%d key:%d\tValue:%s\n", count, currentNode->key, currentNode->value);
        currentNode = currentNode->next;
    }
    printf("Total Nodes:%d\n\n", count);
}

Node *addNode(Node *previous)
{
    //Node *newNode = (Node *) malloc(sizeof(Node));
    int newKey;
    char *newValue;
    printf("\n Enter key: ");
    scanf("%d", &newKey);
    printf("\n Enter Value: ");
    scanf("%s", &newValue);

    Node *newNode = createNode(newKey, &newValue);
    printf("\n Added:%s  key:%d\n\n", newNode->value, newNode->key);
    newNode->next = NULL;

    if ( previous != NULL )
    {
        previous->next = newNode;
    }
    return newNode;
}

void cleanup(Node *start)
{
    Node *freeMe = start;
    Node *holdMe = NULL;

    while ( freeMe != NULL )
    {
        holdMe = freeMe->next;
        printf("Free Value:%s key:%d\n", freeMe->value, freeMe->key);
        free(freeMe);
        freeMe = holdMe;
    }

}

int main()
{
    Node *start = NULL;
    Node *newest = NULL;
    int choice;
    do
    {
        printf("\n\n 1.Add an element into List");
        printf("\n\n 2.Pop an element from List");
        printf("\n\n 3.Display the elements of the List");
        printf("\n\n 4.Exit from the program");
        printf("\n\n 1.Enter your choice(1-4): ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if (start == NULL)
            {
                start = addNode(NULL);
                newest = start;
            }
            else
            {
                newest = addNode(newest);
            }
            break;
        case 2:
            break;
        case 3:
            printList(start);
            break;
        case 4:
            printf("\n\nGood Bye!...\n");
            if(start != NULL)
            {
               cleanup(start);
            }
            exit(0);
            break;
        default:
            printf("\n\n Wrong entry. Try again...");
            break;
        }
    }while(choice != 4);

    return 0;
}
