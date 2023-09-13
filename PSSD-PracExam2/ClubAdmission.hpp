#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getSum(vector<int> card) {
  int sum = 0;
  for (size_t i = 0; i < card.size(); i++) {
    sum += card[i];
  }
  return sum;
};

void printVector(vector<int> vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

class ClubAdmission {
 private:
  // Find the lowest, if (longest == 1 && lowest == 9), return. If (longest ==
  // 2 && lowest == 99), return. Otherwise, if (longest == 1 && lowest != 9),
  // change to 9, if (longest == 2), if string[0] != '9' then change string[0]
  // to 9. If it is '9', change string[1] to '9'
  vector<int> bestSumHelper(vector<int> longestScores, size_t longest) {
    int lowest, lowestIndex;
    for (size_t i = 0; i < longestScores.size(); i++) {
      if (i == 0 || longestScores[i] < lowest) {
        lowestIndex = i;
        lowest = longestScores[i];
      }
    }
    // cout << "Lowest: " << lowest << endl;

    if ((longest == 1 && lowest == 9) || (longest == 2 && lowest == 99)) {
      return longestScores;
    } else if (longest == 1 & lowest != 9) {
      longestScores[lowestIndex] = 9;
    } else if (longest == 2) {
      string temp = to_string(lowest);
      if (temp[0] != '9') {
        temp[0] = '9';
      } else if (temp[1] != '9') {
        temp[1] = '9';
      }
      longestScores[lowestIndex] = stoi(temp);
    }

    return longestScores;
  };

 public:
  int bestSum(vector<int> card) {
    int best = 0;

    // Get the scores with the longest digits
    vector<int> longestScores, longestScores2, others, others2;
    size_t longest;

    // Get the length of longest scores
    for (size_t i = 0; i < card.size(); i++) {
      if (i == 0 || to_string(card[i]).length() > longest) {
        longest = to_string(card[i]).length();
        // cout << longest << endl;
      }
    }

    // Get the longest scores and push into longScores
    for (size_t i = 0; i < card.size(); i++) {
      if (to_string(card[i]).length() == longest) {
        longestScores.push_back(card[i]);
      } else {
        others.push_back(card[i]);
      }
    }
    // printVector(longestScores);
    // if (others.size() > 0) {
    //   printVector(others);
    // }

    longestScores2 = longestScores;
    if (longest == 2 && others.size() != 0) {
      others2 = others;
      others2 = bestSumHelper(others2, 1);
      //   printVector(others2);
      for (size_t i = 0; i < others.size(); i++) {
        longestScores2.push_back(others2[i]);
      }
    }

    longestScores = bestSumHelper(longestScores, longest);
    for (size_t i = 0; i < others.size(); i++) {
      longestScores.push_back(others[i]);
    }
    if (longest == 1) {
      longestScores2 = longestScores;
    }
    best = max(getSum(longestScores), getSum(longestScores2));

    return best;
  }
};