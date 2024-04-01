class Solution {
public:

string temp = "";
vector<string> ans;
int n_global = 0;

void recursive(int op, int cl) {
    if(op+cl == 2*n_global){
        ans.push_back(temp);
        return;
    }

    if(op < n_global){
        temp+='(';
        recursive(op+1, cl);
        temp = temp.substr(0,temp.length()-1);
    }

    if(cl < op){
        temp+=')';
        recursive(op, cl+1);
        temp = temp.substr(0,temp.length()-1);
    }
}
    vector<string> generateParenthesis(int n) {
        n_global = n;
        recursive(0, 0);
        return ans;
    }
};