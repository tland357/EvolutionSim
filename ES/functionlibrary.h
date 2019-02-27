#include <random>

using namespace std;

class Functions {
public:
    static bool bernoulli(double prob) {
        double x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        if (x < prob)
            return true;
        return false;
    }

    static void modPlus(int& x, int val, int mod) {
        x += val;
        if (x < 0) {
            x %= mod;
            x += mod;
        }
        x %= mod;
    }
};
