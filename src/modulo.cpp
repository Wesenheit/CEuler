#include <vector>
#include <array>
#include <cassert>
#include <cmath>
#include "ProjectEuler.h"
using namespace std;
namespace NumberTheory
{
    type inverse(type a, type n)
    {
        type t=0;
        type nt=1;
        type r=n;
        type nr=a;
        type q;
        while (nr!=0)
        {
            q=r/nr;
            type temp1=r-q*nr;
            type temp2=t-q*nt;
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
    array<type,3> ext_euc(type a, type b)
    {
        type ol_r=a;
        type r=b;
        type ol_s=1;
        type s=0;
        type temp;
        type q;
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
        type bez_t;
        if (b!=0)
        {
            bez_t=(ol_r-ol_s*a)/b;
        }
        else
        {
            bez_t=0;
        }
        array<type,3> wyn={ol_r,ol_s,bez_t};
        return wyn;
    }


    type chin(type M, vector<type> &ytab, vector<type> &ntab)
    {
        assert(ytab.size()==ntab.size());
        vector<type> tab=vector<type>(ytab.size());
        for (int i = 0; i < ytab.size(); i++)
        {
            type Mi=M/ntab[i];
            type gi=ext_euc(ntab[i],Mi)[2];
            tab[i]=Mi*gi;
        }
        type wyn=0;
        for (int i = 0; i < ntab.size(); i++)
        {
            wyn+=tab[i]*ytab[i];
        }
        return (wyn+M) % M;
    }

    type leg_sym(type a, type p)
    {
        type ls=pow(a,(p-1)/2) %p;
        if (ls==p-1)
        {
            return -1;
        }
        else
        {
            return ls;
        }
    }

    type mod_sqrt(type a, type p)
    {
        if (leg_sym(a,p)!= 1)
        {
            return 0;
        }
        else if (a==0)
        {
            return 0;
        }
        else if (p==2)
        {
            return p;
        }
        else if (p%4==3)
        {
            return pow(a,(p+1)/4) %p;
        }


        type s=p-1;
        type e=0;
        while (s%2==0)
        {
            s=s/2;
            e+=1;
        }
        type n=2;
        while (leg_sym(n,p)!=-1)
        {
            n+=1;
        }
        type x=pow(a,(s+1)/2) %p;
        type b=pow(a,s) %p;
        type g=pow(n,s) %p;
        type r=e;
        type gs,t,m;
        while (true)
        {
            t=b;
            m=0;
            for (type m=0;m<r;m++)
            {
                if (t==1)
                {
                    break;
                }
                t=pow(t,2) %p;
            }
            if (m==0)
            {
                return x;
            }
            gs=pow(g,pow(2,r-m-2)) %p;
            g= (gs*gs) %p;
            x=(x*gs)%p;
            b=(b*g)%p;
            r=m;
        }
        
    }
} // namespace NumberTheory
