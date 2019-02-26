#include <random>

using namespace std;

class Functions {
public:
    static bool bernoulli(float prob) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        if (x < prob)
            return true;
        return false;
    }
};
