#include <vector>
#include "ProjectEuler.h"
//#include <iostream>
using namespace std;

namespace Utils
{
    vector<vector<type>> cartesian(vector<vector<type>> input)
    {
        vector<vector<type>> wyn;
        if (input.size()==1)
        {
            for (auto c:input[0])
            {
                wyn.push_back(vector<type>{c});
            }
            return wyn;
        }
        else
        {
            vector<type>current=input[input.size()-1];
            input.pop_back();
            vector<vector<type>> temp=cartesian(input);
            for (auto p1:temp)
            {
                vector<type> u;
                for ( auto p2:current)
                {
                    u=p1;
                    u.push_back(p2);
                    wyn.push_back(u);
                }
            
            }
            return wyn;
        }

    }

}