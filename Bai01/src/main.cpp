#include <iostream>
#include <cmath>
#include <string>
#include "DIEM.h"
#include "cTamGiac.h"
using namespace std;

int main()
{
    //Phương thức thiết lập có tham số đầu vào
    DIEM A(1, 2);
    DIEM B(2, 5);
    DIEM C(-3, 10);
    cTamGiac tamgiac(A, B, C);
    cout << "Tam giac ABC duoc tao boi constructor co toa do la:\n";
    tamgiac.Xuat();
    if (!tamgiac.KiemTra()) cout << "khong phai tam giac!";

    //Nhập xuất tam giác ABC
    cTamGiac ABC;
    cout << "\nNhap toa do cac diem cua tam giac!\n";
    ABC.Nhap();
    cout << "\nToa do tam giac ABC vua nhap la: ";
    ABC.Xuat();

    //Kiểm tra loại tam giác
    cout << ABC.KiemTraLoaiTamGiac();

    //Tính chu vi
    cout << "\nChu vi: " << ABC.TinhChuVi() << endl;

    //Tính diện tích
    cout << "Dien tich: " << ABC.TinhDienTich() << endl;

    //Tịnh tiến tam giác
    double dx, dy;
    cout << "\nNhap vector tinh tien (dx, dy): ";
    cin >> dx >> dy;
    ABC.TinhTien(dx, dy);
    cout << "Tam giac sau khi tinh tien: " << endl;
    ABC.Xuat();

    //Quay tam giác
    double angle;
    DIEM P;
    cout << "\nNhap diem tam giac quay:\n";
    P.Nhap();
    cout << "Nhap goc quay (do): ";
    cin >> angle;
    ABC.Quay(P, angle);
    cout << "Tam giac sau khi quay quanh diem ";
    P.Xuat();
    cout << "co toa do la:\n";
    ABC.Xuat();

    //Phóng to tam giác
    double k;
    cout << "\nNhap ti le phong to: ";
    cin >> k;
    //Không thể phóng to với tỉ lệ âm
    if(k <= 0){
        cout << "Ti le khong hop le!\n" << endl;
    }
    else {
        ABC.PhongTo(k);
        cout << "Tam giac sau khi phong to: " << endl;
        ABC.Xuat();
    }

    //Thu nhỏ tam giác
    cout << "\nNhap ti le thu nho: ";
    cin >> k;
    //Không thể thu nhỏ với tỉ lệ âm
    if(k <= 0){
        cout << "Ti le khong hop le!\n" << endl;
    }
    else {
        ABC.ThuNho(k);
        cout << "Tam giac sau khi thu nho: " << endl;
        ABC.Xuat();
    }
    return 0;
}
