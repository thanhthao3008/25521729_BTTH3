#include <iostream>
#include <cmath>
#include <string>
#include "cTamGiac.h"

const double eps = 1e-6; //chọn 1 số siêu nhỏ để so sánh

using namespace std;

//Hàm thiết lập
cTamGiac::cTamGiac(){}
cTamGiac::cTamGiac(DIEM A, DIEM B, DIEM C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}
cTamGiac::cTamGiac(const cTamGiac &T)
{
    this->A = T.A;
    this->B = T.B;
    this->C = T.C;
}

//Hàm kiểm tra có phải tam giác không
bool cTamGiac::KiemTra()
{
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0; //Không phải
    return 1; //Phải
}

//Hàm nhập
void cTamGiac::Nhap()
{
    cout << "Nhap diem A cua tam giac ABC:\n";
    A.Nhap();
    cout << "Nhap diem B cua tam giac ABC:\n";
    B.Nhap();
    cout << "Nhap diem C cua tam giac ABC:\n";
    C.Nhap();
    if (KiemTra() == 1) return;
    else
    {
        cout << "DAY KHONG PHAI LA TAM GIAC!";
        exit(1); //Không phải tam giác thì dừng chương trình
    }
}

//Hàm xuất
void cTamGiac::Xuat()
{
    A.Xuat();
    B.Xuat();
    C.Xuat();
    cout << endl;
}

//Kiểm tra 2 giá trị bằng nhau
bool BangNhau(double a, double b)
{
    return (fabs(a-b) < eps);
}

//Hàm kiểm tra loại tam giác
string cTamGiac::KiemTraLoaiTamGiac()
{
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    if (BangNhau(a, b))
    {
        if (BangNhau(b, c)) return "Day la tam giac deu.";
        else if (BangNhau(a*a + b*b, c*c)) return "Day la tam giac vuong can tai diem C.";
        return "Day la tam giac can tai diem C.";
    }
    else if (BangNhau(b, c))
    {
        if (BangNhau(a*a, b*b + c*c)) return "Day la tam giac vuong can tai diem A.";
        return "Day la tam giac can tai diem A.";
    }
    else if (BangNhau(a, c))
    {
        if (BangNhau(b*b, a*a + c*c)) return "Day la tam giac vuong can tai diem B.";
        return "Day la tam giac can tai diem B.";
    }
    else if (BangNhau(a*a + b*b, c*c)) return "Day la tam giac vuong tai diem C.";
    else if (BangNhau(a*a, b*b + c*c)) return "Day la tam giac vuong tai diem A.";
    else if (BangNhau(b*b, a*a + c*c)) return "Day la tam giac vuong tai diem B.";
    else return "Day la tam giac binh thuong.";
}

//Hàm tính chu vi
double cTamGiac::TinhChuVi()
{
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return a+b+c;
}

//Hàm tính diện tích
double cTamGiac::TinhDienTich()
{
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//Hàm tịnh tiến tam giác
void cTamGiac::TinhTien(double dx, double dy)
{
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

//Hàm quay tam giác
void cTamGiac::Quay(DIEM &P, double angle)
{
    A.Quay(P, angle);
    B.Quay(P, angle);
    C.Quay(P, angle);
}

//Hàm phóng to tam giác
void cTamGiac::PhongTo(double k)
{
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}

//Hàm thu nhỏ tam giác
void cTamGiac::ThuNho(double k)
{
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}


