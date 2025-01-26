#include <stdio.h>
#include <string.h>
#include "matches.h"
#include<stdbool.h>

bool parsePoints(int teamScores[]) {
    FILE* file = fopen("table.txt", "r");
    if (!file) {
        printf("Error: Unable to open file table.txt\n");
        char cwd[1024];
        if (_getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current working directory: %s\n", cwd);
        }
        else {
            perror("getcwd() error");
        }
        return false;
    }

    char teamName[10];
    int points;
    while (fscanf(file, "%s %d", teamName, &points) == 2) {
        int found = 0;
        for (int i = 0; i < MAX_TEAMS; i++) {
            if (strcmp(teamName, teamNames[i]) == 0) {
                teamScores[i] = points;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Warning: Unknown team '%s' in file 'matches.txt'\n", teamName);
        }
    }

    fclose(file);
    return true;
}
