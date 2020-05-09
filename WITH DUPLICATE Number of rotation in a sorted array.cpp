//https://practice.geeksforgeeks.org/problems/rotation/0
#include <iostream>
using namespace std;

int numberofrotation(long arr[], int n){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else if(arr[mid] < arr[end]){
            end = mid;
        }
        else{
            end--;
        }
    }
    return start;

}
int main() {
	//code
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
	   	int n;
	    cin >> n;
	    long arr[n];
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    cout<<numberofrotation(arr,n)<<endl;
	}

	
	return 0;
}