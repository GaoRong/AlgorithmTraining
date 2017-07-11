/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017年7月11日22:13:50
** desc：  字符串高级算法
*********************************************************************************/


//最长回文字串（Longest Palindromic Substring）
//从中心扩展的方式，时间复杂度O(n^2),空间复杂度O(1)
//详细参见：https://leetcode.com/articles/longest-palindromic-substring/ 
string longestPalindrome(string s) {
        int res = -1;
        int l=0;
        
        
        for(int i = 0; i<s.length(); i++){
            int k = i-1,j=i+1;
            
            while( k>=0 && j<s.length() && s[k] == s[j] ){
                k--;
                j++;
            }
            
            if( res < j-k-1)
            {
                l = k+1;
                res = j-k-1;
            }
            
            
            k = i,j=i+1;
            while( k>=0 && j<s.length() && s[k] == s[j] ){
                k--;
                j++;
            }
            
            if( res < j-k-1)
            {
                l = k+1;
                res = j-k-1;
            }
                       
        }
          return s.substr(l,res);
    }
    