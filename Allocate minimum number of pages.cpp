//https://www.interviewbit.com/problems/allocate-books/
#include <bits/stdc++.h>
using namespace std;

bool isvalid(int arr[], int n, int k, int mx){
    int student = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > mx){
            return false;
        }
        sum = sum + arr[i];
        if(sum > mx){
            student++;
            sum = arr[i];
        }
    }
    if(student > k){
        return false;
    }
    return true;
}

int Solution::books(vector<int> &arr, int k) {
    int n = arr.size();
    int temparr[n];
    for(int i=0; i<n; i++){
        temparr[i] = arr[i];
    }
    if(n < k){
        return -1;
    }
    long sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int start = 0;
    int end = sum;
    int result = INT_MAX;
    
    while(end >= start){
        int mid = start + (end - start)/2;
        if(isvalid(temparr,n,k,mid) == true){
            result = min(result,mid);
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    return result;
}
