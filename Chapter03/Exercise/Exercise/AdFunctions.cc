#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

#include <numeric>

namespace Ad {
    using namespace Types;

    namespace Visualize {
        void print_vehicle(const VehicleType &vehicle) {
            std::cout << "ID: " << vehicle.id
                    << ", speed(m/s): " << vehicle.speed_mps
                    << ", distance: " << vehicle.distance_m
                    << ", lane: " << laneString(vehicle)
                    << std::endl;
        }

        void print_neighbor_vehicles(const NeighborVehiclesType &vehicles) {
            std::cout << "Neighbor vehicles:" << std::endl;
            std::cout << "   left:" << std::endl;
            for (const auto &vehicle: vehicles.vehicles_left_lane)
                print_vehicle(vehicle);
            std::cout << "   center:" << std::endl;
            for (const auto &vehicle: vehicles.vehicles_center_lane)
                print_vehicle(vehicle);
            std::cout << "   right:" << std::endl;
            for (const auto &vehicle: vehicles.vehicles_right_lane)
                print_vehicle(vehicle);
        }

        /**
         *
         * @param distance upper distance
         * @param vehicles  array of vehicles to check
         * @return  boolean whether there is at least one vehicle in the distance block.
         */
        bool has_vehicle(const float distance, std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> vehicles) {
            return std::accumulate(vehicles.begin(), vehicles.end(), false,
                                   [distance](const bool &flag, const VehicleType &vehicle) {
                                       return flag || vehicle.distance_m > distance - 20.0 && vehicle.distance_m <=
                                              distance;
                                   });
        }

        void print_scene(const VehicleType &,
                         const NeighborVehiclesType &vehicles) {
            for (int distance = 100; distance >= -100; distance -= 20) {
                auto is_left = has_vehicle(distance, vehicles.vehicles_left_lane);
                auto is_center = has_vehicle(distance, vehicles.vehicles_center_lane);
                auto is_right = has_vehicle(distance, vehicles.vehicles_right_lane);
                auto is_ego = distance == 0;
                printf("%-6d|  %c  |  %c  |  %c  |\n", distance,
                       is_left ? 'V' : ' ',
                       is_ego ? 'E' : (is_center ? 'V' : ' '),
                       is_right ? 'V' : ' ');
            }
        }
    } // namespace Visualize
    namespace Data {
        using namespace Ad::Constants;
        using namespace Ad::Types;

        NeighborVehiclesType init_vehicles() {
            NeighborVehiclesType vehicles{
                {
                    VehicleType{1, LaneAssociationType::LEFT, 25, 80},
                    VehicleType{2, LaneAssociationType::LEFT, 26, -20}
                },
                {
                    VehicleType{3, LaneAssociationType::CENTER, 23, 50},
                    VehicleType{4, LaneAssociationType::CENTER, 24, -50}
                },
                {
                    VehicleType{5, LaneAssociationType::RIGHT, 32, 30},
                    VehicleType{6, LaneAssociationType::RIGHT, 33, -30}
                },

            };
            return vehicles;
        }

        VehicleType init_ego_vehicle() {
            return VehicleType{EGO_VEHICLE_ID, LaneAssociationType::CENTER, 30, 0};
        }
    }
}
