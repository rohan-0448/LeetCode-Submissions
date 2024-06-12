class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0, total = nums1.size()+nums2.size();
        double median = 0.0;
        
        int index1=0, index2=0;
        if(total%2 == 1) {
            while(count < total/2){
                if(index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) index1++;
                else index2++;
                
                count++;
            }
            if (index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) median = nums1[index1];
            else median = nums2[index2];
        }
        else{
            while(count < total/2 - 1){
                if(index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) index1++;
                else index2++;
                
                count++;
            }
            int nextVal1 = 0, nextVal2 = 0;
            if (index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) nextVal1 = nums1[index1++];
            else nextVal1 = nums2[index2++];

            if (index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) nextVal2 = nums1[index1];
            else nextVal2 = nums2[index2];

            median = (nextVal1 + nextVal2) / 2.0;
        }
        return median;
    }
};