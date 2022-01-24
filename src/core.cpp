#include <cmath>
#include <iostream>
#include <vector>
#include "ProjectEuler.h"

using namespace std;
namespace NumberTheory
{   
    vector<type> sito(type N)
    {
        vector<type> tab=vector<type>(N);
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

    vector<type> primes(type u, vector<type> &tab)
    {
        vector<type> primes;
        primes.push_back(tab[u]);
        u/=tab[u];
        while (u>1)
        {
            if (primes.back()==tab[u])
            {
                u/=tab[u];
            }
            else
            {
                primes.push_back(u);
                u/=tab[u];
            }
        }
        return primes;
    }
    
    type tot(type x, vector<type> &tab)
    {
        type wyn=x;
        vector<type> temp =primes(x,tab);
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
        //delete temp;
        return (type) floor(wyn);
    }
    type nwd (type a,type b)
    {
        type c;
        while (b>0)
        {
            c=a%b;
            a=b;
            b=c;

        }
        return a;
    }
} 