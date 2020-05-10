//https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/
class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        char res = ' ';
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == x){
                start = mid + 1;
            }
            else if(arr[mid] < x){
                start = mid +1;
            }
            else if(arr[mid] > x){
                res = arr[mid];
                end = mid -1;
            }
        }
        if(res == ' '){
            return arr[0];
        }
     return res;  
    }
};