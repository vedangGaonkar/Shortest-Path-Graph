/*Author: Vedang D Gaonkar*/

#include "graph.h"

//Default Constructor
Graph::Graph(){}

//Constructor
Graph::Graph(int start, int end, int k, char* fName)
{
    this->k = k;
    this->end = end;
    this->start = start; 
    this->fin.open(fName);
    fin>>n;
}

//Destructor
Graph::~Graph()
{
    this->v.clear();
    this->dp.clear();
    this->adj.clear();
   // this->path.clear();
}


// Function to input the graph from the file and 
// create adjacency list
void Graph::fillVectors()
{

    this->v.resize(n+1, vector<double>(n+1,0));
    this->adj.resize(n+1);
    this->dp.resize(k+1, vector<pair<double, int> >(n+1));
    
    for(int i=1; i<=n; i++)
    {
	for(int j=1; j<=n; j++)
	{
	    double temp;
	    fin>>temp;	   
	    v[i][j] = temp;
	
	    if(temp != -1 && temp != 0)
		adj[i].push_back(j);

	    if(temp == -1)
		v[i][j] = INF; 
	}
    }

    return;
}


//DP Algorithm to find closest path 
void Graph::dpShortest()
{
    
    //Filling first row of dp array with direct distances from source 
    for(int i=1; i<=n; i++)
    {
	dp[1][i].first = v[start][i];
	dp[1][i].second = start;    
    }
    
    dp[1][start].first = INF; 

    //Finding shortest paths for limited no. of edges starting
    //from 2 to k to update the dp array.
    //Complexity: O(k)*O(E) = O(kE)	
    for(int lim = 2; lim <=k; lim++)
    {

	//Going through adjacency list of every node,
	//i.e. going through every edge to find out
	//shortest path using exactly lim edges
	//Complexity = O(2*E) = O(E)
	for(int i = 1; i<= n; i++)
	{
	    double currMin = INF;
    
	    for(int j = 0; j<adj[i].size(); j++)
	    {
		int nbr = adj[i][j];

		/******************************************************
		GRADING: CALC	
		******************************************************/
		if( (dp[lim-1][nbr].first + v[i][nbr])  < currMin)
		{
		    currMin = dp[lim-1][nbr].first + v[i][nbr];
		    dp[lim][i].second = nbr;
		}
    
	    }

	    /******************************************************
	    GRADING: STORAGE	
	    ****************************************************/
	    //Storing the minimum value for shortest
	    //path using exactly lim edges
	    dp[lim][i].first = currMin;
    	 }

    }
  
    return;
}

//Function to find shortest within K
void Graph::findShortest()
{
    finalMin = INF;

    //Going through shortest path from start to end
    //for values of k = 1 to k to find the minimum 
    //distance and to trace the path
    //Complexity : O(k) 
    for(int i=1; i<=k; i++)
	if(dp[i][end].first < (finalMin+0.001))
	{
	   finalMin = dp[i][end].first;
	   finalK = i; 	
	}

    //Return if no path available within limits
    if(finalMin > (INF-0.001))
	return; 

    int x = finalK; 
    int y = end;
    
    //Pushing nodes along the shortest path into the stack
    //Complexity : O(k)
    path.push(end);
    while(x > 1)
    {
	path.push(dp[x][y].second);	
	y = dp[x][y].second;	
	x--;
    }
    path.push(start);

    return;		
}
