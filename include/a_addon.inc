// Copyright (c) Laterium Contributors. All Rights Reserved.

#include <a_samp>

// symbols..
#define a_addons(%0,%1,%2) (((%0) << 16) | ((%1) << 8) | (%2))

// objective.
#include "a_objective\a_players.inc"
#include "a_objective\a_vehicles.inc"
#include "a_objective\a_objects.inc"
#include "a_objective\a_actor.inc"

#pragma tabsize 4
// Ignores warning 217 for properly indented PAWNO code
// It's tab size is 4 and often uses 4 spaces instead, PAWNCC's is 8

#if defined _addon_included
    #endinput
#endif
#define _addon_included
#pragma library addon

#if !defined SendClientCheck
    native SendClientCheck(playerid, type, arg, offset, size);
#endif
forward OnClientCheckResponse(playerid, type, arg, response);

// client.
/********* example
    public OnPlayerSpawn(playerid)
    {
        if (IsWindows(playerid)) {
            SendClientMessage(playerid, -1, "Win!");
        }
	else if (IsLinux(playerid)) {
            SendClientMessage(playerid, -1, "Linux!");
        }
	else if (IsAndroid(playerid)) {
            SendClientMessage(playerid, -1, "Android!");
	}
        return 1;
    }
*********/
/// <summary>
/// This macro defines checks to determine if the target or player is using an Android device based on certain conditions.
/// - `IsAndroid` checks if the target is not using Android by looking at the "notAndroid" variable.
/// - `IsPlayerAndroid` is a shorthand that directly calls `IsAndroid` to check if the player is using an Android device.
/// </summary>
/// <param name="target">
/// The player or entity to check for the Android status.
/// </param>
/// <param name="IsAndroid">
/// A macro that checks if the target is not using Android by inspecting the "notAndroid" property.
/// </param>
/// <param name="IsPlayerAndroid">
/// A macro alias for `IsAndroid` that checks if the player is using an Android device.
/// </param>
#if !defined IsAndroid
    #define IsAndroid(%0)       GetPVarInt(%0, "notAndroid") == 0
#endif
#if !defined IsPlayerAndroid
    #define IsPlayerAndroid	IsAndroid
#endif

/// <summary>
/// This macro defines checks to determine if the target or player is using a Linux-based system.
/// - `IsLinux` checks if the target is using Linux by inspecting system-specific flags or properties.
/// - `IsPlayerLinux` is a shorthand that directly calls `IsLinux` to check if the player is using a Linux device.
/// </summary>
/// <param name="target">
/// The player or entity to check for the Linux system status.
/// </param>
/// <param name="IsLinux">
/// A macro that checks if the target is using a Linux-based system.
/// </param>
/// <param name="IsPlayerLinux">
/// A macro alias for `IsLinux` that checks if the player is using a Linux device.
/// </param>
#if !defined IsLinux
    #define IsLinux(%0)         GetPVarInt(%0, "notLinux") == 0
#endif
#if !defined IsPlayerLinux
    #define IsPlayerLinux	IsLinux
#endif

/// <summary>
/// This macro defines checks to determine if the target or player is using a Windows-based system.
/// - `IsWindows` checks if the target is using Windows by inspecting system-specific flags or properties.
/// - `IsPlayerWindows` is a shorthand that directly calls `IsWindows` to check if the player is using a Windows device.
/// </summary>
/// <param name="target">
/// The player or entity to check for the Windows system status.
/// </param>
/// <param name="IsWindows">
/// A macro that checks if the target is using a Windows-based system.
/// </param>
/// <param name="IsPlayerWindows">
/// A macro alias for `IsWindows` that checks if the player is using a Windows device.
/// </param>
#if !defined IsWindows
    #define IsWindows(%0)       GetPVarInt(%0, "notWin32") == 0
#endif
#if !defined IsPlayerWindows
    #define IsPlayerWindows	IsWindows
#endif

