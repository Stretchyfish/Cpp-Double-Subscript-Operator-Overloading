#include <iostream>
#include <vector>

class DoubleSubscript
{
    private:
        std::vector<std::vector<double>> &values;   
        int j;

    public:
        DoubleSubscript(std::vector<std::vector<double>> &_values, int _j) : values(_values)
        {
            j = _j;
        }
        
        double &operator[](int i)
        {
            return values[j][i];
        }
        
};

class Matrix
{
    private:        
        std::vector<std::vector<double>> values =
        {
            {1, 1, 1},
            {2, 2, 2},
            {3, 3, 3}
        };

    public:
        Matrix()
        {

        }

        DoubleSubscript operator[](int j)
        {
            DoubleSubscript something(values, j);
            return something;
        }
};

int main(int, char**) 
{
    Matrix A;
    A[1][2] = 3;
    std::cout << A[1][1] << std::endl;
    std::cout << A[1][2] << std::endl;
}   

