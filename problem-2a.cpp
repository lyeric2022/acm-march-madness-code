#include <bits/stdc++.h>

using namespace std;

int main() {
  //  variables
  string integerInput, lineInput, countString;
  int count = 0, result = 0;

  //  reading 
  std::ifstream myfile ("input.txt");
  
  getline(myfile, integerInput);
  getline(myfile, lineInput);
  
  while (lineInput.find(integerInput) != string::npos) {   
    lineInput.erase(lineInput.find(integerInput), integerInput.size());

    count++;
  }

  countString = to_string(count);

  while (lineInput.find(countString) != string::npos) {
    lineInput.erase(lineInput.find(countString), countString.size());
    
    result++;
  }

  cout << result;
  
}
