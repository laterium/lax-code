// Copyright (c) Laterium Contributors. All Rights Reserved.

#include <a_samp>

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

/// <summary>
/// Android Checker
/// Original Android Checker @fairuz.
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsAndroid"></param>
#if !defined IsAndroid
    #define IsAndroid(%0)       GetPVarInt(%0, "notAndroid") == 0
#endif

/// <summary>
/// Linux Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsLinux"></param>
#if !defined IsLinux
    #define IsLinux(%0)         GetPVarInt(%0, "notLinux") == 0
#endif

/// <summary>
/// Windows Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsWindows"></param>
#if !defined IsWindows
    #define IsWindows(%0)       GetPVarInt(%0, "notWin32") == 0
#endif

/// <summary>
/// Mouse Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsMouse"></param>
/// <param name="GetPlayerMouse"></param>
#define IsMouse(%0)         GetPVarInt(%0, "isMouse") == 1
#define GetPlayerMouse      IsMouse

/// <summary>
/// Connect alias Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsConnect"></param>
#define IsConnect(%0)       IsPlayerConnected(%0)

/// <summary>
/// Spawn alias Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsSpawn"></param>
#define IsSpawn(%0)         IsPlayerSpawned(%0)

/// <summary>
/// Dialog alias
/// </summary>
/// <param name="HidePlayerDialog"></param>

/// <summary>
/// do not using a function "func"
/// </summary>
#define HidePlayerDialog(%0) ShowPlayerDialog(%0, -1, DIALOG_STYLE_MSGBOX, "", "", "", "")

/// <summary>
/// function forward & public alias
/// </summary>
/// <param name="func"></param>
/// <param name="function"></param>
#define func%0(%1)          forward %0(%1); public %0(%1)

#if !defined function
    #define function        func
#endif

/// <summary>
/// looping alias
/// </summary>
/// <param name="loop"></param>
#define loop(%0,%1,%2)      for(new %0 = %1; %0 < %2; %0++)

/// <summary>
/// player & vehicle count alias
/// </summary>
/// <param name="target">
/// </param>
/// <param name="GetPlayerCounts"></param>
/// <param name="GetVehiclCounts"></param>
#define GetPlayerCounts(%0) loop(%0, 0, MAX_PLAYERS)
#define GetVehiclCounts(%0) loop(%0, 0, MAX_VEHICLES)

/// <summary>
/// Float tags alias
/// </summary>
/// <param name="float"></param
#define float               Float:

/// <summary>
/// Boolean
/// </summary>
new False = false, True = true, FALSE = false, TRUE = true
#pragma unused False, True, FALSE, TRUE

/// <summary>
/// maximum income from player fps
/// default : 100 FPS
/// </summary>
#define MAX_PLAYER_FPS (MAX_FPS)

/// <summary>
/// Addon Map Status
/// </summary>
/// <param name="target">
/// </param>
/// <param name="GetPlayerMapStatus"></param>
/// <param name="HidePlayerMap"></param>
/// <param name="ShowPlayerMap"></param>
new LAX_ADDON_MAP;
#define GetPlayerMapStatus(%0) GetPVarInt(%0, "isPlayerMap") == 1

enum
{
    UNKNOWN = -1, // 0xFFFF
    NONE = 0, // none
    MOBILE = 0, // do not edit this.
    WIN32 = 1, // do not edit this.
    LINUX = 0, // do not edit this.
    MAX_FPS = 100, // default: 100 FPS.

    IGNORE = UNKNOWN | NONE,
    ALL = MOBILE & WIN32 & LINUX
}

/// <summary>
/// Stop Player Sound from PlayerPlaySound.
/// </summary>
/// <param name="target">
/// </param>
/// <param name="PlayerStopSound"></param>
func PlayerStopSound(playerid) {
    return PlayerPlaySound(playerid,1098,0.0,0.0,0.0);
}

static stock const rc[20] = {
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0,
    0xdb92371d, 0x2126e970, 0x03249775, 0x04e8c90e,
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0
};

/// <summary>
/// Android/Linux/Windows Checker from Callbacks.
/// </summary>
/// <param name="target">
/// </param>
/// <param name="OnAndroidDetected"></param>
/// <param name="OnLinuxDetected"></param>
/// <param name="OnWindowsDetected"></param>
forward OnAndroidDetected(playerid);
forward OnLinuxDetected(playerid);
forward OnWindowsDetected(playerid);

/// <summary>
/// Mouse Checker.
/// </summary>
/// <param name="OnPlayerMouse"></param>
/// <param name="OnPlayerOffMouse"></param>
func LAX_SelectTextDraw(playerid, \
    colour)
{
    SelectTextDraw playerid, colour;
    SetPVarInt(playerid, "isMouse", 1);
    CallLocalFunction "OnPlayerMouse", "d", playerid;
    return 1;
}

func LAX_CancelSelectTextDraw(playerid) {
    CancelSelectTextDraw playerid;
    SetPVarInt(playerid, "isMouse", 0);
    CallLocalFunction "OnPlayerOffMouse", "d", playerid;
    return 1;
}

/// <summary>
/// Is PC Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsPC"></param>
func IsPC(playerid) {
    if (IsLinux(playerid) || IsWindows(playerid)) {
        return 1;
    }
    return 0;
}

