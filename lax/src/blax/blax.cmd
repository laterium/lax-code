:: 0cf5c1dd36bd27336c8756a535615321149c8c50063bfed06e9b65f9145b7e17
:: MGNmNWMxZGQzNmJkMjczMzZjODc1NmE1MzU2MTUzMjExNDljOGM1MDA2M2JmZWQwNmU5YjY1ZjkxNDViN2UxNw==
@ECHO OFF

:: << Compiler Tool intended for Pawn Code.
:: Copyright (c) Laterium Contributors. All Rights Reserved. >>

setlocal EnableDelayedExpansion

color 0F

:: variables ~>
SET "SOURCEDIR=%~dp0"
SET "NULLSTATIC=false"
SET "LOCALTITLE=null"
SET "_PAWNCC_=null"
SET "LIB_INLOC=blax.cmd"

:: HH/MM/SS format.
FOR /f "tokens=1-4 delims=:. " %%A in ('ECHO %time%') DO (
    SET HH=%%A
    SET MM=%%B
    SET SS=%%C
)

:: binary combination.
SET "0x01000001=A"
SET "0x01000010=B"
SET "0x01000011=C"
SET "0x01000100=D"
SET "0x01000101=E"
SET "0x01000110=F"
SET "0x01000111=G"
SET "0x01001000=H"
SET "0x01001001=I"
SET "0x01001010=J"
SET "0x01001011=K"
SET "0x01001100=L"
SET "0x01001101=M"
SET "0x01001110=N"
SET "0x01001111=O"
SET "0x01010000=P"
SET "0x01010001=Q"
SET "0x01010010=R"
SET "0x01010011=S"
SET "0x01010100=T"
SET "0x01010101=U"
SET "0x01010110=V"
SET "0x01010111=W"
SET "0x01011000=X"
SET "0x01011001=Y"
SET "0x01011010=Z"
:: lower
SET "1x01100001=a"
SET "1x01100010=b"
SET "1x01100011=c"
SET "1x01100100=d"
SET "1x01100101=e"
SET "1x01100110=f"
SET "1x01100111=g"
SET "1x01101000=h"
SET "1x01101001=i"
SET "1x01101010=j"
SET "1x01101011=k"
SET "1x01101100=l"
SET "1x01101101=m"
SET "1x01101110=n"
SET "1x01101111=o"
SET "1x01110000=p"
SET "1x01110001=q"
SET "1x01110010=r"
SET "1x01110011=s"
SET "1x01110100=t"
SET "1x01110101=u"
SET "1x01110110=v"
SET "1x01110111=w"
SET "1x01111000=x"
SET "1x01111001=y"
SET "1x01111010=z"
:: integar
SET "2x00000000=0"
SET "2x00000001=1"
SET "2x00000010=2"
SET "2x00000011=3"
SET "2x00000100=4"
SET "2x00000101=5"
SET "2x00000110=6"
SET "2x00000111=7"
SET "2x00001000=8"
SET "2x00001001=9"
SET "2x00001010=10"

