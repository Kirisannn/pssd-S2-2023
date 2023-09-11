#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AlternateColors {
   public:
    string getColor(long r, long g, long b, long k) {
        string color;
        vector<string> colors = {"BLUE", "RED", "GREEN"};
        vector<long> balls = {b, r, g};

        int minElement = balls[0], minIndex = 0;
        for (int i = 1; i < 3; i++) {
            if (balls[i] < minElement) {
                minElement = balls[i];
                minIndex = i;
            }
        }

        if (k <= (3 * minElement)) {
            color = colors[k % 3];
        } else {
            colors.erase(colors.begin() + minIndex);
            balls.erase(balls.begin() + minIndex);
            k = k - 3 * minElement;

            if (minIndex == 1) {
                string temp = colors[0];
                colors[0] = colors[1];
                colors[1] = temp;
            }

            if (k <= (2 * min(balls[0], balls[1]))) {
                if (balls[0] == balls[1]) {
                    colors.erase(colors.begin() + (k % 2));
                } else {
                    colors.erase(colors.begin() + minIndex);
                }
            } else {
                minElement = balls[0];
                minIndex = 0;
                if (balls[1] < minElement) {
                    minElement = balls[1];
                    minIndex = 1;
                }
                if (minIndex == 1) {
                    string temp = colors[0];
                    colors[0] = colors[1];
                    colors[1] = temp;
                }
                colors.erase(colors.begin() + minIndex);
            }
            color = colors[0];
        }

        return color;
    };
};

int main() {
    // Test 1
    {
        AlternateColors c1;
        long r = 1, g = 1, b = 1, k = 3;
        cout << "c1: " << c1.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 2
    {
        AlternateColors c2;
        long r = 3, g = 4, b = 5, k = 4;
        cout << "c2: " << c2.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 3
    {
        AlternateColors c3;
        long r = 7, g = 7, b = 1, k = 7;
        cout << "c3: " << c3.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 4
    {
        AlternateColors c4;
        long r = 1000000000000, g = 1, b = 1, k = 1000000000002;
        cout << "c4: " << c4.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 5
    {
        AlternateColors c5;
        long r = 653, g = 32, b = 1230, k = 557;
        cout << "c5: " << c5.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 6: Supposed Output = "GREEN"
    {
        AlternateColors c6;
        long r = 35, g = 41, b = 37, k = 106;
        cout << "c6: " << c6.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    // Test 7: Supposed Output = "Blue";
    {
        AlternateColors c7;
        long r = 4, g = 15, b = 34, k = 50;
        cout << "c7: " << c7.getColor(r, g, b, k) << endl;
        cout << endl;
    }

    return 0;
}