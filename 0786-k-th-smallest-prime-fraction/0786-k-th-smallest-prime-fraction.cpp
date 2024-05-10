class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> fractions;
        for(int i=0; i<arr.size()-1; i++) for(int j=i+1; j<arr.size(); j++) fractions.push_back({(double)arr[i] / (double)arr[j], {arr[i], arr[j]}});
        sort(fractions.begin(), fractions.end());
        return {fractions[k-1].second.first, fractions[k-1].second.second};
    }
};