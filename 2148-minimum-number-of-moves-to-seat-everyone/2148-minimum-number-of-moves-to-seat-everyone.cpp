class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // return abs(accumulate(seats.begin(), seats.end(), 0) - accumulate(students.begin(), students.end(), 0)); 
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for(int i=0; i<seats.size(); i++) ans += abs(seats[i]-students[i]);
        return ans;
    }
};