#include "cDaThuc.h"
#include <bits/stdc++.h>
using namespace std;

//Constructor mặc định
cDaThuc::cDaThuc()
{
    n = 0;                  //đa thức bậc 0
    A = new double[1];   //đa thức bậc 0 cần 1 hệ số
    A[0] = 0;               //hệ số = 0
}

//Constructor có tham số đầu vào
cDaThuc::cDaThuc(long long n, double *A)
{
    this->n = n;
    this->A = new double[n+1];
    for (int i = 0; i <= n; i++)
        this->A[i] = A[i];
}

//Destructor
cDaThuc::~cDaThuc()
{
    delete[] A;     //giải phóng bộ nhớ
}

void cDaThuc::Nhap()
{
    cout << "\nNhap bac cua da thuc (>=0): ";
    cin >> n;
    //Bậc >= 0
    while (n < 0)
    {
        cout << "\nNhap lai bac cua da thuc (>=0): ";
        cin >> n;
    }
    if (A != NULL) delete[] A;  //xóa cũ để cấp phát mới
    A = new double[n+1];        //cấp phát bộ nhớ, bậc n có n+1 phần tử
    //Nhập n+1 hệ số
    for (int i = 0; i <= n; i++)
    {
        cout << "Nhap he so bac " << n - i << ": ";
        cin >> A[i];
    }
}

void cDaThuc::Xuat() const
{
    bool check = false; // kiểm tra đã in số hạng đầu chưa

    for (int i = 0; i <= n; i++)
    {
        if (A[i] == 0) continue;    //không in số 0

        int bac = n - i;

        // dấu +
        if (check && A[i] > 0)
            cout << "+";

        // hệ số
        if (bac == 0)
        {
            cout << A[i];
        }
        else
        {
            if (A[i] == -1)
                cout << "-";
            else if (A[i] != 1)
                cout << A[i];

            if (bac == 1)
                cout << "x";
            else
                cout << "x^" << bac;
        }
        check = true;   //đã có số hạng đầu
    }

    // nếu toàn bộ hệ số đều bằng 0
    if (!check)
        cout << 0;
    cout << endl;
}

//Tính giá trị đa thức khi có x
double cDaThuc::TinhGiaTri(double x)
{
    double kq = 0;
    for (int i = 0; i <= n; i++)
    {
        kq += A[i] * pow(x, (n-i));
    }
    return kq;
}

//Cộng 2 đa thức
cDaThuc cDaThuc::Cong(const cDaThuc& D)
{
    cDaThuc kq;
    kq.n = max(n, D.n);
    if (kq.A != NULL) delete[] kq.A;
    kq.A = new double[kq.n + 1];

    // khởi tạo 0
    for (int i = 0; i <= kq.n; i++)
        kq.A[i] = 0;

    // cộng đa thức thứ nhất
    for (int i = 0; i <= n; i++)
    {
        kq.A[kq.n - n + i] += A[i];
    }

    // cộng đa thức thứ hai
    for (int i = 0; i <= D.n; i++)
    {
        kq.A[kq.n - D.n + i] += D.A[i];
    }
    return kq;
}

//Trừ 2 đa thức
cDaThuc cDaThuc::Tru(const cDaThuc& D)
{
    cDaThuc kq;
    kq.n = max(n, D.n);
    if (kq.A != NULL) delete[] kq.A;
    kq.A = new double[kq.n + 1];

    // khởi tạo 0
    for (int i = 0; i <= kq.n; i++)
        kq.A[i] = 0;

    // cộng đa thức thứ nhất
    for (int i = 0; i <= n; i++)
    {
        kq.A[kq.n - n + i] += A[i];
    }

    // trừ đa thức thứ hai
    for (int i = 0; i <= D.n; i++)
    {
        kq.A[kq.n - D.n + i] -= D.A[i];
    }
    return kq;
}
