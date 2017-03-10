/********************************************************************************
** auth： gaorong
** mail：  gaoronggood@163.com
** date： 2017-03-09 17:04:11
** desc： 从1到n整数中1出现的次数及其相关
*********************************************************************************/

#include <iostream>
using namespace std;

//剑指offer 32:从1到n整数中1出现的次数
//oj: https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//relate: 牛客网模拟题1, 编程之美2.4
//tag : 数学逻辑
//注意边界条件的判断
int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 0)
		return 0;

	int mid = 0;		//标识当前位
	int lower = 0;		//标识当前位的低位
	int upper = 0;		//标识当前位的高位
	int now = 1;		//现在所求的位数
	int count = 0;

	while (now <= n)
	{
		mid = n / now % 10;
		upper = n / (now * 10);

		if (mid == 0)
		{
			count += upper*now;
		}
		else if (mid == 1)
		{
			lower = n % now;
			count += upper*now + lower + 1;
		}
		else
		{
			count += (upper + 1) * now;
		}

		now *= 10;
	}
	return count;
}

//牛客网模拟题：
//oj : https://www.nowcoder.com/questionTerminal/3a003cb6a3174ef9835fa603e01d8b52 
//解法与上面相同，需要注意对于0的情况。
int NumberBetween1AndN(int n, int i)
{
	if (n < 0)
		return 0;

	int mid = 0;		//标识当前位
	int lower = 0;		//标识当前位的低位
	int upper = 0;		//标识当前位的高位
	int now = 1;		//现在所求的位数
	int count = 0;

	while (now <= n)
	{
		mid = n / now % 10;
		upper = n / (now * 10);

		if (i == 0){
			if (upper)
				upper--;
			else
				break;
		}

		if (mid < i)
		{
			count += upper*now;
		}
		else if (mid == i)
		{
			lower = n % now;
			count += upper*now + lower + 1;
		}
		else
		{
			count += (upper + 1) * now;
		}

		now *= 10;
	}
	return count;
}


int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumberOf1Between1AndN_Solution(n) << endl;

		//输出从0到9的数字个数
		//for (int i = 0; i < 9; i++){
		//	cout << NumberBetween1AndN(n, i) << " ";
		//}
	}



	return 0;
}







