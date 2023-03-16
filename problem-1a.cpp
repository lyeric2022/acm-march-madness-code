#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ifstream myfile ("madness.acmcsuf.txt");

  unordered_set<string> hashSet;
  string lineInput, name, status;
  int max = 0;
  
  getline(myfile, lineInput);
  
  while ( myfile ) {
    getline(myfile, lineInput);
    istringstream ss(lineInput);

    ss >> name >> status;
    
    if (status == "entered") {
      if (hashSet.find(name) == hashSet.end()) {
        hashSet.insert(name);
      }
    }
    else {
      if (hashSet.find(name) != hashSet.end()) {
        hashSet.erase(name);
      }
    }

    max = hashSet.size() > max ? hashSet.size() : max;
  }
  
  cout << max;
}
