class Solution {
public:


    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        for(int i=1; i<=n; i++) {
            fact[i] = i * fact[i-1];
        }

        vector<int> number;
        for(int i=1; i<=n; i++) number.push_back(i);
    
        string curr = ""; // "231"
        // n = 2, k = 1; 
        while(n>1) {
            // int combination = fact[n]; // 2
            // int blocks = n; // 2
            // int each_block = combination / blocks; // 1

            int each_block = fact[n-1];


            int index = 1; // 
            while(k > index * each_block) { // 1 > 1
                // k -= each_block; // k = 1
                index++; // 2
            }
            k -= (index - 1) * each_block;
            curr += to_string(number[index-1]); // 2 3 1
            number.erase(number.begin() + index - 1); // 4
            n--;
        }
        curr += to_string(number[0]);
        return curr;
    }
};