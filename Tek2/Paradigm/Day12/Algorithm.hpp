/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD12-tanguy.bellicha
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_


class Algorithm {
    public:
        Algorithm();
        ~Algorithm();


    protected:
    private:
};

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
};

template <typename T>
const T& min(const T& a, const T& b) {
    if (a < b)
        return (a);
    return (b);
};

template <typename T>
const T& max(const T& a, const T& b) {
    if (b < a)
        return (a);
    return (b);
};

template <typename T>
const T& clamp(const T& value, const T& min, const T& max) {
    if (value < min)
        return (min);
    if (max < value)
        return (max);
    return (value);
};

#endif /* !ALGORITHM_HPP_ */
