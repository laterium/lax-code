// copyright (c) Lax Contributors.
#include <a_samp>

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

#define float               Float:

// #pragma tabsize 4
// #pragma ctrlchar '@'
// #pragma dynamic 1000000
// #pragma semicolon 0

static const rc[20] = {
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0,
    0xdb92371d, 0x2126e970, 0x03249775, 0x04e8c90e,
    0x517cc1b7, 0x27220a94, 0xfe13abe8, 0xfa9a6ee0,
    0x6db14acc, 0x9e21c820, 0xff28b1d5, 0xef5de2b0
};

#pragma unused rc

forward OnAndroidDetected(playerid);
forward OnLinuxDetected(playerid);
forward OnWindowsDetected(playerid);

stock GetPlayerClientVersion(playerid) {
  new version[24];
  GetPlayerVersion(playerid, version, sizeof(version));
  return version;
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

new FPS_LevelLast[MAX_PLAYERS];
new FPS_GetData[MAX_PLAYERS];

#if !defined GetPlayerFPS
    #define GetPlayerFPS _GetPlayerFPS_
#endif
#if !defined GetPlayerFps
    #define GetPlayerFps _GetPlayerFPS_
#endif

stock _GetPlayerFPS_(playerid)
{
    SetPVarInt(playerid, "DRUNK_L", GetPlayerDrunkLevel(playerid));
    
    if (GetPVarInt(playerid, "DRUNK_L") < 100)
    {
        SetPlayerDrunkLevel(playerid, 2000);
    } else {
        if (GetPVarInt(playerid, "DRUNK_L") != GetPVarInt(playerid, "FPS"))
        {
            SetPVarInt(playerid, "FPS", (GetPVarInt(playerid, "DRUNK_L") - GetPVarInt(playerid, "DRUNK_L")));
            SetPVarInt(playerid, "DRUNK_L", GetPVarInt(playerid, "DRUNK_L"));
            
            if ((GetPVarInt(playerid, "FPS") > 0) && (GetPVarInt(playerid, "FPS") < 256))
            {
                return GetPVarInt(playerid, "FPS") - 1;
            }
        }
    }
   return GetPVarInt(playerid, "FPS") > 0 ? GetPVarInt(playerid, "FPS") - 1 : 0;
}

public OnPlayerUpdate(playerid)
{
    new DRUNK_Now;
    DRUNK_Now = GetPlayerDrunkLevel(playerid);

    if (DRUNK_Now < 100) {
        SetPlayerDrunkLevel(playerid, 2000);
    } else {
        if (FPS_LevelLast[playerid] != DRUNK_Now) {

            new __FPS = FPS_LevelLast[playerid] - DRUNK_Now;

            if ((__FPS > 0) && (__FPS < 200)) {
                FPS_GetData[playerid] = __FPS;
            }
            FPS_LevelLast[playerid] = DRUNK_Now;
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

                CallLocalFunction("OnAndroidDetected", "d", playerid);
            }
            if ( response == 1 )
            {
                SetPVarInt(playerid, "isPC", 1);
                SetPVarInt(playerid, "isMobile", 0);
            }
        }
        case 0x49:
        {
            switch ( response )  {
                case 1: 
                {
                    SetPVarInt(playerid, "notAndroid", 1);
                    SetPVarInt(playerid, "notLinux", 1);
                    SetPVarInt(playerid, "notWin32", 0);

                    CallLocalFunction("OnWindowsDetected", "d", playerid);
                }
                case 0: 
                {
                    SetPVarInt(playerid, "notAndroid", 1);
                    SetPVarInt(playerid, "notLinux", 0);
                    SetPVarInt(playerid, "notWin32", 1);

                    CallLocalFunction("OnLinuxDetected", "d", playerid);
                }
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