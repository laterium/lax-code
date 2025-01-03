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
    }
#endif

#if !defined vehicles::
    #define vehicles::
    #define vehicles_create(%0)          CreateVehicle(%0)
    #define vehicles_destroy(%0)         DestroyVehicle(%0)
#endif
