#include "Graph.h"

/*
	below function add any number of Edges
*/
void Graph::addEdges(vector<Edge>& edges) {
	//reset size of EdgesVector
	graphSize = edges.size();
	EdgesVector.resize(graphSize);
	for (auto& edge : edges)
	{
		Edge _edge;
		_edge.src = edge.src;
		_edge.dest = edge.dest;
		_edge.weight = edge.weight;
		EdgesVector.at(_edge.src).emplace_back(_edge);
	}
}
//add only one Edge at once this function can override already existing edge
void Graph::addEdge(Edge& edge)
{
	graphSize++;
	EdgesVector.resize(graphSize);
	Edge _edge;
	_edge.src = edge.src;
	_edge.dest = edge.dest;
	_edge.weight = edge.weight;
	EdgesVector.at(_edge.src).push_back(_edge);
}
/* display all Vertices weight etc*/
void Graph::display()
{
	cout << "---------------------" << endl;
	for (auto& edges : EdgesVector)
	{

		for (auto& edgeData : edges)
		{
			cout << "Edge" << endl;
			cout << "starting->" << edgeData.src << endl;
			cout << "ending->" << edgeData.dest << endl;
			cout << "weight->" << edgeData.weight << endl;
			cout << "_____" << endl;
		}
	}
	cout << "---------------------" << endl;
}
//How BFS level wise very important
void Graph::BSF(int index)
{
	int size = EdgesVector.size();
	vector<bool> visited(size, false);//visited node array
	visited.at(index) = true;// Mark given index as visited 
	queue<int> Queue;
	Queue.push(index);
	while (!Queue.empty())
	{
		int selectedIndex = Queue.front();
		cout << selectedIndex << "->";
		Queue.pop();
		for (auto itr = EdgesVector.at(selectedIndex).begin();
			itr != EdgesVector.at(selectedIndex).end();itr++)
		{
			Edge edge = *itr;
			int Dest = edge.dest;
			if (!visited.at(Dest))
			{
				visited.at(Dest) = true;
				Queue.push(Dest);
			}

		}
	}
	cout << endl;
}
void Graph::recursionDFS(int index, vector<bool>& visited)
{
	visited.at(index) = true;
	vector<Edge> edges = EdgesVector.at(index);
	for (auto edge : edges)
	{
		if (!visited.at(edge.dest))
		{
			visited.at(edge.dest) = true;
			int nextIndex = edge.dest;
			recursionDFS(nextIndex, visited);
		}
	}
}
void Graph::DFS(int index)
{
	vector<bool> visited(graphSize, false);
	recursionDFS(index, visited);
}
int Graph::getGraphSize()
{
	return graphSize;
}
//In-Degree And Out-Degree
void Graph::findInOutDegree()
{
	int size = getGraphSize();
	vector<int> InDegree(size, 0);   //coming
	vector<int> OutDegree(size, 0); //going
	for (int i = 0;i < size;i++)
	{
		OutDegree[i] = EdgesVector.at(i).size();
		for (auto itr = EdgesVector.at(i).begin();itr != EdgesVector.at(i).end();itr++)
		{
			InDegree[itr->dest]++;
		}
	}
	for (int i = 0;i < size;i++)
	{
		cout << "-----------------------------------" << endl;
		cout << "Edge" << " " << i << endl;
		cout << "OutDegree" << " " << OutDegree.at(i) << endl;
		cout << "InDegree" << " " << InDegree.at(i) << endl;
		cout << "-----------------------------------" << endl;
	}
}
/*
   calculate all InDegree
*/
vector<int> Graph::TopologicalSortBFS()
{
	vector<int> result; //result
	int size = getGraphSize();
	//create a InDegree vector which store InDegree means the incoming edges
	vector<int> InDegreeVector(size, 0);
	for (int i = 0;i < size;i++)
	{
		for (auto itr = EdgesVector.at(i).begin();itr != EdgesVector.at(i).end();itr++)
		{
			InDegreeVector[itr->dest]++;
		}
	}
	queue<int> Queue; //Create a queue and push those edges don't have incoming path only outgoing path
	for (int i = 0;i < size;i++)
	{
		if (InDegreeVector.at(i) == 0)
		{
			Queue.push(i);
		}
	}
	while (!Queue.empty())
	{
		int index = Queue.front();
		Queue.pop();
		result.push_back(index);
		for (auto itr = EdgesVector.at(index).begin();itr != EdgesVector.at(index).end();itr++)
		{
			if (--InDegreeVector.at(itr->dest) == 0)
			{

				Queue.push(itr->dest);
			}
		}
	}
	return result;

}
void Graph::displayTopologicalSortBFS()
{
	for (auto s : TopologicalSortBFS())
	{
		cout << s << "->";
	}
}
//Topo Logical sort