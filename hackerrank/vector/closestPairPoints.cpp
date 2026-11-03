#include <iostream>
#include <vector>
#include <cmath>

double dist(std::vector<int> a, std::vector<int> b) {
    return std::sqrt(std::pow(a[0] - b[0], 2) + std::pow(a[1] - b[1], 2));
}

std::vector<std::vector<int>> getStripElements(std::vector<std::vector<int>> Y, int midX, double d) {

    std::vector<std::vector<int>> strip;

    for (auto p : Y) {
        if (std::abs(p[0] - midX) < d)
            strip.push_back(p);
    }

    return strip;
}

void divide(std::vector<std::vector<int>> X,
            std::vector<std::vector<int>> Y,
            std::vector<std::vector<int>>& Yl,
            std::vector<std::vector<int>>& Yr) {

    int mid = X.size() / 2;

    for (auto p : Y) {
        bool left = false;

        for (int i = 0; i < mid; i++) {
            if (p == X[i]) {
                left = true;
                break;
            }
        }

        if (left)
            Yl.push_back(p);
        else
            Yr.push_back(p);
    }
}


int closestPairPoints(std::vector<std::vector<int>> X, std::vector<std::vector<int>> Y){
    int n = X.size();

    if (n == 2)
        return dist(X[0], X[1]);

    if (n == 3)
        return std::min({dist(X[0], X[1]), dist(X[1], X[2]), dist(X[0], X[2])});

    int mid = n / 2;
    
    std::vector<std::vector<int>> XL(X.begin(), X.begin() + mid);
    std::vector<std::vector<int>> XR(X.begin() + mid, X.end());

    std::vector<std::vector<int>> Yl, Yr;
    divide(X, Y, Yl, Yr);

    double d = std::min(closestPairPoints(XL, Yl),
                        closestPairPoints(XR, Yr));

    auto strip = getStripElements(Y, X[mid][0], d);

    for (int i = 0; i < strip.size(); i++) {
        for (int j = 1; j <= 7 && i + j < strip.size(); j++) {
            d = std::min(d, dist(strip[i], strip[i + j]));
        }
    }

    return d;

}

int main() {
    std::vector<std::vector<int>> X = {
        {2, 3}, {12, 30}, {40, 50},
        {5, 1}, {12, 10}, {3, 4}
    };

    std::sort(X.begin(), X.end(),
              [](auto a, auto b) { return a[0] < b[0]; });

    auto Y = X;

    std::sort(Y.begin(), Y.end(), [](auto a, auto b) { return a[1] < b[1]; });

    std::cout << closestPairPoints(X, Y) << '\n';
}