//
// Created by Tiana on 2022/8/2.
//


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int low1, int high1, int low2, int high2){
    if (low1 > high1 || low2 > high2) return;
    vector<int> temp; // 暂存合并的数组
    int i, j;
    i = low1;
    j = low2;
    while (i <= high1 && j <= high2){
        if (nums[i] < nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    // 把剩余的全放进temp
    while (i <= high1)
        temp.push_back(nums[i++]);
    while (j <= high2)
        temp.push_back(nums[j++]);

    // 把temp赋值给nums
    for(int k=0; k<temp.size(); k++)
        nums[low1 + k] = temp[k];

}



void mergesort(vector<int>& nums, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, mid+1, high);
    }

}

int main(){

    vector<int> nums = { 6, 2, 3, 1, 8};

    // merge(nums, 0, 1, 2, 2);

    mergesort(nums, 0, (int)nums.size()-1);

    for (auto n : nums)
        cout << n << endl;


}