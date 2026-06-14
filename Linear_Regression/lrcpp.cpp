#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int k;
    cout << "Enter number of data points (k): ";
    cin >> k;

    vector<double> x(k), y(k), out(k);
    cout << "Enter x and y pairs:\n";
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }

    double t1 = 0, t2 = 0;

    double a;
    cout << "Enter learning rate (a): ";
    cin >> a;

    const double EPSILON = 0.00001;
    int maxIter = 100000, iter = 0;

    double t_1 = t1 + 100.0;
    double t_2 = t2 + 100.0;

    while ((fabs(t_1 - t1) > EPSILON || fabs(t_2 - t2) > EPSILON) && iter++ < maxIter) {
        t1 = t_1;
        t2 = t_2;

 // Predict
        for (int i = 0; i < k; i++)
            out[i] = t1 + t2 * x[i];

// Gradients
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++) {
            sum1 += (y[i] - out[i]);
            sum2 += (y[i] - out[i]) * x[i];
        }

// Update
        t_1 = t1 + a * (sum1);
        t_2 = t2 + a * (sum2);
    }

    if (iter >= maxIter)
        cout << "did not converge.\n";

    cout << "Optimized t1 (Bias): " << t1 << "\nOptimized t2 (Slope): " << t2 <<"\n no. of iter:"<< iter << endl;
    return 0;
}