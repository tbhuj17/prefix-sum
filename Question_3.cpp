// We define the conversion array conver of an array arr as follows:
// conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum value of
// arr[j] over 0 <= j <= i .
// We also define the score of an array arr as the sum of the values of the conversion array
// of arr .
// Given a 0-indexed integer array nums of length n , return an array ans of length n where
// ans[i] is the score of the prefix nums[0..i] .

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> score(n);
        vector<int> conver(n);
        int max = INT_MIN;
        cout<<"Original Vector: ";
        for(int i = 0;i < n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        for(int i = 0;i < n;i++)
        {
            if(max < nums[i]) max = nums[i];
            conver[i] = nums[i]+max;
        }

        score[0] = conver[0];

        for(int i = 1;i < n;i++)
        {
            score[i] = score[i-1]+conver[i];
        }
        cout<<"conver vector: ";
        for(int i = 0;i < n;i++)
            cout<<conver[i]<<" ";
        cout<<endl<<"Score Vector: ";
        for(int i = 0;i < n;i++)
            cout<<score[i]<<" ";
        cout<<endl;

    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,3,7,5,10};
    s.findPrefixScore(nums);
}