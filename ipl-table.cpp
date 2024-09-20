#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    enum Team {
        RCB, CSK, MI, GT, LSG, PBKS, SRH, KKR, DC, RR
    };

    unordered_map<Team, string> teamNames = {
        {RCB, "RCB"}, {CSK, "CSK"}, {MI, "MI"}, {GT, "GT"}, {LSG, "LSG"},
        {PBKS, "PBKS"}, {SRH, "SRH"}, {KKR, "KKR"}, {DC, "DC"}, {RR, "RR"}
    };

    struct match {
        Team t1;
        Team t2;
    };

    unordered_map<Team, int> teamScores = {
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

    int totalMatches = sizeof(matches) / sizeof(matches[0]);
    long long totalCombinations = 1LL << totalMatches;  

    cout << "Total combinations: " << totalCombinations << '\n';

    for (long long bitmask = 0; bitmask < totalCombinations; ++bitmask) {
        unordered_map<Team, int> currentScores = teamScores;
        int rank = 1;

        for (int i = 0; i < totalMatches; ++i) {
            if (bitmask & (1LL << i)) 
                currentScores[matches[i].t2] += 2;
            else 
                currentScores[matches[i].t1] += 2;
            
        }

        for (const auto& score : currentScores) {
            if (score.first != RCB && score.second > currentScores[RCB]) {
                rank++;
            }
        }

        if (rank <= 2) {
            cout << "\nRank: " << rank << " | Results: \n";

            for (int i = 0; i < totalMatches; ++i) {
                const Team t1 = matches[i].t1;
                const Team t2 = matches[i].t2;

                cout << teamNames[t1] << " v/s " << teamNames[t2] << " | Winner: ";
                if (bitmask & (1LL << i)) {
                    cout << teamNames[t2];
                } else {
                    cout << teamNames[t1];
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}
