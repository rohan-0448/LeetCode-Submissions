class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int n = asteroids.size();
        for(int i=0; i<n; i++) {
            int cur = asteroids[i]; // 8 -8

            if(cur >= 0) st.push(cur);
            else {
                while(!st.empty() && st.top() >= 0 && abs(cur) > st.top()) st.pop();
            
                if(!st.empty() && st.top() == abs(cur)) st.pop();
                else if(st.empty() || st.top() < 0) st.push(cur);
                // else if(st.empty()) st.push(cur);
            }

            // if(!st.empty() && cur < 0 && st.top() >= 0) {
            //     while(!st.empty() && st.top() >= 0 && abs(cur) > st.top()) st.pop();
                
            //     if(!st.empty() && st.top() >= 0 && st.top() == abs(cur)) st.pop();
            //     else if(!st.empty() && st.top() < abs(cur)) st.push(cur);
            //     else if(st.empty()) st.push(cur);
            // }
            // else {
            //     st.push(cur);
            // }
            // while(!st.empty() && cur < 0 && st.top() >= 0) {
            //         // st.pop();
            //         // collide the two
            //         int right = abs(cur); // 
            //         int left = st.top(); // 
            //         st.pop(); // 

            //         if(right < left) { // 
            //             // st.push(left);
            //             cur = left;
            //         }
                    
            //         // if(!st.empty()) cur = st.top(); // 
            // }
            // st.push(cur);
        }

        int m = st.size();
        vector<int> ans(m, 0);
        while(!st.empty()) {
            ans[m-1] = st.top();
            st.pop();
            m--;
        }

        return ans;
    }
};