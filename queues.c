#include <stdio.h>
#include <stdlib.h>


struct queueNode{
    char data;
    struct queueNode *nextPtr;
};



typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;


void enqueue(QueueNodePtr *headPtr,QueueNodePtr *tailPtr,char value){

    QueueNodePtr newPtr = malloc(sizeof(QueueNode));

    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if(*headPtr == NULL){
            *headPtr = newPtr;
        }else{
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    }

}


char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
     char value = (*headPtr)->data;
    QueueNodePtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if(*headPtr ==NULL){
        *tailPtr = NULL;
    }

    free(tempPtr);

    return value;
}


void printQueue(QueueNodePtr currentPtr){
    if(currentPtr ==NULL){
        puts("Queue is empty");

    }else{
        while(currentPtr != NULL){
            printf("%c ->",currentPtr->data);
            currentPtr = currentPtr->nextPtr;

        }
        puts("NULL\n");
    }
}

int main(void){

    QueueNodePtr head = NULL;
    QueueNodePtr tail = NULL;

    printf("Ading element to the queue: A\n");
    enqueue(&head,&tail,'A');

    printf("Adding element to the queue: B\n");
    enqueue(&head,&tail,'B');
    
    printf("Adding element to the queue: C\n");
    enqueue(&head,&tail,'C');
    
    printf("Adding element to the queue: D\n");
    enqueue(&head,&tail,'D');
    
    printf("Adding element to the queue: E\n");
    enqueue(&head,&tail,'E');
    
    printf("Adding element to the queue: F\n");
    enqueue(&head,&tail,'F');
    
    printQueue(head);

    printf("Removing element from the queue: %c\n",dequeue(&head,&tail));
    printQueue(head);
    return 0;
}