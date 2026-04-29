#include "cArray.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Dùng phương thức thiết lập có tham số đầu vào
    long long a[4] = {1, 2, 3, 4};
    cArray DaySo(4, a);
    cout << "Mang tao tu constructor co tham so dau vao: ";
    DaySo.Xuat();

    //Khởi tạo đối tượng
    cArray Arr;

    //Nhập danh sách mảng
    Arr.Nhap();

    //Xuất danh sách mảng
    cout << "Cac phan tu trong mang vua nhap la: ";
    Arr.Xuat();

    //Đếm số lần xuất hiện
    long long x;
    cout << "\nNhap gia tri can dem: ";
    cin >> x;
    Arr.DemGiaTri_x(x);

    //Kiểm tra xem có phải mảng tăng không
    cout << Arr.KiemTraTang();

    //Tìm số lẻ nhỏ nhất có trong mảng
    Arr.TimSoLeNhoNhat();

    //Tìm số nguyên tố lớn nhất trong mảng
    Arr.TimSoNguyenToLonNhat();

    //Sắp xếp mảng theo thứ tự tăng dần
    Arr.SapXepTangDan();
    cout << "\nMang sau khi sap xep tang dan: ";
    Arr.Xuat();

    //Sắp xếp mảng theo thứ tự giảm dần
    Arr.SapXepGiamDan();
    cout << "\nMang sau khi sap xep giam dan: ";
    Arr.Xuat();
    return 0;
}
