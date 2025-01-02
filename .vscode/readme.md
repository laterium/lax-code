### PAWN/LAX VSCode Tasks
```
shell
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
process
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
