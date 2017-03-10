/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-10 15:48:12
** desc：  如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词,统计循环单词的个数
*********************************************************************************/

//思路1：长度比较小采用暴力解法，主要是考察编码的实现

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool judge(string& scStr, string& tarStr){
    
   	if( scStr.length() != tarStr.length() ){
        return false;
    }
    
    int len = scStr.length();
    int i = 0,j=0,k=0;
    for(k=0; k<scStr.length(); k++){
		i = 0;
        j = k;
        while(scStr[i] == tarStr[j]){
            if( ++i >= len){
                return true;
            }
            j = (++j) % len;
        }
    }
    
    return false;
}

int main(){
    int n;
    while(cin >> n){
        vector<string> vec(n);
        int count = 0;
        for(int i = 0;i<n;i++)  cin >> vec[i];
         
        vector<string>::iterator iterA = vec.begin();
        vector<string>::iterator iterB = iterA+1;
        for( ; iterA<vec.end(); iterA++){
            for(iterB=iterA+1 ; iterB<vec.end(); iterB++){ 
                if( judge(*iterA, *iterB) ){      
                    vec.erase( iterB );
                    --iterB;
                }
                
            }
            
        }
        cout << vec.size();
        
    }
    
}

//思路二：考察两个字符串是否为循环字符串，只需要判断str2是否是str1+str1的子串， 
//例如：hello与elloh : hello+hello = hellohello包含elloh
//这样实现起来相对简单一点，处处皆算法！！