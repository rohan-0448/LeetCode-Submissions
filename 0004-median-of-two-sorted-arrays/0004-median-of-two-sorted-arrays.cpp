class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        if(n%2==0) return ((double)nums1[n/2]+(double)nums1[(n-1)/2])/2;
        else return nums1[n/2];

        // vector<double> add;
        // int i=0, j=0;
        // int n = (nums1.size() + nums2.size())/2;

        // while(i<nums1.size() && j<nums2.size()){
        //     if(nums1[i] < nums2[j]){
        //         add.push_back(nums1[i++]);
        //     }else{
        //         add.push_back(nums2[j++]);
        //     }
        //     cout << i << " " << j << " " << n << endl;
        //     if(add.size()-1==n || n==0){
        //         if(n%2==0) return (add[n]+add[n-1])/2;
        //         else return add[n];
        //     }
        // }
        // while(i<nums1.size()) {
        //     add.push_back(nums1[i++]);
        //     if(add.size()-1==n || n==0){
        //         if(n%2==0) return (add[n]+add[n-1])/2;
        //         else return add[n];
        //     }
        // }
        // while(j<nums2.size()) {
        //     add.push_back(nums2[j++]);
        //     if(add.size()-1==n || n==0){
        //         if(n%2==0) return (add[n]+add[n-1])/2;
        //         else return add[n];
        //     }
        // }

        // if(add.size()-1==n || n==0){
        //     if(n%2==0) return (add[n]+add[n-1])/2;
        //     else return add[n];
        // }
        // return -1;
    }
};