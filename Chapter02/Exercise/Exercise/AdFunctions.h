#pragma once

#include "AdTypes.h"
namespace Ad {
    namespace Data {
        Types::VehicleType init_ego_vehicle();

    }
    namespace Visualize {
        void print_vehicle(Types::VehicleType vehicle);
    }
    namespace Utils {

        float kph_to_mps(const float kph) ;
    }
}
