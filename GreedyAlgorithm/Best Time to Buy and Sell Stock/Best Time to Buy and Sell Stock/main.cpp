//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by zzqmyos on 17/5/11.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int vsize = int(prices.size());
    if(vsize == 0 || vsize == 1) return 0;
    int minr = prices[0];
    int maxp = 0;
    int tmp = 0;
    for(int i = 1; i < vsize; i++)
    {
        if(prices[i] < minr) minr = prices[i];
        else
        {
            tmp = prices[i] - minr;
            if(tmp > maxp) maxp = tmp;
        }
    }
    return (maxp>0)?maxp:0;
}

int main(int argc, const char * argv[]) {
    vector<int>prices;
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);
//    prices.push_back(4);
    cout<<maxProfit(prices)<<endl;
    return 0;
}
