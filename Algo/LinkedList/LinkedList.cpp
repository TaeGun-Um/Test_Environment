﻿
#include <iostream>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNod* NextNode;
} Node;

Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewNode;
    NewNode->NextNode = nullptr;

    return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == nullptr)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = (*Head);
        while (Tail->NextNode != nullptr)
        {
            Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
    }
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if (*Head == nullptr)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != nullptr && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != nullptr)
        {
            Current->NextNode = Remove->NextNode;
        }
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != nullptr && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

int SLL_GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Current = Head;

    while (Current != nullptr)
    {
        Current = Current->NextNode;
        Count++:
    }

    return Count;
}

void TopologicalSort(Vertex* V, Node** List)
{

}

int main()
{
    std::cout << "Hello World!\n";
}
