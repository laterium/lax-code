#include "a_addon.inc"

#if !defined object::
    #define object::
#endif

#if !defined create
    #define create(%0) \
        CreateObject(%0)
#endif

#if !defined destroy
    #define destroy(%0) \
        DestroyObject(%0)
#endif

#if !defined move
    #define move(%0) \
        MoveObject(%0)
#endif
