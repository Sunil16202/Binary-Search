//https://www.interviewbit.com/problems/find-a-peak-element/
int Solution::solve(vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid > 0 && mid < n -1){
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                    return arr[mid];
                }
                else if(arr[mid -1] > arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else if(mid == 0){
                if(arr[mid] > arr[mid+1]){
                    return arr[0];
                }
                else{
                    return arr[1];
                }
            }
            else if(mid == n -1){
                if(arr[n-1] > arr[n-2]){
                    return arr[n-1];
                }              
                else{
                    return arr[n-2];
                }
            }
        }
        return -1;
}
