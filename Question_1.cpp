// Calculate the sum of the elements of nums between indices left and right inclusive where
// left <= right .
// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums .
// int sumRange(int left, int right) Returns the sum of the elements of nums between
// indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... +
// nums[right] ).


#include<iostream>
#include<vector>

using namespace std;
int calc_sum(vector<int> &prefix, int a, int b)
{

    return prefix[b]-prefix[a-1];
}
int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    int n = nums.size();
    vector<int> prefix(n);

    prefix[0] = nums[0];
    for(int i = 1;i < n;i++)
    {
        prefix[i] = prefix[i-1]+nums[i];
    }

    for(int i = 0;i < n;i++) cout<<prefix[i]<<" ";

    cout<<endl<<calc_sum(prefix, 2, 5);

}