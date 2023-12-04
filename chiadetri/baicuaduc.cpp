#include <iostream>
#include <time.h> //for random number in array
#include <stdlib.h> //for using srand() func
#include <string>
#include <vector>

using namespace std;
/**-----------------------------FUNC SU DUNG TRONG BAI 1-------------------------------*/
/*If return = -1 -> khong co gia tri nao > k*/
int devideAndConquer(int *a, int left, int right, int k)
{
    if(left == right)
    {
        if(a[left] <= k) return -1; /*Khong co so nguyen nao trong a > k*/
        return a[left];
    }
    int mid = (left + right) /2;
    int leftMin = devideAndConquer(a, left, mid, k);
    int rightMin = devideAndConquer(a, mid + 1, right, k);
    if(leftMin == -1 && rightMin == -1) return -1;
    else if(leftMin == -1) return rightMin;
    else if(rightMin == -1) return leftMin;
    else return leftMin < rightMin ? leftMin : rightMin;
}
/**-----------------------------END BAI 1-------------------------------*/


/**-----------------------------FUNC SU DUNG TRONG BAI 2-------------------------------*/
struct Lop
{
    string maLop;
    int soHocSinh;
    int soHocSinhNu;
};

Lop initializeLop(string maLop, int soHocSinh, int soHocSinhNu)
{
    Lop res;
    res.maLop = maLop;
    res.soHocSinh = soHocSinh;
    res.soHocSinhNu = soHocSinhNu;
    return res;
}

int greedy(vector<Lop> x, int n)
{
    int size_x = x.size();
    int cnt = 0, i = 0;
    while(i < size_x && n > 0)
    {
        cnt++;
        n -= x[i].soHocSinh;
        i++;
    }
    if(i >= size_x && n >= 0) return -1;
    return cnt;
}

vector<Lop> dynamicProgramming(vector<Lop> x, int k)
{
    int size_x = x.size();
    int dp[size_x + 1][k+1];
    for(int i = 0; i <= size_x; i++) dp[i][0] = 0;
    for(int i = 0; i <= k; i++) dp[0][i] = 0;

    for(int i = 1; i <= size_x; i++)
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int maxWith = 0;
            if(j >= x[i-1].soHocSinh)
            {
                maxWith = dp[i-1][j - x[i-1].soHocSinh] + x[i-1].soHocSinhNu;
            }
            dp[i][j] = dp[i][j] > maxWith ? dp[i][j] : maxWith;
        }

    vector<Lop> res;
    while(size_x != 0)
    {
        if(dp[size_x][k] != dp[size_x - 1][k])
        {
            res.push_back(x[size_x-1]);
            k -= x[size_x - 1].soHocSinh;
        }
        size_x--;
    }
    return res;
}

bool boyerMooreHorspol(string s, string p)
{
    int size_s = s.size(), size_p = p.size();
    int i = size_p;
    while(i <= size_s)
    {
        int x = size_p - 1, j = i - 1;
        while(s[j] == p[x])
        {
            x--;
            j--;
        }
        if(x < 0) return true;
        int idx = -1;
        for(int q = x - 1; q >= 0; q--)
        {
            if(p[q] == s[j])
            {
                idx = q;
                break;
            }
        }
        if(idx == -1) i += size_p;
        else i += (x - idx);
    }
    return false;
}
/**-----------------------------END BAI 2-------------------------------*/


/**-----------------------------FUNC SU DUNG TRONG BAI 3-------------------------------*/
struct SanPham
{
    string maSP;
    string tenSP;
    int khoiLuong;
    int giaTri;
};

SanPham initializeSanPham(string ma, string ten, int khoiLuong, int giaTri)
{
    SanPham res;
    res.maSP = ma;
    res.tenSP = ten;
    res.khoiLuong = khoiLuong;
    res.giaTri = giaTri;
    return res;
}
/**-----------------------------END BAI 3-------------------------------*/
int findPos(vector<SanPham> x, SanPham newPro)
{
    int left = 0, right = x.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x[mid].tenSP > newPro.tenSP) right = mid - 1;
        else left = mid +1;
    }
    return left;
}

