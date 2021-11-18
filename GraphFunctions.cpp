//*****************************************************************************
// Bernadette Kornberger
// Applied Discrete Structures
// 11/20/2020
// 
// 1.Given the vertex pairs assocaited to the edges find the degree of 
//   each vertex
//  
// 9. generate a simple direceted graph by producing an adjacency matrix
//    connections between nodes are called edges and each have a weight
//*****************************************************************************

#include <iostream>

using namespace std;

int main()
{
	// I did number 9 first this is it:
	
	int count, // This will keep track of how many nodes on the graph
		edges, // will keep track of how many edges a node has
		num, //will be used to help us store the values in the matrix
		weight;

	cout << "Hello how many nodes on the graph: ";
	cin >> count;

	//We create a dynamic 2D array that is a square the size of how many 
	//nodes we will be working with
	int** table;
	table = new int* [count];
	for (int c = 0; c < count; c++)
	{
		table[c] = new int[count];
	}


	//runs for how many nodes we have 
	for (int i = 0; i < count; i++) // i is rows
	{
		cout << "For Node " << (i + 1) << " how many connections does it have?"
			<< endl;
		cin >> edges; //sets the nodes edge count

		//runs for how many edges it has
		for (int j = 0; j < edges; j++)
		{
			weight = 0;
			cout << "Which node does it connect to? " << endl;
			cin >> num; //we will use this to store its weight
			num = num - 1; //We do this because arrays start at 0 instead of 1
			cout << "What is the weight of that connection? " << endl;
			cin >> weight;
			table[i][num] = weight; //stores the weight
		}
	}

	// This will go through the 2D array we made and set any values we did not 
	// set equal to zero
	for (int k = 0; k < count; k++)
	{
		for (int h = 0; h < count; h++)
		{
			if (table[k][h] < 0)
				table[k][h] = 0;
		}
	}

	// This will then print the table/matrix

	cout << "       ";
	for (int d = 0; d < count; d++)
	{
		cout << d << "      ";
	}
	cout << endl;

	for (int a = 0; a < count; a++) // rows
	{
		cout << a << "      ";
		for (int b = 0; b < count; b++) // colms
		{
			cout << table[a][b] << "      ";
		}
		cout << endl;
	}

	// I then go into problem number 1
	// i will use the matrix build previously

	int vertex, 
		degree = 0;
	//This is just how many edges touch the vertex
	cout << endl << endl
		<< "Now we will find the degree of a given vertex" <<endl
		<< "Which node/vertex would you like the degree of?" << endl;
	cin >> vertex;

	//We can count how many are not 0's are in the vertex's 
	//column. The total of cells not 0 is the degree

	vertex = vertex - 1; //because of how arrays are indexed
	for (int p = 0; p < count; p++) // rows
	{
		if (table[p][vertex] != 0)
		{
			degree++;
		}
	}

	cout << "The degree for " << (vertex + 1) << " is: "
		<< degree;

	return 0;
}
//*****************************************************************************
