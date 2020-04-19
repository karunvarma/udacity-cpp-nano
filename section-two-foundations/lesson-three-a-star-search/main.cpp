//
// Created by Michael Harris on 04/18/2020
//

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::vector;
using std::cout;
using std::string;
using std::istringstream;
using std::ifstream;

enum class State {
    k_empty,
    k_obstacle
};

vector<State> ParseLine(string line){
    istringstream string_line(line);
    int n;
    char c;
    vector<State> row;
    while(string_line >> n >> c){
        if(n==0){
            row.push_back(State::k_empty);
        } else {
            row.push_back(State::k_obstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadFile(string path){
    ifstream file(path);
    vector<vector<State>> grid{};
    if (file) {
        string line;
        while(getline(file, line)){
            vector<State> row = ParseLine(line);
            grid.push_back(row);
        }
    } else {
        cout << "Stream not created successfully" << "\n";
    }
    return grid;
}

// A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid) {
    cout << "Reading grid of size " << grid.size() << "x" << grid[0].size() << "...\n";
    cout << "Start: (0, 0)\n" << "Goal: (" << grid.size() - 1 << ", " << grid[0].size() - 1 << ")\n";
    cout << "No path found" << "\n";
    return vector<vector<State>> {};
}

string CellString(State cell){
    switch (cell) {
        case State::k_obstacle:
            return "⛰";
        case State::k_empty:
            return "  ";
    }
}

void PrintGrid(const vector<vector<State>> grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << CellString(grid[i][j]) << ",";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<State>> grid = ReadFile("/Users/michaelharris/udacity-cpp-nano/section-two-foundations/lesson-three-a-star-search/grids/grid.csv");
    PrintGrid(grid);
    vector<vector<State>> solution = Search(grid);
    PrintGrid(solution);
    return 0;
}