#include<iostream>
#include<algorithm>
using namespace std;
bool canMakeBouqets(int bloomDay[], int n, int m, int k, int day) {
  int bouquets =0;
int flower = 0;
for (int i=0; i<n; i++){
if(bloomDay[i]<=day){
flowers++;
if (flowers ==k){
bouquets++;
flowers=0;
}
}else{
flowers =0;
}
}
return bouquets>=m;
}
int mainDays(int bloomDay[], int n, int m, int k,){
  long long required= 1LL*m*k;
if(required>n){
return-1;
}
int low= *min_element(bloomDay, bloomDay +n);
int high =*max_element(bloomDay, bloomDay +n);
int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMakeBouquets(bloomDay, n, m, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {

    int bloomDay[] = {1, 10, 3, 10, 2};

    int n = 5;
    int m = 3;
    int k = 1;

    cout << "Minimum days: "
         << minDays(bloomDay, n, m, k)
         << endl;

    return 0;
}
