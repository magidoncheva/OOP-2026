#ifndef __PAIR_H__
#define __PAIR_H__

template <typename T, typename S>
class Pair{
    T first;
    S second;

    public:
    Pair() {}
    Pair(const T& first, const S& second);

    // friend std::ostream& operator<<(std::ostream& os, const Pair<T, S>& pair);
};

template<typename T, typename S>
Pair<T, S>::Pair(const T& first, const S& second): first(first), second(second){}

// template<typename T, typename S>
// std::ostream& operator<<(std::ostream& os, const Pair<T, S>& pair) {
//     os << pair.first << " " << pair.second;

//     return os;
// }

#endif // __PAIR_H__