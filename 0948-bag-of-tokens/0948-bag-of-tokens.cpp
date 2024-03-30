class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int max_score = 0;
        int score = 0;

        sort(tokens.begin(), tokens.end());

        if(tokens.size() < 1) return 0;
        if(tokens[0] > power) return 0;
        
        int left = 0, right = tokens.size()-1;
        while(left<=right){
            if(power >= tokens[left]){
                score++;
                power -= tokens[left];
                left++;
            }else{
                score--;
                power += tokens[right];
                right--;
            }
            if(max_score < score) max_score = score;
            cout << left << " " << right << " " << max_score << ": " << power << endl;
        } 
        return max_score;
    }
};