// copyright (c) Lax Contributors.
#include <a_samp>

#if defined _addon_included
	#endinput
#endif
#define _addon_included
#pragma library addon

#if !defined SendClientCheck
  native SendClientCheck(playerid, type, arg, offset, size);
#endif

forward OnClientCheckResponse(playerid, type, arg, response);

// credit *(@fairuz)
#if !defined IsAndroid
#define IsAndroid(%0)       GetPVarInt(%0, "notAndroid") == 0
#endif

#if !defined IsLinux
#define IsLinux(%0)         GetPVarInt(%0, "notLinux") == 0
#endif

#if !defined IsWindows
#define IsWindows(%0)       GetPVarInt(%0, "notWin32") == 0
#endif

#define IsPC(%0)            GetPVarInt(%0, "isPC") == 1
#define IsMobile(%0)        GetPVarInt(%0, "isMobile") == 1

#define IsConnect(%0)       IsPlayerConnected(%0)
#define IsSpawn(%0)         IsPlayerSpawned(%0)

#define func%0(%1)          forward %0(%1); public %0(%1)
#define loop(%0,%1,%2)      for(new %0 = %1; %0 < %2; %0++)
#define IsMouse(%0)         GetPVarInt(%0, "isMouse") == 1

#define GetPlayerCounts(%0) loop(%0, 0, MAX_PLAYERS)
#define GetVehiclCounts(%0) loop(%0, 0, MAX_VEHICLES)

#define float               Float:

new False = false, True = true, FALSE = false, TRUE = true
#pragma unused False, True, FALSE, TRUE

// #pragma ctrlchar '@'
// #pragma dynamic 1000000
// #pragma semicolon 0
#pragma tabsize 4

stock PlayerStopSound(playerid) {
    PlayerPlaySound(playerid,1098,0.0,0.0,0.0);
    return 1;
}

static stock const rc[20] = {
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0,
    0xdb92371d, 0x2126e970, 0x03249775, 0x04e8c90e,
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0
};

forward OnAndroidDetected(playerid);
forward OnLinuxDetected(playerid);
forward OnWindowsDetected(playerid);

func LCC_SelectTextDraw(playerid, colour) {
    SelectTextDraw playerid, colour;
    SetPVarInt(playerid, "isMouse", 1);
    return 1;
}

func LCC_CancelSelectTextDraw(playerid) {
    CancelSelectTextDraw playerid;
    SetPVarInt(playerid, "isMouse", 0);
    return 1;
}

public OnPlayerConnect(playerid)
{
    SendClientCheck(playerid, 0x48, 0, 0, 2);
    SendClientCheck(playerid, 0x49, 0, 0, 2);

    #if defined LCC_OnPlayerConnect
        return (LCC_OnPlayerConnect(playerid));
    #else
        return (1);
    #endif
}

public OnPlayerSpawn(playerid) {
    #if defined LCC_OnPlayerSpawn
        return (LCC_OnPlayerSpawn(playerid));
    #else
        return (1);
    #endif
}

#if !defined GetPlayerFPS
    #define GetPlayerFPS _GetPlayerFrame_
#endif
#if !defined GetPlayerFps
    #define GetPlayerFps _GetPlayerFrame_
#endif
#if !defined GetPlayerFrame
    #define GetPlayerFrame _GetPlayerFrame_
#endif

new PlayerDrunk[MAX_PLAYERS];
new PlayerFrame[MAX_PLAYERS];

func _GetPlayerFrame_(playerid)
{
    SetPVarInt(playerid, "DrunkL", GetPlayerDrunkLevel(playerid));
    
    if (GetPVarInt(playerid, "DrunkL") < 100)
    {
        SetPlayerDrunkLevel(playerid, 2000);
    } else {
        if (GetPVarInt(playerid, "LDrunkL") != GetPVarInt(playerid, "DrunkL"))
        {
            SetPVarInt(playerid, "FPS", (GetPVarInt(playerid, "LDrunkL") - GetPVarInt(playerid, "DrunkL")));
            SetPVarInt(playerid, "LDrunkL", GetPVarInt(playerid, "DrunkL"));
            
            if ((GetPVarInt(playerid, "FPS") > 0) && (GetPVarInt(playerid, "FPS") < 256))
            {
                return GetPVarInt(playerid, "FPS") - 1;
            }
        }
    }
    new rand = random(60) + 29;
    return GetPVarInt(playerid, "FPS") > 0 ? GetPVarInt(playerid, "FPS") - 1 : rand;
}

