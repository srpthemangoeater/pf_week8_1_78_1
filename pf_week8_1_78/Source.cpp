#include <stdio.h>

int main()
{

	int n;
	bool check = true;
	scanf_s("%d", &n);

	int table[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &table[i][j]);
		}
	}

	//>
	for (int i = 0; i < n; i++)
	{
		int cur= 0, pre = 0;
		for (int j = 0; j < n; j++)
		{
			cur += table[i][j];

			if (i < n-1 )
			{
				pre += table[i + 1][j];
			}
			else
			{
				pre += table[0][j];
			}
		}

		if (cur != pre)
			check = false;
	}

	//V
	for (int j = 0; j < n; j++)
	{
		int cur = 0, pre = 0;
		for (int i = 0; i < n; i++)
		{
			cur += table[i][j];
			if (j < n - 1)
			{
				pre += table[i][j + 1];
			}
			else
			{
				pre += table[i][0];
			}
		}

		if (cur != pre)
			check = false;
	}

	//X
	int cur = 0, pre = 0;
	for (int i = 0; i < n; i++)
	{
		cur += table[i][i];
		pre += table[n-i-1][n-i-1];
	}
	if (cur != pre)
		check = false;

	//check 3
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++)
	{
		a += table[i][0];
		b += table[0][i];
		c += table[i][i];
	}
	if (a != b || a !=c || b!=c)
		check = false;

	if(check == true)
		printf("YES");
	else
		printf("NO");


	return 0;

}