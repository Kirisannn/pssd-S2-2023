#include <iostream>
#include <vector>

using namespace std;

class Ascending {
 public:
  int steps(vector<int> flights, int stairsPerStride) {
    int steps = 0;
    for (auto it = flights.begin(); it != flights.end(); it++) {
      if (*it % stairsPerStride != 0) {
        steps += ((*it - (*it % stairsPerStride)) / stairsPerStride) + 1;
        if (it != flights.end() - 1) {
          steps += 2;
        }
      } else {
        steps += (*it / stairsPerStride);
        if (it != flights.end() - 1) {
          steps += 2;
        }
      }
    }

    return steps;
  };
};

// int main() {
//   Ascending asc;
//   vector<int> flights = {5, 11, 11};
//   int stairsPerStride = 5;
//   int res = asc.steps(flights, stairsPerStride);
//   cout << "Steps: " << res << endl << endl;
//   return 0;
// }