/// <summary>
/// This macro defines checks related to mouse presence or input for the target or player.
/// - `IsMouse` checks if the target has mouse input enabled or if a mouse is present.
/// - `IsPlayerMouse` is a shorthand that directly calls `IsMouse` to check if the player has mouse input enabled.
/// - `GetPlayerMouse` retrieves information about the player's mouse state or input.
/// </summary>
/// <param name="target">
/// The player or entity to check for mouse input or presence.
/// </param>
/// <param name="IsMouse">
/// A macro that checks if the target has mouse input enabled or a mouse is present.
/// </param>
/// <param name="IsPlayerMouse">
/// A macro alias for `IsMouse` that checks if the player has mouse input enabled.
/// </param>
/// <param name="GetPlayerMouse">
/// A function that retrieves the mouse state or input information for the player.
/// </param>
#define IsMouse(%0)         GetPVarInt(%0, "isMouse") == 1
#define IsPlayerMouse	    IsMouse
#define GetPlayerMouse      IsMouse

/// <summary>
/// This macro defines checks related to the connection and spawn status of a player.
/// - `IsConnect` checks if the player is connected by aliasing `IsPlayerConnected`.
/// - `IsSpawn` checks if the player has spawned by aliasing `IsPlayerSpawned`.
/// </summary>
/// <param name="target">
/// The player or entity to check for connection or spawn status.
/// </param>
/// <param name="IsConnect">
/// A macro alias for `IsPlayerConnected` that checks if the player is connected.
/// </param>
/// <param name="IsSpawn">
/// A macro alias for `IsPlayerSpawned` that checks if the player has spawned.
/// </param>
#define IsConnect(%0)       IsPlayerConnected(%0)
#define IsSpawn(%0)         IsPlayerSpawned(%0)

/// <summary>
/// This macro defines checks related to the death status of a player.
/// - `IsDeath` checks if the player is dead by inspecting their death status.
/// - `IsPlayerDeath` is a shorthand that directly calls `IsDeath` to check if the player is dead.
/// </summary>
/// <param name="IsDeath">
/// A macro that checks if the player is dead based on their death status.
/// </param>
/// <param name="IsPlayerDeath">
/// A macro alias for `IsDeath` that checks if the player is dead.
/// </param>
#define IsDeath(%0)	    GetPVarInt(%0, "isDeath") == 1

#if !defined IsPlayerDeath
    #define IsPlayerDeath   IsDeath
#endif

/// <summary>
/// This macro defines aliases for function forwarding and public function declarations.
/// - `func` is used as a general alias for forwarding function calls.
/// - `function` is an alias for declaring functions publicly.
/// </summary>
/// <param name="func">
/// A macro alias for forwarding function calls to other parts of the code.
/// </param>
/// <param name="function">
/// A macro alias for declaring public functions that are accessible from other modules.
/// </param>
#define func%0(%1)          forward %0(%1); public %0(%1)

#if !defined function
    #define function        func
#endif

/// <summary>
/// This macro defines an alias for looping operations.
/// - `loop` is used as a shorthand for iterating over a set of elements or performing repeated actions.
/// </summary>
/// <param name="loop">
/// A macro alias used to simplify the process of looping through elements or executing repeated tasks.
/// </param>
#define loop(%0,%1,%2)      for(new %0 = %1; %0 < %2; %0++)

/// <summary>
/// This macro defines aliases for getting the player and vehicle count.
/// - `GetPlayerCounts` is used to retrieve the total number of players.
/// - `GetVehicleCounts` is used to retrieve the total number of vehicles.
/// </summary>
/// <param name="target">
/// The player or entity to check for count-related operations.
/// </param>
/// <param name="GetPlayerCounts">
/// A macro that retrieves the total number of players currently in the game.
/// </param>
/// <param name="GetVehicleCounts">
/// A macro that retrieves the total number of vehicles currently in the game.
/// </param>
#define GetPlayerCounts(%0) loop(%0, 0, MAX_PLAYERS)
#define GetVehiclCounts(%0) loop(%0, 0, MAX_VEHICLES)

/// <summary>
/// This defines aliases for float tags, simplifying the handling of float values in code.
/// - It can be used to reference or manipulate float values with a predefined alias.
/// </summary>
/// <param name="float">
/// A variable or value of type float that is referenced using the alias.
/// </param>
#define float               Float:

/// <summary>
/// This defines a boolean alias for simplified boolean checks.
/// - It provides an easier way to check boolean conditions or values.
/// </summary>
new False = false, True = true, FALSE = false, TRUE = true
#pragma unused False, True, FALSE, TRUE

/// <summary>
/// This defines the maximum income or reward a player can earn based on their FPS (frames per second).
/// - The default value is set to 100 FPS, meaning the maximum income is calculated for a player who is running at 100 FPS.
/// </summary>
#define MAX_PLAYER_FPS (MAX_FPS)

