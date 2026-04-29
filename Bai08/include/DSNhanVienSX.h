#ifndef DANHSACHNV_H
#define DANHSACHNV_H

#include "cNhanVienSX.h"
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class DanhSachNV {
    private:
        vector<cNhanVienSX> ds;
    public:
        // Hàm Nhập danh sách
        void Nhap();
        // Hàm Xuất danh sách
        void Xuat() const;
        // Xuất ra Nhân Viên có lương thấp nhất
        void LuongThapNhat() const;
        // Tính Tổng lương
        double TongLuong() const;
        // Nhân viên có tuổi cao nhất
        void TuoiCaoNhat() const;
        // Sắp xếp nhân viên tăng dần theo lương
        void SapXepTangTheoLuong();
};

#endif
