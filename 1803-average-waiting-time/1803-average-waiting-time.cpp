class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double maxt = customers[0][0]+customers[0][1], waiting = 0, extra = 0;
        cout << maxt << endl;
        for(int i=1; i<customers.size(); i++){
            if(customers[i][0] < maxt) waiting += maxt-customers[i][0];
            if(customers[i][0] > maxt) {
                extra += customers[i][0] - maxt;
                maxt = customers[i][0]; 
            }
            maxt += customers[i][1];
            cout << waiting << " " << maxt << endl;
        }
        return (maxt-customers[0][0]+waiting-extra)/customers.size();
    }
};