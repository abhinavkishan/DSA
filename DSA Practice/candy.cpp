#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> choco(ratings.size(), 1);
        // 1st iteration:
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) choco[i] = choco[i - 1] + 1;
        }
        vector<int> choco2(ratings.size(), 1);
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                choco2[i] = choco2[i+1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < choco.size(); i++) {
            sum += max(choco[i], choco2[i]);
        }
        return sum;
    }
};

int main() {
    int pointsSize;
    scanf("%d", &pointsSize);
    vector<int> points(pointsSize);
    for (int i = 0; i < pointsSize; i++)
    {
        cin >> points[i];
    }
    Solution s;
    printf("%d", s.candy(points, pointsSize));
    return 0;
}