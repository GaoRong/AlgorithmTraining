#牛客网校招模拟题1
####[序列和](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/SumOfSequence.cpp)
tag : 数学逻辑    
address: https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9   
>给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我们需要找出长度最小的那个。
>例如 N = 18  L = 2：   
>5 + 6 + 7 = 18;   
>3 + 4 + 5 + 6 = 18;   
>都是满足要求的，但是我们输出更短的 5 6 7      

####[超级素数幂](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/PrimePow.cpp)      
tag : 数学逻辑,精度		     
address: https://www.nowcoder.com/questionTerminal/fb511c3f1ac447309368d7e5432c6c79		
>如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,如果n是一个超级素数幂需要找出对应的p,q。    
>输入描述:输入一个正整数n(2 ≤ n ≤ 10^18)    
>输出描述:如果n是一个超级素数幂则输出p,q,以空格分隔,行末无空格。如果n不是超级素数幂，则输出No    
>输入例子:27    
>输出例子:3 3    

####[连续整数](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/SeriesNumber.cpp)	
tag : 按位异或	
address: https://www.nowcoder.com/questionTerminal/c3083cd30d5043e1b95000f139b5b2c9	

####[循环单词](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/CircleWord.cpp)	
tag : 字符串    	
address: https://www.nowcoder.com/questionTerminal/9d5fbe7750a34d0b91c73943f93b2d7d  
>如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。 现在给出n个单词，需要统计这个n个单词中有多少种循环单词。 



#网易2016实习研发工程师   
###[二叉树](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/BTleafNodeDistance.cpp)
tag: 二叉树   
address: https://www.nowcoder.com/questionTerminal/d567727f21a247f7b64ba32431cb9a19   
>有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。 给定二叉树的根节点root，请返回所求距离。    
tips: 典型的二叉树递归也可解，但将二叉树叶子结点进行01编码是妙解     

###[比较重量](https://github.com/GaoRong/AlgorithmTraining/blob/master/exam/WeightCompare.cpp)
tag: 有向图，多叉树，bfs，floyd算法  
address: https://www.nowcoder.com/questionTerminal/ac27e60e63b549d6a9b59f815d9bc6e2       
>给定两颗钻石的编号g1,g2，编号从1开始，同时给定关系数组vector,其中元素为一些二元组，第一个元素为一次比较中较重的钻石的编号，第二个元素为较轻的钻石的编号。最后给定之前的比较次数n。请返回这两颗钻石的关系，若g1更重返回1，g2更重返回-1，无法判断返回0。输入数据保证合法，不会有矛盾情况出现。    
tips:  对于判断相互关系的题型都可以这样将一个构造一个有向图或多叉树      


 