REM             <filename> [filename...] [option]
REM -A<num>  alignment in bytes of the data segment and the stack
REM -a       AMX_O assembler code
REM -C[+/-]  compact encoding for AMX_O file (default=+)
REM -c<name> codepage name or number; e.g. 1252 for Windows Latin-1
REM -Dpath   active directory path
REM -d<num>  debugging level (default=-d1)
REM     0    no symbolic information, no run-time checks
REM     1    run-time checks, no symbolic information
REM     2    full debug information and dynamic checking
REM     3    same as -d2, but implies -O0
REM -e<name> SET name of error file (quiet compile)
REM -H<hwnd> window handle to send a notification message on finish
REM -i<name> path for include files
REM -l       create list file (preprocess only)
REM -o<name> SET base name of (P-code) AMX_O file
REM -O<num>  optimization level (default=-O1)
REM     0    no optimization
REM     1    JIT-compatible optimizations only
REM     2    full optimizations
REM -p<name> SET name of "prefix" file
REM -r[name] write cross reference report to console or to specified file
REM -S<num>  stack/heap size in cells (default=4096)
REM -s<num>  skip lines from the input file
REM -t<num>  TAB indent size (in character positions, default=8)
REM -v<num>  verbosity level; 0=quiet, 1=normal, 2=verbose (default=1)
REM -w<num>  disable a specific warning by its number
REM -X<num>  abstract machine size limit in bytes
REM -XD<num> abstract machine data/stack size limit in bytes
REM -\       use '\' for escape characters
REM -^       use '^' for escape characters
REM -;[+/-]  require a semicolon to end each statement (default=-)
REM -([+/-]  require parantheses for function invocation (default=-)
REM sym=val  define constant "sym" with value "val"
REM sym=     define constant "sym" with value 0

REM Options may start with a dash or a slash; the options "-d0" and "/d0" are
REM equivalent.

REM Options with a value may optionally separate the value from the option letter
REM with a colon (":") or an equal sign ("="). That is, the options "-d0", "-d=0"
REM and "-d:0" are all equivalent.

:: JIT-compatible optimizations
SET "ASM_OPTION_M=-!1x01101111!"
SET "ASM_OPTION_P=-!0x01001111!!2x00000001!"

SET "METADAT_FILE=compile.log"

TITLE %username%@%computername%:~

:COMMAND_TYPEOF
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do (set "DEL=%%a")

<nul set /p=""
call :COLOURTEXT a "%SOURCEDIR%~#"
SET /p TYPEOF=" "

goto :end

:: colour handle in batch
:COLOURTEXT
<nul set /p "=%DEL%" > "%~2"
findstr /v /a:%1 /R "+" "%~2" nul
del "%~2" > nul
goto :eof

:end

SET "OPTIONTYPEOF=cat"

IF "%TYPEOF%"=="%OPTIONTYPEOF% -c" (
    SET "LOCALTITLE=compilers"
    TITLE %username%@%computername%:~/!LOCALTITLE!
    ECHO.

    SET "NULLSTATIC=true"
    GOTO COMPILERS

) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -r" (
    SET "LOCALTITLE=running"
    TITLE %username%@%computername%:~/!LOCALTITLE!

    TASKKILL /f /im "samp-server.exe" >nul 2>&1

    GOTO SERVERS

) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -ci" (
    SET "LOCALTITLE=compile running"
    TITLE %username%@%computername%:~/!LOCALTITLE!

    SET "NULLSTATIC=false"

    DEL "%SOURCEDIR%server_log.txt" /q >nul
    
    CALL :COMPILERS
    FINDSTR /i "error" %METADAT_FILE% >nul && echo. || CALL :GO_START

:GO_START
    TASKKILL /f /im "samp-server.exe" >nul 2>&1
    ECHO # Press any key to Start Server's . . .
    PAUSE >nul

:SERVERS
    START "" "samp-server.exe"
    TIMEOUT /t 2 >nul
    TASKLIST | FIND /i "samp-server.exe" >nul

    IF not exist samp-server.exe (
        ECHO # samp-server.exe not found..
        TIMEOUT /t 1 >nul
        START "" "https://sa-mp.app/"
        GOTO COMMAND_TYPEOF
    )

    IF ERRORLEVEL 1 (
        ECHO.
        ECHO # [%HH%:%MM%:%SS%] Starting.. no
        IF exist "server_log.txt" (
            TIMEOUT /t 2
            TYPE server_log.txt
        ) ELSE (
            ECHO # server_log.txt not found.
        )
        ECHO.
        <nul set /p=""
                    call :COLOURTEXT a "# End."
                    echo.
        GOTO COMMAND_TYPEOF
    ) ELSE (
        ECHO # [%HH%:%MM%:%SS%] Starting.. Done

        FINDSTR /i "failed" server_log.txt >nul && CALL :lax_TRUE || CALL :lax_FALSE

        :lax_TRUE
        <nul set /p=""
                    call :COLOURTEXT 4X "~"
                    echo    Failed? .. Yes .. True
                echo.
        CALL :FAIL_SERVERLOG
        
        GOTO :eof

        :lax_FALSE
                <nul set /p=""
                    call :COLOURTEXT a "~"
                    echo    Failed? .. No .. False
                echo.
        GOTO ENDOFALL
    )

