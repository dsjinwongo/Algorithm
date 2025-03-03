#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, i, j, row, col, overlap;
	char** condo;
	int* row_spare;
	int* col_spare;
	int* row_overlap;
	int* col_overlap;
	row = 0;
	col = 0;

	cin >> N;
	condo = new char*[N];
	for (i = 0; i < N; i++)
		condo[i] = new char[N];
	row_spare = new int[N]();
	col_spare = new int[N]();
	row_overlap = new int[N]();
	col_overlap = new int[N]();

	for (i = 0; i < N; i++)
	{
		row_spare[i] = -1;
		col_spare[i] = -1;
		row_overlap[i] = -2;
		col_overlap[i] = -2;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> condo[i][j];
			if (condo[i][j] == '.')
			{
				if (j - row_spare[i] > 1 && row_overlap[i] != row_spare[i])
				{
					row++;
					row_overlap[i] = row_spare[i];
				}
				if (i - col_spare[j] > 1 && col_overlap[j] != col_spare[j])
				{
					col++;
					col_overlap[j] = col_spare[j];
				}
			}
			else
			{
				row_spare[i] = j;
				col_spare[j] = i;
			}
		}
	}
	for (i = 0; i < N; i++)
		delete[] condo[i];
	delete[] condo;
	delete[] row_spare;
	delete[] col_spare;

	cout << row << " " << col;
}