#include <iostream>
#include <cmath>
#include <random>

class StdDevBase {
public:
    StdDevBase() {};
    ~StdDevBase() {}

    void LoadData(std::vector<float> &data_in) {
        data_ = data_in;
    }

    virtual float get_stddev() = 0; // pure virtual class

protected:
    std::vector<float> data_;
};

/*
class StdDev
Implements 2-pass standard deviation formula
*/
class StdDev : public StdDevBase {
public:
    StdDev() {}
    ~StdDev() {}
    float get_stddev() override;
};

float StdDev::get_stddev() {
    unsigned int N = data_.size();

    // Compute mean
    float sum = 0.;
    for (auto& it : data_) {
        sum += it;
    }
    float mean = sum / N;

    // Compute standard deviation
    float dev_sum2 = 0.;
    for (auto& it : data_) {
        dev_sum2 += std::pow(it - mean, 2);
    }
    float sigma = std::pow(dev_sum2 / (N - 1), 0.5);
    
    return sigma;
}

/*
Generate random numbers from a gaussian distribution
n = number of numbers to generate
mean = mean of gaussian
sigma = width of gaussian
*/
std::vector<float> GenerateData(unsigned int n, float mean, float sigma) {
    // Standard C++ machinery for random number generation
    std::random_device rd;
    std::mt19937 rng;
    std::normal_distribution<float> gaussian = std::normal_distribution<float>(mean, sigma);

    // Create data storage
    std::vector<float> random_data;
    random_data.reserve(n); // allocate memory in one go, instead of resizing repeatedly

    // Generate random numbers
    for (int i = 0; i < n; i++) {
        random_data.push_back(gaussian(rng));
    }

    std::cout << "Generated random data with n=" << n << ", mean=" << mean << ", sigma = " << sigma << std::endl;

    return random_data;
}

int main() {
    std::vector<float> random_data = GenerateData(1'000, 1.0, 0.01);

    StdDev stddev = StdDev();
    stddev.LoadData(random_data);
    std::cout << "Std. dev. = " << stddev.get_stddev() << std::endl;
}
