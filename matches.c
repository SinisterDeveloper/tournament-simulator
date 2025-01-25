#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h> 

#define MAX_TEAMS 10
#define MAX_LINE_LENGTH 50
#define MAX_MATCHES 100

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

Team getTeamEnum(const char* name) {
    for (int i = 0; i < TEAM_COUNT; i++) {
        if (strcmp(name, teamNames[i]) == 0) {
            return i;
        }
    }
    return -1; 
}

int parseMatches(Match matches[100]) {
    FILE* file = fopen("matches.txt", "r");
    if (!file) {
        printf("UNABLE TO FIND MATCHES DECLARATION FILE\n\nCreate a 'matches.txt' file in the same directory and declare the matches using the format:\nTEAM_1 TEAM_2\nTEAM_3 TEAM_4\n\n");
        
        char cwd[1024];
        if (_getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current working directory: %s\n", cwd);
        }
        else {
            perror("getcwd() error");
        }
        return 0;
    }

    int matchCount = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char team1[MAX_LINE_LENGTH], team2[MAX_LINE_LENGTH];
        if (sscanf(line, "%s %s", team1, team2) == 2) {
            Team t1 = getTeamEnum(team1);
            Team t2 = getTeamEnum(team2);

            if (t1 != -1 && t2 != -1) {
                matches[matchCount].t1 = t1;
                matches[matchCount].t2 = t2;
                matchCount++;
            }
            else {
                printf("Error: Invalid team name in line: %s\n", line);
            }
        }
    }

    fclose(file);
    return matchCount;
}