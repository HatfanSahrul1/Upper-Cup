#pragma once

#include <iostream>
#include <memory>
#include "objects.h"

namespace UpperCup::Factories
{
    class CupFactory
    {
        public:
            static std::shared_ptr<UpperCup::Objects::Cup> CreateCup(Vector2 position)
            {
                auto cup = std::make_shared<UpperCup::Objects::Cup>(position);
                return cup;
            }
    };
}
