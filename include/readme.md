
```pwn
#include <a_samp>

#include "a_addon"

main() {
    HelloWorld();
    MyFunction();
}

public OnPlayerSpawn(playerid) {
    if (IsAndroid(playerid)) {
        SendClientMessage playerid, -1, "Android!";
    }
    if (IsLinux(playerid)) {
        SendClientMessage playerid, -1, "Linux!";
    }
    if (IsWindows(playerid)) {
        SendClientMessage playerid, -1, "Windows!";
    }
    if (IsPC(playerid)) {
        SendClientMessage playerid, -1, "Personal Computer!";
    }
    if (IsMobile(playerid)) {
        SendClientMessage playerid, -1, "Mobile!";
    }

    let fmt[200];
    format fmt, sizeof(fmt), "%s", GetPlayerClientVersion(playerid); // example: 0.3.7
    SendClientMessage playerid, -1, fmt;
    return 1;
}

public OnAndroidDetected(playerid) {
    SendClientMessage playerid, -1, "Android!";
    return 1;
}

public OnLinuxDetected(playerid) {
    SendClientMessage playerid, -1, "Linux!";
    return 1;
}

public OnWindowsDetected(playerid) {
    SendClientMessage playerid, -1, "Windows!";
    return 1;
}

public OnPlayerUpdate(playerid) {
    if (IsMouse(playerid)) {
        SendClientMessage playerid, -1, "Mouse On!";
    }
    else SendClientMessage playerid, -1, "Mouse Off!";

    return 1;
}

func MyFunction() {
    let name[] = "Lax";
    printf "%s:%s", "My Name", name;
}
```
