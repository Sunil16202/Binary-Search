//https://practice.geeksforgeeks.org/problems/ceil-the-floor/0

#include <bits/stdc++.h>
using namespace std;

int ceilofelement(int arr[], int x, int n){
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
            start = mid +1;
        }
        else if(arr[mid] > x){
            res = mid;
            end = mid -1;
        }

    }
    return res;
}

int floorofelement(int arr[], int x, int n){
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
	cin >> t;
	for(int i=0; i<t; i++){
	    int n;
	    cin >> n;
	    int arr[n];
	    int x;
	    cin >> x;
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    sort(arr,arr+n);
	    int f = floorofelement(arr,x,n);
	    int c = ceilofelement(arr,x,n);
	    if(f == -1){
	        cout<<"Floor doesn't exist"<<endl;
	    }
	    else{
	        cout<<arr[f]<<endl;
	    }
	    
	    if(c==-1){
	        cout<<"Ceil doesn't exist"<<endl;
	    }
	    else{
	        cout<<arr[c]<<endl;
	    }
	}
	return 0;
}