public OnPlayerUpdate(playerid)
{
    new PlayerDrunkNew;
    PlayerDrunkNew = GetPlayerDrunkLevel(playerid);

    if (PlayerDrunkNew < 100) {
        SetPlayerDrunkLevel(playerid, 2000);
    } else {
        if (PlayerDrunk[playerid] != PlayerDrunkNew) {

            new wfps = PlayerDrunk[playerid] - PlayerDrunkNew;

            if ((wfps > 0) && (wfps < 200)) {
                PlayerFrame[playerid] = wfps;
            }
            PlayerDrunk[playerid] = PlayerDrunkNew;
        }
  }
  #if defined LCC_OnPlayerUpdate
    return (LCC_OnPlayerUpdate(playerid));
  #else
    return (1);
  #endif
}

public OnClientCheckResponse(playerid, type, arg, response)
{
    switch ( type ) 
    {
        case 0x48:
        {
            if ( response == 0 ) 
            {
                SetPVarInt(playerid, "notAndroid", 0);
                SetPVarInt(playerid, "notLinux", 1);
                SetPVarInt(playerid, "notWin32", 1);

                SetPVarInt(playerid, "isPC", 0);
                SetPVarInt(playerid, "isMobile", 1);

                CallLocalFunction "OnAndroidDetected", "d", playerid;
            }
            if ( response == 1 )
            {
                SetPVarInt(playerid, "isPC", 1);
                SetPVarInt(playerid, "isMobile", 0);
            }
        }
        case 0x49:
        {
            if ( response == 1 ) {
                SetPVarInt(playerid, "notAndroid", 1);
                SetPVarInt(playerid, "notLinux", 1);
                SetPVarInt(playerid, "notWin32", 0);

                CallLocalFunction "OnWindowsDetected", "d", playerid;
            }
            if ( response == 0 ) {
                SetPVarInt(playerid, "notAndroid", 1);
                SetPVarInt(playerid, "notLinux", 0);
                SetPVarInt(playerid, "notWin32", 1);

                CallLocalFunction "OnLinuxDetected", "d", playerid;
            }
        }
    }
    #if defined LCC_OnClientCheckResponse
    return (LCC_OnClientCheckResponse(playerid, type, arg, response));
    #else
    return (1);
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect LCC_OnPlayerConnect
#if defined LCC_OnPlayerConnect
    forward LCC_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn LCC_OnPlayerSpawn
#if defined LCC_OnPlayerSpawn
    forward LCC_OnPlayerSpawn(playerid);
#endif

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate LCC_OnPlayerUpdate
#if defined LCC_OnPlayerUpdate
    forward LCC_OnPlayerUpdate(playerid);
#endif

#if defined _ALS_OnClientCheckResponse
    #undef OnClientCheckResponse
#else
    #define _ALS_OnClientCheckResponse
#endif
#define OnClientCheckResponse LCC_OnClientCheckResponse
#if defined LCC_OnClientCheckResponse
    forward LCC_OnClientCheckResponse(playerid, type, arg, response);
#endif

#if defined _ALS_SelectTextDraw
    #undef SelectTextDraw
#else
    #define _ALS_SelectTextDraw
#endif
#define SelectTextDraw LCC_SelectTextDraw

#if defined _ALS_CancelSelectTextDraw
    #undef CancelSelectTextDraw
#else
    #define _ALS_CancelSelectTextDraw
#endif
#define CancelSelectTextDraw LCC_CancelSelectTextDraw
