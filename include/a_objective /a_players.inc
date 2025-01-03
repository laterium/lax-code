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
        players::player_virtualworld(...do here);
        players::player_color(...do here);
        players::player_health(...do here);
        players::player_armour(...do here);
        players::player_team(...do here);
        players::player_score(...do here);
        players::player_ammo(...do here);
        players::player_drunk(...do here);
    }
#endif

#if !defined players::
    #define players::
    #define player_pos(%0)          SetPlayerPos(%0)
    #define player_findz(%0)        SetPlayerPosFindZ(%0)
    #define player_angle(%0)        SetPlayerFacingAngle(%0)
    #define player_interior(%0)     SetPlayerInterior(%0)
    #define player_virtualworld(%0) SetPlayerVirtualWorld(%0)
    #define player_color(%0)        SetPlayerColor(%0)
    #define player_health(%0)       SetPlayerHealth(%0)
    #define player_armour(%0)       SetPlayerArmour(%0)
    #define player_team(%0)         SetPlayerTeam(%0)
    #define player_score(%0)        SetPlayerScore(%0)
    #define player_ammo(%0)         SetPlayerAmmo(%0)
    #define player_drunk(%0)        SetPlayerDrunkLevel(%0)
#endif
