class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        if (groupSize == 1) return true;

        map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }

        while (!countMap.empty()) {
            int start = countMap.begin()->first;
            for (int i = 0; i < groupSize; ++i) {
                int current = start + i;
                if (countMap[current] == 0) {
                    return false;
                }
                if (--countMap[current] == 0) {
                    countMap.erase(current);
                }
            }
        }

        return true;
    }
};
