#ifndef MATCHES_H
#define MATCHES_H

#include <stdio.h>

#define MAX_TEAMS 20
#define MAX_LINE_LENGTH 50
#define MAX_MATCHES 100

typedef enum {
    RCB, CSK, MI, GT, LSG, PBKS, SRH, KKR, DC, RR, TEAM_COUNT
} Team;

typedef struct {
    Team t1;
    Team t2;
} Match;

Team getTeamEnum(const char* name);

extern const char* teamNames[TEAM_COUNT];

int parseMatches(Match matches[100]);

#endif // MATCHES_H
