#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename S>
void swap(S &a, S &b)
{
    S tmp = a;
    a = b;
    b = tmp;
}

template <typename M>
M &min(M &a, M &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename M>
M &max(M &a, M &b)
{
    if (a > b)
        return a;
    return b;
}


#endif