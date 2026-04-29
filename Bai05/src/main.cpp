#include <bits/stdc++.h>
#include "cDaThuc.h"

using namespace std;

int main()
{
    // Constructor có tham số đầu vào
    // P(x) = 2x^2 + 3x + 1
    double heso[] = {2, 3, 1};

    cDaThuc P(2, heso);

    cout << "Da thuc P(x): ";
    P.Xuat();

    // Nhập đa thức Q từ bàn phím
    cDaThuc Q;

    cout << "\nNhap da thuc Q(x):";
    Q.Nhap();

    cout << "\nDa thuc Q(x): ";
    Q.Xuat();

    // Tính giá trị đa thức tại x
    double x;
    cout << "\nNhap gia tri x can tinh: ";
    cin >> x;
    cout << "\nP(" << x << ") = " << P.TinhGiaTri(x) << endl;
    cout << "Q(" << x << ") = " << Q.TinhGiaTri(x) << endl;

    // Cộng hai đa thức
    cDaThuc Tong = P.Cong(Q);
    cout << "\nP(x) + Q(x) = ";
    Tong.Xuat();

    // Trừ hai đa thức
    cDaThuc Hieu = P.Tru(Q);
    cout << "P(x) - Q(x) = ";
    Hieu.Xuat();
    return 0;
}
