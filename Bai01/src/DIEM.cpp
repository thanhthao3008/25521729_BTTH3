#include <iostream>
#include <cmath>
#include <string>
#include "DIEM.h"

#define PI 3.1415926535

const double eps = 1e-6; //chọn 1 số siêu nhỏ để so sánh

using namespace std;

//Các hàm thiết lập
DIEM::DIEM(): x(0),y(0){}
DIEM::DIEM(double xx, double yy): x(xx), y(yy){}
DIEM::DIEM(const DIEM &A): x(A.x), y(A.y){}

//Hàm nhập
void DIEM::Nhap()
{
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

//Hàm xuất
void DIEM::Xuat()
{
    cout << "(";
    if (x < eps) cout << 0;
    else cout << x;
    cout << ", ";
    if (y < eps) cout << 0;
    else cout << y;
    cout << ") ";

}

//Hàm tính khoảng cách
double DIEM::KhoangCach(DIEM &P)
{
    double k = pow((x-P.x), 2) + pow((y-P.y), 2);
    return sqrt(k);
}

//Hàm tịnh tiến
void DIEM::TinhTien(double dx, double dy)
{
    x += dx;
    y += dy;
}

//Hàm quay
void DIEM::Quay(DIEM &P, double angle)
{
    double rad = angle*PI/180.0; //đưa về góc radian
    //đưa về hệ trục có tâm tại P
    x -= P.x;
    y -= P.y;
    //Quay
    double xx = x*cos(rad) - y*sin(rad);
    double yy = x*sin(rad) + y*cos(rad);
    //đưa trở lại hệ trục ban đầu
    x = xx + P.x;
    y = yy + P.y;
}

//Hàm phóng to
void DIEM::PhongTo(double k)
{
    x *= k;
    y *= k;
}

//Hàm thu nhỏ
void DIEM::ThuNho(double k)
{
    x /= k;
    y /= k;
}
