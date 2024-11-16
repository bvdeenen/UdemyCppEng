#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include "AdConstants.h"

namespace Ad {
    namespace Types {
        enum class LaneAssociationType {
            LEFT,
            CENTER,
            RIGHT,
            NONE,
        };

        struct VehicleType {
            std::int32_t id;
            LaneAssociationType lane;
            float speed_mps;
            float distance_m;
        };

        const inline std::string &laneString(VehicleType vehicle) noexcept {
            static const std::array LANE_STRINGS{
                std::string{"LEFT"}, std::string{"CENTER"}, std::string{"RIGHT"}, std::string{"NONE"}
            };
            return LANE_STRINGS[static_cast<int>(vehicle.lane)];
        }

        struct NeighborVehiclesType {
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> vehicles_left_lane;
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> vehicles_center_lane;
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> vehicles_right_lane;
        };
    } // namespace Types
} // namespace Ad
