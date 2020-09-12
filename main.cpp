/* Author: Vedang D Gaonkar
 *
 * Class: CSC 372 - Analysis of Algorithms
 *
 * Project : Shortest Path using Dynamic Programming
 *
 */

#include "graph.h"

int main(int argc, char* argv[])
{
    int nGraphs = argc/4;
    int z = 1;

    //Continue while there are more graphs in the command line
    while(nGraphs > 0)
    {
	//Assign command line arguments to graph attributes
	Graph G(stoi(argv[z+1]), stoi(argv[z+2]), stoi(argv[z+3]), argv[z]);		  		
    
	cout<<"Test "<<(z/4)+1<<endl;
	cout<<"Input: start = "<<G.start<<", end = "<<G.end<<", k = "<<G.k<<endl;	

	//Input graph from text file and make adjacency lists 
	G.fillVectors();

	//Utility function to carry out the alorithm and print results	
	utility(G);
	
	nGraphs--;
	z += 4;	
    }

    return 0;
}
