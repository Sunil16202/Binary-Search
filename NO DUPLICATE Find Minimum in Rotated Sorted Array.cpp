//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0; 
        int end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
                return arr[mid];
            }
            else if(arr[end] >= arr[mid]){
                    end = mid -1;
            }
            else if(arr[start] <= arr[mid]){
                    start = mid +1;
            }
        }
        return -1;

    }
};