
#include <iostream>

void Swap(int* A, int* B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int Pivot = DataSet[First];

    ++Left;

    while (Left < Right)
    {
        while (DataSet[Left] <= Pivot)
        {
            ++Left;
        }

        while (DataSet[Right] > Pivot)
        {
            --Right;
        }

        if (Left >= Right)
        {
            break;
        }

        Swap(&DataSet[Left], &DataSet[Right]);
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    // 1)
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

int main()
{
    int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length - 1);

    for (i = 0; i < Length; i++)
    {
        std::cout << DataSet[i];
        std::cout << " ";
    }

    return 0;
}