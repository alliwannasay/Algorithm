//
//  main.cpp
//  Maximum Subarray
//
//  Created by zzqmyos on 17/5/14.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int vsize = int(nums.size());
    if(vsize == 0) return 0;
    if(vsize == 1) return nums[0];
    int tmp = nums[0];
    int last = nums[0];
    for(int i = 1; i < vsize; i++)
    {
        last = max(nums[i],nums[i]+last);
        tmp = max(tmp,last);
    }
    return tmp;
}

//动态规划也可以O(n)
//而且这里面有一个贪心的想法
//就是每次只要和比当前数小
//就全扔掉
//也好证明
//就是注意别乱设初始值
//尤其是有max min这样的操作的时候
//人家有负的你干嘛设0

int main(int argc, const char * argv[]) {
    vector<int>nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    
    //    nums.push_back(3);
    //    nums.push_back(2);
    //    nums.push_back(1);
    //    nums.push_back(0);
    //    nums.push_back(4);
    cout<<maxSubArray(nums)<<endl;
    return 0;
}
