#include <stdio.h>
#include <stdlib.h>


struct queueNode{
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueueCircular(QueueNodePtr *headPtr , QueueNodePtr *tailPtr ,char value){

    QueueNodePtr newPtr = malloc(sizeof(QueueNode));

    if(newPtr != NULL){
        newPtr->data = value;
        if(*headPtr ==NULL){
            *headPtr = newPtr;
        }else{
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;

        (*tailPtr)->nextPtr = *headPtr;

    }


}

char dequeueCircular(QueueNodePtr *headPtr,QueueNodePtr *tailPtr){

    char value = (*headPtr)->data;
    QueueNodePtr tempPtr = *headPtr;

    if(*headPtr ==*tailPtr){
        *headPtr = NULL;
        *tailPtr = NULL;
    }else{
        *headPtr = (*headPtr)->nextPtr;
        (*tailPtr)->nextPtr = *headPtr;
    }

    free(tempPtr);
    return value;


}


void printCircularQueue(QueueNodePtr headPtr){
    if(headPtr == NULL){
        puts("Queue is empty");
        return;
    }
    QueueNodePtr currentPtr = headPtr;
    puts("The circular queue is: ");

    do{
        printf("%c -> ",currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }while(currentPtr != headPtr);

    printf("(This is a circular queue, so it loops back to the head)\n");

}

int main(void){
    QueueNodePtr head = NULL;
    QueueNodePtr tail = NULL;

    printf("Adding element to the circular queue: A ,B, C, D\n");
    enqueueCircular(&head, &tail, 'A');
    enqueueCircular(&head, &tail, 'B');
    enqueueCircular(&head, &tail, 'C');
    enqueueCircular(&head, &tail, 'D');
    printCircularQueue(head);

    printf("Removing element from the circular queue: %c\n", dequeueCircular(&head, &tail));
    printCircularQueue(head);

    return 0;
}