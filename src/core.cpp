#include <cmath>
#include <iostream>
#include <list>
#include <array>
#include <vector>
using namespace std;
namespace NumberTheory
{   
    template<typename T,size_t N>
    array<T,N> sito()
    {
        array<T,N> tab;
        tab[0]=1;
        tab[1]=1;
        for(int i = 2; i < N+1; i++)
        {
            tab[i]=i;
        }
        for (int i = 4; i < N+1; i+=2)
        {
            tab[i]=2;
        }
        for (int i = 3; i < sqrt(N); i++)
        {
            if (tab[i]==i)
            {
                for (int j = i*i; j < N+1; j+=i)
                {
                    if (tab[j]==j)
                    {
                        tab[j]=i;
                    }
                    
                }
                
            }
            
        }
        return tab;
        
    }
    void hello()
    {
        std::cout<<"test"<<std::endl;
    }

    template<typename T,typename S>
    vector<T> primes(S u, T* tab)
    {
        vector<T> primes;
        while (u>1)
        {
            if (primes[primes.size()-1]==tab[u])
            {
                u/=tab[u];
            }
            else
            {
                primes.insert(tab[u]);
                u/=tab[u];
            }
        }
        return primes;
    }
    
    template <typename T,typename S> S tot(S x, T* tab)
    {
        S wyn=x;
        vector<T> temp =primes<T,S>(x,tab);
        if (x==0)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < temp.size(); i++)
            {
                wyn*=(1-1/temp[i]);
            }
            
        }
        delete temp;
        return (S) floor(wyn);
    }
    template <typename T> T nwd (T a,T b)
    {
        T c;
        while (b>0)
        {
            c=a%b;
            a=b;
            b=c;

        }
        return a;
    }
} 