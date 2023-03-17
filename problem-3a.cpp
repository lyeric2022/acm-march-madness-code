#include <bits/stdc++.h>

using namespace std;

int main() {
  // initializing
  string start, end, location1, location2;
  int n, count = 0;

  unordered_map<string, string> hm;

  // reading
  ifstream myFile ("input.txt");
  myFile >> start >> end >> n;

  // keying in hashmap
  for (int i = 0; i < n; i++) {
    myFile >> location1 >> location2;
    
    hm[location1] = location2;
  }

  // looping to next location until destination is reached
  while (true) {
    string nextLocation = hm.at(start);

    // changeing elusiveness
    if (start.length() < nextLocation.length())       count += 5;
    else if (start.length() > nextLocation.length())  count -= 2;

    // checking if destination has been found
    if (end == nextLocation) {
      break;
    };

    // setting start to the next location, for the loop
    start = nextLocation;
  }

  // outputing the elusiveness
  cout << count;
}
