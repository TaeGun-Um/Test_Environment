
#include <iostream>

typedef int ElementType;

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
        ParentPosition = HEAP_GETParent(CurrentPosition);
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

int main()
{
    std::cout << "Hello World!\n";
}

