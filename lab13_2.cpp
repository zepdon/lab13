#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[N][M]) {
    int i = 0;
    while (i < M + 2) {
        std::cout << "-";
        i++;
    }
    std::cout << "\n";

    int y = 0;
    while (y < N) {
        std::cout << "|";
        int x = 0;
        while (x < M) {
            if (image[y][x] == 1)
                std::cout << "*";
            else
                std::cout << " ";
            x++;
        }
        std::cout << "|\n";
        y++;
    }

    i = 0;
    while (i < M + 2) {
        std::cout << "-";
        i++;
    }
    std::cout << "\n";
}

void updateImage(bool image[N][M], int s, int x, int y) {
    int j = 0;
    while (j < M) {
        int i = 0;
        while (i < N) {
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) <= s - 1) {
                image[i][j] = 1;
            }
            i++;
        }
        j++;
    }
}