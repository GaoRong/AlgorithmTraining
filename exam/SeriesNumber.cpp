/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-10 14:49:59
** desc：  连续整数中找抹去的一个
*********************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

/*
//自己写的渣渣代码，下面有大神写的
int main(){
    int n;
    while( cin >> n ){
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }
        sort(vec.begin(),vec.end());		//先排序，然后再遍历
        
        int i;
        int flag = 0;
        bool mistake = false;
        for(i = 1; i<n; i++){
            if( vec[i] - vec[i-1]  == 2 ){
                if(flag != 0){
                    mistake = true;
                    break;
                }else{
                    flag = i;
                }
                
            }else if( vec[i] - vec[i-1] > 2 ){
                mistake = true;
                break;
            }
                
            
        }
        
        if( mistake ){
            cout << "mistake";
            continue;
        }
        if( flag == 0 ){
            if( vec[0]-1 > 0)
                cout << vec[n-1]+1;
            else
            	cout << vec[0]-1 <<" " << vec[n-1]+1;
        }else{
    		cout << vec[flag]-1;
    	} 
    }    
}
*/

//利用按位异或运算
#include<iostream>
using namespace std;
int main() 
{ 
	int n;    
	cin >> n;   
	int min = 1000000001; 
	int max = 0;   
	int res = 0;  
	int num = 0;   
	for (int i = 0; i < n; i++) 
	{ 
		cin >> num;   
		if (num < min) min = num;   
		if (num > max) max = num;     
		res ^= num; 
	}    
	for (int i = min; i <= max; i++) 
	{ 
		res ^= i; 
	}   
	if (res == 0) 
	{
		if (min - 1> 0)    
			cout << min - 1 << " " << max + 1;      
		else cout << max + 1; } 
	else if (res <= min || res >= max) 
	{ 
		cout << "mistake" << endl;
	} 
	else
		cout << res; 
}
