#include <array>
#include <vector>
#include <cstdint>
using namespace std;

//**********
#define type uint64_t
//**********

namespace NumberTheory
{
    vector<type> sito(); //return array containing smaller prime dividing given number
    vector<type> primes(type u,vector<type> &tab);// return array of primes dividing s, tab =sito
    type tot(type x, vector<type> &tab);//return totient of x, tab=sito
    type nwd (type a,type b); //return least common divisor 


    type inverse(type a, type n); // inverse element of a in mod n group
    array<type,3> ext_euc(type a, type b);
    type chin(type M,vector<type> &ytab, vector<type> &ntab);

} // namespace NumberTheory