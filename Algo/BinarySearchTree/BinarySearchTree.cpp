
#include <iostream>

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree = nullptr)
	{
		return nullptr;
	}

	if (Tree->Data == Target)
	{
		return Tree;
	}
	else if (Tree->Data > Target)
	{
		return BST_SearchNode(Tree->Left, Target);
	}
	else
	{
		return BST_SearchNode(Tree->Right, Target);
	}
}

void BST_InsertNode(BSTNode** Tree, BSTNode* Child)
{
	if ((*Tree)->Data < Child->Data) // 1)
	{
		if ((*Tree)->Right == nullptr)
		{
			(*Tree)->Right = Child;
		}
		else
		{
			BST_InsertNode(&(*Tree)->Right, Child);
		}
	}
	else if ((*Tree)->Data > Child->Data) // 2)
	{
		if ((*Tree)->Left == nullptr)
		{
			(*Tree)->Left = Child;
		}
		else
		{
			BST_InsertNode(&(*Tree)->Left, Child);
		}
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* Removed = nullptr;

	if (Tree == nullptr)
	{
		return nullptr;
	}

	if (Tree->Data > Target)
	{
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	}
	else if (Tree->Data < Target)
	{
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	}
	else // 목표 값을 찾은 경우
	{
		Removed = Tree;

		if (Tree->Left == nullptr && Tree->Right == nullptr) // 잎 노드인 경우 바로 삭제
		{
			if (Parent->Left == Tree)
			{
				Parent->Left == nullptr;
			}
			else
			{
				Parent->Right == nullptr;
			}
		}
		else
		{
			if (Tree->Left != nullptr && Tree->Right != nullptr) // 양쪽 자식이 다 있는 경우
			{
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
				Remove = BST_RemoveNode(Tree, nullptr , MinNode->Data); // 1)
				Tree->Data = MinNode->Data;
			}
			else // 자식이 하나만 있는 경우
			{
				BSTNode* Temp = nullptr;

				if (Tree->Left != nullptr)
				{
					Temp = Tree->Left;
				}
				else
				{
					Temp = Tree->Right;
				}

				if (Parent->Left == Type)
				{
					Parent->Left = Temp;
				}
				else
				{
					Parent->Right = Temp;
				}
			}
		}
	}

	return Removed;
}

int main()
{
    std::cout << "Hello World!\n";
}

