#include <bits/stdc++.h>
using namespace std;

int demsoduong(float *a, int n)
{
    if (n == 0)
        return 0;
    if (n == 1 && a[n] > 0)
        return 2 + demsoduong(a, n - 1);
    else return 1 + demsoduong(a, n - 1);
    if (a[n] > 0)
        return 1 + demsoduong(a, n - 1);
    else return demsoduong(a, n - 1);
}
void hienthi(float *a, int n){
    cout << a[n] << " ";
    if (n == 0)
        return;
    else return hienthi(a, n - 1);
}

float tongsoduong(float *a, int n)
{
    float b = 0;
    for (int i = 0; i <= n; i++){
        if (a[i] > 0)
            b += a[i];
    }
    return b;
}
int main()
{
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    float a[11] = {10001.1, 10000.2, 10000.3, 10000.3, 10000.4, 10000.4, 10000.4,10000.4, 10000.5, 10000.6, 10000.8};
    cout << "co tong cac so duong la:" << demsoduong(a, 10) << endl;
    cout << "-----MANG----" << endl;
    hienthi(a, 10);
    cout << fixed << setprecision(20);
    cout << endl;
    if (demsoduong(a, 10) == 0)
        cout << "Khong co so am";
    else cout << "TBC cac so duong trong mang la:" << tongsoduong(a, 10) / demsoduong(a, 10) << endl;
    return 0;
}


