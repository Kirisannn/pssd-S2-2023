#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameTable {
 public:
  int maxArea(vector<string> board) {}
};

int main() {
  // Test 1: Expected Output - 2
  {
    int expected = 2;
    vector<string> board = {"1", "2"};
    int result = GameTable().maxArea(board);
    cout << "Test 1: " << (expected == result ? "PASSED" : "FAILED") << endl;
  }

  return 0;
}