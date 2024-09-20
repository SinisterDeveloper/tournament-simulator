#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> combinations;

bool sortByValue(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

void printAllKLengthRec(char set[], string prefix, const int n, const int k)
{
	if (k == 0)
	{
		combinations.push_back(prefix);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		string newPrefix = prefix + set[i];
		printAllKLengthRec(set, newPrefix, n, k - 1);
	}
}

void printAllKLength(char set[], const int k, const int n)
{
	printAllKLengthRec(set, "", n, k);
}

int main()
{
	enum Team {
		RCB,
		CSK,
		MI,
		GT,
		LSG,
		PBKS,
		SRH,
		KKR,
		DC,
		RR
	};

	// Map enum to team names
	map<Team, string> teamNames = {
		{RCB, "RCB"}, {CSK, "CSK"}, {MI, "MI"}, {GT, "GT"}, {LSG, "LSG"},
		{PBKS, "PBKS"}, {SRH, "SRH"}, {KKR, "KKR"}, {DC, "DC"}, {RR, "RR"}
	};

	struct match {
		Team t1;
		Team t2;
	};

	map<Team, int> teamScores = {
		{RCB, 6}, {CSK, 10}, {MI, 6}, {GT, 8}, {LSG, 12},
		{PBKS, 8}, {SRH, 12}, {KKR, 14}, {DC, 10}, {RR, 16}
	};

	const match matches[19] = {
		{RCB, GT}, {PBKS, CSK}, {LSG, KKR}, {MI, SRH}, {DC, RR},
		{SRH, LSG}, {PBKS, RCB}, {GT, CSK}, {KKR, MI}, {CSK, RR},
		{RCB, DC}, {GT, KKR}, {DC, LSG}, {RR, PBKS}, {SRH, GT},
		{MI, LSG}, {RCB, CSK}, {SRH, PBKS}, {RR, KKR}
	};

	cout << "Matches Declared. Reading all possibilities...\n";

	char possibilities[] = { '0', '1' };
	int k = sizeof(matches) / sizeof(matches[0]);

	printAllKLength(possibilities, k, 2);

	cout << "Possibilities initialized! Total combinations: " << combinations.size() << endl;

	for (const string& results : combinations) {
		map<Team, int> currentScores = teamScores;

		for (int i = 0; i < results.size(); i++) {
			if (results[i] == '0') {
				currentScores[matches[i].t1] += 2;
			}
			else {
				currentScores[matches[i].t2] += 2;
			}
		}

		int rank = 1;
		for (const auto& score : currentScores) {
			if (score.second > currentScores[RCB])
				rank++;
		}

		if (rank <= 2) {
			cout << results << " Rank: " << rank << '\n';
			cout << "Results Required for RCB to attain position: " << rank << " in points table: " << '\n';

			for (int i = 0; i < results.size(); i++) {
				const Team t1 = static_cast<Team>(matches[i].t1);
				const Team t2 = static_cast<Team>(matches[i].t2);

				cout << teamNames[t1] << " v/s " << teamNames[t2] << " | Winner: ";
				if (results[i] == '0') {
					cout << teamNames[t1] << '\n';
				}
				else {
					cout << teamNames[t2] << '\n';
				}
			}
		}
	}

	return 0;
}
