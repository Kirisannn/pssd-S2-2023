#include <iostream>
#include <vector>

using namespace std;

class ChickensAndCows {
 private:
  int maxCows(int tempHeads, int tempLegs, int cows) {
    int cows = 0, temp = 0;
    if (legs / 4 <= heads) {
      for (int i = 0; i < legs / 4; i++) {
        temp = legs - 4;
        if () }
    }

    return cows;
  }

 public:
  vector<int> howMany(int heads, int legs) {
    vector<int> animals = {0, 0};
    int chickens = 0, int cows = 0;
    bool temp = true;

    if (legs % 2 != 0) {  // if legs are odd, impossible.
      return animals;
    } else if (legs % 4 == 0) {  // if legs % 4 has no remainder
      if (legs % heads == 0) {   // if legs % heads has no remainder
        if (legs / 4 == heads) {
          animals[0] += 0;
          animals[1] += legs / 4;
        } else {
          animals.pop_back();
          animals.pop_back();
        }
      }
    } else if (legs % 2 == 0) {
      while (temp == true) {
        chickens++;
        legs -= 2;
        if (legs % 4 == 0) {
          cows = heads - chickens;
          if (cows + chickens == heads) {
            temp = false;
          }
        }
      }
      animals[0] = chickens;
      animals[1] = cows;
    }

    return animals;
  };
};

int main() {
  ChickensAndCows cc;
  int heads = 3, legs = 8;
  vector<int> animals = cc.howMany(heads, legs);

  if (animals.size() != 0) {
    for (auto it = animals.begin(); it != animals.end(); it++) {
      cout << *it << endl;
    }
  } else {
    cout << "{ empty }" << endl;
  }
  cout << endl;

  return 0;
}

// 10, 40 -> {0,10}
// 3, 8   -> {2,1}
// 10, 42 -> {}
// 1, 3   -> {}
