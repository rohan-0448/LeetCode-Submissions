class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int st = 0, ed = n-1;
        for(int i=0; i<=ed;){
            // cout << nums[i] << " " << st << "-" << ed << endl;
            // if(st > ed) break;
            if(nums[i] == 0 && st < n){
                int temp = nums[st];
                nums[st] = nums[i];
                nums[i] = temp;
                st++;
                i++;
            }
            else if(nums[i] == 2 && ed >= 0){
                int temp2 = nums[ed];
                nums[ed] = nums[i];
                nums[i] = temp2;
                ed--;
                // i--;
            }
            else i++;
        }
    }
};