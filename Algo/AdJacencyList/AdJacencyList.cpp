
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

enum Visitmod {Visitede, NotVisited};

typedef int ElementType;

typedef struct tagVertex
{
    ElementType Data;
    int Visited;
    int Index;

    struct tagVertex* Next;
    struct tagEdge* AdjacencyList;
} Vertex;


typedef struct tagEdge
{
    int Weight;
    struct tagEdge* Next;
    Vertex* From;
    Vertex* Target;
} Edge;

typedef struct tagGraph
{
    Vertex* Vertices;
    int VertexCount;
} Graph;

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->From = From;
    E->Target = Target;
    E->Next = nullptr;
    E->Weight = Weight;

    return E;
}

void DestoryEdge(Edge* E)
{
    free(E);
}

Vertex* CreateVertex(ElementType Data)
{
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));

    V->Data = Data;
    V->Next = nullptr;
    V->AdjacencyList = nullptr;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex(Vertex* V)
{
    while (V->AdjacencyList != nullptr)
    {
        Edge* Edge = V->AdjacencyList->Next;
        DestroyEdge(V->AdjacencyList);
        V->AdjacencyList = Edge;
    }

    free(V);
}

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = nullptr;
    graph->VertexCount = 0;

    return graph;
}

void DestroyGraph(Graph* G)
{
    while (G->Vertices != nullptr)
    {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;
    }

    free(G);
}

void AddVertex(Graph* G, Vertex* V)
{
    Vertex* VertexList = G->Vertices;

    if (VertexList == nullptr)
    {
        G->Vertices = V;
    }
    else
    {
        while (VertexList->Next != nullptr)
        {
            VertexList = VertexList->Next;
        }

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
    if (V->AdjacencyList == nullptr)
    {
        V->AdjacencyList = E;
    }
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while (AdjacencyList->Next != nullptr)
        {
            AdjacencyList = AdjacencyList->Next;
        }

        AdjacencyList->Next = E;
    }
}

void PrintGraph(Graph* G)
{
    Vertex* V = nullptr;
    Edge* E = nullptr;

    if ((V = G->Vertices) == nullptr)
    {
        return;
    }

    while (V != nullptr)
    {
        printf("%c : ", V->Data);

        if ((E = V->AdjacencyList) == nullptr)
        {
            V = V->Next;
            printf("\n");
            continue;
        }

        while (E != nullptr)
        {
            printf("%c[%d] ", E->Target->Data, E->Weight);
            E = E->Next;
        }

        printf("\n");

        V = V->Next;
    }

    printf("\n");
}

void DFS(Vertex* V)
{
    Edge* E = nullptr;

    printf("%d", V->Data);
    // 1)
    V->Visited = Visitede;

    E = V->AdjacencyList;
    // 2)
    while (E != nullptr)
    {
        if (E->Target != nullptr && E->Target->Visited == NotVisited)
        {
            // 3)
            DFS(E->Target);
        }

        E = E->Next;
    }
}

void BFS(Vertex* V, LinkedQueue* Queue)
{
    Edge* E = nullptr;

    printf("&d", V->Data);
    V->Visited = Visitede;

    LQ_Enqueue(&Queue, LQ_CreateNode(V));

    while (!LQ_IsEmpty(Queue))
    {
        Node* Popped = LQ_Dequeue(&Queue);
        V = Popped->Data;
        E = V->AdjacencyList;

        while (E != nullptr)
        {
            V = E->Target;

            if (V != nullptr && V->Visited == NotVisited)
            {
                printf("%d", V->Data);
                V->Visited = Visitede;
                LQ_Enqueue(&Queue, LQ_CreateNode(V));
            }

            E = E->Next;
        }
    }
}

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

void TS_DFS(Vertex* V, Node** List)
{
    Node* NewHead = nullptr;
    Edge* E = nullptr;

    V->Visited = Visitede;
    E = V->AdjacencyList;

    while (E != nullptr)
    {
        if (E->Target != nullptr && E->Target->Visited == NotVisited)
        {
            TS_DFS(E->Target, List);
        }
        
        E = E->Next;
    }

    printf("%c\n", V->Data);
    
    NewHead = SLL_CreateNode(V);
    SLL_InsertNewHead(List, &NewHead);
}

