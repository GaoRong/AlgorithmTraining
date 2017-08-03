/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-08-03 21:01:10
** desc：  整形数组，array
*********************************************************************************/

//partition 函数，在快排，topK等需要
//这里实现每次都取第一个元素作为枢纽元素
int partition(int *array, int left, int right) {

	int small = left - 1;
	int val = array[left];

	swap(array[left], array[right]);

	for (int i = left; i < right; i++)
	{
		if (val > array[i]) {
			small++;
			swap(array[small], array[i]);
		}
	}

	small++;
	swap(array[small], array[right]);
	return small;
}
