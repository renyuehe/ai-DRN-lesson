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


分析
这个问题本身的描述就是一个多重背包，
也就是每个砝码有多个

多重背包就不需要01背包里面的 1、统计砝码总数，准备好砝码序列

多重背包可以在01背包的基础上稍微改一下就实现了

*/

#include <iostream>
using namespace std;
int f[1005]={0};
int main(){
    
    int n[7];
    int a[7]={0,1,2,3,5,10,20};
    for(int i=1;i<=6;i++){
        cin>>n[i];
    }
    //2、初始化动态规划数组，做动态规划
    f[0]=1;
    for(int i=1;i<=6;i++){ //对不同型号的砝码进行循环
        for(int k=1;k<=n[i];k++){ //对同一个型号的多个砝码进行循环
            for(int j=1000;j>=a[i];j--){
                f[j]=f[j] + f[j-a[i]];
            }
        }
    }
    //3、统计方案总数
    int count=0;
	for(int i=1;i<=1000;i++){
		if(f[i]) count++;
	}
	cout<<"Total="<<count<<endl;
    return 0;
}







