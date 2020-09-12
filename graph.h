/* Author: Vedang D Gaonkar*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <fstream>
#include <stack>

using namespace std;

class Graph
{	
    public: 
     
    ifstream fin;
    int start=0;
    int end = 0;
    int k=0;
    int n=0;

    double finalMin = 0;
    int finalK = 0;

    const double INF = 1000000;
    
    //Original array from the file	
    vector<vector<double> > v;
    //adjacency list for every node
    vector<vector<int> > adj;
    //double is currDistance, int is node it came from
    vector<vector<pair<double, int> > > dp;
    //Last Path
    stack<int> path;

    Graph();
    Graph(int start, int end, int k, char* fName);
    ~Graph();

    void fillVectors();
    void dpShortest(); 
    void findShortest();
};

void utility(Graph &G);

#endif
