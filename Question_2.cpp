// // Given an array of integers nums , calculate the pivot index of this array.
// // The pivot index is the index where the sum of all the numbers strictly to the left of the index is
// // equal to the sum of all the numbers strictly to the index's right.
// // If the index is on the left edge of the array, then the left sum is 0 because there are no elements
// // to the left. This also applies to the right edge of the array.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3};
    vector<int> prefix(nums.size()+1);
    vector<int> suffix(nums.size()+1);
    int n = prefix.size();

    prefix[0] = 0;
    suffix[n-1] = 0;

    for(int i = 1; i < n;i++)
    {
        prefix[i] = prefix[i-1]+nums[i-1];
    }

    for(int i = n-2; i >= 0;i--)
    {
        suffix[i] = suffix[i+1]+nums[i];
    }

    int p = 0;
    int idx=-1;
    while(p <= n)
    {
        if(prefix[p] == suffix[p+1] && prefix[p+1] == suffix[p])
        {
            idx = p;
            false;
            break;
        }
        p++;
        
    }
    cout<<idx<<endl;
    
}


