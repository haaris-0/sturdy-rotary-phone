// Meal.cpp
#include "Meal.h"

Meal::Meal(const std::string& name, const std::map<std::string, int>& nutrition)
    : name(name), nutrition(nutrition) {
    // ... (constructor implementation)
}

std::string Meal::getName() const {
    return name;
}

std::map<std::string, int> Meal::getNutrition() const {
    return nutrition;
}
