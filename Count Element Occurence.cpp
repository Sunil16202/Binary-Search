//https://www.interviewbit.com/problems/count-element-occurence/

#include <bits/stdc++.h>
using namespace std;

int last(int arr[], int x, int n){
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

int first(int arr[], int x, int n){
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

int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = A[i];
    }
    int f = first(arr,B,n);
    int l = last(arr, B,n);
    if(f != -1 && l!= -1){
        return l-f+1;
    }
    return 0;
}
