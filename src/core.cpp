#include "ProjectEuler.h"
#include <cmath>
#include <iostream>

namespace NumberTheory
{   
    long* sito(int u)
    {
        long *tab;
        tab=new long [u];
        for(int i = 2; i < u+1; i++)
        {
            tab[i]=i;
        }
        for (int i = 4; i < u+1; i+=2)
        {
            tab[i]=2;
        }
        for (int i = 3; i < sqrt(u); i++)
        {
            if (tab[i]==i)
            {
                for (int j = i*i; j < u+1; j+=i)
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

    
} // namespace NumberTheory