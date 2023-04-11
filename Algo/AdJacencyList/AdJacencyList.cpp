
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

int main()
{
    std::cout << "Hello World!\n";
}

