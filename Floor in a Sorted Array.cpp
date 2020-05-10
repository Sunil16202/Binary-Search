//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array/0
#include <iostream>
using namespace std;

int floorofelement(long arr[], int x, int n){
    int start = 0;
    int end = n-1;
    int res = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == x){
            res = mid;
            return mid;
        }
        else if(arr[mid] < x){
            res = mid;
            start = mid +1;
        }
        else if(arr[mid] > x){
            end = mid -1;
        }

    }
    return res;
}

int main() {
	//code
	int t;
	cin >>t;
	for(int i=0; i<t; i++){
	    int n;
	    int x;
	    cin >>n;
	    cin >> x;
	    long arr[n];
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    cout<<floorofelement(arr,x,n)<<endl;
	}
	return 0;
}