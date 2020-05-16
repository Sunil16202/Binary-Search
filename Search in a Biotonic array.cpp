#include <iostream>
using namespace std;

int ascendingBinarySearch(int arr[], int low,int high, int key){ 
   while (low <= high) 
   { 
       int mid = low + (high - low) / 2; 
       if (arr[mid] == key) 
           return mid; 
       if (arr[mid] > key) 
           high = mid - 1; 
       else
           low = mid + 1; 
   } 
    return -1; 
} 
  
// Function for binary search in descending part of array 
int descendingBinarySearch(int arr[], int low,  
                            int high, int key) 
{ 
   while (low <= high) 
   { 
       int mid = low + (high - low) / 2; 
       if (arr[mid] == key) 
           return mid; 
       if (arr[mid] < key) 
           high = mid - 1; 
       else
           low = mid + 1; 
   } 
    return -1; 
} 


int peakelement(int arr[], int n){
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
int searchinbio(int arr[], int n, int x){
    int peak = peakelement(arr, n);
    if(peak == -1){
        return -1;
    }
    int left = ascendingBinarySearch(arr,0,peak-1,x);
    int right = descendingBinarySearch(arr,peak,n-1,x);
    if(left != -1){
        return left;
    }
    if(right != -1){
        return right;
    }
    if(left==-1 && right == -1){
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
      int ans = searchinbio(arr,n,x);
      cout<<ans<<endl;
  }
  return 0;
}