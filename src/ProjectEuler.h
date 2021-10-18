#include <array>
#include <vector>
using namespace std;
namespace NumberTheory
{
    //core.cpp
    template <typename T,size_t N> array<T,N> sito(); //return array containing smaller prime dividing given number
    template <typename T,typename S,size_t N> vector<T> primes(S u,array<T,N> &tab);// return array of primes dividing s, tab =sito
    template <typename T,typename S,size_t N> T tot(S x, array<T,N> &tab);//return totient of x, tab=sito
    template <typename T> T nwd (T a,T b); //return least common divisor 


    //modulo.cpp
    template <typename T>T inverse(T a, T n); // inverse element of a in mod n group
    template <typename T>array<T,3> ext_euc(T a, T b);
    template <typename T>T chin(T M,vector<T> &ytab, vector<T> &ntab);

} // namespace NumberTheory
#include "core.cpp"
#include "modulo.cpp"