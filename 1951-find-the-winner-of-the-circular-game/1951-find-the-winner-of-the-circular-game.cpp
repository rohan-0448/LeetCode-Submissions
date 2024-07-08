class Solution {
public:

    int josephus(int n, int k){
        if(n == 1) return 0;
        return (josephus(n-1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return josephus(n, k)+1;
        // queue<int> q;
        // for(int i=1; i<=n; i++) q.push(i);

        // int i = 1;
        // while(q.size() > 1){
        //     int temp = q.front();
        //     q.pop();
        //     // cout << temp << i << endl;
        //     if(i==k) {
        //         i = 1;
        //         continue;
        //     }
        //     else{
        //         q.push(temp);
        //         i++;
        //     }
        // }
        // return q.front();
    }
};