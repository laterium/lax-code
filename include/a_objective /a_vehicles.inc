#if !defined example
//    #include "System"

//    main() {}

//    public OnGameModeInit() {
//        vehicles::vehicle_create(.........................format);
//        vehicles::vehicle_destroy(........................format);
//        vehicles::vehicle_pos(............................format);
//        vehicles::vehicle_angle(..........................format);
//        vehicles::vehicle_velocity(.......................format);
//        vehicles::vehicle_angularvelocity(................format);
//        vehicles::vehicle_interior(.......................format);
//        vehicles::vehicle_virtualworld(...................format);
//        vehicles::vehicle_color(..........................format);
//        vehicles::vehicle_paintjob(.......................format);
//        vehicles::vehicle_addcomponent(...................format);
//        vehicles::vehicle_removecomponent(................format);
//        vehicles::vehicle_params(.........................format);
//        vehicles::vehicle_cardoors(.......................format);
//        vehicles::vehicle_carwindows(.....................format);
//        vehicles::vehicle_respawn(........................format);
//        vehicles::vehicle_health(.........................format);
//        vehicles::vehicle_repair(.........................format);
//        vehicles::vehicle_plate(..........................format);
//        vehicles::vehicle_putvehicle(.....................format);
//        vehicles::vehicle_removefromvehicle(..............format);
//        vehicles::vehicle_remotevehiclecollisions(........format);
//    }
#endif

#if !defined vehicles::
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