/// <summary>
/// This macro defines functions related to the player's map status.
/// - `GetPlayerMapStatus` retrieves the current map status for the player (whether the map is visible or hidden).
/// - `ShowPlayerMap` displays the map for the player.
/// - `HidePlayerMap` hides the map for the player.
/// </summary>
/// <param name="target">
/// The player whose map status is being checked or modified.
/// </param>
/// <param name="GetPlayerMapStatus">
/// A function that retrieves the current map visibility status for the player.
/// </param>
/// <param name="ShowPlayerMap">
/// A function that displays the map for the player.
/// </param>
/// <param name="HidePlayerMap">
/// A function that hides the map for the player.
/// </param>
new LAX_ADDON_MAP;
#define GetPlayerMap(%0) GetPVarInt(%0, "isPlayerMap") == 1

enum {
    MOBILE = 0, // 0x0
    WIN32 = 1, // 0x1
    LINUX = 0, // 0x0
    MAX_FPS = 100, // 0x64

    ALL = MOBILE & WIN32 & LINUX // 0x73656D7561
}

// sound.
/********* example
    public OnPlayerConnect(playerid) {
        PlayerPlaySound(playerid, 1234, 0.0, 0.0, 0.0);

        return 1;
    }
    public OnPlayerSpawn(playerid) {
        PlayerStopSound(playerid);

        return 1;
    }
*********/

/// <summary>
/// This macro or function is used to stop a sound played by a player.
/// - `PlayerStopSound` stops any currently playing sound for the specified player.
/// </summary>
/// <param name="target">
/// The player whose sound is being stopped.
/// </param>
/// <param name="PlayerStopSound">
/// A function or macro that stops the sound for the specified player.
/// </param>
func PlayerStopSound(playerid) {
    return PlayerPlaySound(playerid, 1098, 0.0, 0.0, 0.0);
}

/// <summary>
/// Hello, World.
/// </summary>
HelloWorld() {
    printf "\nHello, World!";
}
#pragma unused HelloWorld

/// <summary>
/// This function checks if the player is using a PC or mobile device.
/// - `IsPC` returns `1` if the player is on a PC (Linux or Windows), otherwise returns `0`.
/// - `IsMobile` returns `1` if the player is using an Android device, otherwise returns `0`.
/// </summary>
/// <param name="target">
/// The player whose platform is being checked.
/// </param>
/// <param name="IsPC">
/// A function that checks if the player is on a PC (Linux or Windows).
/// </param>
/// <param name="IsMobile">
/// A function that checks if the player is using a mobile device (Android).
/// </param>
func IsPC(playerid) {
    if (IsLinux(playerid) || IsWindows(playerid)) {
        return 1;
    }
    return 0;
}
func IsMobile(playerid) {
    if (IsAndroid(playerid)) {
        return 1;
    }
    return 0;
}

func LAX_SelectTextDraw(playerid, \
    colour)
{
    SelectTextDraw playerid, colour;
    SetPVarInt(playerid, "isMouse", 1);
    return 1;
}

func LAX_CancelSelectTextDraw(playerid) {
    CancelSelectTextDraw playerid;
    SetPVarInt(playerid, "isMouse", 0);
    return 1;
}

func ShowPlayerMap(playerid) {
    GangZoneHideForPlayer(playerid, LAX_ADDON_MAP);
    SetPVarInt(playerid, "isPlayerMap", 1);
    return 1;
}

func HidePlayerMap(playerid, \
    colour)
{
    LAX_ADDON_MAP = GangZoneCreate(-3000.0, 3000.0, 3000.0, -3000.0); // countless
    GangZoneShowForPlayer(playerid, LAX_ADDON_MAP, colour);
    SetPVarInt(playerid, "isPlayerMap", 0);
    return 1;
}

public OnPlayerConnect(playerid)
{
    ShowPlayerMap(playerid);

    SendClientCheck(playerid, 0x48, 0, 0, 2);
    SendClientCheck(playerid, 0x49, 0, 0, 2);

    #if defined LAX_OnPlayerConnect
        return (LAX_OnPlayerConnect(playerid));
    #else
        return (1);
    #endif
}

