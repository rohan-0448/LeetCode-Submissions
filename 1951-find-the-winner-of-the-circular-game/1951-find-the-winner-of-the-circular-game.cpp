class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);

        int i = 1;
        while(q.size() > 1){
            int temp = q.front();
            q.pop();
            // cout << temp << i << endl;
            if(i==k) {
                i = 1;
                continue;
            }
            else{
                q.push(temp);
                i++;
            }
        }
        return q.front();
    }
};