#ifndef CARRAY_H
#define CARRAY_H
#include<bits/stdc++.h>
using namespace std;

class cArray
{
    private:
        long long n;    //số phàn tử của mảng
        long long *A;   //Mảng động lưu các giá trị nguyên
    public:
        //Constructor mặc định
        cArray();

        //Constructor có tham số đầu vào
        cArray(long long n, long long *A);

        //Constructor sao chép
        cArray(const cArray &C);

        //Destructor
        ~cArray();

        //Nhập mảng
        void Nhap();

        //Xuất mảng
        void Xuat();

        //Đếm giá trị x có trong mảng
        void DemGiaTri_x(long long x);

        //Kiểm tra xem có phải mảng tăng không
        string KiemTraTang();

        //Tìm số lẻ nhỏ nhất có trong mảng
        void TimSoLeNhoNhat();

        //Tìm số nguyên tố lớn nhất trong mảng
        void TimSoNguyenToLonNhat();

        //Sắp xếp mảng theo thứ tự tăng dần
        void SapXepTangDan();

        //Sắp xếp mảng theo thứ tự giảm dần
        void SapXepGiamDan();
};

#endif
