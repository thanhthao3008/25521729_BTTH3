#ifndef DIEM_H
#define DIEM_H
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class DIEM
{
    private:
        double x; //Hoành độ
        double y; //Tung độ
    public:
        //Các phương thức thiết lập
        DIEM();
        DIEM(double x, double y);
        DIEM(const DIEM &A);
        //Nhập điểm
        void Nhap();
        //Xuất điểm
        void Xuat();

        //Tính khoảng cách giữa 2 điểm
        double KhoangCach(DIEM &P);

        //Tịnh tiến 1 điểm theo tỉ lệ (dx, dy)
        void TinhTien(double dx, double dy);

        //Quay 1 điểm xung quanh điểm P một góc angle
        void Quay(DIEM &P, double angle);

        //Phóng to theo tỉ lệ k
        void PhongTo(double k);

        //Thu nhỏ theo tỉ lệ k
        void ThuNho(double k);
};

#endif
