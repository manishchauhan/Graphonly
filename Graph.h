#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
struct Edge
{
	int src;
	int dest;
	int weight;
};
typedef  pair<int, int> Pair;
class Graph
{
private:
	vector<vector<Edge>> EdgesVector;
	int graphSize = 0;
	void recursionDFS(int index, vector<bool>& visited);
public:
	Graph() {};
	~Graph() {};
	/*
		below function add any number of Edges
	*/
	void addEdges(vector<Edge>& edges);
	//add only one Edge at once this function can override already existing edge
	void addEdge(Edge& edge);
	/* display all Vertices weight etc*/
	void display();
	//How BFS level wise
	void BSF(int index);
	//How DFS level wise
	void DFS(int index);
	//Get graph size
	int getGraphSize();
	//topo logical sort very important - need to be added
	//Finding in and out degrees of all vertices in a graph
	//In-Degree And Out-Degree
	void findInOutDegree();
	vector<int> TopologicalSortBFS();//Kahns algorithm for Topological Sorting 
	void displayTopologicalSortBFS();
};

