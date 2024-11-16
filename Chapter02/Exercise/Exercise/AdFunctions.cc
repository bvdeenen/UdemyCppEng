#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad {
    namespace Data {
        Types::VehicleType init_ego_vehicle() {
            return Types::VehicleType{
                .id = Constants::EGO_VEHICLE_ID,
                .lane = Types::LaneAssociationType::CENTER,
                .speed = 135,
                .distance = 0,
            };
        }
    }
    namespace Visualize {
        void print_vehicle(const Types::VehicleType vehicle) {
            std::cout << "id: " << vehicle.id
                << "\tspeed (kph): " << vehicle.speed
                << "\tspeed (m/s): " << Utils::kph_to_mps(vehicle.speed)
            << "\tdistance: " << vehicle.distance << std::endl;

        }
    }
    namespace Utils {
        float kph_to_mps(const float kph) {
            return kph / 3.6;
        }

    }
}
