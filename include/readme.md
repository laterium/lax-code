```pwn
#include <a_samp>
#include "a_addon"

/// <summary>
/// Entry point of the script. Initializes the script and calls helper functions.
/// </summary>
main() {
    HelloWorld();
    MyFunction();
}

/// <summary>
/// Example function to demonstrate printing a formatted string.
/// </summary>
func MyFunction() {
    let name[] = "Lax";
    printf("%s: %s", "My Name", name);
}

/// <summary>
/// Called when a player spawns. Detects platform and device, sets a timer for FPS, and handles map visibility.
/// </summary>
public OnPlayerSpawn(playerid) {
/// <summary>
/// IsPlayerDeath Check
/// </summary>
    if (IsPlayerDeath(playerid)) {
        SendClientMessage(playerid, -1, "Your is Death!");
    }
    if (IsAndroid(playerid)) {
        SendClientMessage(playerid, -1, "Platform: Android");
    }
    if (IsLinux(playerid)) {
        SendClientMessage(playerid, -1, "Platform: Linux");
    }
    if (IsWindows(playerid)) {
        SendClientMessage(playerid, -1, "Platform: Windows");
    }
    if (IsPC(playerid)) {
        SendClientMessage(playerid, -1, "Device: PC");
    }
    if (IsMobile(playerid)) {
        SendClientMessage(playerid, -1, "Device: Mobile");
    }

    // Set a timer to send FPS info
    SetTimerEx("SendPlayerFPS", 1500, false, "d", playerid);

    // Hide player map if status is normal
    if (GetPlayerMapStatus(playerid)) {
        HidePlayerMap(playerid, 0x000000FF); // Set map to full black
    }
    return 1;
}

/// <summary>
/// Sends the player's FPS to their client after a short delay.
/// </summary>
func SendPlayerFPS(playerid) {
    if (IsConnect(playerid)) {
        new fmt[64];
        format(fmt, sizeof(fmt), "FPS: %d", GetPlayerFrame(playerid));
        SendClientMessage(playerid, -1, fmt);
    }
    return 1;
}

/// <summary>
/// Triggered when a player's FPS is updated. Displays old and new FPS values.
/// </summary>
public OnPlayerFPSUpdate(playerid, oldfps, newfps) {
    new fmt[128];
    format(fmt, sizeof(fmt), "Old FPS: %d, New FPS: %d", oldfps, newfps);
    SendClientMessage(playerid, -1, fmt);
    return 1;
}

/// <summary>
/// Called when an Android platform is detected for a player.
/// </summary>
public OnAndroidDetected(playerid) {
    SendClientMessage(playerid, -1, "Platform: Android Detected");
    return 1;
}

/// <summary>
/// Called when a Linux platform is detected for a player.
/// </summary>
public OnLinuxDetected(playerid) {
    SendClientMessage(playerid, -1, "Platform: Linux Detected");
    return 1;
}

/// <summary>
/// Called when a Windows platform is detected for a player.
/// </summary>
public OnWindowsDetected(playerid) {
    SendClientMessage(playerid, -1, "Platform: Windows Detected");
    return 1;
}

/// <summary>
/// Triggered when the player's map is enabled.
/// </summary>
public OnPlayerMap(playerid) {
    SendClientMessage(playerid, -1, "Map is On");
    return 1;
}

/// <summary>
/// Triggered when the player's map is disabled.
/// </summary>
public OnPlayerOffMap(playerid) {
    SendClientMessage(playerid, -1, "Map is Off");
    return 1;
}

/// <summary>
/// Called regularly to check the player's mouse state and send a message accordingly.
/// </summary>
public OnPlayerUpdate(playerid) {
    if (IsMouse(playerid)) {
        SendClientMessage(playerid, -1, "Mouse: On");
    } else {
        SendClientMessage(playerid, -1, "Mouse: Off");
    }
    return 1;
}

/// <summary>
/// Triggered when the player enables mouse input.
/// </summary>
public OnPlayerMouse(playerid) {
    SendClientMessage(playerid, -1, "Mouse is On");
    return 1;
}

/// <summary>
/// Triggered when the player disables mouse input.
/// </summary>
public OnPlayerOffMouse(playerid) {
    SendClientMessage(playerid, -1, "Mouse is Off");
    return 1;
}
```