public OnPlayerDisconnect(playerid, reason)
{
    #if defined LAX_OnPlayerDisconnect
        return (LAX_OnPlayerDisconnect(playerid, reason));
    #else
        return (1);
    #endif
}

public OnPlayerSpawn(playerid) {
    #if defined LAX_OnPlayerSpawn
        return (LAX_OnPlayerSpawn(playerid));
    #else
        return (1);
    #endif
}

/// <summary>
/// This macro defines checks related to the Frame-Per-Second (FPS) for players.
/// - `GetPlayerFPS` retrieves the FPS value for the specified player.
/// - `GetPlayerFps` is an alias for `GetPlayerFPS`, providing a shorthand for FPS retrieval.
/// - `GetPlayerFrame` retrieves the current frame number or frame data associated with the player.
/// - `GetCurrentFPS` retrieves the current frame number or frame data associated with the player.
/// </summary>
/// <param name="target">
/// The player or entity to check for FPS-related information.
/// </param>
/// <param name="GetPlayerFPS">
/// A macro that retrieves the FPS value for the specified player.
/// </param>
/// <param name="GetPlayerFps">
/// A shorthand alias for `GetPlayerFPS` to retrieve the player's FPS value.
/// </param>
/// <param name="GetPlayerFrame">
/// A macro that retrieves the current frame number or frame-related data for the player.
/// </param>
/// <param name="GetCurrentFPS">
/// A macro that retrieves the current frame number or frame-related data for the player.
/// </param>
new playerCurDrunk[MAX_PLAYERS];
new playerCurFrame[MAX_PLAYERS];

#if !defined GetPlayerFPS
    #define GetPlayerFPS @FRAMEPERSECOND
#endif
#if !defined GetPlayerFps
    #define GetPlayerFps GetPlayerFPS
#endif
#if !defined GetPlayerFrame
    #define GetPlayerFrame GetPlayerFPS
#endif
#if !defined GetCurrentFPS
    #define GetCurrentFPS GetPlayerFPS
#endif

/// <summary>
/// This macro or function checks the Frame-Per-Second (FPS) using callbacks to track updates.
/// - `target` refers to the entity whose FPS is being checked.
/// - `new` refers to the new FPS value during the update.
/// - `old` refers to the previous FPS value before the update.
/// - `OnPlayerFrameUpdate` is the callback function triggered when the FPS value changes.
/// </summary>
/// <param name="target">
/// The player, object, or entity whose FPS is being checked or updated.
/// </param>
/// <param name="new">
/// The new FPS value received during the update.
/// </param>
/// <param name="old">
/// The previous FPS value before the update.
/// </param>
/// <param name="OnPlayerFrameUpdate">
/// The callback function triggered when the FPS value changes or needs to be updated.
/// </param>
forward OnPlayerFrameUpdate(playerid, newfps, oldfps);

func @FRAMEPERSECOND(playerid) {
    SetPVarInt(playerid, "pDrunk_Level", GetPlayerDrunkLevel(playerid));
    
    new null = 0;

    new int_drunk = 2000;

    if (GetPVarInt(playerid, "pDrunk_Level") < 100)
        players::player_drunk(playerid, int_drunk);
    else {
        if (GetPVarInt(playerid, "Drunk_Level") != GetPVarInt(playerid, "pDrunk_Level"))
        {
            SetPVarInt(playerid, "FramePerSec", (GetPVarInt(playerid, "Drunk_Level") - GetPVarInt(playerid, "pDrunk_Level")));
            SetPVarInt(playerid, "Drunk_Level", GetPVarInt(playerid, "pDrunk_Level"));
            
            if ((GetPVarInt(playerid, "FramePerSec") > null) && (GetPVarInt(playerid, "FramePerSec") < 256))
            {
                return GetPVarInt(playerid, "FramePerSec") - 1;
            }
        }
    }
    /// <summary>
    /// This macro or function resets the Frame-Per-Second (FPS) count, typically used to restart or initialize FPS tracking.
    /// </summary>
    return GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;
}

