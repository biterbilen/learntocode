#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>      

using namespace std;

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

int main(){
   string line;
   cin >> line;
   int C = stoi(line);

   cin >> line;
   vector<string> l_line = split(line, ' ');
   int N = stoi(l_line[0]);
   int L = stoi(l_line[1]);

   vector<float> l_r; 
   for(int n; n<C; ++n)
   {
      cin >> line;
      l_line = split(line, ' ');
      for (auto s = l_line.begin(); s != l_line.end(); ++s)
      {  
	
      }
   }



   









    return 0;
}
