#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(int A[], int left, int mid, int right){
	int i = left;
	int j = mid;
	int k = 0;

	int temp[right - left + 1];
	ll count = 0;
	while( i< mid && j <= right){
		if(A[i] <= A[j]){
			temp[k] = A[i];
			i++;
			k++;
		}
		else{
			temp[k] = A[j];
			k++;
			j++;
			count = count + mid - i;
		}
	}
	while(i < mid){
		temp[k++] = A[i++];
	}
	while(j <= right){
		temp[k++] = A[j++];
	}

	for(int i=left,k=0; i<=right; i++,k++){
		A[i] = temp[k];
	}
	return count;
}
ll merge_sort(int A[], int left, int right){
	ll count = 0;
	if(right > left){
		int mid = left + (right - left)/2;

		ll countLeft = merge_sort(A,left,mid);
		ll countRight = merge_sort(A,mid+1,right);
		ll  myCount = merge(A,left,mid+1,right);

		return myCount + countLeft + countRight;

	}
	return count;
}
ll solve(int A[], int n){
	ll ans = merge_sort(A,0,n-1);
	return ans;
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
	    cout<<solve(arr,n)<<endl;
	}
	return 0;
}