int longestCommonSubstring(string s, string p)
{
    int size_s = s.size(), size_p = p.size();
    int dp[size_s + 1][size_p + 1];

    for(int i = 0; i <= size_s; i++) dp[i][0] = 0;
    for(int i = 0; i <= size_p; i++) dp[0][i] = 0;
    for(int i = 1; i <= size_s; i++)
    {
        for(int j = 1; j <= size_p; j++)
        {
            if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    return dp[size_s][size_p];
}

bool z_algo(string s, string p)
{
    string newString = p + "#" + s;
    int newSize = newString.size(), low = 0, high = 0;
    int z[newSize];
    z[0] = -1;
    for(int i = 1; i < newSize; i++)
    {
        if(i > high) {
            low = high = i;
            while(high < newSize && newString[high - low] == newString[high]) high++;
            z[i] = high - low;
            high--;
        }
        else if(z[i - low] == high - i + 1) z[i] = z[i - low];
        else {
            low = i;
            while(high < newSize && newString[high - low] == newString[high]) high++;
            z[i] = high - low;
            high--;
        }
    }
    int pSize = p.size();
    for(int i: z) if(i == pSize) return true;
    return false;
}

string checkContainByID(vector<SanPham> x, string ma)
{
    for(const auto &it: x) if(it.maSP == ma) return it.tenSP;
    return "";
}

bool checkContainByName(vector<SanPham> x, string name)
{
    for(const auto &it: x) if(z_algo(it.tenSP, name)) return true;
    return false;
}

int main()
{
    /**------------------------------------------BAI 1---------------------------------------------*/
    /*
    int nSize = 20;
    int a[nSize];
    srand(time(NULL));
    for(auto &it: a) it = rand() % nSize;
    for(auto it: a) cout << it << " ";
    cout << "\n";
    int k;
    cin >> k;
    int gre = devideAndConquer(a, 0, nSize - 1, k);
    if(gre != -1)
        cout << "closest greater: " << gre << endl;
    else cout << "hehehehehhehehe\n";
    */

    /**------------------------------------------BAI 2---------------------------------------------*/
    /*
    vector<Lop> d;
    d.push_back(initializeLop("L001", 75, 30));
    d.push_back(initializeLop("L002", 63, 43));
    d.push_back(initializeLop("L003", 57, 14));
    d.push_back(initializeLop("L004it", 48, 23));
    d.push_back(initializeLop("L005", 39, 15));
    d.push_back(initializeLop("L006", 24, 0));
    d.push_back(initializeLop("L007", 19, 2));

    int n, k;
    n = 133;
    k = 300;


    int res = greedy(d, n);
    if(res == -1) cout << "Lay tat ca lop trong d cung khong dc so hoc sinh > n\n";
    else cout << "can it nhat " << res << " lop trong d\n";

    cout << "\nCan lay cac lop sau de so hoc sinh nu max:\n";
    vector<Lop> dp = dynamicProgramming(d, k);
    for(auto it: dp) {
        cout << it.maLop << ", " << it.soHocSinh << ", " << it.soHocSinhNu << endl;
    }

    cout << "\nCac lop hoc phan nganh cntt:\n";
    for(auto it: d)
    {
        if(boyerMooreHorspol(it.maLop, "it")) cout << it.maLop << ", " << it.soHocSinh << ", " << it.soHocSinhNu << endl;
    }

    */

    /**------------------------------------------BAI 3---------------------------------------------*/
    vector<SanPham> d;
    d.push_back(initializeSanPham("SP0011", "ApplGeare", 2, 3));
    d.push_back(initializeSanPham("SP0022", "Btivihehe", 10, 5));
    d.push_back(initializeSanPham("SP0023", "Chehetivi", 10, 5));
    d.push_back(initializeSanPham("SP0024", "Dtibanavi", 10, 5));
    d.push_back(initializeSanPham("SP0033", "DCoconut", 1, 2));
    d.push_back(initializeSanPham("SP0044", "Eabcdefghikhhehehelmjkfdsdf", 4, 6));
    d.push_back(initializeSanPham("SP0055", "FElectronic Gear", 2, 10));
    d.push_back(initializeSanPham("SP0066", "GFly camera", 6, 1));
    d.push_back(initializeSanPham("SP0088", "Habcdefghikhlmjkfdsdf", 3, 5));

    SanPham newProduct = initializeSanPham("SP007", "Banana", 10, 2);
    cout << "\nVi tri co the chen: " << findPos(d, newProduct) << endl;

    //check d contain SP0088
    string name = checkContainByID(d, "SP0088");
    if(name == ""){
        cout << "\nkhong co ma SP0088\n";
    }
    else {
    cout << "\nSan pham co ma SP0088 giong voi nhung san pham:\n";
    for(const auto &it: d) {
        if(longestCommonSubstring(name, it.tenSP) >= 10) cout << it.maSP << ", " << it.tenSP << ", " << it.khoiLuong << it.giaTri << endl;
    }
    }
    if(checkContainByName(d, "tivi")) cout << "\nTrong d co tivi\n";
    else cout << "\ntrong d khong co tivi\n";
    return 0;
}