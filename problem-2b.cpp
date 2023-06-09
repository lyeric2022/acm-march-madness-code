#include <bits/stdc++.h>

using namespace std;

int main() {
  //  variables
  double pi = 3.141592653589793;
  double n, radius, area, diff_area;
  
  //  arr[x][0] is area error, and arr[x][1] is radius
  double arr[5][2] = {{INT_MAX, 0}, {INT_MAX, 0}, {INT_MAX, 0},  {INT_MAX, 0}, {INT_MAX, 0}};
  
  //   reading 
  std::ifstream myfile ("input.txt");
  
  myfile >> n;

  for (int i= 0; i < n; i++) {
    myfile >> radius >> area;
    // cout << radius << "\t" << area << "\t";

    double diff = abs(pi - (area / radius / radius));
    cout << diff << "\n";

    int indexReplace;
    double maxDiff = 0;
    
    for (int i = 0; i < 5; i++) {
      // cout << arr[i][0] << "\t" << arr[i][1] << "\n";
      
      if (arr[i][0] > maxDiff) {
        maxDiff      = arr[i][0];
        indexReplace = i;
      }
    }
    // cout << maxDiff << "\n";
    
    if (maxDiff > diff) {
      // cout << "executed with " << diff << "\t" << radius << "\n";
      arr[indexReplace][0] = diff;
      arr[indexReplace][1] = radius;
    }
    
    // cout << "\n";
  }

  double product = 1;

  for (int i = 0; i < 5; i++) {
    // cout << arr[i][1] << "\t";
    product *= arr[i][1];
  }

  cout << product;
}
