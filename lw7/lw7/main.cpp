#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int** create_adjacency_matrix(int vertexes);
int cout_matrix(int vertexes, int** G);

void main()
{
	int** M;
	int vertexes = 0;

	cout << "input graph size: ";
	cin >> vertexes;

	M = create_adjacency_matrix(vertexes);
	cout_matrix(vertexes, M);

	cout << endl;
	return;
}

int** create_adjacency_matrix(int vertexes)
{
	srand(time(NULL));
	int** G = new int* [vertexes];

	for (int i = 0; i < vertexes; i++)
	{
		G[i] = new int[vertexes];
	}

	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < vertexes; j++)
		{
			if (j < i)
			{
				G[i][j] = G[j][i];
			}
			else
			{
				G[i][j] = rand() % 2;
			}
		}
	}

	return G;
}

int cout_matrix(int vertexes, int** G)
{
	cout << "    ";
	for (int i = 0; i < vertexes; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < vertexes; i++)
	{
		cout << i << "   ";
		for (int j = 0; j < vertexes; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}