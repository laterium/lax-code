```pwn
#include <a_samp>
#include "a_addon"

main() {
    HelloWorld();
    MyFunction();
}

func MyFunction() {
    let name[] = "Lax";
    printf "%s:%s", "My Name", name;
}

public OnPlayerSpawn(playerid) {
    if (IsAndroid(playerid)) {
        SendClientMessage(playerid, -1, "Android!");
    }
    if (IsLinux(playerid)) {
        SendClientMessage(playerid, -1, "Linux!");
    }
    if (IsWindows(playerid)) {
        SendClientMessage(playerid, -1, "Windows!");
    }
    if (IsPC(playerid)) {
        SendClientMessage(playerid, -1, "PC!");
    }
    if (IsMobile(playerid)) {
        SendClientMessage(playerid, -1, "Mobile!");
    }

    /* delay */
    SetTimerEx("delayFPS", 1500, false, "d", playerid);

    /* map status */
    if (GetPlayerMapStatus(playerid)) { /* if the player map is normal. then .. */
        HidePlayerMap(playerid, 0x000000FF); // The player map becomes full black.
    }
    return 1;
}

func delayFPS(playerid) {
    if (IsConnect(playerid)) {
        format fmt, sizeof(fmt), "FPS: %d", GetPlayerFrame(playerid));
        SendClientMessage(playerid, -1, fmt);
    }
    return 1;
}

public OnPlayerFPSUpdate(playerid, oldfps, newfps) {
    new fmt[200];
    format(fmt, sizeof(fmt), "OLD FPS: %d NEW FPS: %d", oldfps, newfps);
    SendClientMessage(playerid, -1, fmt);
    return 1;
}

public OnAndroidDetected(playerid) {
    SendClientMessage(playerid, -1, "Android!");
    return 1;
}

public OnLinuxDetected(playerid) {
    SendClientMessage(playerid, -1, "Linux!");
    return 1;
}

public OnWindowsDetected(playerid) {
    SendClientMessage(playerid, -1, "Windows!");
    return 1;
}

public OnPlayerUpdate(playerid) {
    if (IsMouse(playerid)) {
        SendClientMessage(playerid, -1, "Mouse On!");
    } else {
        SendClientMessage(playerid, -1, "Mouse Off!");
    }
    return 1;
}
```
