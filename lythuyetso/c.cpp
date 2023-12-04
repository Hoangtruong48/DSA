#include <bits/stdc++.h>

using namespace std;
class tivi;
class ngaythang
{
private:
    int ngay, thang, nam;
public:
    void nhap();
    void xuat();
    friend int tong(tivi *a, int n);
};
class hangdientu
{
protected:
    char mahang[30], tenhang[30];
    ngaythang x;
public:
    void nhap();
    void xuat();
};

class tivi:public hangdientu
{
private:
    char kichthuoc[30], tenhangsx[30];
    float giaban;
public:
    void nhap();
    void xuat();
    friend void in(tivi *a, int n);
    friend int tong(tivi *a, int n);
    //friend void in2(int *a, int n);

};

void ngaythang::nhap()
{
    cout << "nhap ngay:";   cin >> ngay;
    cout << "nhap thang:";  cin >> thang;
    cout << "nhap nam";     cin >> nam;
}
void ngaythang::xuat()
{
    cout << ngay << "/" << thang << "/" << nam << endl;
}
void hangdientu::nhap()
{
    cout << "nhap ma hang dien tu:";    fflush(stdin);  gets(mahang);
    cout << "nhap ten hang dt:";        fflush(stdin);  gets(tenhang);
    x.nhap();
};
void hangdientu::xuat()
{
    x.xuat();
    cout << "ma hang dien tu:" << mahang << endl;
    cout << "ten hang       :" << tenhang << endl;
}
void tivi::nhap()
{
    hangdientu::nhap();
    cout << "nhap kich thuoc mh:";     fflush(stdin);   gets(kichthuoc);
    cout << "nhap ten hang:";          fflush(stdin);   gets(tenhangsx);
    cout << "nhap gia ban:";           cin >> giaban;
};
void tivi::xuat()
{
    hangdientu::xuat();
    cout << "kich thuoc man hinh: " << kichthuoc << endl;
    cout << "ten hang sx:"          << tenhangsx << endl;
    cout << "gia ban:" << giaban << endl;
};

void in(tivi *a, int n)
{
    for (int i = 0; i < n; i++){
        if (a[i].giaban > 3000000){
            a[i].xuat();
        }
    }
}
int tong(tivi *a, int n)
{
    int t = 0;
    for (int i = 0; i < n; i++){
        if (a[i].x.nam == 2019){
            t += a[i].giaban;
        }
    }
    return t;
}
//void in2(int *a, int n)
//{
//    for (int i = 0; i < n; i++){
//        if (strcmp(a[i].tenhangsx, "SONY" == 0 )
//            a[i].xuat();
//        }
//    }

int main()
{
    tivi *a;
    int n;
    cout << "n=";
    cin >> n;
    a = new tivi[n];
    for (int i = 0; i < n; i++){
        cout << "nhap thong tin tivi thu" << i+1 << endl;
        a[i].nhap();
    }
    for (int i = 0; i < n; i++){
        cout << "Tivi thu" << i+1 << endl;
        a[i].xuat();
    }
    cout << "------DANH SACH TI VI TREN 3tr la --------" << endl;
    in(a, n);
    cout << "TONG GIA TI VI NAM 2019 la" << tong(a, n) << endl;
    cout << "-----------HANG SONY-------------- " << endl;
//    in2(a,n);
    return 0;
}
