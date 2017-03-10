/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-10 12:19:03
** desc：  https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9 
*********************************************************************************/


#include <iostream>
using namespace std;

bool test(int n,int l){
    int mid = n/l;          //取出中值
    int begin = mid-(l-1)/2;		//取出第一个元素
    if(begin < 0 || l > 100){		//如果元素下标小于0或序列长度大于100则输出结果
        cout << "No" << endl;
        return true;
    }
    int sum = 0;			//求序列和
    for(int i = 0;i<l;i++){
    	sum += begin;
        begin++;
    }
    
    if( sum == n ){
        begin = mid-(l-1)/2;
        for(int i = 0;i<l;i++){
            i==0 ? cout << begin++ : cout << " " << begin++;
        }
        return true;
    }else{
        return false;
    }
}


int main(){
    int n,l;
    while(cin >> n >> l){
		//如果没有得到结果就一直加大序列的长度
        while( !test(n,l) ){
            l++;
        }    
    }
}