#include "sandpiles.h"

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				unstable = 1;
		}
	while (unstable == 1)
	{
		print_g(grid1);
		unstable = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid2[i][j] = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid2[i][j] -= 4;
					if (i + 1 <= 2)
						grid2[i + 1][j] += 1;
					if (j + 1 <= 2)
						grid2[i][j + 1] += 1;
					if (i - 1 >= 0)
						grid2[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid2[i][j - 1] += 1;
				}
			}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid2[i][j];
				if (grid1[i][j] > 3)
					unstable = 1;
			}
	}
}

/**
 * print_g - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_g(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

