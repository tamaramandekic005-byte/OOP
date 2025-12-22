#ifndef ZOOSECTION_H
#define ZOOSECTION_H

#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T>
class ZooSection {
private:
    vector<unique_ptr<T>> animals;

public:
    void addAnimal(unique_ptr<T> animal) {
        if (!animal)
            throw runtime_error("Ne moze se dodati nullptr zivotinja");

        animals.push_back(move(animal));
    }

    double totalFood() const {
        double sum = 0;

        for (const auto& a : animals) {
            sum += a->getDailyFood();
        }

        return sum;
    }

    size_t size() const {
        return animals.size();
    }

    T* getAnimal(size_t index) const {
        return animals.at(index).get();
    }
};
#endif


