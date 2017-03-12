/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-12 20:46:15
** desc：  设计一个算法，给一个字符串进行二进制编码，使得编码后字符串的长度最短。
*********************************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    char s[3300];
    while(scanf("%s",s) != EOF){
        int n = strlen(s);
        sort(s,s + n);    //排序之后便于统计字符频度
        priority_queue<int> heap;

        int cnt = 0;
        //统计字符出现次数，次数放入优先级队列中
		//因为priority_queue默认返回的是最大值，所以将次数转换为负数使其返回的最小值，负数再另外处理。
		for(int i = 0,j;i < n;){
            j = i;
            while(j < n && s[j] == s[i]) ++ j;
            heap.push(i - j);
            i = j;
            ++ cnt;
        }

		//计算长度
        int ret = 0;
        for(int i = 0;i < cnt - 1;++ i){
            int A = heap.top(); heap.pop();
            int B = heap.top(); heap.pop();
            ret -= A + B;		
            heap.push(A + B);
        }  
        printf("%d\n",ret);
    }
    return 0;
}
