// Increasing Array
#include <iostream>
#include <vector>
#define ll long long
#define loop(i, n) for(int i=0; i<n; i++)
using namespace std;
bool sorted(vector<int> &v, int n){
	loop(i, n-1){
		if(v[i] > v[i+1])
			return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	loop(i, n)
		cin >> v[i];
	if(!sorted(v, n)){
		ll minCost = 0;
		ll mini = v[0];
		for(int i=1; i<n; i++) {
			if(v[i] <= mini)
				minCost += mini - v[i];
			else
				mini = v[i];
		}
		cout << minCost << endl;
	}
	else
		cout << 0 << endl;

}