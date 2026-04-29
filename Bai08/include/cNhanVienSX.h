#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H
#include <iostream>
#include <string>
using namespace std;

class cNhanVienSX {
    private:
        string maNV;
        string hoTen;
        string ngaySinh;
        int soSanPham;
        double donGia;
    public:
        // Constructor
        cNhanVienSX();
        cNhanVienSX(string, string, string, int, double);

        // Nhập / Xuất
        void Nhap();
        void Xuat() const;

        // Getter
        string getMaNV() const;
        string getHoTen() const;
        string getNgaySinh() const;
        int getSoSanPham() const;
        double getDonGia() const;

        // Setter
        void setMaNV(string);
        void setHoTen(string);
        void setNgaySinh(string);
        void setSoSanPham(int);
        void setDonGia(double);

        // Tính lương
        double TinhLuong() const;

        // Tính tuổi (lấy năm sinh)
        cNhanVienSX SoSanhTuoi(const cNhanVienSX &NV);
};

#endif

