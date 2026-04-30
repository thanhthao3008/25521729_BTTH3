#include "DSNhanVienSX.h"
using namespace std;

// Nhập danh sách Nhân Viên
void DanhSachNV::Nhap() {
    int n;
    cout << "Nhap so nhan vien(> 0): ";
    cin >> n;
    //số nhân viên dương
    while (n <= 0)
    {
        cout << "Nhap lai so nhan vien (> 0): ";
        cin >> n;
    }
    ds.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

// Xuất danh sách Nhân viên
void DanhSachNV::Xuat() const {
    for (auto nv : ds) {
        nv.Xuat();
    }
}

// Xuất ra Nhân Viên có Lương thấp nhất
void DanhSachNV::LuongThapNhat() const {
    double minLuong = ds[0].TinhLuong();
    for (auto nv : ds) {
        if (nv.TinhLuong() < minLuong)
            minLuong = nv.TinhLuong();
    }
    cout << "\nNhan vien luong thap nhat:\n";
    for (auto nv : ds) {
        if (nv.TinhLuong() == minLuong)
            nv.Xuat();
    }
}

// Tổng lương của các Nhân Viên
double DanhSachNV::TongLuong() const {
    double sum = 0;
    for (auto nv : ds) {
        sum += nv.TinhLuong();
    }
    return sum;
}

// Tìm và xuất nhân viên có tuổi cao nhất (người sinh sớm nhất)
void DanhSachNV::TuoiCaoNhat() const
{
    cNhanVienSX lonTuoiNhat = ds[0];

    // dùng hàm SoSanhTuoi()
    for (int i = 1; i < ds.size(); i++)
    {
        lonTuoiNhat = lonTuoiNhat.SoSanhTuoi(ds[i]);
    }

    cout << "\nNhan vien co tuoi cao nhat:\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].getNgaySinh() == lonTuoiNhat.getNgaySinh())
        {
            ds[i].Xuat();
        }
    }
}

// Sắp xếp danh sách nhân viên theo lương tăng dần
void DanhSachNV::SapXepTangTheoLuong() {
    sort(ds.begin(), ds.end(), [](cNhanVienSX a, cNhanVienSX b) {
        return a.TinhLuong() < b.TinhLuong();
    });
}
