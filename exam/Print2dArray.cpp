/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-03-12 22:02:02
** desc：  实现从右上角到左下角沿主对角线方向打印二维矩阵
*********************************************************************************/
class Printer {
public:

//定义一系列指针进行标识
 vector<int> arrayPrint(vector<vector<int> >& arr, int n) {
 
    vector<int> res;
 
    int i = n - 1;
    int j = 0;
    int I = n-1;
    while (I >= 0)
    {
        i = I,j = 0;
        while (i < n && j < n)
        {
            res.push_back(arr[j][i]);
            i++;
            j++;
        }
        I--;
    }
 
    int J = 1;
    while (J < n)
    {
        i = 0, j = J;
        while ( j < n)
        {
            res.push_back(arr[j][i]);
            i++;
            j++;
        }
        J++;
    }
    return res;
}
 
};