/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-08-04 08:44:47
** desc：  sort and binary search
*********************************************************************************/



int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (result > numbers[i])
			result = numbers[i];
	}

	return result;
}

//旋转数组，见剑指offer， 二分查找

int rotateArray(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])   //需要考虑1,2,3,4,5这般情况
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		// 如果下标为index1、index2和indexMid指向的三个数字相等，
		// 则只能顺序查找
		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		// 缩小查找范围
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}


