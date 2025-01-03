/// <summary>
/// object defined
/// </summary>
#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        object::obj_create(...do here);
        object::obj_destroy(...do here);
        object::obj_move(...do here);
        object::obj_edit(...do here);
    }
#endif

#if !defined object::
    #define object::
#endif

#if !defined obj_create
    #define obj_create(%0) \
        CreateObject(%0)
#endif

#if !defined obj_destroy
    #define obj_destroy(%0) \
        DestroyObject(%0)
#endif

#if !defined obj_move
    #define obj_move(%0) \
        MoveObject(%0)
#endif

#if !defined obj_edit
    #define obj_edit(%0) \
        EditObject(%0)
#endif
