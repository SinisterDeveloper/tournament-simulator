
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string combinations;
ofstream ResultFile("results.txt");

void printAllKLengthRec(char set[], string prefix, int n, int k)
{

	if (k == 0)
	{
		combinations += ((prefix)+"\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		string newPrefix;

		newPrefix = prefix + set[i];

		printAllKLengthRec(set, newPrefix, n, k - 1);
	}

}

void printAllKLength(char set[], int k, int n)
{
	printAllKLengthRec(set, "", n, k);
}

