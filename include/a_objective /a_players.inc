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

    public OnPlayerConnect(playerid) {
        players::player_pos(...do here);
        players::player_findz(...do here);
        players::player_angle(...do here);
        players::player_interior(...do here);
        players::player_virtualworld(...do here);
        players::player_color(...do here);
        players::player_skin(...do here);
        players::player_health(...do here);
        players::player_armour(...do here);
        players::player_team(...do here);
        players::player_score(...do here);
        players::player_ammo(...do here);
        players::player_resetweapon(...do here);
        players::player_armedweapon(...do here);
        players::player_giveweapon(...do here);
        players::player_drunk(...do here);
        players::player_wanted(...do here);
        players::player_skill(...do here);
        players::player_name(...do here);
        players::player_time(...do here);
        players::player_weather(...do here);
        players::player_fightstyle(...do here);
        players::player_velocity(...do here);
        players::player_shopname(...do here);
        players::player_chatbubble(...do here);
        players::player_camerapos(...do here);
        players::player_controllable(...do here);
        // money
        money::player_givemoney(...do here);
        money::player_resetmoney(...do here);
        // animation
        animation::player_clearanim(...do here);
        animation::player_animation(...do here);
        animation::player_specialanim(...do here);
        // mapicon
        mapicon::player_mapicon(...do here);
        mapicon::player_removemapicon(...do here);
        // spectate
        spectate::player_togglespectate(...do here);
        spectate::player_spectateplayer(...do here);
        spectate::player_spectatevehicle(...do here);
        // textdraw
        textdraw::player_selecttextdraw(...do here);
        textdraw::player_canceltextdraw(...do here);
        // message
        message::player_clientmsg@player(...do here);
        message::player_clientmsgto@all(...do here);
        message::player_messageto@player(...do here);
        message::player_messageto@all(...do here);
        message::player_messagedeath@player(...do here);
        message::player_messagedeath@toplayer(...do here);
    }
#endif

#if !defined players::
    #define players::
    #define player_pos(%0)                   SetPlayerPos(%0)
    #define player_findz(%0)                 SetPlayerPosFindZ(%0)
    #define player_angle(%0)                 SetPlayerFacingAngle(%0)
    #define player_interior(%0)              SetPlayerInterior(%0)
    #define player_virtualworld(%0)          SetPlayerVirtualWorld(%0)
    #define player_color(%0)                 SetPlayerColor(%0)
    #define player_skin(%0)                  SetPlayerSkin(%0)
    #define player_health(%0)                SetPlayerHealth(%0)
    #define player_armour(%0)                SetPlayerArmour(%0)
    #define player_team(%0)                  SetPlayerTeam(%0)
    #define player_score(%0)                 SetPlayerScore(%0)
    #define player_ammo(%0)                  SetPlayerAmmo(%0)
    #define player_resetweapon(%0)           ResetPlayerWeapons(%0)
    #define player_armedweapon(%0)           SetPlayerArmedWeapon(%0)
    #define player_giveweapon(%0)            GivePlayerWeapon(%0)
    #define player_drunk(%0)                 SetPlayerDrunkLevel(%0)
    #define player_wanted(%0)                SetPlayerWantedLevel(%0)
    #define player_skill(%0)                 SetPlayerSkillLevel(%0)
    #define player_name(%0)                  SetPlayerName(%0)
    #define player_time(%0)                  SetPlayerTime(%0)
    #define player_weather(%0)               SetPlayerWeather(%0)
    #define player_fightstyle(%0)            SetPlayerFightingStyle(%0)
    #define player_velocity(%0)              SetPlayerVelocity(%0)
    #define player_shopname(%0)              SetPlayerShopName(%0)
    #define player_chatbubble(%0)            SetPlayerChatBubble(%0)
    #define player_camerapos(%0)             SetPlayerCameraPos(%0)
    #define player_controllable(%0)          TogglePlayerControllable(%0)
#endif
#if !defined mapicon::
    #define mapicon::
    #define player_mapicon(%0)               SetPlayerSpecialAction(%0)
    #define player_removemapicon(%0)         RemovePlayerMapIcon(%0)
#endif
#if !defined spectate::
    #define spectate::
    #define player_togglespectate(%0)        TogglePlayerSpectating(%0)
    #define player_spectateplayer(%0)        PlayerSpectatePlayer(%0)
    #define player_spectatevehicle(%0)       PlayerSpectateVehicle(%0)
#endif
#if !defined money::
    #define money::
    #define player_givemoney(%0)             GivePlayerMoney(%0)
    #define player_resetmoney(%0)            ResetPlayerMoney(%0)
#endif
#endif
#if !defined textdraw::
    #define textdraw::
    #define player_selecttextdraw(%0)        SelectTextDraw(%0)
    #define player_canceltextdraw(%0)        CancelSelectTextDraw(%0)
#endif
#if !defined animation::
    #define animation::
    #define player_clearanim(%0)             ClearAnimations(%0)
    #define player_animation(%0)             ApplyAnimation(%0)
    #define player_specialanim(%0)           SetPlayerSpecialAction(%0)
#endif
#if !defined message::
    #define message::
    #define player_clientmsg@player(%0)      SendClientMessage(%0)
    #define player_clientmsgto@all(%0)       SendClientMessageToAll(%0)
    #define player_messageto@player(%0)      SendPlayerMessageToPlayer(%0)
    #define player_messageto@all(%0)         SendPlayerMessageToAll(%0)
    #define player_messagedeath@player(%0)   SendDeathMessage(%0)
    #define player_messagedeath@toplayer(%0) SendDeathMessageToPlayer(%0)
#endif
