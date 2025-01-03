/// <summary>
/// object defined
/// </summary>
#if defined example
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        object::create(...do here);
        object::destroy(...do here);
        object::move(...do here);
    }
#endif

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
