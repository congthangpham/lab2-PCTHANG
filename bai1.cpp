#include <iostream>
using namespace std;

const int GRID_SIZE = 3; 

bool isLoShuMagicSquare(const double[][GRID_SIZE]);
double tongHang(const double[][GRID_SIZE]);
double tongCot(const double[][GRID_SIZE]);
double tongCheoTrenTraiSangPhai(const double[][GRID_SIZE]);
double tongCheoTrenPhaiSangTrai(const double[][GRID_SIZE]);

int main()
{
    double grid_array_1[GRID_SIZE][GRID_SIZE] = {{1, 2, 3},
                                                 {4, 5, 6},
                                                 {7, 8, 9}},

           grid_array_2[GRID_SIZE][GRID_SIZE] = {{4, 9, 2},
                                                 {3, 5, 7},
                                                 {8, 1, 6}};

    cout << "Array is";
    cout << (isLoShuMagicSquare(grid_array_2) ? " " : " NOT ");
    cout << "a Lo Shu Magic Square!" 
         << endl;
    
    return 0;
}

double tongHang(const double array[][GRID_SIZE])
{
    double total;

    for(int row = 0; row < GRID_SIZE; row++)
    {
        total = 0;
        for(int column = 0; column < GRID_SIZE; column++)
            total += array[row][column];
    }
    return total;
}

double tongCot(const double array[][GRID_SIZE])
{
    double total;
    for(int columns = 0; columns < GRID_SIZE; columns++)
    {
        total = 0;
        for (int row = 0; row < GRID_SIZE; row++)
            total += array[row][columns];
    }
    return total;
}
double tongCheoTrenTraiSangPhai(const double array[][GRID_SIZE])
{
    double total = 0;
  
    for(int i = 0; i < GRID_SIZE; i++)
        total += array[i][i];
    return total;
}
double tongCheoTrenPhaiSangTrai(const double array[][GRID_SIZE])
{
    double total = 0;
    int column = (GRID_SIZE - 1); // 3 - 1 = 2
    for (int row = 0; row < GRID_SIZE; row++)
    {
        total += array[row][column];
        column--;
    }
    return total;
}

bool isLoShuMagicSquare(const double array[][GRID_SIZE])
{
    if(
        tongHang(array)              == 15 &&
        tongCot(array)           == 15 &&
        tongCheoTrenPhaiSangTrai(array)  == 15 &&
        tongCheoTrenTraiSangPhai(array)  == 15
       )
        return true;
    else
        return false;
}