/*Реализуйте шаблонный класс многомерных матриц,
поддерживающий красивую печать, сложение, вычитание,
умножение на число, функцию возвращения элемента по индексам.*/

#include <iostream>
#include <utility>
#include <vector>
#include <array>

template <size_t DimensionsAmount, typename T>
class Array
{
private:
    std::vector<std::pair<std::array<size_t, DimensionsAmount>, T>> ValuesHolder;

    std::array<size_t, DimensionsAmount> Dimensions;

public:
    Array(std::array<size_t, DimensionsAmount> dimensions)
    {
        Dimensions = dimensions;

        std::array<size_t, DimensionsAmount> coord;
        for (int i = 0; i < DimensionsAmount; i++)
        {
            coord[i] = 0;
        };
        bool flag = true;
        size_t k = DimensionsAmount - 1;

        while (flag)
        {

            ValuesHolder.push_back(std::make_pair(coord, 0));

            k = DimensionsAmount - 1;
            coord[k]++;

            while (coord[k] >= Dimensions[k])
            {
                if (k == 0)
                {
                    flag = false;
                    break;
                };

                coord[k - 1] += (coord[k] / Dimensions[k]);
                coord[k] %= Dimensions[k];
                k--;
            };
        }
    };


    //вызов по индексу
    T operator[] (std::array<size_t, DimensionsAmount> coords) const
    {
        for (std::pair<std::array<size_t, DimensionsAmount>, T> Pair : ValuesHolder)
        {
            if (Pair.first == coords)
            {
                return Pair.second;
            };
        };
        std::cout << "not found" << std::endl;
    };

    const std::array<size_t, DimensionsAmount> DimensionsSize() const
    {
        return Dimensions;
    };

    void SetValue(std::array<size_t, DimensionsAmount> coords, T value)
    {
        for (int i = 0; i < ValuesHolder.size(); i++)
        {
            if (ValuesHolder[i].first == coords)
            {
                ValuesHolder[i].second = value;
                return;
            };
        };

        return;
    };


    //умножение на число
    Array<DimensionsAmount, T> operator* (const double k) const
    {
        Array<DimensionsAmount, T> A(Dimensions);

        for (int i = 0; i < ValuesHolder.size(); i++)
        {
            A.SetValue(ValuesHolder[i].first, ValuesHolder[i].second * k);
        };

        return A;
    };

    bool SameSize(const Array<DimensionsAmount, T> other) const
    {
        auto dim = other.DimensionsSize();
        for (int i = 0; i < DimensionsAmount; i++)
        {
            if (dim[i] != Dimensions[i])
            {
                return false;
            };
        };

        return true;
    };


    //сложение
    Array<DimensionsAmount, T> operator+ (const Array<DimensionsAmount, T> other)
    {
        if (!SameSize(other))
        {
            std::runtime_error a("Addition on different matrix sizes");
            throw(a);
        };

        Array<DimensionsAmount, T> Ans(Dimensions);

        for (int i = 0; i < ValuesHolder.size(); i++)
        {
            Ans.SetValue(ValuesHolder[i].first, other[ValuesHolder[i].first] + ValuesHolder[i].second);
        };
        return Ans;
    };


    //вычитание
    Array<DimensionsAmount, T> operator- (const Array<DimensionsAmount, T> other)
    {
        if (!SameSize(other))
        {
            std::runtime_error a("Substration on different matrix sizes");
            throw(a);
        };

        Array<DimensionsAmount, T> A(other * (-1));
        Array<DimensionsAmount, T> B(A + (*this));
        return B;
    };


    // красивая печать
    void print() const
    {
        for (int i = 0; i < ValuesHolder.size(); i++)
        {
            std::cout << "(";
            for (int j = 0; j < DimensionsAmount; j++)
            {
                std::cout << ValuesHolder[i].first[j] << " ";
            };
            std::cout << ") - " << ValuesHolder[i].second << std::endl;
        };

        return;
    };
};


int main()
{
    std::array<size_t, 2> u = { 2, 2 };
    std::array<size_t, 2> v = { 1, 1 };
    Array<2, int> A(u);
    A.SetValue(v, 1);
    v[0]--;

    Array<2, int> S(A);
    S.SetValue(v, -3);

    Array<2, int> B(A * 2);
    Array<2, int> C(B - S * 3);

    Array<2, int> E(v);
    try
    {
        Array<2, int> D(E - A);
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    };



    S.print();
    std::cout << std::endl;
    B.print();
    std::cout << std::endl;
    C.print();


    2 + 3;

    return 0;
}
