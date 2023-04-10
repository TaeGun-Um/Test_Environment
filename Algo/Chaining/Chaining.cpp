
#include <iostream>

typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode
{
    KeyType Key;
    ValueType Value;

    struct tagNode* Next;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
    int TableSize;
    List* Table;
} HashTable;

ValueType CHT_Get(HashTable* HT, KeyType Key)
{
    int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
    List TheList = HT->Table[Address];
    List Target = nullptr;

    if (TheList == nullptr)
    {
        return nullptr;
    }
    
    while (strcmp(TheList->Key, Key) == 0)
    {
        Target = TheList;
        break;
    }

    if (TheList->Next == nullptr)
    {
        return nullptr;
    }
    else
    {
        TheList = TheList->Next;
    }

    return Target->Value;
}

ValueType CHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
    Node* NewNode = CHT_CreateNode(Key, Value);

    if (HT->Table[Address] == nullptr)
    {
        HT->Table[Address] = NewNode;
    }
    else
    {
        List L = HT->Table[Address];
        NewNode->Next;
        HT->Table[Address] = NewNode;

        printf("Collision occured : Key(%s), Address(%d)\n", Key, Address);
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
