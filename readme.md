# About Lax (PAWN/LAX)
[@2.3.2](https://github.com/laterium/lax-code/blob/main/lax/src/blax/blax.cmd) a7e5edfe2739385409762b06b26bf0dbf5eaef01d4e5320a0880376491151a69
----
**What is Lax?** Lax (PAWN/LAX) or BLax (Batch Lax) is a simple compilation tool created using only batch scripts and various perfect combinations of the Pawn Code Compiler (PAWNCC). Initially, Lax was just a compiler tool, but Laterium Contrib. (Contributors) is now focused on developing Lax into a versatile tool for both the Pawn Language Compiler and SA-MP Server Integration.
# Getting Started
- [x] Install from reposit "Download ZIP" or clone: `git clone https://github.com/laterium/lax-code.git`
- [x] Paste ".cmd" to into gamemodes directory (not in an existing folder)
```
── project-dir
    ├── @gamemodes
    ├── @filterscripts
    ├── server.cfg
    ├── blax.cmd
```
> You can use Setup if necessary, for installations that are not complex or difficult: [Download](https://drive.google.com/file/d/1OtyQ05_Mg81UZt7J8B8A7xxh-IYyCwTC/view) (This file does not contain any viruses that could harm your computer, so rest assured.)
- [x] Rename the file to be compiled to `example.lax` or if you want to keep using the pawn extension, you can use `example.lax.pwn` or `example.lax.p` and others.
> Start ".cmd" and use a command "cat" or "help"
>> Example: -c (to compile) -ci (to compile & running)..
>>> Requirement: [pawncc](https://github.com/laterium/lax-code/tree/main/lax/src/bin) 
# Example
```pwn
#include <a_samp>

main()
    print "Hello, World!";
```