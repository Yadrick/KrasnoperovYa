#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char** argv)
{
    double y0=0, x0 = 0, vx = 0, vy = 0, g = 9.8, x, y;
    int site = 0;

    vector<double> X;
    vector<double> Y;

    ifstream fin(argv[1]);

    if (fin.is_open()) {
        fin >> y0 >> vx >> vy;
        //double t = (vy + sqrt(vy * vy + 2 * y0 * g)) / g;

            while (fin >> x >> y)
            {
                X.push_back(x);
                Y.push_back(y);
            }


    }
    fin.close();

    int direction = 1;
    double t = (vy + sqrt(vy*vy+2*y0*g))/g;
    double t_col;


    if (X.size() == 0) {
        site = 0;
    }
    else {
        for (int i = 0; (i >= 0) && (i <= X.size() - 1); i = i + direction) {
            // x = x0+vx*t
            t_col = (X[i] - x0) / vx;
            if (t_col <= t) {
                if ((y0 + vy * t_col - g * t_col * t_col / 2 <= Y[i])) //y = y0 + vy*t -gt^2/2
                {
                    x0 = 2 * vx * t_col + x0;
                    vx = -vx;
                    direction = (-1) * direction;
                }
            } else {
                break;
            }
        }

        double XX = x0 + vx * t; // поиск конечной координаты


        for (int i = 0; (i <= X.size() - 1); i++) {
            if ((XX >= X[i]) && (XX <= X[i + 1])) {
                site = i + 1;
                break;
            }
        }

        if ((XX > X[X.size() - 1])) {
            site = X.size();
        }

        if (XX < X[0]) {
            site = 0;
        }
    }

    X.clear();
    Y.clear();
    X.shrink_to_fit();
    Y.shrink_to_fit();
    cout << site << endl;
    return 0;
}