void TopologicalSort(Vertex* V, Node** List)
{
    while (V != nullptr && V->Visited == NotVisited)
    {
        TS_DFS(V, List);

        V = V->Next;
    }
}

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

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
    int i = 0;

    PQNode StartNode = { 0, StartVertex };
    PriorityQueue* PQ = PQ_Create(10);

    Vertex* CurrentVertex = nullptr;
    Edge* CurrentEdge = nullptr;

    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    CurrentVertex = G->Vertices;

    while (CurrentVertex != nullptr)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(&MST, NewVertex);

        Fringes[i] = nullptr;
        Precedences[i] = nullptr;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    PQ_Enqueue(PQ, StartNode);

    Weights[StartVertex->Index] = 0;

    while (!PQ_IsEmpty(PQ))
    {
        PQNode Popped;
        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;
        Fringes[CurrentVertex->Index] = CurrentVertex;
        CurrentEdge = CurrentVertex->AdjacencyList;

        while (CurrentEdge != nullptr)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            if (Fringes[TargetVertex->Index] == nullptr && CurrentEdge->Weight < Weights[TargetVertex->Index])
            {
                PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
                PQ_Enqueue(PQ, NewNode);

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
        }
    }

    for (i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;

        if (Precedences[i] == nullptr)
        {
            continue;
        }

        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));
        AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));
    }

    free(Fringes);
    free(Precedences);
    free(MSTVertices);
    free(Weights);

    PQ_Destroy(PQ);
}

typedef struct tagDisjointSet
{
    struct tagDisjointSet* Parent;
    void* Data;
} DisjointSet;

DisjointSet* DS_FindSet(DisjointSet* Set)
{
    while (Set->Parent != nullptr)
    {
        Set = Set->Parent;
    }

    return Set;
}

void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2)
{
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

DisjointSet* DS_MakeSet(void* NewData)
{
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
    NewNode->Data = NewData;
    NewNode->Parent = nullptr;

    return NewNode;
}

void DS_DestroySet(DisjointSet* Set)
{
    free(Set);
}

void Kruskal(Graph* G, Graph* MST)
{
    int i = 0;
    Vertex* CurrentVertex = nullptr;

    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);

    PriorityQueue* PQ = PQ_Create(10);
    CurrentVertex = G->Vertices;

    while (CurrentVertex != nullptr)
    {
        Edge* CurrentEdge;

        VertexSet[i] = DS_MakeSet(CurrentVertex);
        MSTVertices[i] = CreateVertex(CurrentVertex->Data);
        AddVertex(&MST, MSTVertices[i]);

        CurrentEdge = CurrentVertex->AdjacencyList;
        
        while (CurrentEdge != nullptr)
        {
            PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };
            PQ_Enqueue(PQ, NewNode);

            CurrentEdge = CurrentEdge->Next;
        }

        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    while (!PQ_IsEmpty(PQ))
    {
        Edge* CurrentEdge;
        int FromIndex;
        int ToIndex;
        PQNode Popped;

        PQ_Dequeue(PQ, &Popped);
        CurrentEdge = (Edge*)Popped.Data;

        FromIndex = CurrentEdge->From->Index;
        ToIndex = CurrentEdge->Target->Index;

        CurrentVertex = (Vertex*)Popped.Data;

        if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
        {
            AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], CurrentEdge->Weight));
            AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], CurrentEdge->Weight));
            DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
        }
    }

    for (i = 0; i < G->VertexCount; i++)
    {
        DS_DestroySet(VertexSet[i]);
    }

    free(VertexSet);
    free(MSTVertices);
}

#define MAX_WEIGHT 36267

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath)
{
    int i = 0;

    PQNode StartNode = { 0, StartVertex };
    PriorityQueue* PQ = PQ_Create(10);

    Vertex* CurrentVertex = nullptr;
    Edge* CurrentEdge = nullptr;

    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
    Vertex** ShortestPathVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    CurrentVertex = G->Vertices;

    while (CurrentVertex != nullptr)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(ShortestPath, NewVertex);

        Fringes[i] = nullptr;
        Precedences[i] = nullptr;
        ShortestPathVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    PQ_Enqueue(PQ, StartNode);

    Weights[StartVertex->Index] = 0;

    while (!PQ_IsEmpty(PQ))
    {
        PQNode Popped;
        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;
        Fringes[CurrentVertex->Index] = CurrentVertex;
        CurrentEdge = CurrentVertex->AdjacencyList;

        while (CurrentEdge != nullptr)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            if (Fringes[TargetVertex->Index] == nullptr &&
                (Weights[CurrentVertex->Index] + CurrentEdge->Weight) < Weights[TargetVertex->Index])
            {
                PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
                PQ_Enqueue(PQ, NewNode);

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] + CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
        }
    }

    for (i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;

        if (Precedences[i] == nullptr)
        {
            continue;
        }

        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(ShortestPathVertices[FromIndex], CreateEdge(ShortestPathVertices[FromIndex], ShortestPathVertices[ToIndex], Weights[i]));
    }

    free(Fringes);
    free(Precedences);
    free(ShortestPathVertices);
    free(Weights);

    PQ_Destroy(PQ);
}

int main()
{
    std::cout << "Hello World!\n";
}

