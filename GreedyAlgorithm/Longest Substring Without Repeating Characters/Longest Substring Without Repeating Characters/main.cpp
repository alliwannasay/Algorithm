//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by zzqmyos on 17/5/15.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring_v1(string s)
{
    int vsize = int(s.length());
    if(vsize == 0 || vsize == 1) return vsize;
    vector<int>dp;
    dp.resize(vsize);
    dp[0] = 1;
    int tmp = 0;
    int step = 0;
    for(int i = 1; i < vsize; i++)
    {
        int start = i-dp[i-1];
        for(int j = 1; j <= dp[i-1]; j++)
        {
            step++;
            if(s[i-j] == s[i])
            {
                start = i-j+1;
                break;
            }
        }
        dp[i] = i-start+1;
        tmp = max(tmp,dp[i]);
    }
    cout<<"size:"<<vsize<<" step:"<<step<<endl;
    return tmp;
}

//简单动态规划
//最坏情况下是O(n2)



int main(int argc, const char * argv[]) {
    string s = "pwwkew";
    std::cout << lengthOfLongestSubstring_v1(s)<<endl;
    return 0;
}
