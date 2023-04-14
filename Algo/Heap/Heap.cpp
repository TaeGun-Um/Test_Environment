
#include <iostream>

typedef int ElementType;
typedef int PriorityType;

// 힙 구조체 ---------------
typedef struct tageHeapNode
{
    ElementType Data;
} HeapNode;

typedef struct tagHeap
{
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;
// ------------------------
// 우선순위 큐 구조체 ------
typedef struct tagePQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;
// ------------------------

// 우선순위 큐 함수 ---------------------------------
PriorityQueue* PQ_Create(int InitialSize)
{
    PriorityQueue* NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode)) * NewPQ->Capacity);

    return NewPQ;
}

void PQ_Destroy(PriorityQueue* PQ)
{
    free(PQ->Nodes);
    free(PQ);
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
    int CopySize = sizeof(PQNode);
    PQNode* Temp = (PQNode*)malloc(CopySize);

    memcpy(Temp, &PQ->Nodes[Index1], CopySize);
    memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize);
    memcpy(&PQ->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

int PQ_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ)
{
    return PQ->UsedSize == 0;
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode)
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent(CurrentPosition);

    if (PQ->UsedSize == PQ->Capacity)
    {
        if (PQ->Capacity == 0)
        {
            PQ->Capacity = 1;
        }

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode)) * PQ->Capacity);
    }

    PQ->Nodes[CurrentPosition] = NewNode;
    
    // 후속처리
    while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
    {
        PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent(CurrentPosition);
    }

    PQ->UsedSize++;
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPostion = 0;

    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
    memcpy(&PQ->Nodes[0], 0, sizeof(PQNode));

    PQ->UsedSize--;
    PQ_SwapNodes(PQ, 0, PQ->UsedSize);

    LeftPosition = PQ_GetLeftChild(0);
    RightPostion = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        if (LeftPosition >= PQ->UsedSize)
        {
            break;
        }

        if (RightPostion >= PQ->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPostion].Priority)
            {
                SelectedChild = RightPostion;
            }
            else
            {
                SelectedChild = LeftPosition;
            }
        }

        if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
        {
            break;
        }

        LeftPosition = PQ_GetLeftChild(ParentPosition);
        RightPostion = LeftPosition + 1;
    }

    if (PQ->UsedSize < (PQ->Capacity / 2))
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }
}

// 힙 함수 -----------------------------------------

Heap* HEAP_Create(int InitialSize)
{
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

    printf("size : %d\n", sizeof(HeapNode));

    return NewHeap;
}

void HEAP_Destroy(Heap* H)
{
    free(H->Nodes);
    free(H);
}

int HEAP_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void HEAP_PrintNodes(Heap* H)
{
    int i = 0;

    for (i = 0; i < H->UsedSize; i++)
    {
        printf("%d", H->Nodes[i].Data);
    }
    printf("\n");
}

int HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

void HEAP_Insert(Heap* H, ElementType NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    if (H->UsedSize == H->Capacity) // 1)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;
    
    // 후속처리
    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode)); // 1)
    memset(&H->Nodes[0], 0, sizeof(HeapNode));

    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize); // 2)

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1) // 3)
    {
        int SelectedChild = 0;
        
        if (LeftPosition >= H->UsedSize)
        {
            break;
        }

        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
            {
                SelectedChild = RightPosition;
            }
            else
            {
                SelectedChild = LeftPosition;
            }
        }

        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
        {
            break;
        }

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))
    {
        H->Capacity /= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}
// ------------------------------------------------

int main()
{
    std::cout << "Hello World!\n";
}

