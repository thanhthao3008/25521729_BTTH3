#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "DIEM.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class cTamGiac
{
    private:
        DIEM A;
        DIEM B;
        DIEM C;
    public:
        //Các phương thức thiết lập
        cTamGiac();
        cTamGiac(DIEM A, DIEM B, DIEM C);
        cTamGiac(const cTamGiac &T);

        //Nhập tam giác
        void Nhap();
        //Xuất tam giác
        void Xuat();

        //Kiểm tra có phải tam giác không
        bool KiemTra();

        //Kiểm tra loại tam giác
        string KiemTraLoaiTamGiac();

        //Chu vi
        double TinhChuVi();
        //Diện tích
        double TinhDienTich();

        //Tịnh tiến tam giác theo tỉ lệ (dx, dy)
        void TinhTien(double dx, double dy);

        //Quay tam giác xung quanh điểm P một góc angle
        void Quay(DIEM &P, double angle);

        //Phóng to theo tỉ lệ k
        void PhongTo(double k);

        //Thu nhỏ theo tỉ lệ k
        void ThuNho(double k);
};

#endif
