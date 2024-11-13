#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

#define MAX_VERTICES 20

struct Node
{
	int vertex;
	struct Node* next;
};

struct Graph
{
	int vertexes_amount;
	struct Node** list;
};

struct Stack 
{
	int items[MAX_VERTICES];
	int top;
};

int** create_adjacency_matrix(int vertexes);
int cout_matrix(int vertexes, int** G);
void DFS_matrix_stack(int** g, int s, int size, bool* vis);

void main()
{
	int** M;
	int vertexes = 0;
	int to_start_with = 0;

	cout << "input graph size: ";
	cin >> vertexes;

	M = create_adjacency_matrix(vertexes);
	cout_matrix(vertexes, M);

	bool* visited = new bool[vertexes];
	for (int i = 0; i < vertexes; i++)
	{
		visited[i] = false;
	}

	cout << endl << "input input number of vertex to star with: ";
	cin >> to_start_with;

	cout << endl << "First-deep matrix search: " << endl;
	DFS_matrix_stack(M, to_start_with, vertexes, visited);
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

void DFS_matrix_stack(int** g, int s, int size, bool* vis)
{
	stack<int> stack;
	stack.push(s);
	vis[s] = true;

	while (!stack.empty()) {
		int v = stack.top();
		stack.pop();
		cout << v << " -> ";

		for (int i = size - 1; i >= 0; i--) {
			if (g[v][i] == 1 && !vis[i]) {
				stack.push(i);
				vis[i] = true;
			}
		}
	}
}