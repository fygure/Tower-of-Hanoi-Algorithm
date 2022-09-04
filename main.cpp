/*
* Maximillian Chalitsios
* 1808500
* 8/26/2022
* Solution to Problem 1
*/
//===================================================================================================//
#include <iostream>
#include <fstream>
using std::cout;
using std::string;
//===================================================================================================//
//declare functions
//===================================================================================================//
//#1 Solves TOH problem with the adjacency rule and second sub-problem
void H_Adj(int n, string start, string aux, string dest, int &num_moves, std::ofstream& outFS);
//===================================================================================================//
//#2 Solves first sub-problem
void F(int n, string A4, string A1, string dest, string start, int &num_moves, std::ofstream& outFS);
//===================================================================================================//
//main function
int main()
{
	//write results to file
	std::ofstream outFS("results.txt");

	//total move counter
	int num_moves = 0;

	//declare variable n
	int n = 10;

	F(n, "A4", "A1", "D", "S", num_moves, outFS);
	H_Adj(n, "A4", "A1", "D", num_moves, outFS);

	outFS << "\nMoves: " << num_moves << std::endl;
	outFS.close();

	return 0;
}
//===================================================================================================//
//define function #1
void H_Adj(int n, string start, string aux, string dest, int& num_moves, std::ofstream& outFS)
{
	//base case
	if (n == 1)
	{
		num_moves++;
		outFS << "\nMove(" << num_moves << ") 1 from " << start << " to " << aux;
		
		num_moves++;
		//increment by 2 to account for A2 and A3 moves
		outFS << "\nMove(" << num_moves << ") 1 from " << aux << " to " << dest;
		if (aux == "A1" && dest == "A4")
		{
			outFS << " (A1->A2->A3->A4)";
			num_moves += 2;
		}
		return;
	}

	//recursive call 1
	H_Adj(n - 1, start, aux, dest, num_moves, outFS);

	num_moves++;
	outFS << "\nMove(" << num_moves << ") " << n << " from " << start << " to " << aux;

	//recursive call 2
	H_Adj(n - 1, dest, aux, start, num_moves, outFS);

	num_moves++;
	//increment by 2 to account for A2 and A3 moves
	outFS << "\nMove(" << num_moves << ") " << n << " from " << aux << " to " << dest;
	if (aux == "A1" && dest == "A4")
	{
		outFS << " (A1->A2->A3->A4)";
		num_moves += 2;
	}
	//recursive call 3
	H_Adj(n - 1, start, aux, dest, num_moves, outFS);
}
//===================================================================================================//
//define function #2
void F(int n, string A4, string A1, string dest, string start, int& num_moves, std::ofstream& outFS)
{
	//base case
	if (n == 1)
	{
		num_moves++;
		outFS << "\nMove(" << num_moves << ") 1 from " << start << " to " << dest;

		num_moves++;
		outFS << "\nMove(" << num_moves << ") 1 from " << dest << " to " << A1;

		num_moves++;
		outFS << "\nMove(" << num_moves << ") 1 from " << A1 << " to " << A4;
		if (A1 == "A1" && A4 == "A4")
		{
			outFS << " (A1->A2->A3->A4)";
			num_moves += 2;
		}
		return;
	}
	//recursive call 1
	F(n - 1, A4, A1, dest, start, num_moves, outFS);

	num_moves++;
	outFS << "\nMove(" << num_moves << ") " << n << " from " << start << " to " << dest;

	num_moves++;
	outFS << "\nMove(" << num_moves << ") " << n << " from " << dest << " to " << A1;

	//move tower from A4 to D
	H_Adj(n - 1, A4, A1, dest, num_moves, outFS);

	num_moves++;
	outFS << "\nMove(" << num_moves << ") " << n << " from " << A1 << " to " << A4;
	if (A1 == "A1" && A4 == "A4")
	{
		outFS << " (A1->A2->A3->A4)";
		num_moves += 2;
	}
	//move tower from D to A4
	H_Adj(n - 1, dest, A1, A4, num_moves, outFS);
}
//===================================================================================================//
