/********************************************************************************
** auth�� gaorong
** mail��  gaoronggood@163.com
** date�� 2017-03-09 17:04:11
** desc�� ��1��n������1���ֵĴ����������
*********************************************************************************/

#include <iostream>
using namespace std;

//��ָoffer 32:��1��n������1���ֵĴ���
//oj: https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//relate: ţ����ģ����1, ���֮��2.4
//tag : ��ѧ�߼�
//ע��߽��������ж�
int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 0)
		return 0;

	int mid = 0;		//��ʶ��ǰλ
	int lower = 0;		//��ʶ��ǰλ�ĵ�λ
	int upper = 0;		//��ʶ��ǰλ�ĸ�λ
	int now = 1;		//���������λ��
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

//ţ����ģ���⣺
//oj : https://www.nowcoder.com/questionTerminal/3a003cb6a3174ef9835fa603e01d8b52 
//�ⷨ��������ͬ����Ҫע�����0�������
int NumberBetween1AndN(int n, int i)
{
	if (n < 0)
		return 0;

	int mid = 0;		//��ʶ��ǰλ
	int lower = 0;		//��ʶ��ǰλ�ĵ�λ
	int upper = 0;		//��ʶ��ǰλ�ĸ�λ
	int now = 1;		//���������λ��
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

		//�����0��9�����ָ���
		//for (int i = 0; i < 9; i++){
		//	cout << NumberBetween1AndN(n, i) << " ";
		//}
	}



	return 0;
}







