/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-15 17:00:19
** desc：  小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
		为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,
		小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。
		小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点
		可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗
		3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法
		逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
*********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef struct Point{
	int x;
	int y;
	int power;
	Point(int tx, int ty, int tpower) :x(tx), y(ty), power(tpower){}
} P;


int factor[4][3] = { { 0, 1, -1 }, { 1, 0, 0 }, { 0, -1, -1 }, { -1, 0, -3 } };

int n, m, power;

int bfs(vector<vector<int>>& vec, vector<vector<P>>& res){
	
	queue<P> q;
	q.push(P(0,0,power));
	res[0][0] = P(100001, 100001, power);	

	while (!q.empty()){
		P temp = q.front(); q.pop();

		if (temp.x == 0 && temp.y == m-1){
			return true;
		}

		for (int i=0; i<4; i++){
			int x = temp.x + factor[i][0];
			int y = temp.y + factor[i][1];
			int tempPower = temp.power + factor[i][2];

			if (x >= 0 && x < n && y >= 0 && y < m && vec[x][y] == 1 && tempPower >= 0 && res[x][y].x==-1){
					q.push(P(x, y, tempPower));
					res[x][y] = P(temp.x,temp.y, temp.power);
			}
		}
	}

	return false;
}


int main(){
	while (cin >> n >> m >> power){
		vector<vector<int>> vec(n, vector<int>(m, 0));
		//需要一个保存访问过标志的数组
		vector<vector<P>> res(n, vector<P>(m, P(-1, -1, 0)));
		for (int i = 0; i<n; i++){
			for (int j = 0; j<m; j++){
				cin >> vec[i][j];
			}
		}
	
		if (!bfs(vec, res)){
			cout << "Can not escape!" << endl;
			continue;
		}

		P temp(0,m-1,0);
		stack<P> s;
		s.push(P(0, m - 1,0));
		
		while(true) {
			temp = s.top();
			if (res[temp.x][temp.y].x > 10000 || res[temp.x][temp.y].y > 10000)
				break;
			s.push(res[temp.x][temp.y]);
		}

		temp = s.top();  s.pop();
		cout << "[" << temp.x << "," << temp.y << "]";
		while (!s.empty()){
			temp = s.top();
			s.pop();
			cout << "," << "[" << temp.x << "," << temp.y << "]";
		}
	}
}