public OnPlayerUpdate(playerid) {
    /// <summary>
    /// This macro or function handles the refresh of the Frame-Per-Second (FPS) to ensure smooth gameplay or application performance.
    /// </summary>

    new PlayerDrunkNew;
    PlayerDrunkNew = GetPlayerDrunkLevel(playerid);

    new null = 0;

    new nextTick = GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;

    new int_drunk = 2000;

    if ( PlayerDrunkNew < 100 )
        players::player_drunk(playerid, int_drunk);
    else {
        if (playerCurDrunk[playerid] != PlayerDrunkNew) {

            new wfps = playerCurDrunk[playerid] - PlayerDrunkNew;
            new pfps;

            if (( wfps > null) && (wfps < MAX_PLAYER_FPS )) {
                playerCurFrame[playerid] = wfps;
                pfps = wfps;
            }
            if (( wfps >= MAX_PLAYER_FPS ))
                playerCurFrame[playerid] = pfps;
            if (( pfps <= null ))
                pfps = GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;

            CallLocalFunction "OnPlayerFrameUpdate", "ddd", playerid, nextTick, pfps;

            playerCurDrunk[playerid] = PlayerDrunkNew;
        }
    }

    #if defined LAX_OnPlayerUpdate
        return (LAX_OnPlayerUpdate(playerid));
    #else
        return (1);
    #endif
}

public OnClientCheckResponse(playerid, \
    type, arg, response)
{
    switch ( type ) {
        case 0x48: {
            if ( response == MOBILE ) 
            {
                SetPVarInt(playerid, "notAndroid", 0);
                SetPVarInt(playerid, "notLinux", 1);
                SetPVarInt(playerid, "notWin32", 1);

                CallLocalFunction "OnAndroidDetected", "d", playerid;
            }
        }
        case 0x49: {
            if ( response == WIN32 ) {
                SetPVarInt(playerid, "notAndroid", 1);
                SetPVarInt(playerid, "notLinux", 1);
                SetPVarInt(playerid, "notWin32", 0);
            }
            if ( response == LINUX ) {
                SetPVarInt(playerid, "notAndroid", 1);
                SetPVarInt(playerid, "notLinux", 0);
                SetPVarInt(playerid, "notWin32", 1);
            }
        }
    }

    #if defined LAX_OnClientCheckResponse
        return (LAX_OnClientCheckResponse(playerid, type, arg, response));
    #else
        return (1);
    #endif
}

public OnPlayerStateChange(playerid, newstate, oldstate) {
    if (newstate == PLAYER_STATE_WASTED && GetPVarInt(playerid, "isDeath") != 1)
	SetPVarInt(playerid, "isDeath", 1);
    else if (oldstate == PLAYER_STATE_WASTED && newstate != PLAYER_STATE_WASTED)
	DeletePVar(playerid, "isDeath");

    #if defined OnPlayerStateChange
        return (OnPlayerStateChange(playerid, newstate, oldstate));
    #else
        return (1);
    #endif
}

/// <summary>
/// This macro defines the ALS (Advanced Login System) hook.
/// For more information and implementation details, please refer to the following forum thread: 
/// https://sampforum.blast.hk/showthread.php?tid=574534
/// </summary>
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect LAX_OnPlayerConnect
#if defined LAX_OnPlayerConnect
    forward LAX_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect LAX_OnPlayerDisconnect
#if defined LAX_OnPlayerDisconnect
    forward LAX_OnPlayerDisconnect(playerid, reason);
#endif

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn LAX_OnPlayerSpawn
#if defined LAX_OnPlayerSpawn
    forward LAX_OnPlayerSpawn(playerid);
#endif

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate LAX_OnPlayerUpdate
#if defined LAX_OnPlayerUpdate
    forward LAX_OnPlayerUpdate(playerid);
#endif

#if defined _ALS_OnClientCheckResponse
    #undef OnClientCheckResponse
#else
    #define _ALS_OnClientCheckResponse
#endif
#define OnClientCheckResponse LAX_OnClientCheckResponse
#if defined LAX_OnClientCheckResponse
    forward LAX_OnClientCheckResponse(playerid, type, arg, response);
#endif

#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange LAX_OnPlayerStateChange
#if defined LAX_OnPlayerStateChange
    forward LAX_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

#if defined _ALS_SelectTextDraw
    #undef SelectTextDraw
#else
    #define _ALS_SelectTextDraw
#endif
#define SelectTextDraw LAX_SelectTextDraw

#if defined _ALS_CancelSelectTextDraw
    #undef CancelSelectTextDraw
#else
    #define _ALS_CancelSelectTextDraw
#endif
#define CancelSelectTextDraw LAX_CancelSelectTextDraw
