// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/castle-on-the-grid/problem


#include <bits/stdc++.h>

using namespace std;

int minimumMoves(vector <string> grid, int startX, int startY, int goalX, int goalY) {
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    return 0;
}
