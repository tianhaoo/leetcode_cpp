//
// Created by Tiana on 2022/8/2.
//
#include<iostream>
#include<vector>
using namespace std;



int partition(vector<int>& nums, int low, int high){
    int pivot = nums[high];
    vector<int> temp(high-low+1, 0);
    int temp_i, temp_j;
    temp_i = 0;
    temp_j = high-low;

    // 在temp里放置合适顺序的元素
    for(int i=low; i<=high-1; i++) {
        if (nums[i] < pivot)
            temp[temp_i++] = nums[i];
        else
            temp[temp_j--] = nums[i];
    }
    // 将pivot放回中间
    temp[temp_i] = pivot;

    for(auto n: temp)
        cout << n << endl;
    cout << endl;

    // 将temp里的元素放回去
    for(int i=low; i<=high; i++){
        nums[i] = temp[i-low];
    }

    return low + temp_i;

}

void quicksort(vector<int>& nums, int low, int high){
    if(high > low){
        int p = partition(nums, low, high);
        cout << low << p << high << endl;
        quicksort(nums, low, p-1);
        quicksort(nums, p+1, high);

    }
}


int main(){

    vector<int> nums = {8, 9, 7, 11, 89, 3, 2, 5, 1};

    for (auto n : nums)
        cout << n << ' ';
    cout << endl;

//    int p = partition(nums, 2, 3);
//    cout << p << endl << endl;

//    p = partition(nums, 1, (int)nums.size()-1);
//    cout << p << endl;

    quicksort(nums, 0, (int)nums.size()-1);

    for (auto n : nums)
        cout << n << ' ';
    cout << endl;

    return 0;
}
