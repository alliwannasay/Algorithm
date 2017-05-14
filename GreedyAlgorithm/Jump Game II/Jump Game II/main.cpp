//
//  main.cpp
//  Jump Game II
//
//  Created by zzqmyos on 17/5/13.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int jump_v1(vector<int>& nums)
{
    int vsize = int(nums.size());
    if(vsize == 0) return 0;
    if(vsize == 1) return 0;
    vector<int>isAble;
    isAble.resize(vsize);
    isAble[0] = 0;
    for(int i = 1; i < vsize; i++)
    {
        isAble[i] = -1;
        int tmp = -1;
        for(int j = 0; j <= i-1; j++)
        {
            if(isAble[j] >= 0 && ((i-j)<=nums[j]))
            {
                if(tmp == -1) tmp = isAble[j]+1;
                else tmp = min(tmp,isAble[j]+1);
            }
        }
        isAble[i] = tmp;
    }
    return isAble[vsize-1];
}

//动归就适合做这种事，但是又是慢到一个有一个样例过不了。

int jump(vector<int>& nums)
{
    int vsize = int(nums.size());
    if(vsize == 0) return 0;
    if(vsize == 1) return 0;
    int reach = 0;
    int step = 0;
    int lastr = 0;
    for(int i = 0; i < vsize; i++)
    {
        if(i > lastr)
        {
            step++;
            lastr = reach;
        }
        reach = max(reach,i+nums[i]);
    }
    return step;
}

//感觉这就有点
//感觉贪心里方法摸不到套路啊
//这块比Jump Game多的就是记录一个上一次到达的位置
//如果走过了上一次的位置
//说明step不够，就加1
//这个事听起来好 但是根本想不到啊


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
    cout<<jump(nums)<<endl;
    return 0;
    return 0;
}
