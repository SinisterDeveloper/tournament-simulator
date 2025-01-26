# Tournament (IPL) Scenario Analyzer 

**Discover pathways to victory** - A powerful simulation engine for sports enthusiasts, analysts, and organizers to explore all possible tournament outcomes. Determine how your favorite team can reach specific rankings by analyzing every combination of match results through advanced league table calculations.

## What This Tool Solves

Ever wondered:
* "What matches does Team X need to win to reach the top 4?"
* "Can Team Y still qualify if they lose their next two games?"
* "What other matches of other teams should result in a certain way for Team Z to qualify?"

This tool helps in the following ways:
1. Simulating **every possible combination** of remaining matches
2. Calculating league standings for each scenario
3. Identifying critical matches that affect final rankings
4. Providing detailed breakdowns of qualification possibilities

## Simulation Design/Architecture

1. Data Initialization --> 2. Match Simulation --> 3. Scenario Analysis

### Stage 1: Data Initialisation/Foundation

- The current points table is parsed and read from the file `table.txt` and the teams are assigned their respective points
- Data related to the remaining matches are parsed and read from the file `matches.txt`. They are then stored in a structured format to enable simulations of all possible outcomes.
- The system receives input regarding the team to analyse, the desired rank and the number of results to be displayed (the no. of permutations are very high!)

### Stage 2: Match Simulation

- Bitmasking: Each valid result of a match is represented in a unique bitmask allowing efficient traversal and other operations on them
- For each simulation of a match result, the points table is updated and the teams winning are allotted points

### Stage 3: Scenario Analysis

- After the points are updated, the rank of the team to be analysed is calculated relative to the other teams
- Scenarios where the team attains the desired rank after simulation of all games are displayed in the CLI

### Important Considerations:

* All matches are assumed to end with a conclude with a result ie. matches do not result in a draw
* The Net Run Rate of the team to be analysed is assumed superior to other teams with the same points after a match simulation

## Using the Tool

* Download the Program Executable file from the `Releases` section into a folder
* Create `table.txt` with the following format in the same folder and updaete them with the current points table:
```
RCB <points>
CSK <points>
MI <points>
GT <points>
LSG <points>
PBKS <points>
SRH <points>
KKR <points>
DC <points>
RR <points>
```
* Create `matches.txt` with the following format in the same folder and insert the remaining matches:
```
<TEAM-1> <space> <TEAM-2>
<TEAM-3> <space> <TEAM-4>
```
* Run the executable file
* Enter the team to be analysed (ex: RCB)
* Enter the rank desired for the analysed team to attain
* Enter the maximum number of simulation results to be shown

### Note From Developer

- This tool was originally written in C++ and hardcoded to analyse RCB's chances in the IPL. Being a cricket fan, making this tool was inevitable and urgent, and hence I prioritised core system logic as the tool was meant only for me to use
- I rewrote this in C-lang as a college project and hence made it less hardcoded for it to be able to analyse other teams' performances as well. The original C++ version of the code can be found in the `cpp` branch
- I am well aware of the fact that I can extend the usability and worth of this project beyond a CLI interface by using other languages and frameworks, yet C-lang was the criteria for the college project
- However, I am considering converting this into a C# or a Go-lang project to build helpful APIs for other services to consume and to extend the features of this project (while not degrading performance) coupled with maybe a website

