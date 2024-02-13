/*
** EPITECH PROJECT, 2022
** Project
** File description:
** pizza
*/

#include "pizza.hpp"

/**
 * @brief Construct a new Pizza::Pizza object
 * @param type Set type of the new pizza
 * @param size Set size of the new pizza
 */
pizza::pizza(PizzaType_e type, PizzaSize_e size)
{
    _type = type;
    _size = size;
    switch (_type) {
        case Regina: createRegina(); break;
        case Margarita: createMargarita(); break;
        case Americana: createAmericana(); break;
        case Fantasia: createFantasia(); break;
        default: throw exception::pizza::InvalidPizzaType("Invalid pizza type");
    }
}

/**
 * @brief Destroy the Pizza::Pizza object, and clear the ingredients vector
 */
pizza::~pizza()
{
    _ingredients.clear();
}

/**
 * @brief Get the type of the pizza
 * @return PizzaType_e The type of the pizza
 */
PizzaType_e pizza::getPizzaType(void) const
{
    return _type;
}

/**
 * @brief Get the size of the pizza
 * @return PizzaSize_e The size of the pizza
 */
PizzaSize_e pizza::getPizzaSize(void) const
{
    return _size;
}

/**
 * @brief Get the time it takes to cook the pizza
 * @return size_t The time it takes to cook the pizza
 */
size_t pizza::getCookTime() const
{
    return _time;
}

/**
 * @brief Get the type of the pizza as a string
 * @return std::string The type of the pizza as a string
 */
std::string pizza::getPizzaTypeString(void) const
{
    std::vector<std::string> types = {"Regina", "Margarita", "Americana", "Fantasia"};

    for (int i = 0; i < (int)types.size(); i++)
        if (_type == (PizzaType_e)pow(2, i))
            return types[i];
    return "";
}

/**
 * @brief Get the size of the pizza as a string
 * @return std::string The size of the pizza as a string
 */
std::string pizza::getPizzaSizeString(void) const
{
    std::vector<std::string> sizes = {"S", "M", "L", "XL", "XXL"};

    for (int i = 0; i < (int)sizes.size(); i++)
        if (_size == (PizzaSize_e)pow(2, i))
            return sizes[i];
    return "";
}

/**
 * @brief Get the enum ingredients of the pizza
 * @return std::vector<size_t> The ingredients of the pizza
 */
std::vector<size_t> pizza::getIngredients(void) const
{
    return _ingredients;
}

/**
 * @brief Assign the default preparation time for Margarita pizza, and all the needed ingredients
 */
void pizza::createMargarita(void)
{
    _time = 1;
    _ingredients.clear();
    _ingredients.resize(NB_INGREDIENTS);
    _ingredients[Doe]++;
    _ingredients[Tomato]++;
    _ingredients[Gruyere]++;
}

/**
 * @brief Assign the default preparation time for Regina pizza, and all the needed ingredients
 */
void pizza::createRegina(void)
{
    _time = 2;
    _ingredients.clear();
    _ingredients.resize(NB_INGREDIENTS);
    _ingredients[Doe]++;
    _ingredients[Tomato]++;
    _ingredients[Gruyere]++;
    _ingredients[Ham]++;
    _ingredients[Mushrooms]++;
}

/**
 * @brief Assign the default preparation time for Americana pizza, and all the needed ingredients
 */
void pizza::createAmericana(void)
{
    _time = 2;
    _ingredients.clear();
    _ingredients.resize(NB_INGREDIENTS);
    _ingredients[Doe]++;
    _ingredients[Tomato]++;
    _ingredients[Ham]++;
    _ingredients[Steak]++;
}

/**
 * @brief Assign the default preparation time for Fantasia pizza, and all the needed ingredients
 */
void pizza::createFantasia(void)
{
    _time = 4;
    _ingredients.clear();
    _ingredients.resize(NB_INGREDIENTS);
    _ingredients[Doe]++;
    _ingredients[Tomato]++;
    _ingredients[Eggplant]++;
    _ingredients[Goat_Cheese]++;
}