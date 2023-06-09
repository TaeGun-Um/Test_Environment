﻿
#include <iostream>

typedef int PriorityType;

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
    NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * NewPQ->Capacity);

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
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
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

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct TagSymbolInfo
{
    UCHAR Symbol;
    int Frequency;
} SymbolInfo;

typedef struct TagHuffmanNode
{
    SymbolInfo Data;
    struct TagHuffmanNode* Left;
    struct TagHuffmanNode* Right;
} HuffmanNode;

typedef struct TagBitBuffer
{
    UCHAR Buffer;
    UINT Size;
} BitBuffer;

typedef struct TagHuffmanCode
{
    UCHAR Code[MAX_BIT];
    int Size;
} HuffmanCode;

HuffmanNode* Huffman_CreateNode(SymbolInfo NewData);
void Huffman_DestroyNode(HuffmanNode* Node);
void Huffman_DestroyTree(HuffmanNode* Node);
void Huffman_AddBit(BitBuffer* Buffer, char value);
void Huffman_Encode(HuffmanNode** Tree, UCHAR* Source, BitBuffer* Encoded, HuffmanCode CodeTable[MAX_CHAR]);
void Huffman_Decode(HuffmanNode* Tree, BitBuffer* Encoded, UCHAR* Decoded);
void Huffman_BuildPrefixTree(HuffmanNode** Tree, SymbolInfo SymbolInfoTable[MAX_CHAR]);
void Huffman_BuildCodeTable(HuffmanNode* Tree, HuffmanCode CodeTable[MAX_CHAR], UCHAR Code[MAX_BIT], int Size);
void Huffman_PrintBinary(BitBuffer* Buffer);

HuffmanNode* Huffman_CreateNode(SymbolInfo NewData)
{
    HuffmanNode* NewNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    NewNode->Left = nullptr;
    NewNode->Right = nullptr;
    NewNode->Data = NewData;

    return NewNode;
}

void Huffman_DestroyNode(HuffmanNode* Node)
{
    free(Node);
}

void Huffman_DestroyTree(HuffmanNode* Node)
{
    if (Node == nullptr)
    {
        return;
    }

    Huffman_DestroyTree(Node->Left);
    Huffman_DestroyTree(Node->Right);
    Huffman_DestroyTree(Node);
}

void Huffman_AddBit(BitBuffer* Buffer, char value)
{
    UCHAR Mask = 0x80;

    if (Buffer->Size % 8 == 0)
    {
        Buffer->Buffer = realloc(Buffer->Buffer, sizeof(UCHAR) * ((Buffer->Size / 8) + 1));
        Buffer->Buffer[Buffer->Size / 8] = 0x00;
    }
    
    Mask >>= Buffer->Size % 8;

    if (Bit == 1)
    {
        Buffer->Buffer[Buffer->Size / 8] != Mask;
    }
    else
    {
        Buffer->Buffer[Buffer->Size / 8] &= ~Mask;
    }

    Buffer->Size++;
}

void Huffman_BuildCodeTable(HuffmanNode* Tree, HuffmanCode CodeTable[MAX_CHAR], UCHAR Code[MAX_BIT], int Size)
{
    if (Tree == nullptr)
    {
        return;
    }

    if (Tree->Left != nullptr)
    {
        Code[Size] = 0;
        Huffman_BuildCodeTable(Tree->Left, CodeTable, Code, Size + 1);
    }

    if (Tree->Right != nullptr)
    {
        Code[Size] = 1;
        Huffman_BuildCodeTable(Tree->Right, CodeTable, Code, Size + 1);
    }
    
    if (Tree->Left == nullptr && Tree->Right == nullptr)
    {
        int i;
        
        for (i = 0; i < Size; i++)
        {
            CodeTable[Tree->Data.Symbol].Code[i] = Code[i];
        }

        CodeTable[Tree->Data.Symbol].Size = Size;
    }
}

