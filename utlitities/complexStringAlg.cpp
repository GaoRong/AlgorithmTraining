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
        int res = -1;	//字串长度
        int l=0;		//子串起始index
         
        for(int i = 0; i<s.length(); i++){

			//从i-1和i+1开始扩展，当对称中心为该字母  avcvl-> vcv
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
            
			//从i和i+1开始扩展，当对称中心为该字母和下一个字母，例如： acvvcl -> cvvc
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
   


//最全面atoi函数，考虑任何非法输入
//The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

//思路：
//注意：当i超出string的范围的时候并并不会产生异常
//	  直接进行情况判断，用++操作符进行自增，不需要专门的循环
//1.去除前置(leading)空格
//2.处理符号
//3.while循环判断每个字符，循环条件为是否为数字
int myAtoi(string str) {
	long result = 0;	
	int indicator = 1;	//表示符号
	int i = 0; 
	
	i = str.find_first_not_of(' ');
	if(str[i] == '-' || str[i] == '+')
		indicator = (str[i++] == '-')? -1 : 1;
	while('0'<= str[i] && str[i] <= '9') 
	{
		result = result*10 + (str[i++]-'0');
		if(result*indicator >= INT_MAX) return INT_MAX;
		if(result*indicator <= INT_MIN) return INT_MIN;                
	}

	return result*indicator;
}