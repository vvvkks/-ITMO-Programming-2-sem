#include <iostream>
#include "gtest/gtest.h"
#include <cmath>


class Poly {
private:
    int *coeff;
    int size;

public:

    Poly(int *arr, int size_)
    {
        coeff = arr;
        size = size_;
    }

    int constexpr da(const int x)
    {

        int res = 0;
        for (int i = 0; i < size; ++i)
        {
            res += coeff[i] * pow(x, i);
        }
        return res;
    };

    friend std::ostream& operator <<(std::ostream &os, const Poly &c)
    {

        for (int i=0;i<(c.size);i++)
        {
            os << c.coeff[i] << std::endl;
        }
        return os;
    }
};
int mass[] = {1,3,5};
Poly piz(mass , 3);
int pop[] = {1,2,3,4};
Poly da(mass , 4);


TEST(TestCaseName, TestName)
{
    EXPECT_EQ((piz.da(2)), 27); //1 + 3x + 5x^2 (1 + 6 + 20)
    EXPECT_EQ((da.da(0)), 4);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}