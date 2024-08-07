class Solution {
public:
    string check(string s) {
        vector<string> lower = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        int num = stoi(s);
        string ans = "";

        if(num >= 100){
            ans += lower[num / 100] + " Hundred ";
            num %= 100;
        }
        if(num >= 20){
            ans += tens[num / 10] + " ";
            num %= 10;
        }
        if(num > 0){
            ans += lower[num] + " ";
        }
        // Remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();

        return ans;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        string number = to_string(num);
        vector<string> words;
        int segment = 0;

        while(!number.empty()) {
            int len = number.length();
            int segmentLength = (len > 3) ? 3 : len;
            string segmentString = number.substr(len - segmentLength, segmentLength);
            number = number.substr(0, len - segmentLength);
            
            string segmentWords = check(segmentString);
            if(!segmentWords.empty()) {
                words.push_back(segmentWords + (thousands[segment].empty() ? "" : " " + thousands[segment]));
            }
            segment++;
        }
        
        string ans;
        for(int i = words.size() - 1; i >= 0; i--) {
            ans += words[i] + " ";
        }
        // Remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        
        return ans;
    }
};

// class Solution {
// public:

//     string check(string s) {
//         vector<string> lower = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
//         vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
//         int num = stoi(s);
//         string ans = "";

//         if(num>=100){
//             ans += lower[num/100];
//             ans += " Hundred ";
//             num %= 100;
//         }
//         if(num>=20){
//             ans += tens[num/10];
//             ans += " ";
//             num %= 10;
//         }
//         if(num>0){
//             ans += lower[num];
//             ans += " ";
//         }
//         while(!ans.empty() && ans[ans.length()-1] == ' ') ans.pop_back();

//         return ans;
//     }

//     string numberToWords(int num) {
//         if(num == 0) return "Zero";

//         string number = to_string(num);
//         vector<string> words;
//         while(number != ""){
//             int temp = number.length()%3;
//             if(temp) {
//                 words.push_back(check(number.substr(0, temp)));
//                 number = number.substr(temp);
//             }
//             else {
//                 words.push_back(check(number.substr(0, 3)));
//                 number = number.substr(3);
//             }
//         }
//         int len = words.size();
//         string ans = "";
//         if(len == 1) ans = words[0];
//         else if(len == 2) ans = words[0] + " Thousand " + words[1];
//         else if(len == 3) ans = words[0] + " Million " + words[1] + " Thousand " + words[2];
//         else if(len == 4) ans = words[0] + " Billion " + words[1] + " Million " + words[2] + " Thousand " + words[3];
//         while(!ans.empty() && ans[ans.length()-1] == ' ') ans.pop_back();
        
//         return ans;
//     }
// };