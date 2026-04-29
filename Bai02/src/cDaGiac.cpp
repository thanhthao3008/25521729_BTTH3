#include <bits/stdc++.h>
#include "cDaGiac.h"

using namespace std;

const double eps = 1e-6;    //Định nghĩa một số thực siêu nhỏ để so sánh

// Constructor mặc định
cDaGiac::cDaGiac()
{
    n = 0;          // chưa có đỉnh nào
    A = NULL;       // chưa cấp phát bộ nhớ
}

// Constructor có tham số
cDaGiac::cDaGiac(int n, DIEM *A)
{
    this->n = n;

    // cấp phát mảng động gồm n điểm
    this->A = new DIEM[n];

    // sao chép từng điểm từ mảng truyền vào
    for (int i = 0; i < n; i++)
        this->A[i] = A[i];
}

// Copy constructor
cDaGiac::cDaGiac(const cDaGiac &D)
{
    n = D.n;

    // cấp phát vùng nhớ mới
    A = new DIEM[n];

    // sao chép dữ liệu từ đối tượng D
    for (int i = 0; i < n; i++)
        A[i] = D.A[i];
}

// Destructor
cDaGiac::~cDaGiac()
{
    // giải phóng vùng nhớ động
    delete[] A;
}

//Hàm tính diện tích bằng phương pháp Shoelace
double cDaGiac::TinhDienTich()
{
    double s = 0;

    for (int i = 0; i < n - 1; i++)
    {
        s += A[i].GetX() * A[i + 1].GetY()
           - A[i].GetY() * A[i + 1].GetX();
    }

    // cộng cạnh cuối với đỉnh đầu
    s += A[n - 1].GetX() * A[0].GetY()
       - A[n - 1].GetY() * A[0].GetX();

    return fabs(s) / 2.0;
}

// Hàm nhập đa giác
void cDaGiac::Nhap()
{
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    while (n < 3)
    {
        cout << "Nhap lai so dinh cua da giac: ";
        cin >> n;
    }

    // cấp phát mảng động cho n đỉnh
    A = new DIEM[n];

    // nhập từng đỉnh
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap dinh thu " << i + 1 << ":\n";
        A[i].Nhap();
    }
    if (TinhDienTich() <= 0) {
        cout << "DAY KHONG PHAI LA DA GIAC!";
        exit(0);
    }
}

// Hàm xuất đa giác
void cDaGiac::Xuat()
{
    // xuất từng đỉnh
    for (int i = 0; i < n; i++)
    {
        A[i].Xuat();
    }
}

//Hàm tính chu vi
double cDaGiac::TinhChuVi()
{
    double cv = 0;

    for (int i = 0; i < n - 1; i++)
        cv += A[i].KhoangCach(A[i + 1]);

    // cộng cạnh cuối nối về đỉnh đầu
    cv += A[n - 1].KhoangCach(A[0]);

    return cv;
}

// Hàm tịnh tiến đa giác
void cDaGiac::TinhTien(double dx, double dy)
{
    // tịnh tiến từng đỉnh
    for (int i = 0; i < n; i++)
        A[i].TinhTien(dx, dy);
}

// Hàm quay đa giác
void cDaGiac::Quay(const DIEM &P, double angle)
{
    // quay từng đỉnh quanh điểm P
    for (int i = 0; i < n; i++)
        A[i].Quay(P, angle);
}

// Hàm phóng to đa giác
void cDaGiac::PhongTo(double k)
{
    // phóng to từng đỉnh theo tỉ lệ k
    for (int i = 0; i < n; i++)
        A[i].PhongTo(k);
}

// Hàm thu nhỏ đa giác
void cDaGiac::ThuNho(double k)
{
    // thu nhỏ từng đỉnh theo tỉ lệ k
    for (int i = 0; i < n; i++)
        A[i].ThuNho(k);
}
