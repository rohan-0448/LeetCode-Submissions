class Solution {
public:
    
    // check the window has all the characters present the str1
    
    bool is_check(vector<int>& mp1, vector<int>& mp2)
    {
        for(int i = 0; i < 26; i++)
        {
            if(mp1[i] != mp2[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string str2, string str1) {
        
        int n1 = str1.size();
        
        int n2 = str2.size();
        
        vector<int> mp1(26, 0);
        
        vector<int> mp2(26, 0);
        
        vector<int> ans;
        
        // store the count of all characters of str1 in mp1
        
        for(int i = 0; i < n1; i++)
        {
            mp1[str1[i] - 'a']++;
        }
        
        // apply sliding window
        
        // here we can take n1 as the size of sliding window
        
        for(int i = 0; i < n2; i++)
        {
            if(i < n1)
            {
                mp2[str2[i]- 'a']++;
            }
            else
            {
                if(is_check(mp1, mp2))
                {
                    ans.push_back(i - n1);
                }
                
                mp2[str2[i - n1] - 'a']--;
                
                mp2[str2[i] - 'a']++;
            }
        }
        
        if(is_check(mp1, mp2))
        {
            ans.push_back(n2 - n1);
        }
        
        return ans;  
    }
};