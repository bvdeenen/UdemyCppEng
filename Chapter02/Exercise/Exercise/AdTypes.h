#pragma once

#include <cstdint>

#include "AdConstants.h"
namespace Ad {
    namespace Types {
        enum class LaneAssociationType {
            UNKNOWN,
            LEFT,
            CENTER,
            RIGHT,
        };
        struct VehicleType {
            std::int64_t id;
            LaneAssociationType lane;
            float speed;
            float distance;
        };
    }
}
