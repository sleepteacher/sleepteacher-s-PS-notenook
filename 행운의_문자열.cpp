#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    map<char, int> V;
    string a;
    int i,j,k,l;
    cin >> a;
    for(i = 0; i < a.size(); i++) V[a[i]]++;
	for (auto iter = V.begin(); iter != V.end(); iter++) cout << (*iter).first << " " << (*iter).second << "\n";

	return 0;
}