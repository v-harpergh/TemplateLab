#include <algorithm>
#include <cassert>
#include <list>
#include <vector>

template <typename T>
std::vector<T> vec_fill(T elem)
{
    std::vector<T> result;
    result.reserve(10);

    for (int i = 0; i < 10; ++i)
        result.push_back(elem + i);

    return result;
}

template <typename T>
void order(T& a, T& b, T& c)
{
    if (a < b)
        std::swap(a, b);

    if (a < c)
        std::swap(a, c);

    if (b < c)
        std::swap(b, c);
}

template <typename T>
T search(T begin, T end, int elem)
{
    for (T it = begin; it != end; ++it)
    {
        if (*it == elem)
            return it;
    }

    return end;
}

int main()
{
    assert((vec_fill<int>(1) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    assert((vec_fill<double>(0.5) == std::vector<double>{0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5}));
    assert((vec_fill<float>(-3.0f) == std::vector<float>{-3, -2, -1, 0, 1, 2, 3, 4, 5, 6}));

    int a = 2, b = 9, c = 5;
    order(a, b, c);
    assert(a == 9 && b == 5 && c == 2);

    double d = 3.5, e = 1.5, f = 7.5;
    order(d, e, f);
    assert(d == 7.5 && e == 3.5 && f == 1.5);

    float g = 10.0f, h = 20.0f, i = 15.0f;
    order(g, h, i);
    assert(g == 20.0f && h == 15.0f && i == 10.0f);

    std::vector<int> v{ 1, 2, 3, 4, 5 };
    assert(search(v.begin(), v.end(), 3) == v.begin() + 2);
    assert(search(v.begin(), v.end(), 99) == v.end());

    std::list<int> l{ 10, 20, 30, 40 };
    assert(search(l.begin(), l.end(), 30) == std::next(l.begin(), 2));
    assert(search(l.begin(), l.end(), 99) == l.end());

    int arr[]{ 5, 10, 15, 20 };
    assert(search(arr, arr + 4, 15) == arr + 2);
    assert(search(arr, arr + 4, 99) == arr + 4);
}