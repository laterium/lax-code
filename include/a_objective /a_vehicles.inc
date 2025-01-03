/// <summary>
/// vehicles defined
/// </summary>
#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        vehicles::vehicles_create(...do here);
        vehicles::vehicles_destroy(...do here);
        vehicles::vehicles_pos(...do here);
        vehicles::vehicle_angle(...do here);
        vehicles::vehicle_velocity(...do here);
        vehicles::vehicle_Angularvelocity(...do here);
        vehicles::vehicle_interior(...do here);
        vehicles::vehicle_color(...do here);
        vehicles::vehicle_paintjob(...do here);
        vehicles::vehicle_addcomponent(...do here);
        vehicles::vehicle_removecomponent(...do here);
        vehicles::vehicle_params(...do here);
        vehicles::vehicle_cardoors(...do here);
        vehicles::vehicle_carwindows(...do here);
        vehicles::vehicle_respawn(...do here);
        vehicles::vehicle_health(...do here);
        vehicles::vehicle_repair(...do here);
        vehicles::vehicle_plate(...do here);
    }
#endif

#if !defined vehicles::
    #define vehicles::
    #define vehicles_create(%0)          CreateVehicle(%0)
    #define vehicles_destroy(%0)         DestroyVehicle(%0)
    #define vehicles_pos(%0)             SetVehiclePos(%0)
    #define vehicle_angle(%0)            SetVehicleZAngle(%0)
    #define vehicle_velocity(%0)         SetVehicleVelocity(%0)
    #define vehicle_Angularvelocity(%0)  SetVehicleAngularVelocity(%0)
    #define vehicle_interior(%0)         LinkVehicleToInterior(%0)
    #define vehicle_color(%0)            ChangeVehicleColor(%0)
    #define vehicle_paintjob(%0)         ChangeVehiclePaintjob(%0)
    #define vehicle_addcomponent(%0)     AddVehicleComponent(%0)
    #define vehicle_removecomponent(%0)  RemoveVehicleComponent(%0)
    #define vehicle_params(%0)           SetVehicleParamsEx(%0)
    #define vehicle_cardoors(%0)         SetVehicleParamsCarDoors(%0)
    #define vehicle_carwindows(%0)       SetVehicleParamsCarWindows(%0)
    #define vehicle_respawn(%0)          SetVehicleToRespawn(%0)
    #define vehicle_health(%0)           SetVehicleHealth(%0)
    #define vehicle_repair(%0)           RepairVehicle(%0)
    #define vehicle_plate(%0)            SetVehicleNumberPlate(%0)
#endif
