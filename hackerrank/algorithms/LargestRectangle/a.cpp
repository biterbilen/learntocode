// Copyright (C) 2017 by iamslash

#include <bits/stdc++.h>

using namespace std;

long largestRectangle(vector <int> h) {
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}
