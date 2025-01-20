#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    RCB, CSK, MI, GT, LSG, PBKS, SRH, KKR, DC, RR, TEAM_COUNT
} Team;

const char* teamNames[TEAM_COUNT] = {
    "RCB", "CSK", "MI", "GT", "LSG", "PBKS", "SRH", "KKR", "DC", "RR"
};

typedef struct {
    Team t1;
    Team t2;
} Match;

int main() {
    int teamScores[TEAM_COUNT] = {
        6, 10, 6, 8, 12, 8, 12, 14, 10, 16
    };

    Match matches[] = {
        {RCB, GT}, {PBKS, CSK}, {LSG, KKR}, {MI, SRH}, {DC, RR},
        {SRH, LSG}, {PBKS, RCB}, {GT, CSK}, {KKR, MI}, {CSK, RR},
        {RCB, DC}, {GT, KKR}, {DC, LSG}, {RR, PBKS}, {SRH, GT},
        {MI, LSG}, {RCB, CSK}, {SRH, PBKS}, {RR, KKR}
    };

    printf("Matches Declared. Reading all possibilities...\n");
    int totalMatches = sizeof(matches) / sizeof(matches[0]);
    long long totalCombinations = 1LL << totalMatches;

    printf("Total combinations: %lld\n", totalCombinations);

    for (long long bitmask = 0; bitmask < totalCombinations; ++bitmask) {
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
            if (i != RCB && currentScores[i] > currentScores[RCB]) {
                rank++;
            }
        }

        if (rank <= 2) {
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
        }
    }

    getchar();
    return 0;
}
