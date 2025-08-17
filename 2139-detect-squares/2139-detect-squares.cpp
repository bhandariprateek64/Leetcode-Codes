#include <bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
    map<pair<int,int>, int> freq;

    DetectSquares() {}

    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int total = 0;

        for (auto &entry : freq) {
            int x = entry.first.first;
            int y = entry.first.second;

            if (x == px || y == py) continue;
            if (abs(x - px) != abs(y - py)) continue;

            int diag   = freq[{x, y}];
            int side1  = freq[{x, py}];
            int side2  = freq[{px, y}];

            total += diag * side1 * side2;
        }
        return total;
    }
};
