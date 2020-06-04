//https://classroom.codingninjas.com/app/classroom/me/1206/content/18762/offering/177392/problem/1745

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// time complexity = nlog(d)
bool check(int cows, ll position[], int n, ll distance){
	int count = 1;
	ll last_position = position[0];

	for(int i=1; i<n; i++){
		if(position[i] - last_position >= distance){
			last_position = position[i];
			count++;
		}
		if(count == cows){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		int c;
		cin >> n;
		cin >> c;
		ll position[n];
		for(int i=0; i<n; i++){
			cin >> position[i];
		}
		sort(position, position + n);
		ll start = 0;
		ll end = position[n-1] - position[0];

		ll ans = -1;

		while(start <= end){
			ll mid = start + (end - start)/2;
			if(check(c,position,n,mid)){
				ans = mid;
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		cout << ans << endl;


	}

	

	return 0;
}