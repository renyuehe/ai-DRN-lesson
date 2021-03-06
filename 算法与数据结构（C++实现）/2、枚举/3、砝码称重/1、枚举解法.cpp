/*
砝码称重(NOIP1996)

【问题描述】
设有1g、2g、3g、5g、10g、20g的砝码各若干枚（其总重<=1000），
求用这些砝码能称出不同的重量的个数。
【输入文件】
        输入1g、2g、3g、5g、10g、20g的砝码个数
【输出文件】
        能称出不同的重量的个数
【输入样例】
        1 1 0 0 0 0 
【输出样例】
        3

题目提交位置
https://www.luogu.com.cn/problem/P2347


分析
根据输入的砝码信息，每种砝码可用的最大个数是确定的，而且每种砝码的个数是连续的，
能取0到最大个数，所以，符合穷举法的两个条件，可以使用穷举法。

穷举时，重量可以由1g,2g,……,20g的砝码中的任何一个，或者多个构成，
枚举对象可以确定为6种重量的砝码，范围为每种砝码的个数，判定时，
只需判断这次得到的重量是新得到的，还是前一次已经得到的，即判重。
由于总重<=1000，所以，可以开一个flag[1..1000]的布尔数组来判重，
当得到v重量时，把flag[v]置为true，下次再得到v时，还是置true，
最后只需遍历一下flag数组，即可得到重量的个数。

枚举变量：1g砝码，2g砝码，3g砝码，5g砝码，10g砝码，20g砝码
枚举范围：1g砝码0-n1，2g砝码0-n2，3g砝码0-n3，5g砝码0-n5，10g砝码0-n10，20g砝码0-n20
枚举判断条件：
统计所有砝码和的不同重量
砝码和总重小于1000

算法思路：
1、枚举不同砝码的个数，计算总重量，并将总重量对应的标志置为1
2、根据标志，计算总重量的个数


100 100 150 250 100 300
100*50*50*50*10*15

*/
#include <iostream>
using namespace std;
int flag[1005] = {0};
int main()
{
	int n1, n2, n3, n5, n10, n20;
	cin >> n1 >> n2 >> n3 >> n5 >> n10 >> n20;
	//1、枚举不同砝码的个数，计算总重量，并将总重量对应的标志置为1
	for (int i1 = 0; i1 <= n1; i1++)
	{
		for (int i2 = 0; i2 <= n2; i2++)
		{
			for (int i3 = 0; i3 <= n3; i3++)
			{
				for (int i5 = 0; i5 <= n5; i5++)
				{
					for (int i10 = 0; i10 <= n10; i10++)
					{
						for (int i20 = 0; i20 <= n20; i20++)
						{
							int sum=i1+i2*2+i3*3+i5*5+i10*10+i20*20;
							flag[sum]=1;
						}
					}
				}
			}
		}
	}
	//2、根据标志，计算总重量的个数
	int count=0;
	for(int i=1;i<=1000;i++){
		if(flag[i]) count++;
	}
	cout<<"Total="<<count<<endl;
	return 0;
}
