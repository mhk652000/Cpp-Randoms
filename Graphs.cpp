//Muhammad Hasan Khan 2019328

#include<iostream>
#include <list>

using namespace std;

class Graph
{
	int Nodes;
	list<int>* adj;

public:


	Graph(int Nodes)
	{
		this->Nodes = Nodes;
		adj = new list<int>[Nodes];
	}

	void bfs(int s)
	{
		bool* visited = new bool[Nodes];


		for (int i = 0; i < Nodes; i++)
		{
			visited[i] = false;
		}


		list<int> queue;

		visited[s] = true;
		queue.push_back(s);

		list<int>::iterator i;

		while (!queue.empty())
		{
			s = queue.front();
			cout << s << " ";
			queue.pop_front();

			for (i = adj[s].begin(); i != adj[s].end(); ++i)
			{
				if (!visited[*i])
				{
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}

	void Einsert(int v, int w)
	{
		adj[v].push_back(w);
	}

	
};

int main()
{
	Graph bfs(6);
	bfs.Einsert(1, 2);
	bfs.Einsert(1, 3);
	bfs.Einsert(1, 4);
	bfs.Einsert(2, 1);
	bfs.Einsert(3, 1);
	bfs.Einsert(4, 1);
	bfs.Einsert(2, 3);
	bfs.Einsert(3, 2);
	bfs.Einsert(2, 5);
	bfs.Einsert(5, 2);

	int choice;
	cout << "\n  vertex for BFS : ";
	cin >> choice;
	bfs.bfs(choice);
}