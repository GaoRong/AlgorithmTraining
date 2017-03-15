/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-15 15:32:35
** desc：  一个数组有 N 个元素，求连续子数组的最大和。
*********************************************************************************/
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
 
int main(){
         
    int n;
    while( cin>>n ){
        vector<int> vec(n);
        for(int i=0; i<n; i++) cin >> vec[i];
         
        int maxValue = INT_MIN;
        int temp = 0;
        for(int i=0; i<n; i++){
            temp+=vec[i];
            maxValue = max(temp, maxValue);
            if( temp <= 0 ) temp=0;
             
        }
         
        cout << maxValue << endl;
    }
  
}