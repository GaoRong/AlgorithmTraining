/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-15 16:51:06
** desc：  某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数；
		有m批客人，每批客人有两个参数:b人数，c预计消费金额。 
		在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
*********************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct node{
    int b,c;
    node(int ta,int tb):b(ta),c(tb){}
};

bool cmp(node x, node y){   //默认的比较符号为小于号
    if( x.c==y.c )
        return x.b < y.b;
    
    return x.c > y.c;
}

int n,m,temp;
vector<node> v;
multiset<int> ms;
long res=0;

int main(){
    
    while(cin >> n >> m){
        for(int i=0; i<n; i++){
            cin >> temp;
            ms.insert(temp);   //之所以用multiset来存储是为了利用其自动排序和二分查找的功能
        }
        
        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            v.push_back( node(x,y) );
        }
        
        sort(v.begin(),v.end(), cmp);
        res = 0;
        
        for(int i=0; i<m; i++){
            multiset<int>::iterator iter = ms.lower_bound(v[i].b);
            if( iter != ms.end() ){
          		res += v[i].c;
                ms.erase(iter);
            }
        }
        
        cout << res << endl;
    }
     
}