#include <bits/stdc++.h>
#include "DIEM.h"
#include "cDaGiac.h"

using namespace std;

int main()
{
    // Phương thức thiết lập có tham số đầu vào
    DIEM ds[4];

    ds[0] = DIEM(1, 2);
    ds[1] = DIEM(4, 2);
    ds[2] = DIEM(5, 6);
    ds[3] = DIEM(2, 7);

    cDaGiac dagiac(4, ds);

    cout << "Da giac duoc tao boi constructor:\n";
    dagiac.Xuat();

    // Nhập xuất đa giác
    cDaGiac DG;

    cout << "\n\nNhap thong tin da giac:\n";
    DG.Nhap();

    cout << "\nCac dinh cua da giac vua nhap la:\n";
    DG.Xuat();

    //Chu vi đa giác
    cout << "\nChu vi: " << DG.TinhChuVi();

    //Diện tích đa giac
    cout << "\nDien tich: " << DG.TinhDienTich();

    // Tịnh tiến đa giác
    double dx, dy;
    cout << "\n\nNhap vector tinh tien (dx, dy): ";
    cin >> dx >> dy;

    DG.TinhTien(dx, dy);

    cout << "Da giac sau khi tinh tien:\n";
    DG.Xuat();

    // Quay đa giác
    double angle;
    DIEM P;

    cout << "\n\nNhap diem tam quay:\n";
    P.Nhap();

    cout << "Nhap goc quay (do): ";
    cin >> angle;

    DG.Quay(P, angle);

    cout << "Da giac sau khi quay quanh diem ";
    P.Xuat();
    cout << " la:\n";
    DG.Xuat();

    // Phóng to đa giác
    double k;

    cout << "\n\nNhap ti le phong to: ";
    cin >> k;

    //Không thể phóng to với tỉ lệ không dương
    if(k <= 0){
        cout << "Ti le khong hop le!" << endl;
    }
    else {
        DG.PhongTo(k);
        cout << "Da giac sau khi phong to:\n";
        DG.Xuat();
    }

    // Thu nhỏ đa giác
    cout << "\n\nNhap ti le thu nho: ";
    cin >> k;

    //Không thể thu nhỏ với tỉ lệ không dương
    if(k <= 0){
        cout << "Ti le khong hop le!" << endl;
    }
    else
    {
        DG.ThuNho(k);
        cout << "Da giac sau khi thu nho:\n";
        DG.Xuat();
    }


    return 0;
}
