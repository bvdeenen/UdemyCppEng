#include <iostream>

#include "Weapons.h"

int main()
{
    auto axe = Axe{"Great dwarfen axe", 12.0F, 1.2F};
    std::cout << axe.get_name() << '\n';

    const auto axe_ptr = &axe;
    std::cout << axe_ptr->get_name() << '\n';
    std::cout << axe_ptr->get_damage() << '\n';

    axe.increment_damage(2);
    std::cout << axe_ptr->get_damage() << '\n';
    return 0;
}
