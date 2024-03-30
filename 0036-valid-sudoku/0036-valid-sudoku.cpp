class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        for(int i=0; i<9; i++){
            unordered_map<int, int> mp1, mp2;
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(mp1[board[i][j]]==1) {
                        cout << i << " " << j << endl;  
                        return false; 
                    }
                    else mp1[board[i][j]]++;
                }
                if(board[j][i]!='.'){
                    if(mp2[board[j][i]]==1) {
                        cout << i << " " << j << endl;  
                        return false;
                    }
                    else mp2[board[j][i]]++;
                }
            }
        }
        int num1 = 0, num2 = 0;
        
        while(true){
            unordered_map<int, int> mp;
            for(int i=num1; i<num1+3; i++){
                for(int j=num2; j<num2+3; j++){
                    if(board[i][j]!='.'){
                        if(mp[board[i][j]]==1) return false;
                        else mp[board[i][j]]++;
                    }
                }
            }
            if(num1!=6) num1+=3;
            else if(num2!=6) {
                num2+=3;
                num1=0;
            }
            else break;
        }
        return true;
    }
};