void Huffman_BuildPrefixTree(HuffmanNode** Tree, SymbolInfo SymbolInfoTable[MAX_CHAR])
{
    int i = 0;
    PQNode Result;
    PriorityQueue* PQ = PQ_Create(0);

    for (i = 0; i < MAX_CHAR; i++)
    {
        if (SymbolInfoTable[i].Frequency > 0)
        {
            HuffmanNode* BitNode = Huffman_CreateNode(SymbolInfoTable[i]);
            PQNode NewNode;
            NewNode.Priority = SymbolInfoTable[i].Frequency;
            NewNode.Data = BitNode;
            PQ_Enqueue(PQ, NewNode);
        }
    }

    while (PQ->UsedSize > 1)
    {
        SymbolInfo NewData = { 0, 0 };
        HuffmanNode* BitNode = Huffman_CreateNode(NewData);
        HuffmanNode* Left;
        HuffmanNode* Right;

        PQNode QLeft;
        PQNode QRight;
        PQNode NewNode;

        PQ_Dequeue(PQ, &QLeft);
        PQ_Dequeue(PQ, &QRight);

        Left = (HuffmanNode*)QLeft.Data;
        Right = (HuffmanNode*)QRight.Data;

        BitNode->Data.Symbol = 0;
        BitNode->Data.Frequency = Left->Data.Frequency + Right->Data.Frequency;

        BitNode->Left = Left;
        BitNode->Right = Right;

        NewNode.Priority = BitNode->Data.Frequency;
        NewNode.Data = BitNode;

        PQ_Enqueue(PQ, NewNode);
    }

    PQ_Dequeue(PQ, &Result);
    *Tree = (HuffmanNode*)Result.Data;
}

void Huffman_Encode(HuffmanNode** Tree, UCHAR* Source, BitBuffer* Encoded, HuffmanCode CodeTable[MAX_CHAR])
{
    int i = 0;
    j = 0;
    SymbolInfo SymbolInfoTable[MAX_CHAR];
    UCHAR Temporary[MAX_BIT];

    for (i = 0; i < MAX_CHAR; i++)
    {
        SymbolInfoTable[i].Symbol = i;
        SymbolInfoTable[i].Frequency = 0;
    }

    i = 0;
    
    while (Source[i] != '\0')
    {
        SymbolInfoTable[Source[i++]].Frequency++;
    }

    Huffman_BuildPrefixTree(Tree, SymbolInfoTable);
    Huffman_BuildCodeTable(*Tree, CodeTable, Temporary, 0);

    i = 0;

    while (Source[i] != '\0')
    {
        int BitCount = CodeTable[Source[i]].Size;

        for (j = 0; j < BitCount; j++)
        {
            Huffman_AddBit(Encoded, CodeTable[Source[i]].Code[j]);
        }

        i++;
    }
}

void Huffman_Decode(HuffmanNode* Tree, BitBuffer* Encoded, UCHAR* Decoded)
{
    int i;
    int Index = 0;
    HuffmanNode* Current = Tree;

    for (i = 0; i < Encoded->Size; i++)
    {
        UCHAR Mask = 0x80;

        if (Current->Left == nullptr && Current->Right == nullptr)
        {
            Decoded[Index++] = Current->Data.Symbol;
            Current = Tree;
        }

        Mask >>= i % 8;

        if ((Encoded->Buffer[i / 8] & Mask) != Mask)
        {
            Current = Current->Left;
        }
        else
        {
            Current = Current->Right;
        }

        Decoded[Index] = '\0';
    }
}

void Huffman_PrintBinary(BitBuffer* Buffer)
{
    int i;

    for (i = 0; i < Buffer->Size; i++)
    {
        UCHAR Mask = 0x80;
        Mask >>= i % 8;

        printf("%d", (Buffer->Buffer[i / 8] & Mask) == Mask);
    }
}


int main()
{
    

}
