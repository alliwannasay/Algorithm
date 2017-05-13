//
//  main.cpp
//  Jump Game
//
//  Created by zzqmyos on 17/5/13.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool canJump_v1(vector<int>& nums)
{
    int vsize = int(nums.size());
    if(vsize == 0) return false;
    if(vsize == 1) return true;
    vector<bool>isAble;
    isAble.resize(vsize);
    isAble[0] = true;
    for(int i = 1; i < vsize; i++)
    {
        isAble[i] = false;
        for(int j = 0; j <= i-1; j++)
        {
            isAble[i] = isAble[i] || (isAble[j] && ((i-j)<=nums[j]));
        }
    }
    return isAble[vsize-1];
}

//这动态规划方法是对的，而且写出递推式后很快就写出来了。就是太慢了，两个样例通不过。

bool canJump(vector<int>& nums)
{
    int vsize = int(nums.size());
    if(vsize == 0) return false;
    if(vsize == 1) return true;
    int isAble = 0;
    int i = 0;
    for(i = 0; i < vsize && i <= isAble; i++)
    {
        isAble = max(isAble,i+nums[i]);
    }
    return (i == vsize);
}

//这个贪心不难证，但是为什么会想到去这样做？
//有一个思路是，动归的时候我是再想这些能跳的里面我遍历选一个
//但是这里面是变成，我选一个凡是跳我就让跳最大
//这个贪心贪的是跳的步数
//所以很重要的一个是去想，贪心贪什么指标
//而且，不一定是一定和动归丝毫不差的
//贪心选择不一定是动归中的选择
//就想这样一个事：我每次走下一步能不能贪一个什么东西
//然后证明

int main(int argc, const char * argv[]) {
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    
//    nums.push_back(3);
//    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(4);
    cout<<canJump(nums)<<endl;
    return 0;
}
