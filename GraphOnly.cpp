

#include <iostream>
#include "Graph.h"
int main()
{
    //each node in vector define three things first parameter is starting Vertices end Vertices
    //and weight

    /*
    vector<Edge> edges =
    {
        // `(x, y, w)` —> edge from `x` to `y` having weight `w`
         { 1, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 5, 4, 1 }, { 4, 2, 999 }

    };*/
    /*
    vector<Edge> edges =
    {
        // `(x, y, w)` —> edge from `x` to `y` having weight `w`
        { 5, 2, 25 }, { 5, 0, 57 }, { 4, 0, 35 }, { 4, 1, 14 },
        { 2, 3, 330 }, { 3, 1, 1222 }
    };*/

    //for false case
    vector<Edge> edgesfalse =
    {
        {0,1,101},{0,3,102},{1,0,103},{1,2,104},{2,1,105},{2,3,106},{2,0,1000},{3,0,105},{3,2,106}
    };

    //for true case
    vector<Edge> edgestrue =
    {
        {0,1,101},{0,3,102},{1,0,103},{1,2,104},{2,1,105},{2,3,106},{3,0,105},{3,2,106}
    };
    Graph graph;
    graph.addEdges(edgestrue);
        cout << graph.isBipartite();
   // graph.displayTopologicalSortBFS();
    // graph.display();
   // graph.BSF(5);

     //DFS we need one visited array with bools
   //  graph.DFS(5);

   //  graph.findInOutDegree();
}

