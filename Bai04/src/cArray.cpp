#include "cArray.h"
#include<bits/stdc++.h>
using namespace std;

//Constructor mặc định
cArray::cArray()
{
    n = 0;      //mảng chưa có phần tử nào
    A = NULL;   //chưa cấp phát bộ nhớ
}

//Constructor có tham số đầu vào
cArray::cArray(long long n, long long *A)
{
    this->n = n;
    this->A = new long long[n];     //Cấp phát bộ nhớ
    for (long long i = 0; i < n; i++)
    {
        this->A[i] = A[i];      //sao chép từng phần tử
    }
}

//Constructor sao chép
cArray::cArray(const cArray &C)
{
    n = C.n;
    A = new long long[n];       //Cấp phát bộ nhớ
    for (long long i = 0; i < n; i++)
    {
        A[i] = C.A[i];      //sao chép từng phần tử
    }
}

//Destructor
cArray::~cArray()
{
    delete[] A;     //Giải phóng vùng nhớ động
}

//Hàm nhập
void cArray::Nhap()
{
    cout << "\nNhap so phan tu cua mang: ";
    cin >> n;
    //Mảng có số phần tử > 0
    while (n <= 0)
    {
        cout << "Nhap lai so phan tu cua mang: ";
        cin >> n;
    }
    A = new long long[n];       //Cấp phát bộ nhớ
    cout << "Nhap " << n << " phan tu cua mang: ";
    for (long long i = 0; i < n; i++) cin >> A[i];
}

//Hàm xuất
void cArray::Xuat()
{
    for (long long i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

//Hàm đếm giá trị x có trong mảng
void cArray::DemGiaTri_x(long long x)
{
    long long dem = 0;
    for (long long i = 0; i < n; i++)
        if (A[i] == x) dem++;
    cout << "Trong mang co " << dem << " gia tri " << x << endl;
}

//Hàm kiểm tra xem có phải mảng tăng không
string cArray::KiemTraTang()
{
    for (long long i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i+1]) return "\nDay khong phai la day tang!\n";
    }
    return "\nDay la day tang!\n";
}

//Hàm tìm số lẻ nhỏ nhất có trong mảng
void cArray::TimSoLeNhoNhat()
{
    long long MIN = LLONG_MAX;      //số nguyên lớn nhất của kiểu long long
    long long dem = 0;
    for (long long i = 0; i< n; i++)
    {
        if (A[i] % 2 != 0 && A[i] < MIN)
        {
            MIN = A[i];
            dem++;
        }
    }
    if (dem == 0)   //số giá trị lẻ = 0;
        cout << "\nMang khong co so le!\n";
    else            //số giá trị lẻ > 0
        cout << "\nPhan tu le nho nhat trong mang la: " << MIN << endl;
}

//Hàm kiểm tra xem có phải số nguyên tố không
bool KiemTraSoNguyenTo(long long x)
{
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}


//Hàm tìm số nguyên tố lớn nhất có trong mảng
void cArray::TimSoNguyenToLonNhat()
{
    long long snt = 0;
    for (long long i = 0; i < n; i++)
    {
        if(KiemTraSoNguyenTo(A[i]) && A[i] > snt) snt = A[i];
    }
    if (snt == 0) cout << "\nMang khong co so nguyen to!\n";
    else cout << "\nSo nguyen to lon nhat cua mang la: " << snt << endl;
}

//Hàm sắp xếp mảng tăng dần theo phương phác selection sort
void cArray::SapXepTangDan()
{
    for (int i = 0; i < n - 1; i++)
    {
        long long min = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[min]) min = j;
        }
        swap(A[i], A[min]);
    }
}

//Hàm sắp xếp mảng giảm dần bằng phương pháp selection sort
void cArray::SapXepGiamDan()
{
    for (int i = 0; i < n - 1; i++)
    {
        long long max = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] > A[max]) max = j;
        }
        swap(A[i], A[max]);
    }
}
