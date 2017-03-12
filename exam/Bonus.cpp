/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-12 20:28:54
** desc：  比赛结束之后要发奖金，以1w为单位，每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。 
*********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;

	while (cin >> n){
		vector<int> vec(n);
		for (int i = 0; i<n; i++)  cin >> vec[i];

		vector<int> res(n, 1);

		for (int i = 1; i<n; i++){
			if (vec[i] > vec[i - 1]){
				res[i] = max(res[i], res[i - 1] + 1);
			}
		}

		for (int i = n - 2; i >= 0; i--){
			if (vec[i] > vec[i + 1]){
				res[i] = max(res[i], res[i + 1] + 1);
			}
		}

		int ret = 0;
		for (int i = 0; i<n; i++){
			ret += res[i];
		}
		cout << ret << endl;
	}

	return 0;

}