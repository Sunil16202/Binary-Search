//https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
#include <iostream>
using namespace std;

int bin_search(int A[], int left, int right, int k)
{
    while(left <= right){
        int mid = left + (right-left)/2;
        if(A[mid] == k){
            return mid;
        }
        else if(k < A[mid]){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;

}

int minindex(int arr[], int n) {
    int start = 0; 
    int end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            return mid;
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

int findelement(int arr[], int n, int x){
    int index = minindex(arr,n);
    int left = bin_search(arr,0,index-1,x);
    int right = bin_search(arr,index,n-1,x);
    if(left != -1){
        return left;
    }
    else if(right != -1){
        return right;
    }
    else{
        return -1;
    }
}
int main() {
	//code
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    int x;
	    cin >> x;
	    cout<<findelement(arr,n,x)<<endl;
	    
	}
	return 0;
}