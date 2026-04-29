#ifndef DIEM_H
#define DIEM_H
#include <bits/stdc++.h>

class DIEM
{
    private:
        double x; //Hoành độ
        double y; //Tung độ
    public:
        // Constructor mặc định
        DIEM();
        // Constructor có tham số
        DIEM(double x, double y);
        // Copy constructor
        DIEM(const DIEM &A);

        //Nhập điểm
        void Nhap();
        //Xuất điểm
        void Xuat();

        //Lấy giá trị x, y
        double GetX();
        double GetY();

        //Tính khoảng cách giữa 2 điểm
        double KhoangCach(const DIEM &P);

        //Tịnh tiến 1 điểm theo tỉ lệ (dx, dy)
        void TinhTien(double dx, double dy);

        //Quay 1 điểm xung quanh điểm P một góc angle
        void Quay(const DIEM &P, double angle);

        //Phóng to theo tỉ lệ k
        void PhongTo(double k);

        //Thu nhỏ theo tỉ lệ k
        void ThuNho(double k);
};

#endif
