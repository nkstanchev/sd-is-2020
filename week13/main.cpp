#include "hashmap.cpp"
#include <sstream>
#include <iostream>

std::function<size_t(const std::string&)> h = [](const std::string &s)->size_t
    {
        size_t sum = 0;
        for (char c: s)
        {
            sum += c;
        }
        return sum;
    };

int main ()
{
    HashMap<std::string,int> hm1(10, h);
    hm1["ab"] = 1;
    hm1["ba"] = 2;
    hm1["bc"] = 3;

    HashMap<std::string,int> hm2(hm1);
    hm1["ab"] = 5;
    hm2 = hm1;
    std::cout << hm2["ab"];
    return 0;
}