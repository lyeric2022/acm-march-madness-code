#include <bits/stdc++.h>

using namespace std;

// global vector storing x & y values of the dots
vector<vector<int>> vect;

// calculates the distance between two points (distance formula)
double distance(int x1, int x2, int y1, int y2) {
  
  double xx = pow(x1 - x2, 2);
  double yy = pow(y1 - y2, 2);
  double distance = sqrt(xx + yy);

  return distance;
}

// calculates midpoint between two points (midpoint formula)
vector<double> midPoint(double x1, double x2, double y1, double y2) {
  
  // variables
  double x, y;
  vector<double> xy;
  
  xy.push_back( (x1 + x2) / 2);
  xy.push_back( (y1 + y2) / 2);
  
  return xy;
}

//  checks if an additional dot exists within the circle (brute-force search)
bool triad(double x_mid, double y_mid, double maxRadius, int skip1, int skip2) {
  
  bool count = false;
  
  for (int i = 0; i < vect.size(); i++) {
    if (i == skip1 || i == skip2)  continue;

    // distance from midpoint to dot (aka radius)
    double compareRadius = distance(vect[i][0], x_mid, vect[i][1], y_mid);
    
    if (compareRadius <= maxRadius)  count = true;
  }

  return count;
}

int main() {
  // initializing variables
  int n, x, y;
  double minimumRadius = INT_MAX;

  // reading
  ifstream myfile ("input.txt");
  myfile >> n;
  
  // indexing vector with x & y coordinates
  for (int i = 0; i < n; i++) {
    myfile >> x >> y;
    
    vect.push_back({x, y});
  }

  // comparing one coordinate to the other (brute-force comparision, but does not ever recompares)
  for (int i = 0; i < vect.size(); i++) {
    for (int j = i +1; j < vect.size(); j++) {

      //using functions to set values
      double radius = distance(vect[i][0], vect[j][0], vect[i][1], vect[j][1]) / 2;

      vector<double> v = midPoint(vect[i][0], vect[j][0], vect[i][1], vect[j][1]);

      // checking if 3+ values exists within the circle
      if ( triad(v[0], v[1], radius, i, j) ) {
        
        // setting the smallest radius to the radius if radius is smaller
        if (radius < minimumRadius) {
          minimumRadius = radius;
        }
      }

      // cout << "dental1 location: " << vect[i][0] << "\t" << vect[i][1] << "\n";
      // cout << "dental2 location: " << vect[j][0] << "\t" << vect[j][1] << "\n";
      // cout << "radius: " << radius << "\n";
      // cout << "mid-point: " << v[0] << "\t" << v[1] << "\n";
      // cout << "circumference: " << ( 2 * minimumRadius * 3.141592653589793 ) << "\n\n";
    }
  }
  
  // outputting the circumference of the smallest circle
  cout << ( 2 * minimumRadius * 3.141592653589793 );
}
