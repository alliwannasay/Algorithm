//
//  main.cpp
//  Best Time to Buy and Sell Stock III
//
//  Created by zzqmyos on 17/5/11.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit_v1(vector<int>& prices)
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    int i = vsize-1;
    int maxp = 0;
    for(int j = 0; j <= i; j++)
    {
        int s1 = 0;
        int e1 = j;
        int minf = prices[s1];
        int maxf = 0;
        for(int k = s1; k <= e1; k++)
        {
            if(prices[k] < minf) minf = prices[k];
            else maxf = ((prices[k] - minf)>maxf)?(prices[k] - minf):maxf;
        }
        int s2 = j;
        int e2 = i;
        int minr = prices[s2];
        int maxr = 0;
        for(int k = s2; k <= e2; k++)
        {
            if(prices[k] < minr) minr = prices[k];
            else maxr = ((prices[k] - minr)>maxr)?(prices[k] - minr):maxr;
        }
        maxp = ((maxf+maxr)>maxp)?(maxf+maxr):maxp;
    }
    return maxp;
}

//总结1:这个方法1根本不是动归，是两个贪心合起来
//实际上有计算得重复的地方。
//所以有一个样例通不过。

int maxProfit(vector<int>& prices)
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    vector<int>global;
    global.resize(3);
    global.assign(3, 0);
    vector<int>local;
    local.resize(3);
    local.assign(3, 0);
    for(int i = 1; i < vsize; i++)
    {
        global[0] = 0;
        local[0] = 0;
        int diff = prices[i]-prices[i-1];
        for(int j = 2; j >= 1; j--)
        {
            local[j] = max(global[j-1]+max(diff,0),local[j]+diff);
            global[j] = max(local[j],global[j]);
        }
    }
    return global[2];
}

//感觉这个算法超出我的掌控
//首先解释一下：
//local[i][j]指的是第i天为止共进行j次交易且第j次在第i天的最大利润
//global[i][j]指的是到第i天为止共进行j次交易的最大利润
//local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)
//global[i][j]=max(local[i][j],global[i-1][j])
//知道这两个那两个递推式就好想了。
//但是问题难在，我为什么要这么分析问题
//按理说子问题分解一个方向是天数，这个很trivial
//但是另一个方向竟然是次数
//这个我没见过。
//于是得出一个经验之谈
//子问题分解维度的选择可以选题目中的限制指标
//子问题的分解维度就是dp矩阵的两个轴。


int main(int argc, const char * argv[]) {
    vector<int>prices;
//        prices.push_back(3);
//        prices.push_back(3);
//        prices.push_back(5);
//        prices.push_back(0);
//        prices.push_back(0);
//        prices.push_back(3);
//        prices.push_back(1);
//        prices.push_back(4);
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
//        prices.push_back(1);
//        prices.push_back(2);
//        prices.push_back(4);
    cout<<maxProfit(prices)<<endl;
    int a = 0;
    return 0;
}