/// <summary>
/// Is Android Checker
/// </summary>
/// <param name="target">
/// </param>
/// <param name="IsMobile"></param>
func IsMobile(playerid) {
    if (IsAndroid(playerid)) {
        return 1;
    }
    return 0;
}

func HidePlayerMap(playerid, \
    colour)
{
    LAX_ADDON_MAP = GangZoneCreate(-3000.0, 3000.0, 3000.0, -3000.0); // countless
    GangZoneShowForPlayer(playerid, LAX_ADDON_MAP, colour);
    SetPVarInt(playerid, "isPlayerMap", 0);
    return 1;
}

func ShowPlayerMap(playerid) {
    GangZoneHideForPlayer(playerid, LAX_ADDON_MAP);
    SetPVarInt(playerid, "isPlayerMap", 1);
    return 1;
}

public OnPlayerConnect(playerid)
{
    SetPVarInt(playerid, "isPlayerMap", 1);

    SendClientCheck(playerid, 0x48, 0, 0, 2);
    SendClientCheck(playerid, 0x49, 0, 0, 2);

    #if defined LAX_OnPlayerConnect
      return (LAX_OnPlayerConnect(playerid));
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
/// Frame-Per-Second (FPS) Checker.
/// </summary>
/// <param name="target">
/// </param>
/// <param name="GetPlayerFPS"></param>
/// <param name="GetPlayerFps"></param>
/// <param name="GetPlayerFrame"></param>
new _PlayerDrunk[MAX_PLAYERS];
new _PlayerFrame[MAX_PLAYERS];

#if !defined GetPlayerFPS
    #define GetPlayerFPS @FRAMEPERSECOND_
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
/// Frame-Per-Second (FPS) Checker from Callbacks.
/// </summary>
/// <param name="target">
/// <param name="old">
/// <param name="new">
/// </param>
/// <param name="OnPlayerFPSUpdate"></param>
forward OnPlayerFPSUpdate(playerid, oldfps, newfps);

func @FRAMEPERSECOND_(playerid) {
    SetPVarInt(playerid, "DrunkL", GetPlayerDrunkLevel(playerid));
    
    new null = 0;

    new int_drunk = 2000;

    if (GetPVarInt(playerid, "DrunkL") < 100)
    {
        SetPlayerDrunkLevel(playerid, int_drunk);
    }
    else {
        if (GetPVarInt(playerid, "Drunk_Level") != GetPVarInt(playerid, "DrunkL"))
        {
            SetPVarInt(playerid, "FramePerSec", (GetPVarInt(playerid, "Drunk_Level") - GetPVarInt(playerid, "DrunkL")));
            SetPVarInt(playerid, "Drunk_Level", GetPVarInt(playerid, "DrunkL"));
            
            if ((GetPVarInt(playerid, "FramePerSec") > null) && (GetPVarInt(playerid, "FramePerSec") < 256))
            {
                return GetPVarInt(playerid, "FramePerSec") - 1;
            }
        }
    }
    /// <summary>
    /// Frame-Per-Second (FPS) reset.
    /// </summary>
    return GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;
}

public OnPlayerUpdate(playerid)
{
    /// <summary>
    /// Frame-Per-Second (FPS) reset.
    /// </summary>
    new PlayerDrunkNew;
    PlayerDrunkNew = GetPlayerDrunkLevel(playerid);

    new null = 0;

    new nextTick = GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;

    new int_drunk = 2000;

    if ( PlayerDrunkNew < 100 ) {
        SetPlayerDrunkLevel(playerid, int_drunk);
    }
    else {
        if (_PlayerDrunk[playerid] != PlayerDrunkNew) {

            new wfps = _PlayerDrunk[playerid] - PlayerDrunkNew;
            new pfps;

            if (( wfps > null) && (wfps < MAX_PLAYER_FPS )) {
                _PlayerFrame[playerid] = wfps;
                pfps = wfps;
            }
            if (( wfps >= MAX_PLAYER_FPS )) {
                _PlayerFrame[playerid] = pfps;
            }
            if (( pfps <= null )) {
                pfps = GetPVarInt(playerid, "FramePerSec") > null ? GetPVarInt(playerid, "FramePerSec") - 1 : random(60) + 29;
            }

            CallLocalFunction "OnPlayerFPSUpdate", "ddd", playerid, pfps, nextTick;

            _PlayerDrunk[playerid] = PlayerDrunkNew;
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

                CallLocalFunction "OnWindowsDetected", "d", playerid;
            }
            if ( response == LINUX ) {
                SetPVarInt(playerid, "notAndroid", 1);
                SetPVarInt(playerid, "notLinux", 0);
                SetPVarInt(playerid, "notWin32", 1);

                CallLocalFunction "OnLinuxDetected", "d", playerid;
            }
        }
    }
    #if defined LAX_OnClientCheckResponse
        return (LAX_OnClientCheckResponse(playerid, type, arg, response));
    #else
        return (1);
    #endif
}

/// <summary>
/// ALS Hook.
/// please see https://sampforum.blast.hk/showthread.php?tid=574534
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