:FAIL_SERVERLOG
    TIMEOUT /t 2
    ECHO.
    FINDSTR /i "failed" ^> server_log.txt
    ECHO.
    <nul set /p=""
            call :COLOURTEXT E6 "# End."
            echo.
    GOTO COMMAND_TYPEOF

) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -cls" (
    :CLEARS
    SET "LOCALTITLE=clear screen"
    TITLE %username%@%computername%:~/!LOCALTITLE!
    CLS
    GOTO MAINOFALL
    GOTO COMMAND_TYPEOF

) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -vsc" (
    SET "LOCALTITLE=vscode tasks"
    TITLE %username%@%computername%:~/!LOCALTITLE!
    IF exist ".vscode" (
        ECHO # [%HH%:%MM%:%SS%] A subdirectory or file .vscode already exists.
        GOTO ENDOFALL
    )
    MKDIR ".vscode"
    (
        ECHO {
        ECHO   "version": "2.0.0",
        ECHO   "tasks": [
        ECHO     {
        ECHO       "label": "Run lax",
        ECHO       "type": "shell",
        ECHO       "command": "${workspaceFolder}/%LIB_INLOC%",
        ECHO       "group": {
        ECHO           "kind": "build",
        ECHO           "isDefault": true
        ECHO       },
        ECHO       "problemMatcher": [],
        ECHO       "detail": "Task to run the batch file"
        ECHO     }
        ECHO   ]
        ECHO }
    ) > ".vscode\tasks.json"
    ECHO # [%HH%:%MM%:%SS%] Creating '.vscode\tasks.json'...: [yes]
    START explorer ".vscode\"
    GOTO ENDOFALL

)  ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -dg" (
    SET "LOCALTITLE=create simple pack"
    TITLE %username%@%computername%:~/!LOCALTITLE!

    IF exist filterscripts (
        echo.
        <nul set /p=""
            call :COLOURTEXT a "# filterscripts is .. Ok .."
            echo  [A subdirectory or file server.cfg already exists.]
            echo -
        timeout /t 2 >nul
    ) else (
        mkdir filterscripts
        ECHO # [%HH%:%MM%:%SS%] Creating '%SOURCEDIR%filterscripts'...: [yes]
        timeout /t 2 >nul
    )
    IF exist gamemodes (
        <nul set /p=""
            call :COLOURTEXT a "# gamemodes is .. Ok .."
            echo  [A subdirectory or file server.cfg already exists.]
            echo -
        timeout /t 2 >nul
    ) else (
        setlocal EnableDelayedExpansion
        mkdir gamemodes
        
        (
            ECHO #include ^<a_samp^>
            ECHO.
            ECHO main^(^) {
            ECHO     printf "Hello, World!";
            ECHO }
        ) > "gamemodes\main.lax.pwn"
        endlocal
        echo.
        ECHO # [%HH%:%MM%:%SS%] Creating '%SOURCEDIR%gamemodes'...: [yes]
        echo.
        timeout /t 2 >nul
    )
    IF exist scriptfiles (
        <nul set /p=""
            call :COLOURTEXT a "# scriptfiles is .. Ok .."
            echo  [A subdirectory or file server.cfg already exists.]
            echo -
        timeout /t 2 >nul
    ) else (
        mkdir scriptfiles
        ECHO # [%HH%:%MM%:%SS%] Creating '%SOURCEDIR%scriptfiles'...: [yes]
        timeout /t 2 >nul
    )
    IF exist server-readme.txt (
        <nul set /p=""
            call :COLOURTEXT a "# server readme is .. Ok .."
            echo  [A subdirectory or file server.cfg already exists.]
            echo -
        timeout /t 2 >nul
    ) else (
        (
            ECHO SA-MP 0.3 Server Setup
            ECHO ----------------------
            ECHO.
            ECHO Once the configuration is complete, run samp-server.exe to
            ECHO launch the server process.
            ECHO.
            ECHO CONFIGURATION:
            ECHO.
            ECHO Example server.cfg:
            ECHO     echo Executing Server Config...
            ECHO     maxplayers 32
            ECHO     port 7777
            ECHO     hostname Unnamed Server
            ECHO     announce 0
            ECHO     gamemode0 lvdm 1
            ECHO     gamemode1 rivershell 1
            ECHO     weburl www.sa-mp.com
            ECHO     rcon_password mypassword
            ECHO.
            ECHO To configure the server, you must edit the values in server.cfg. They are explained below:
            ECHO.
            ECHO hostname
            ECHO --------
            ECHO     Parameters:
            ECHO         string
            ECHO.
            ECHO     Description:
            ECHO         Specifies the hostname shown in the server browser
            ECHO.
            ECHO port
            ECHO ----
            ECHO     Parameters:
            ECHO         int
            ECHO.
            ECHO     Description:
            ECHO         Specifies the port to listen on.
            ECHO         This port is used for game connections, rcon connections, and for querying.
            ECHO.
            ECHO maxplayers
            ECHO ----------
            ECHO     Parameters:
            ECHO         int
            ECHO.
            ECHO     Description:
            ECHO         Specifies the maximum amount of players.
            ECHO.
            ECHO announce
            ECHO -------
            ECHO     Parameters:
            ECHO         int ^(0 or 1^)
            ECHO.
            ECHO     Description:
            ECHO         Announces your server to the 'Internet' server list in the SA:MP browser. On ^(1^) or Off ^(0^).
            ECHO.
            ECHO weburl
            ECHO ------
            ECHO     Parameters:
            ECHO         string
            ECHO.
            ECHO     Description:
            ECHO         Specifies the URL shown in the server browser, which is associated to the server.
            ECHO.
            ECHO rcon_password
            ECHO -------------
            ECHO     Parameters:
            ECHO         string
            ECHO.
            ECHO     Description:
            ECHO         Specifies the password needed to connect to rcon, or login to rcon ingame.
            ECHO.
            ECHO gamemode0 - gamemode15
            ECHO ----------------------
            ECHO     Parameters:
            ECHO         string
            ECHO         int
            ECHO.
            ECHO     Description:
            ECHO         Specifies the rotation settings. The first parameter sets the game mode name. The second is the number of times it will repeat.
            ECHO         You can use gamemode0 to specify the first gamemode, gamemode1 to specify the second, etc.
        ) > "server-readme.txt"
        echo.
        ECHO # [%HH%:%MM%:%SS%] Creating '%SOURCEDIR%server-readme.txt'...: [yes]
        echo.
    )
    IF exist server.cfg (
        <nul set /p=""
            call :COLOURTEXT a "# server.cfg is .. Ok .."
            echo  [A subdirectory or file server.cfg already exists.]
            echo.
    ) else (
        (
            ECHO echo Executing Server Config...
            ECHO lanmode 0
            ECHO rcon_password changename
            ECHO maxplayers 150
            ECHO port 7777
            ECHO hostname SA-MP 0.3 ^(Lax^)
            ECHO gamemode0 main 1
            ECHO filterscripts 
            ECHO announce 0
            ECHO chatlogging 0
            ECHO weburl www.sa-mp.com
            ECHO onfoot_rate 40
            ECHO incar_rate 40
            ECHO weapon_rate 40
            ECHO stream_distance 300.0
            ECHO stream_rate 1000
            ECHO maxnpc 0
            ECHO logtimeformat [%H:%M:%S]
            ECHO language English
        ) > "server.cfg"
        ECHO # [%HH%:%MM%:%SS%] Creating '%SOURCEDIR%server.cfg'...: [yes]
        echo.
        type server.cfg
        goto ENDOFALL
    )
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -gitc" (
    SET "LOCALTITLE=git clone"
    TITLE %username%@%computername%:~/!LOCALTITLE!

    set /p URL="# [%HH%:%MM%:%SS%] Enter Repo URL: "
    if "!URL!"=="" (
        <nul set /p=""
            call :COLOURTEXT 4X "[#]~"
            echo ERR? .. Yes .. Url Required..
            echo.
    ) else (
        echo # Cloning repository from !URL!
        git clone !URL!
    )
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -lax" (
    START "" "https://github.com/laterium/lax-code"
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -pcc" (
    START "" "https://github.com/pawn-lang/compiler/releases"
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -mpg" (
    START "" "https://sa-mp.app/"
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -inc" (
    START "" "https://github.com/laterium/lax-code/blob/main/include/a_addon.inc"
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% -dlax" (
    START "" "https://dsc.gg/evercool/"
) ELSE IF "%TYPEOF%"=="help" (
    SET "LOCALTITLE=help"
    TITLE %username%@%computername%:~/!LOCALTITLE!
    
    :_HELP
    ECHO usage: cat [-c compile] [-r running server] [-ci compile-running] [-vsc vscode tasks]
    ECHO       [-dg create gamemode pack ^& debugging gamemode] [-cls clear screen] [-gitc git clone] [-inc lax include+]
    ECHO       [-lax lax development] [-pcc pawncc release] [-mpg gamemode download]
    ECHO       [-dlax discord lax development support]
    GOTO COMMAND_TYPEOF

) ELSE IF "%TYPEOF%"=="cat" (
    SET "LOCALTITLE=cat"
    TITLE %username%@%computername%:~/!LOCALTITLE!
    GOTO _HELP
) ELSE IF "%TYPEOF%"=="" (
    GOTO COMMAND_TYPEOF
) ELSE IF "%TYPEOF%"==" " (
    GOTO COMMAND_TYPEOF
) ELSE IF "%TYPEOF%"=="%OPTIONTYPEOF% " (
    GOTO _HELP
) ELSE (
    echo '!TYPEOF!' is not recognized as an internal or external command,
    echo operable program or batch file.
    echo.
    goto _HELP
    GOTO COMMAND_TYPEOF
)

