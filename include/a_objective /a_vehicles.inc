/// <summary>
/// This section defines a set of macros for managing vehicle-related actions and attributes in the game. 
/// Each macro is a simplified version of the corresponding function that deals with vehicle properties and actions.
///
/// Vehicle Macros:
/// - vehicle_create(%0)                : Creates a vehicle with the given parameters.
/// - vehicle_destroy(%0)               : Destroys the specified vehicle.
/// - vehicle_pos(%0)                   : Sets the position of the vehicle.
/// - vehicle_angle(%0)                 : Sets the vehicle's angle (rotation) in the Z-axis.
/// - vehicle_velocity(%0)              : Sets the vehicle's linear velocity (movement speed).
/// - vehicle_angularvelocity(%0)       : Sets the vehicle's angular velocity (rotation speed).
/// - vehicle_interior(%0)              : Links the vehicle to a specific interior.
/// - vehicle_virtualworld(%0)          : Sets the vehicle's virtual world ID.
/// - vehicle_colour(%0)                : Changes the vehicle's color.
/// - vehicle_color                     : Alias for `vehicle_colour`, changes the vehicle's color.
/// - vehicle_paintjob(%0)              : Changes the vehicle's paint job (skin or texture).
/// - vehicle_addcomponent(%0)          : Adds a specified component to the vehicle.
/// - vehicle_removecomponent(%0)       : Removes a specified component from the vehicle.
/// - vehicle_params(%0)                : Sets various parameters for the vehicle (such as speed, handling).
/// - vehicle_cardoors(%0)              : Sets the car door state (open/close).
/// - vehicle_carwindows(%0)            : Sets the car window state (up/down).
/// - vehicle_respawn(%0)               : Sets the vehicle to respawn after a specified time or condition.
/// - vehicle_health(%0)                : Sets the vehicle's health (damage level).
/// - vehicle_repair(%0)                : Repairs the vehicle to restore its health.
/// - vehicle_plate(%0)                 : Sets the vehicle's number plate text.
/// - vehicle_putvehicle(%0)            : Puts the player in the specified vehicle.
/// - vehicle_removefromvehicle(%0)     : Removes the player from the vehicle.
/// - vehicle_remotevehiclecollisions(%0) : Disables remote vehicle collisions for the specified vehicle.
/// </summary>

#if !defined vehicles::
    #define vehicle->
    #define vehicles::
    #define vehicle_create(%0)                  CreateVehicle(%0)
    #define vehicle_destroy(%0)                 DestroyVehicle(%0)
    #define vehicle_pos(%0)                     SetVehiclePos(%0)
    #define vehicle_angle(%0)                   SetVehicleZAngle(%0)
    #define vehicle_velocity(%0)                SetVehicleVelocity(%0)
    #define vehicle_angularvelocity(%0)         SetVehicleAngularVelocity(%0)
    #define vehicle_interior(%0)                LinkVehicleToInterior(%0)
    #define vehicle_virtualworld(%0)            SetVehicleVirtualWorld(%0)
    #define vehicle_colour(%0)                  ChangeVehicleColor(%0)
    #define vehicle_color                       vehicle_colour
    #define vehicle_paintjob(%0)                ChangeVehiclePaintjob(%0)
    #define vehicle_addcomponent(%0)            AddVehicleComponent(%0)
    #define vehicle_removecomponent(%0)         RemoveVehicleComponent(%0)
    #define vehicle_params(%0)                  SetVehicleParamsEx(%0)
    #define vehicle_cardoors(%0)                SetVehicleParamsCarDoors(%0)
    #define vehicle_carwindows(%0)              SetVehicleParamsCarWindows(%0)
    #define vehicle_respawn(%0)                 SetVehicleToRespawn(%0)
    #define vehicle_health(%0)                  SetVehicleHealth(%0)
    #define vehicle_repair(%0)                  RepairVehicle(%0)
    #define vehicle_plate(%0)                   SetVehicleNumberPlate(%0)
    #define vehicle_putvehicle(%0)              PutPlayerInVehicle(%0)
    #define vehicle_removefromvehicle(%0)       RemovePlayerFromVehicle(%0)
    #define vehicle_remotevehiclecollisions(%0) DisableRemoteVehicleCollisions(%0)
#endif
