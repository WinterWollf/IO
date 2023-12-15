#include "funkcje.h"
#include <cmath>
#include <vector>

double ln(const double number) {
	return log(number);
}
double standard_deviation(const std::vector<double>& dane) {
    int n = dane.size();

    double sum = 0;
    for (double number : dane) {
        sum += number;
    }

    double avg = sum / n;
    double pow_sum = 0;

    for (double number : dane) {
        pow_sum += pow(number - avg, 2);
    }

    double deviation = sqrt(pow_sum / n);

    return deviation;
}
double exponent(const double number) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i <= 200; ++i) {
        term *= number / i;
        result += term;
    }

    return result;
}
