#include <bits/stdc++.h>
#include "cNhanVienSX.h"
#include "DSNhanVienSX.h"
using namespace std;

int main() {
    DanhSachNV ds;
    ds.Nhap();
    cout << "\nDanh sach nhan vien:\n";
    ds.Xuat();
    ds.LuongThapNhat();
    cout << "\nTong luong: " << ds.TongLuong() << endl;
    ds.TuoiCaoNhat();
    cout << "\nSap xep tang theo luong:\n";
    ds.SapXepTangTheoLuong();
    ds.Xuat();
    return 0;
}


