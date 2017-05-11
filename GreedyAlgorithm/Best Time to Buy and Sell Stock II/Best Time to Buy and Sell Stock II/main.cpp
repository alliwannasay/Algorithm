//
//  main.cpp
//  Best Time to Buy and Sell Stock II
//
//  Created by zzqmyos on 17/5/11.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit_dp(vector<int>& prices)//这个动归的算法是正确的，就是太慢了
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    vector<int>dp;
    dp.resize(vsize);
    dp[0] = 0;
    dp[1] = (prices[1] > prices[0])?(prices[1]-prices[0]):0;
    for(int i = 2; i < vsize; i++)
    {
        dp[i] = dp[i-1];
        for(int j = 0; j < i-1; j++)
        {
            int minr = prices[j+1];
            for(int k = j; k <= i-1; k++)
            {
                if(prices[k] < minr) minr = prices[k];
            }
            int minp = (prices[i]>minr)?dp[j]+prices[i]-minr:dp[j];
            if(dp[i] != 0 && minp > dp[i]) dp[i] = minp;
            else if(dp[i] == 0) dp[i] = minp;
        }
    }
    return dp[vsize-1];
}

int maxProfit(vector<int>& prices)
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    int index = 0;
    int tmpmin = prices[0];
    int sum = 0;
    for(int i = 1; i < vsize; i++)
    {
        if(prices[i] > tmpmin)
        {
            sum += prices[i] - tmpmin;
            index = i + 1;
            tmpmin = prices[index-1];
        }
        else
        {
            tmpmin = prices[i];
        }
    }
    return sum;
}

//总结：非常容易忽视的一点：题意理解是当天可以买卖。
//为什么能用贪心很容易证明。但是想到去证明贪心比较难。
//在这里只能说，先多做吧。

int main(int argc, const char * argv[]) {
    vector<int>prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
//    prices.push_back(1);
//    prices.push_back(2);
//    prices.push_back(4);
    cout<<maxProfit(prices)<<endl;
    return 0;
}
