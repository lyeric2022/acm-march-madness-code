#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ifstream myfile ("input.txt");

  string lineInput, status, line_value;
  int max = 0, current = 0;
  
  getline(myfile, lineInput);

  int n;
  while ( myfile ) {
    getline(myfile, lineInput);
    istringstream ss(lineInput);

    ss >> line_value;

    cout << lineInput << "\n";

    if ( !isalpha(line_value[0]) ) { 
      n = stoi(line_value);

      current += ( lineInput.find("in") != string::npos ) ? n : -n;
    }
    else if ( (lineInput.find("entered") != string::npos) || ( lineInput.find("exited") != string::npos) ) {
      n = (lineInput.find(" and ") != string::npos) ? -1 : 0;
      
      while (true) {
        ss >> line_value;
        n++;
        
        if (line_value == "entered" || line_value == "exited")   {  break;  };
      }
      if (line_value == "entered")   {  current += n;  };
      if (line_value == "exited")    {  current -= n;  };
    }
    else {
      if ( (lineInput.find(" and ") != string::npos) ) {
        ss >> line_value;
        ss >> line_value;

        int n = stoi(line_value);
        current += (lineInput.find("arrived") != string::npos) ? (n+1) : -(n+1);
      }
      else   { current = (lineInput.find("arrived") != string::npos) ? current +1 : current -1; };
    }
  
    cout << current << "\n";
    
    if (current > max) {  max = current; };
  }

  cout << max;
}
