/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-15 17:11:00
** desc：  输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2
*********************************************************************************/
#include <iostream>
using namespace std;
 
int main(){
     
    int n;
    while( cin >> n ){
        //算出包含5的个数即为0的个数
        int factor = 5;
        int count = 0;
        while( factor <= n ){
             
            count += n/factor;
            factor *= 5;
 
        }
        cout << count << endl;
    }
     
     