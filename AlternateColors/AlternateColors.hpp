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
            }
            color = colors[0];
        }

        return color;
    };
};