
#include <iostream>

ElementType BinarySearch(ElementType DataSet[], int Size, ElementType Target)
{
    int Left, Right, Mid;

    Left = 0;
    Right = Size - 1;

    while (Left <= Right)
    {
        // 1)
        Mid = (Left + Right) / 2;

        // 2)
        if (Target == DataSet[Mid])
        {
            return DataSet[Mid];
        }
        else if (Target > DataSet[Mid])
        {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
        }
    }

    // 3)
    return nullptr;
}

int main()
{
    std::cout << "Hello World!\n";
}
