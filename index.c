#include <stdio.h>
#include <string.h>
#include "matches.h"

int main() {
    char input[5];
    int desiredRank = 1, res = 0, i = 0;
    FILE* fPtr;
    printf("Welcome to IPL Analyzer\n\n");

    Match matches[100];
    int totalMatches = parseMatches(matches);

    printf("%d matches declared.\n", totalMatches);

    int teamScores[MAX_TEAMS] = { 0 };

    if (!parsePoints(teamScores)) {
        printf("Failed to load points table. Exiting...\n");
        return 1;
    }

    printf("Current Points Table:\n");
    for (int i = 0; i < MAX_TEAMS; i++) {
        printf("%s: %d points\n", teamNames[i], teamScores[i]);
    }

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

    printf("Matches Declared. Reading all possibilities...\n");
    long long totalCombinations = 1LL << totalMatches;

    printf("Total combinations: %lld\n", totalCombinations);

    for (long long bitmask = 0; bitmask < totalCombinations; ++bitmask) {
        if (i >= res) break;
        int currentScores[20];
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
    system("pause");
    return 0;
}
