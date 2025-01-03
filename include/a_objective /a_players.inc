/// <summary>
/// players defined
/// </summary>
#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        players::player_pos(...do here);
        players::player_findz(...do here);
        players::player_angle(...do here);
        players::player_interior(...do here);
    }
#endif

#if !defined players::
    #define players::
    #define player_pos(%0)          SetPlayerPos(%0)
    #define player_findz(%0)        SetPlayerPosFindZ(%0)
    #define player_angle(%0)        SetPlayerFacingAngle(%0)
    #define player_interior(%0)     SetPlayerInterior(%0)
#endif