:ENDOFALL
ECHO # Press any key to return . . .
PAUSE >nul
GOTO COMMAND_TYPEOF

:COMPILERS
    ECHO # Starting at %time% ...
    FOR /r "%SOURCEDIR%" %%P in (pawncc.exe) DO (
        IF EXIST "%%P" (
            SET "_PAWNCC_=%%P"
            GOTO PAWNCC
        )
    )
    :PAWNCC
    IF not DEFINED _PAWNCC_ (
        ECHO.
            ECHO # [%HH%:%MM%:%SS%] pawncc not found in any subdirectories.
        ECHO.
        TIMEOUT /t 1 >nul
        START "" "https://github.com/pawn-lang/compiler/releases"
        GOTO COMMAND_TYPEOF
    )
    SET "SOURCEFILE=false"
    FOR /r "%SOURCEDIR%" %%F in (*.lax*) DO (
    IF EXIST "%%F" (
        SET "SOURCEFILE=true"
        
        ECHO *^(%%F^)
        ECHO.
        
        SET "AMX_O=%%~dpnF"
        SET "AMX_O=!AMX_O:.lax=!%.amx"

        "!_PAWNCC_!" "%%F" %ASM_OPTION_M%"!AMX_O!" %ASM_OPTION_P% > %METADAT_FILE% 2>&1
        TYPE %METADAT_FILE%

        IF EXIST "!AMX_O!" (
            FOR %%A IN ("!AMX_O!") DO (
                <nul set /p=""
                call :COLOURTEXT a "[#]~"
                echo Compilation finished at %time%..
                call :COLOURTEXT a "[#]~"
                echo Total Size [%%~zA / bytes] ^| "!AMX_O!" ^| "%ASM_OPTION_M% %ASM_OPTION_P%" 
            )
        ) ELSE (
                setlocal DisableDelayedExpansion 
                <nul set /p=""
                    call :COLOURTEXT 4X "[#]~"
                    echo Compilation failed!. ERR? .. Yes
                    endlocal
                    IF "%NULLSTATIC%"=="false" (
                        goto ENDOFALL
                    )
                echo.
            )
            ECHO.
        )
    )
    IF not "%SOURCEFILE%"=="true" (
       setlocal DisableDelayedExpansion 
        <nul set /p=""
                call :COLOURTEXT 4X "[#]~"
                echo Compilation failed!.
        endlocal
        ECHO    ~ "!SOURCEDIR!.lax" no files found.
    )
    IF "%NULLSTATIC%"=="true" (
        GOTO ENDOFALL
    )