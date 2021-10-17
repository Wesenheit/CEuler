#include <vector>
#include <array>
using namespace std;
namespace NumberTheory
{
    template <typename T>T inverse(T a, T n)
    {
        T t=0;
        T nt=1;
        T r=n;
        T nr=a;
        T q;
        while (nr!=0)
        {
            q=r/nr;
            T temp1=r-q*nr;
            T temp2=t-q*nt;
            r=nr;
            t=nt;
            nr=temp1;
            nt=temp2;
        }
        if (r>1)
        {
            return 0;
        }
        if (t<0)
        {
            t+=n;
        }
        return t;
    }
    template <typename T>array<T,3> ext_euc(T a, T b)
    {
        T ol_r=a;
        T r=b;
        T ol_s=1;
        T s=0;
        T temp;
        T q;
        while (r!=0)
        {
            q=ol_r/r;
            temp=r;
            r=ol_r-q*r;
            ol_r=temp;
            temp=s;
            s=ol_s-q*s;
            ol_r=temp;
        }
        T bez_t;
        if (b!=0)
        {
            bez_t=(ol_r-ol_s*a)/b;
        }
        else
        {
            bez_t=0;
        }
        array<T,3> wyn={ol_r,ol_s,bez_t};
        return wyn;
    }


    template <typename T>T chin(T M,vector<T> ytab, vector<T> ntab)
    {
        assert(ytab.size()==ntab.size());
        array<T,ytab.size()> tab;
        for (int i = 0; i < ytab.size(); i++)
        {
            T Mi=M/ntab[i];
            T gi=ext_euc(ntab[i],Mi)[2];
            tab[i]=Mi*gi;
        }
        T wyn=0;
        for (int i = 0; i < ntab.size(); i++)
        {
            wyn+=tab[i]*ytab[i];
        }
        return wyn;
    }
} // namespace NumberTheory
