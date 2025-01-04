#if !defined example
//    #include "System"

//    main() {}

//    public OnPlayerConnect(playerid) {
//        players::player_pos(......................format);
//        players::player_findz(....................format);
//        players::player_angle(....................format);
//        players::player_interior(.................format);
//        players::player_virtualworld(.............format);
//        players::player_color(....................format);
//        players::player_skin(.....................format);
//        players::player_health(...................format);
//        players::player_armour(...................format);
//        players::player_team(.....................format);
//        players::player_score(....................format);
//        players::player_ammo(.....................format);
//        players::player_giveweapon(...............format);
//        players::player_armedweapon(..............format);
//        players::player_resetweapon(..............format);
//        players::player_drunk(....................format);
//        players::player_wanted(...................format);
//        players::player_skill(....................format);
//        players::player_name(.....................format);
//        players::player_time(.....................format);
//        players::player_weather(..................format);
//        players::player_fightstyle(...............format);
//        players::player_velocity(.................format);
//        players::player_chatbubble(...............format);
//        players::player_camerapos(................format);
//        players::player_controllable(.............format);
//        players::player_shopname(.................format);
//        money::player_givemoney(..................format);
//        money::player_resetmoney(.................format);
//        animation::player_clearanim(..............format);
//        animation::player_animation(..............format);
//        animation::player_specialanim(............format);
//        mapicon::player_mapicon(..................format);
//        mapicon::player_removemapicon(............format);
//        spectate::player_togglespectate(..........format);
//        spectate::player_spectateplayer(..........format);
//        spectate::player_spectatevehicle(.........format);
//        textdraw::mouse(..........................format);
//        textdraw::unmouse(........................format);
//        message::client@player(...................format);
//        message::client@toall(....................format);
//        message::player@player(...................format);
//        message::player@toall(....................format);
//        message::death@player(....................format);
//        message::death@toplayer(..................format);
//    }
#endif

#if !defined players::
    #define player->
    #define players::
    #define player_pos(%0)                   SetPlayerPos(%0)
    #define player_findz(%0)                 SetPlayerPosFindZ(%0)
    #define player_angle(%0)                 SetPlayerFacingAngle(%0)
    #define player_interior(%0)              SetPlayerInterior(%0)
    #define player_virtualworld(%0)          SetPlayerVirtualWorld(%0)
    #define player_colour(%0)                SetPlayerColor(%0)
    #define player_color                     player_colour
    #define player_skin(%0)                  SetPlayerSkin(%0)
    #define player_health(%0)                SetPlayerHealth(%0)
    #define player_armour(%0)                SetPlayerArmour(%0)
    #define player_team(%0)                  SetPlayerTeam(%0)
    #define player_score(%0)                 SetPlayerScore(%0)
    #define player_ammo(%0)                  SetPlayerAmmo(%0)
    #define player_giveweapon(%0)            GivePlayerWeapon(%0)
    #define player_armedweapon(%0)           SetPlayerArmedWeapon(%0)
    #define player_resetweapon(%0)           ResetPlayerWeapons(%0)
    #define player_drunk(%0)                 SetPlayerDrunkLevel(%0)
    #define player_wanted(%0)                SetPlayerWantedLevel(%0)
    #define player_skill(%0)                 SetPlayerSkillLevel(%0)
    #define player_name(%0)                  SetPlayerName(%0)
    #define player_time(%0)                  SetPlayerTime(%0)
    #define player_weather(%0)               SetPlayerWeather(%0)
    #define player_fightstyle(%0)            SetPlayerFightingStyle(%0)
    #define player_velocity(%0)              SetPlayerVelocity(%0)
    #define player_chatbubble(%0)            SetPlayerChatBubble(%0)
    #define player_camerapos(%0)             SetPlayerCameraPos(%0)
    #define player_controllable(%0)          TogglePlayerControllable(%0)
    #define player_shopname(%0)              SetPlayerShopName(%0)
#endif
#if !defined money::
    #define money::
    #define player_givemoney(%0)             GivePlayerMoney(%0)
    #define player_resetmoney(%0)            ResetPlayerMoney(%0)
#endif
#if !defined animation::
    #define animation::
    #define player_clearanim(%0)             ClearAnimations(%0)
    #define player_animation(%0)             ApplyAnimation(%0)
    #define player_specialanim(%0)           SetPlayerSpecialAction(%0)
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
#if !defined textdraw::
    #define textdraw::
    #define mouse(%0)                        SelectTextDraw(%0)
    #define unmouse(%0)                      CancelSelectTextDraw(%0)
#endif
#if !defined message::
    #define message::
    #define client@player(%0)                SendClientMessage(%0)
    #define client@toall(%0)                 SendClientMessageToAll(%0)
    #define player@player(%0)                SendPlayerMessageToPlayer(%0)
    #define player@toall(%0)                 SendPlayerMessageToAll(%0)
    #define death@player(%0)                 SendDeathMessage(%0)
    #define death@toplayer(%0)               SendDeathMessageToPlayer(%0)
#endif
