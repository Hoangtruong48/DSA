#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    do{
        printf("Nhap n =");
        scanf("%d", &n);
    }
    while(n <= 0);
    int temp = 0, n1 = n;
    int m = -1, m1 = 10;
    while(n1){
        temp = temp * 10 + n1 % 10;
        if (n1 % 10 > m){
            m = n1 % 10;
        }
        if (n1 % 10 < m1){
            m1 = n1 % 10;
        }
        n1 /= 10;
    }
    if (temp == n){
        printf("%d la so doi xung \n", n);
    }
    else{
        printf("%d khong la so doi xung \n", n);
    }

    int k = (int)sqrt(n);
    if (k * k == n){
        printf("%d la so chinh phuong", n);
    }
    else{
        printf("%d la so chinh phuong", n);
    }
    bool c = true;
    if (n < 2){
        c = false;
    }
    int i;
    for (i = 2; i <= k; i++){
        if (n % i == 0){
            c = false;
        }
    }
    if (c){
        printf("%d la so nguyen to", n);
    }
    else{
        printf("%d khong la so nguyen to", n);
    }
    printf("Chu so lon nhat la %d", m);
    printf("Chu so nho nhat la %d", m1);

    int n2 = n;
    bool c1 = true;
    bool c2 = true;



    return 0;
}
