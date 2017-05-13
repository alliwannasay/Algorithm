//
//  main.cpp
//  Best Time to Buy and Sell Stock IV
//
//  Created by zzqmyos on 17/5/13.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int simMaxProfit(vector<int>& prices)
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


int maxProfit(int k, vector<int>& prices)
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    if(k > vsize+1) return simMaxProfit(prices);
    vector<int>global;
    global.resize(k+1);
    vector<int>local;
    local.resize(k+1);
    for(int i = 1; i < vsize; i++)
    {
        int diff = prices[i]-prices[i-1];
        for(int j = k; j >= 1; j--)
        {
            local[j] = max(global[j-1]+max(diff,0),local[j]+diff);
            global[j] = max(local[j],global[j]);
        }
    }
    return global[k];
}

//具体的参见Best Time to Buy and Sell Stock III
//比III多一个大坑就是，可能k特别大超过了数组大小
//就回归到II的解法



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
    
    
    cout<<maxProfit(2,prices)<<endl;
    int a = 0;
    return 0;
}
