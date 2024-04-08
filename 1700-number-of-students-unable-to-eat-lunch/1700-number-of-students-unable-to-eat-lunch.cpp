class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stu_0 = 0, stu_1 = 0;
        for(auto i: students) {
            if(i == 0) stu_0++;
            else stu_1++;
        }
        for(int i=0; i<sandwiches.size(); i++){
            if(sandwiches[i] == 1) stu_1--;
            else stu_0--;
            
            if(stu_0 < 0 || stu_1 < 0) return sandwiches.size()-i;
        }
        return 0;
    }
};