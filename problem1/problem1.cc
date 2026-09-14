#include <iostream>

template<class T> T E_exact(T d, T x=1.0, T q=1) {
    return q / ((x - d / 2) * (x - d / 2)) - q / ((x + d / 2) * (x + d / 2));
}

template<class T> T E_approx(T d, T x=1.0, T q=1) {
    return T(2.) * q * d / (x * x * x);
}

template float E_exact(float d, float x=1.0, float q=1.);
template double E_exact(double d, double x=1.0, double q=1.);
template double E_approx(double d, double x=1.0, double q=1);

int main() {
    float d_float = 0.01;
    float E_exact_float = E_exact(d_float); // Or E_exact<float>(d_float), to be more explicit

    double d_double = 0.01;
    double E_exact_double = E_exact(d_double); // Or E_exact<double>(d_double), to be more explicit
    double E_approx_double = E_approx(d_double);

    std::cout << "E_exact<double>(0.01)   = " << E_exact_double << std::endl;
    std::cout << "E_exact<float>(0.01)    = " << E_exact(d_float) << "\tRel. diff. = " << (E_exact_float - E_exact_double) / E_exact_double << std::endl;
    std::cout << "E_approx<double>(0.01)  = " << E_approx(d_double) << "\t\tRel. diff. = " << (E_approx_double - E_exact_double) / E_exact_double << std::endl;

}