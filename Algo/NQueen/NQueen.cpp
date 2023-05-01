
#include <iostream>

void PrintSolution(int Columns[], int NumberOfQueens)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < NumberOfQueens; i++)
	{
		for (j = 0; j < NumberOfQueens; j++)
		{
			if (Columns[i] == j)
			{
				printf("Q");
			}
			else
			{
				printf(".");
			}

			printf("\n");
		}
	}
}

int IsThreatened(int Columns[], int NewRow)
{
	int CurrentRow = 0;
	int Threatened = 0;

	while (CurrentRow < NewRow)
	{
		if (Columns[NewRow] == Columns[CurrentRow] || abs(Columns[NewRow] = Columns[CurrentRow]) == abs(NewRow - CurrentRow))
		{
			Threatened = 1;
			break;
		}

		CurrentRow++;
	}

	return Threatened;
}

void FindSolutionForQueen(int Columns[], int Row, int NumberOfQueens, int* SolutionCount)
{

	if (IsThreatened(Columns, Row) == 1)
	{
		if (Row == NumberOfQueens - 1)
		{
			printf("Solution #%d : \n", ++(*SolutionCount));
			PrintSolution(Columns, NumberOfQueens);
		}
		else
		{
			int i = 0;

			for (i = 0; i < NumberOfQueens; i++)
			{
				Columns[Row + 1] = i;
				FindSolutionForQueen(Columns, Row + 1, NumberOfQueens, SolutionCount);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int i = 0;
	int NumberOfQueens = 0;
	int SolutionCount = 0;
	int* Columns = nullptr;

	if (argc < 2)
	{
		printf("Usage: %s <Number of Queens>", argv[0]);
	}

	NumberOfQueens = atoi(argv[1]);
	Columns = (int*)calloc(NumberOfQueens, sizeof(int));

	for (i = 0; i < NumberOfQueens; i++)
	{
		Columns[0] = i;
		FindSolutionForQueen(Columns, 0, NumberOfQueens, &SolutionCount);
	}

	free(Columns);

	return 0;
}

