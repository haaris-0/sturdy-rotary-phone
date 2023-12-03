// Meal.h
#ifndef MEAL_H
#define MEAL_H

#include <string>
#include <map>

class Meal {
public:
    Meal(const std::string& name, const std::map<std::string, int>& nutrition);
    std::string getName() const;
    std::map<std::string, int> getNutrition() const;

private:
    std::string name;
    std::map<std::string, int> nutrition;
};

#endif // MEAL_H
