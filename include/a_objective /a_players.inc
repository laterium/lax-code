/// <summary>
/// This section defines a set of macros for managing player-related actions and attributes in the game. 
/// Each macro is a simplified version of the corresponding function that deals with player properties and actions.
///
/// Player Macros:
/// - player_pos(%0)               : Sets the position of the player.
/// - player_findz(%0)             : Sets the player's position and automatically finds the Z coordinate.
/// - player_angle(%0)             : Sets the player's facing angle (rotation).
/// - player_interior(%0)          : Sets the player's interior ID.
/// - player_virtualworld(%0)      : Sets the player's virtual world ID.
/// - player_colour(%0)            : Sets the player's color (used for skins and other aspects).
/// - player_color                 : Alias for `player_colour`, sets the player's color.
/// - player_skin(%0)              : Sets the player's skin (model).
/// - player_health(%0)            : Sets the player's health value.
/// - player_armour(%0)            : Sets the player's armor value.
/// - player_team(%0)              : Sets the player's team ID.
/// - player_score(%0)             : Sets the player's score.
/// - player_ammo(%0)              : Sets the player's ammo count.
/// - player_giveweapon(%0)        : Gives the player a weapon with specified properties.
/// - player_armedweapon(%0)       : Sets the player's armed weapon.
/// - player_resetweapon(%0)       : Resets the player's weapons (removes all weapons).
/// - player_drunk(%0)             : Sets the player's drunk level.
/// - player_wanted(%0)            : Sets the player's wanted level (police attention).
/// - player_skill(%0)             : Sets the player's skill level in various attributes.
/// - player_name(%0)              : Sets the player's name.
/// - player_time(%0)              : Sets the time for the player (day/night cycle).
/// - player_weather(%0)           : Sets the weather for the player.
/// - player_fightstyle(%0)        : Sets the player's fighting style.
/// - player_velocity(%0)          : Sets the player's velocity (movement speed).
/// - player_chatbubble(%0)        : Sets the player's chat bubble (for messages).
/// - player_camerapos(%0)         : Sets the player's camera position.
/// - player_controllable(%0)      : Toggles whether the player can control their character.
/// - player_shopname(%0)          : Sets the name of the shop the player is interacting with.
/// </summary>

/// <summary>
/// Money-related macros for managing player money actions.
///
/// Money Macros:
/// - player_givemoney(%0)         : Gives the player a specific amount of money.
/// - player_resetmoney(%0)        : Resets the player's money balance to zero.
/// </summary>

/// <summary>
/// Animation-related macros for controlling player animations.
///
/// Animation Macros:
/// - player_clearanim(%0)         : Clears the player's current animations.
/// - player_animation(%0)         : Applies a specified animation to the player.
/// - player_specialanim(%0)       : Sets a special animation for the player.
/// </summary>

/// <summary>
/// Map icon-related macros for managing map icons related to players.
///
/// Map Icon Macros:
/// - player_mapicon(%0)           : Sets a special map icon for the player.
/// - player_removemapicon(%0)     : Removes the specified map icon from the player.
/// </summary>

/// <summary>
/// Spectating-related macros for managing player spectating actions.
///
/// Spectating Macros:
/// - player_togglespectate(%0)    : Toggles the player's spectating mode on or off.
/// - player_spectateplayer(%0)    : Makes the player spectate another player.
/// - player_spectatevehicle(%0)   : Makes the player spectate a vehicle.
/// </summary>

/// <summary>
/// Text drawing macros for selecting and deselecting text draws for players.
///
/// Text Draw Macros:
/// - mouse(%0)                    : Selects the specified text draw for the player.
/// - unmouse(%0)                  : Cancels the selection of the text draw for the player.
/// </summary>

/// <summary>
/// Message-related macros for sending messages to players or all players.
///
/// Message Macros:
/// - client@player(%0)            : Sends a message to a specific player.
/// - client@toall(%0)             : Sends a message to all players.
/// - player@player(%0)            : Sends a private message to another player.
/// - player@toall(%0)             : Sends a message to all players (similar to `client@toall`).
/// - death@player(%0)             : Sends a death message to a specific player.
/// - death@toplayer(%0)           : Sends a death message to a player when they kill someone else.
/// </summary>
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
