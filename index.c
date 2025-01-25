#include <stdio.h>
#include <string.h>
#include "matches.h"

int main() {
    char input[5];
    int desiredRank = 1, res = 0, i = 0;
    FILE* fPtr;
    printf("Welcome to IPL Analyzer\n\n");

    Match matches[100];
    int count = parseMatches(matches);

    printf("%d matches declared.\n", count);

    printf("Enter the team name to analyse chances:\n");
    scanf_s("%s", input);


    Team selectedTeam = -1;
    for (int i = 0; i < TEAM_COUNT; i++) {
        if (strcmp(input, teamNames[i]) == 0) {
            selectedTeam = i;
            break;
        }
    }

    if (selectedTeam == -1) {
        printf("Error: Invalid team name entered.\n");
        return 1;
    }

    printf("Enter the desired rank:\n");
    scanf_s("%d", &desiredRank);

    printf("Enter maximum number of results to be shown:\n");
    scanf_s("%d", &res);

    printf("Analyzing chances for team: %s\n", teamNames[selectedTeam]);

    int teamScores[TEAM_COUNT] = {
        6, 10, 6, 8, 12, 8, 12, 14, 10, 16
    };

    /*
    Match matches[] = {
        {RCB, GT}, {PBKS, CSK}, {LSG, KKR}, {MI, SRH}, {DC, RR},
        {SRH, LSG}, {PBKS, RCB}, {GT, CSK}, {KKR, MI}, {CSK, RR},
        {RCB, DC}, {GT, KKR}, {DC, LSG}, {RR, PBKS}, {SRH, GT},
        {MI, LSG}, {RCB, CSK}, {SRH, PBKS}, {RR, KKR}
    };

    */
    

    printf("Matches Declared. Reading all possibilities...\n");
    int totalMatches = sizeof(matches) / sizeof(matches[0]);
    long long totalCombinations = 1LL << totalMatches;

    printf("Total combinations: %lld\n", totalCombinations);

    for (long long bitmask = 0; bitmask < totalCombinations; ++bitmask) {
        if (i >= res) break;
        int currentScores[TEAM_COUNT];
        memcpy(currentScores, teamScores, sizeof(teamScores));
        int rank = 1;

        for (int i = 0; i < totalMatches; ++i) {
            if (bitmask & (1LL << i)) {
                currentScores[matches[i].t2] += 2;
            }
            else {
                currentScores[matches[i].t1] += 2;
            }
        }

        for (int i = 0; i < TEAM_COUNT; ++i) {
            if (i != selectedTeam && currentScores[i] > currentScores[selectedTeam]) {
                rank++;
            }
        }

        if (rank <= desiredRank) {
            printf("\nRank: %d | Results:\n", rank);
            for (int i = 0; i < totalMatches; ++i) {
                const Team t1 = matches[i].t1;
                const Team t2 = matches[i].t2;

                printf("%s v/s %s | Winner: ", teamNames[t1], teamNames[t2]);
                if (bitmask & (1LL << i)) {
                    printf("%s", teamNames[t2]);
                }
                else {
                    printf("%s", teamNames[t1]);
                }
                printf("\n");
            }
            printf("\n");
            i++;
        }
    }
    getchar();
    return 0;
}
