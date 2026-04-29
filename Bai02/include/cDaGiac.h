#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "DIEM.h"

class cDaGiac
{
private:
    int n;      // số lượng đỉnh của đa giác
    DIEM *A;    // mảng động lưu các đỉnh của đa giác

public:
    // Constructor mặc định
    cDaGiac();

    // Constructor có tham số
    cDaGiac(int n, DIEM *A);

    // Copy constructor
    cDaGiac(const cDaGiac &D);

    // Destructor giải phóng vùng nhớ động
    ~cDaGiac();

    //Tính diện tích
    double TinhDienTich();

    // Nhập thông tin đa giác
    void Nhap();

    // Xuất thông tin đa giác
    void Xuat();

    //Tính chu vi
    double TinhChuVi();

    // Tịnh tiến đa giác theo vector (dx, dy)
    void TinhTien(double dx, double dy);

    // Quay đa giác quanh điểm P một góc angle (độ)
    void Quay(const DIEM &P, double angle);

    // Phóng to đa giác theo tỉ lệ k
    void PhongTo(double k);

    // Thu nhỏ đa giác theo tỉ lệ k
    void ThuNho(double k);
};

#endif
