
#include <iostream>

typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front;
    Node* Rear;
    int Count;
} LinkedQueue;

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
    if (Queue->Front == nullptr)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
    Node* Front = Queue->Front;

    if (Queue->Front->NextNode == nullptr)
    {
        Queue->Front = nullptr;
        Queue->Rear = nullptr;
    }
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
    return Queue->Front == nullptr;
}

void LQ_CreateQueue(LinkedQueue** Queue)
{
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = nullptr;
    (*Queue)->Rear = nullptr;
    (*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
    while (!LQ_IsEmpty(Queue))
    {
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyQueue(Popped);
    }

    free(Queue);
}

Node* LQ_CreateNode(char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    strcpy(NewNode->Data, NewData);
    NewNode->NextNode = nullptr;

    return NewNode;
}

void LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}

int main()
{
    std::cout << "Hello World!\n";
}
