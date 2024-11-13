#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

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

int** create_adjacency_matrix(int vertexes);
int cout_matrix(int vertexes, int** G);
void DFS_matrix(int** g, int s, int size, bool* vis);

struct Graph* create_adjacency_list(int vertexes);
struct Node* create_vertex(int vertex);
void connect_vertexes(struct Graph* graph, int coll, int dest);
void cout_adjacency_list(struct Graph* graph);
void DFS_list(struct Graph* G, int s, int size, bool* vis);

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
	DFS_matrix(M, to_start_with, vertexes, visited);
	cout << endl;

	struct Graph* G1 = create_adjacency_list(vertexes);
	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < vertexes; j++)
		{
			if (M[i][j] == 1)
			{
				connect_vertexes(G1, i, j);
			}
		}
	}
	cout_adjacency_list(G1);
	cout << endl << "---------------------------------" << endl;

	for (int i = 0; i < vertexes; i++)
	{
		visited[i] = false;
	}
	cout << endl << "input input number of vertex to star with: ";
	cin >> to_start_with;
	cout << endl << "First-deep list search: " << endl;
	DFS_list(G1, to_start_with, vertexes, visited);
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

void DFS_matrix(int** g, int s, int size, bool* vis)
{
	vis[s] = true;
	cout << s << " -> ";
	for (int i = 0; i < size; i++)
	{
		if (g[s][i] == 1 && vis[i] == 0)
		{
			DFS_matrix(g, i, size, vis);
		}
	}
}

struct Graph* create_adjacency_list(int vertexes)
{
	struct Graph* graph = new struct Graph;
	graph->vertexes_amount = vertexes;
	graph->list = new struct Node* [vertexes];
	for (int i = 0; i < vertexes; i++)
	{
		graph->list[i] = new struct Node[vertexes];
	}

	for (int i = 0; i < vertexes; i++)
	{
		graph->list[i] = create_vertex(i);
	}

	return graph;
}

struct Node* create_vertex(int vertex)
{
	struct Node* new_node = new struct Node;
	new_node->vertex = vertex;
	new_node->next = NULL;
	return new_node;
}

void connect_vertexes(struct Graph* graph, int coll, int dest)
{
	struct Node* new_node = create_vertex(dest);
	int i = 0;
	while (graph->list[i]->vertex != coll)
	{
		i++;
	}

	struct Node* tmp = graph->list[i];
	while (tmp->next != NULL)
	{

		tmp = tmp->next;
	}

	tmp->next = new_node;
}

void cout_adjacency_list(struct Graph* graph)
{
	cout << endl << "adjacency list:" << endl;
	struct Node* tmp;
	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		tmp = graph->list[i];
		while (tmp)
		{
			cout << tmp->vertex;
			tmp = tmp->next;
			if (tmp != NULL)
			{
				cout << " -> ";
			}
		}
		cout << endl;
	}
}

void DFS_list(struct Graph* G, int s, int size, bool* vis) 
{
	vis[s] = true;
	cout << s << " -> ";
	Node* adjNode = G->list[s];
	while (adjNode != NULL) 
	{
		int v = adjNode->vertex;
		if (!vis[v]) {
			DFS_list(G, v, size, vis);
		}
		adjNode = adjNode->next;
	}
}