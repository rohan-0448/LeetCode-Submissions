class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> stack;
        
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        std::reverse(result.begin(), result.end()); // Reverse to get the correct order
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         if(num.length() == k) return "0";
//         stack<char> s;

//         int ind = 0;
//         while(ind < num.length()){
//             if(s.empty()) s.push(num[ind++]);
//             else if(s.top() <= num[ind]) s.push(num[ind++]);
//             else {
//                 while(k>0 && !s.empty() && s.top() > num[ind]) {
//                     s.pop();
//                     k--;
//                 }
//                 s.push(num[ind++]);
//             }
//             if(k==0) break;
//         } 
//         for(int i = ind; i<num.length(); i++) s.push(num[i]);

//         string ans = "";
//         while(!s.empty()) {
//             ans = s.top() + ans;
//             s.pop();
//         }
//         cout << ans << " " << k << endl;
//         if(k!=0) ans = ans.erase(ans.length()-k, k);
//         while(ans[0] == '0') ans = ans.erase(0,1);
//         return (ans == "")? "0": ans;
//         // for(int i=0; i<num.length()-1; i++){
//         //     if(num[i] > num[i+1]){ 
//         //         num = num.erase(i, 1);
//         //         i--;
//         //         // if(i >= num.length()-2) i--;
//         //         k--;
//         //         if(k==0) break;
//         //     }
//         //     cout << num << endl;
//         // }
//         // if(k!=0) num = num.erase(num.length()-k, k);
//         // while(num[0] == '0') num = num.erase(0, 1);
//         // if(num == "") return "0";
//         // return num;
//     }
// };