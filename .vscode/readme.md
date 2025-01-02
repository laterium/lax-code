### PAWN/LAX VSCode Tasks
```
For Shell
```
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Run lax",
      "type": "shell",
      "command": "${workspaceFolder}/blax.cmd",
      "group": {
          "kind": "build",
          "isDefault": true
      },
      "problemMatcher": [],
      "detail": "Task to run the batch file"
    }
  ]
}
```
```
For Process
```
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Run lax",
      "type": "process",
      "command": "${workspaceFolder}/blax.cmd",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": [],
      "detail": "Task to run the batch file"
    }
  ]
}
```
