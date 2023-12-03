// Main.cpp
#include "UserManager.h"
#include "Meal.h"
#include "MealPlanner.h"

int main() {
    UserManager userManager;
    userManager.createUser("student123", "password123");

    StudentMealPlanner mealPlanner(userManager);
    mealPlanner.customizeMeal("Lunch", "Custom Salad", {{"calories", 200}, {"protein", 15}, {"carbs", 10}});
    mealPlanner.planMeals(5);
    mealPlanner.viewGroceryList();

    return 0;
}
