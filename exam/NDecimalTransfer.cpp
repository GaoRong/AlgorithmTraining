/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-15 11:11:20
** desc：  给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数 
*********************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I'};

int main(){
    int n,m;
    while( cin>>n>>m ){
    
        string str;
		//判断是否为小数
        bool flag = false;	
        if( n<0 ){
            flag = true;
            n = -1*n;
        }
        
		
        while( n>0 ){
            str.append(1,a[n%m]);
            n = n/m;
        }
        if( flag ){
        	str.append(1,'-');    
        }
        
		//反转字符串
        reverse(str.begin(),str.end());
        cout << str << endl;
        
    }
    
    
}