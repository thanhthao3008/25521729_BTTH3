#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc
{
    private:
        long long n;
        double *A;
    public:
        cDaThuc();
        cDaThuc(long long n, double *a);
        ~cDaThuc();
        void Nhap();
        void Xuat() const;
        double TinhGiaTri(double x);
        cDaThuc Cong(const cDaThuc &D);
        cDaThuc Tru(const cDaThuc &D);
};

#endif
