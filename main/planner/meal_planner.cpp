#include <iostream>
#include <vector>
#include <map>
#include <cstdlib> // for rand
#include <algorithm> // for find
#include <ctime> // for time function

class Meal {
public:
    Meal(const std::string& name, const std::map<std::string, int>& nutrition)
        : name(name), nutrition(nutrition) {}

    std::string getName() const {
        return name;
    }

    std::map<std::string, int> getNutrition() const {
        return nutrition;
    }

private:
    std::string name;
    std::map<std::string, int> nutrition;
};

class StudentMealPlanner {
public:
    StudentMealPlanner() {}

    void planMeals(int days = 7) {
        for (int day = 1; day <= days; ++day) {
            std::cout << "\nDay " << day << " Meal Plan:\n";
            for (const auto& mealType : meals) {
                const auto& options = mealType.second;
                const Meal& chosenMeal = options[std::rand() % options.size()];
                std::cout << mealType.first << ": " << chosenMeal.getName() << "\n";
                addToGroceryList(chosenMeal);
            }
        }
    }

    void addToGroceryList(const Meal& meal) {
        if (std::find(groceryList.begin(), groceryList.end(), meal.getName()) == groceryList.end()) {
            groceryList.push_back(meal.getName());
        }
    }

    void viewGroceryList() const {
        std::cout << "\nGrocery List:\n";
        for (const auto& item : groceryList) {
            std::cout << "- " << item << "\n";
        }
    }

    void customizeMeal(const std::string& mealType, const std::string& name, const std::map<std::string, int>& nutrition) {
        Meal customMeal(name, nutrition);
        meals[mealType].push_back(customMeal);
        std::cout << "Custom meal '" << name << "' added to " << mealType << ".\n";
    }

private:
    std::map<std::string, std::vector<Meal>> meals;
    std::vector<std::string> groceryList;
};

int main() {
    std::srand(std::time(nullptr));

    StudentMealPlanner mealPlanner;
    mealPlanner.customizeMeal("Lunch", "Custom Salad", {{"calories", 200}, {"protein", 15}, {"carbs", 10}});
    mealPlanner.planMeals(5);
    mealPlanner.viewGroceryList();

    return 0;
}
