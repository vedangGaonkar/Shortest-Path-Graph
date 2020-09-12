/*Author: Vedang D Gaonkar */

#include "graph.h"

void utility(Graph &G)
{
	
	if(G.k == 1)
	{
	    cout<<"Path: ";
	    if(G.v[G.start][G.end] > (G.INF-0.001))
		cout<<"none"<<endl;

	    else
	    {
		cout<<G.start<<" to "<<G.end<<endl;
		cout<<"Weight: "<<G.v[G.start][G.end]<<endl;
	    }
	    cout<<"=================================================="<<endl;	
	    return;
	}

	G.dpShortest();

	G.findShortest();

	cout<<"Path: ";

	if(G.finalMin > (G.INF - 0.001))
	    cout<<"none"<<endl;

	else
	{
	    cout<<G.path.top();
	    G.path.pop();

	    while(!G.path.empty())
	    {
		cout<<" to "<<G.path.top();
		G.path.pop();	
	    }
	    
	    cout<<endl;	
	    cout<<"Weight = "<<G.finalMin<<endl;
	}	
	cout<<"=================================================="<<endl; 

    return;
}
