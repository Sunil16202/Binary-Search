//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
class Solution {
public:
    
int last(vector<int>& arr, int x){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int res = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == x){
            res = mid;
            start = mid + 1;
        }
        else if(arr[mid] > x){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    return res;
}

int first(vector<int>& arr, int x){
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int res = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == x){
            res = mid;
            end = mid-1;
        }
        else if(arr[mid] > x){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    return res;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int l = last(nums, target);
        vector<int> v;
        v.push_back(f);
        v.push_back(l);
        return v;
    }
};