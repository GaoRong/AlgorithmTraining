/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-12 20:02:00
** desc： 马戏团员叠罗汉表演。要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
          团长想要本次节目中的罗汉塔叠的最高，由于人数众多，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
*********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//为了让体重从大到小排列，自定义比较函数
//注意这里当体重相同的时候，需要让身高小的排在前面（根据题意指定比较函数）
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first > b.first || (a.first == b.first && a.second < b.second);
    
}

int main(){
	int n, temp;
	while (cin >> n){
		vector<pair<int, int>> vec(n);
		for (int i = 0; i<n; i++){
			cin >> temp >> vec[i].first >> vec[i].second;
		}
		sort(vec.begin(), vec.end(),cmp);

		vector<int> res(n, 1);
4
		int bigValue = 1;
		for (int i = 0; i<vec.size(); i++){
			int j = i - 1;
			for (; j >= 0; j--){
				if (  vec[j].second >= vec[i].second ) {
					res[i] = max(res[i], res[j] + 1);
				}
			}
			bigValue = max(bigValue, res[i]);
		}

		cout << bigValue << endl;
	}
}


