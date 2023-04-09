
#include <iostream>

Node* SLL_SequentialSearch(Node* Head, int Target)
{
    Node* Current = Head;
    Node* Match = nullptr;

    while (Current != nullptr)
    {
        if (Current->Data == Target)
        {
            Match = Current;
            brake;
        }
        else
        {
            Current = Current->NextNode;
        }
    }
    return Match;
}

Node* SLL_MoveToFront(Node* Head, int Target)
{
    Node* Current = (*Head);
    Node* Previous = nullptr;
    Node* Match = nullptr;

    while (Current != nullptr)
    {
        Match = Current;

        if (Previous != nullptr)
        {
            Previous->NextNode = Current->NextNode;
            Current->NextNode = (*Head);
            (*Head) = Current;
        }
        else
        {
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

Node* SLL_Transpose(Node* Head, int Target)
{
    Node* Current = (*Head);
    Node* Pre_Previous = nullptr;   // 이전 노드의 이전 노드
    Node* Previous = nullptr;       // 이전 노드
    Node* Match = nullptr;

    while (Current != nullptr)
    {
        if (Currrent->Data == Target)
        {
            Match = Current;

            if (Previous != nullptr)
            {
                if (Pre_Previous)
                {
                    Pre_Previous->NextNode = Current;
                }
                else
                {
                    (*Head) = Current;
                }

                Previous->NextNode = Current->NextNode;

                Current->NextNode = Previous;
            }
            break;
        }
        else
        {
            if (Previous != nullptr)
            {
                Pre_Previous = Previous;
                Previouse = Current;
                Current = Current->NextNode;
            }
        }
    }
    return Match;
}

int main()
{
    std::cout << "Hello World!\n";
}

