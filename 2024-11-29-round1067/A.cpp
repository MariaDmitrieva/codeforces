#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;
    while (k--){
        int n, y, r;
        cin >> n >> y >>r;

        int disc_red = min(r,n);
        int diff = n- disc_red; 
        int disc_yellow = min(diff, y/2);
        cout << disc_red+disc_yellow << "\n";
    }
    return 0;
}