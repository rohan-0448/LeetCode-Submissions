
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Initialize variables
        int openParenthesesCount = 0;
        vector<char> arr(s.begin(), s.end()); // Convert string to character array

        // First pass: mark excess closing parentheses with '*'
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                openParenthesesCount++;
            else if (arr[i] == ')') {
                if (openParenthesesCount == 0)
                    arr[i] = '*'; // Mark excess closing parentheses
                else
                    openParenthesesCount--;
            }
        }

        // Second pass: mark excess opening parentheses from the end
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (openParenthesesCount > 0 && arr[i] == '(') {
                arr[i] = '*'; // Mark excess opening parentheses
                openParenthesesCount--;
            }
        }
        
        // Filter out marked characters and store the result in a new string
        string result = "";
        for (char c : arr) {
            if (c != '*')
                result += c;
        }

        return result;
    }
};

// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         // int left = 0, right = 0, index = 0;
//         // for(int i=0; i<s.length(); i++){
//         //     if(s[i] == '(') left++;
//         //     if(s[i] == ')') right++;
//         // }
//         // if(left < right){
//         //     index = s.length()-1;
//         //     while(left < right) {
//         //         if(s[index] == ')') {
//         //             s.erase(index, 1);
//         //             index--;
//         //             right--;
//         //         }
//         //     }
//         // }else if(right < left){
//         //     index = 0;
//         //     while(left > right) {
//         //         if(s[index] == '(') {
//         //             s.erase(index, 1);
//         //             index++;
//         //             left--;
//         //         }
//         //     }
//         // }
//         // return s;

        
//         // reverse(s.begin(), s.end());
//         // int left = 0;
//         // cout << s << endl;
//         // for(int i=0; i<s.length(); i++){
//         //     if(s[i] == '(' && left == 0) s.erase(i, 1);
//         //     else if(s[i] == '(' && left == 1) left = 0;
//         //     else if(s[i] == ')') left = 1;
//         // }
//         // cout << s << endl;
//         // reverse(s.begin(), s.end());
//         // left = 0;
//         // cout << s << endl;
//         // for(int i=0; i<s.length(); i++){
//         //     if(s[i] == ')' && left == 0) s.erase(i, 1);
//         //     else if(s[i] == ')' && left == 1) left = 0;
//         //     else if(s[i] == '(') left = 1;
//         // }
//         // return s;
//     }
// };