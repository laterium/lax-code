
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
