/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-10 13:52:27
** desc：  如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,如果n是一个超级素数幂需要找出对应的p,q。 
*********************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
bool isPrime(int n){
    int num = sqrt(n);
    for(int i = 2; i<=num; i++){
        if( n % i == 0 )
        	return false;
    }
    return true; 
}


int main(){
    long long int n;    //输入值较大
    bool flag = false;
    while( cin >> n ){
        
        int ceil = log10(n)/log10(2);	//为log2(N)，因为底数最小为2，指数最大为log2(N)
        int temp;
        
        for(int i = 2; i<=ceil; i++){
           temp = pow(n, 1.0/i);
            
			//因为double类型转化为int的temp,所以需要重新pow一下验证
            if( pow(temp, i)==n && isPrime(temp) ){    
                cout << temp << " " << i;
                flag = true;
                break;
            }
        }
        
        if(!flag){
            cout << "No" << endl;
        }
        
    }
    return 0;
}