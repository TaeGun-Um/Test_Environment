
#include <iostream>

typedef struct tagRBTNode
{
    struct tagRBTNode* Parent;
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;

    enum
    {
        RED,
        BlACK

    } Color; // 노드의 색을 나타내는 Color 필드, RED 아니면 BLACK의 값을 저장할 수 있다.

    int Data;

} RBTNode;

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
    RBTNode* LeftChild = Parent->Left;

    Parent->Left = LeftChild->Right;

    if (LeftChild->Right != Nil)
    {
        LeftChild->Right->Parent = Parent;
    }

    LeftChild->Parent = Parent->Parent;

    if (Parent->Parent == nullptr)
    {
        (*Root) = LeftChild;
    }
    else
    {
        if (Parent == Parent->Parent->Left)
        {
            Parent->Parent->Left = LeftChild;
        }
        else
        {
            Parent->Parent->Right = LeftChild;
        }
    }

    LeftChild->Right = Parent;
    Parent->Parent = LeftChild;
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
    // 1)
    while (X != (*Root) && X->Parent->Color == RED)
    {
        // 2)
        if (X->Parent == X->Parent->Parent->Left)
        {
            RBTNode* Uncle = X->Parent->Parent->Right;
            
            // 3)
            if (Uncle->Color == RED)
            {
                X->Parent->Color = BLACK;
                Uncle->Color = BLACK;
                X->Parent->Parent->Color = RED;

                X = X->Parent->Parent;
            }
            else
            {
                // 4)
                if (X == X->Parent->Right)
                {
                    X = X->Parent;
                    RBT_RotateLeft(Root, X);
                }

                X->Parent->Color = BLACK;
                X->Parent->Parent->Color = RED;
                RBT_RotateRight(Root, X->Parent->Parent);
            }
        }
        else
        {
            // 부모가 할아버지의 오른쪽 자식인 경우에는
            // 왼쪽 자식인 경우의 코드에서 좌우만 바꾸면 된다.
        }
    }

    // 5)
    (*Root)->Color = BLACK;
}

void RBT_InsertNode(RBTNode* Tree, RBTNode* NewNode)
{
    RBT_InsertNodeHelper(Tree, NewNode);  // 1)

    NewNode->Color = RED;
    NewNode->Left = Nil;  // 2)
    NewNode->Right = Nil;

    RBT_RebuildAfterInsert(Tree, NewNode);  // 3)
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
    RBTNode* Sibling = nullptr;

    while (Successor->Parent != nullptr && Successor->Color == BLACK) // 1)
    {
        if (Successor == Successor->Parent->Left)
        {
            Sibling = Successor->Parent->Right;

            if (Sibling->Color == RED)
            {
                Sibling->Color = BLACK;
                Successor->Parent->Color = RED;

                RBT_RotateLeft(Root, Successor->Parent);
            }
            else // 2)
            {
                if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK) // 3)
                {
                    Sibling->Color = RED;
                    Successor = Successor->Parent;
                }
                else
                {
                    if (Sibling->Left->Color == RED) // 4)
                    {
                        Sibling->Left->Color = BLACK;
                        Sibling->Color = RED;

                        RBT_RotateRight(Root, Sibling);
                    }

                    Sibling->Color = Successor->Parent->Color; // 5)
                    Successor->Parent->Color = BLACK;
                    Sibling->Right->Color = BLACK;
                    RBT_RotateLeft(Root, Successor->Parent);
                    Successor = (*Root);
                }
            }
        }
        else
        {
            // ~~
        }
    }

    Successor->Color = BLACK;
}

RBTNode* RBT_RemoveNode(RBTNode** Root, int Data)
{
    RBTNode* Removed = nullptr;
    RBTNode* Successor = nullptr;
    RBTNode* Target = RBT_SearchNode((*Root), Data);
    
    if (Target == nullptr)
    {
        return nullptr;
    }

    if (Target->Left == Nil || Target->Right == Nil)
    {
        Removed = Target;
    }
    else
    {
        Removed = RBT_SearchMinNode(Target->Right);
        Target->Data = Removed->Data;
    }

    if (Removed->Left != Nil)
    {
        Successor = Removed->Left;
    }
    else
    {
        Successor = Removed->Right;
    }

    Successor->Parent = Removed->Parent;

    if (Removed->Parent == nullptr)
    {
        (*Root) = Successor;
    }
    else
    {
        if (Removed == Removed->Parent->Left)
        {
            Removed->Parent->Left = Successor;
        }
        else
        {
            Removed->Parent->Right = Successor;
        }
    }

    if (Removed->Color == BLACK) // 1)
    {
        RBT_RebuildAfterRemove(Root, Successor);
    }

    return Removed;
}

int main()
{
    std::cout << "Hello World!\n";
}
