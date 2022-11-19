#include <iostream>
#include <vector>
#include <algorithm>

using Data = std::vector<int>;

template <size_t number, int init = 0, int step = 1>
class GenWithStep{
public:
    static void fill(Data& d){
        int current_value{init};
        for(size_t i = 0; i < number; ++i){
            d.push_back(current_value);
            current_value += step;
        }
    }
};

template <size_t number>
class GenWithEven{
public:
    static void fill(Data& d){
        for(size_t i=0; i < number; i++){
            d.push_back(i * 2);
        }
    }
};

template <typename ... Rules>
class VectorGenerator{
public:
    Data generate(){
        Data new_data;
        (Rules::fill(new_data),...);
        return new_data;
    }
};

void print(const Data& d){
    std::for_each(d.begin(), d.end(), [](auto x){std::cout << x << ' ';});
    std::cout << '\n';
}

int main(){
    VectorGenerator<GenWithEven<4>, GenWithStep<5,5,-1>> vec_gen;
    Data d1 = vec_gen.generate();
    print(d1);
    VectorGenerator<GenWithStep<10, -4>, GenWithEven<10>> vec_gen2;
    Data d2 = vec_gen2.generate();
    print(d2);
    return 0;
}