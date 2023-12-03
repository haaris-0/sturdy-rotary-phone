// MealPlanner.h
#ifndef MEALPLANNER_H
#define MEALPLANNER_H

#include "UserManager.h"
#include "Meal.h"
#include <vector>
#include <map>

class StudentMealPlanner {
public:
    StudentMealPlanner(UserManager& userManager);
    void planMeals(int days = 7);
    void addToGroceryList(const Meal& meal);
    void viewGroceryList() const;
    void customizeMeal(const std::string& mealType, const std::string& name, const std::map<std::string, int>& nutrition);
    void runPlanner();

private:
    UserManager& userManager;
    std::map<std::string, std::vector<Meal>> meals;
    std::vector<std::string> groceryList;
};

#endif // MEALPLANNER_H
