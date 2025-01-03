#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        object::obj_create(...format);
        object::obj_destroy(...format);
        object::obj_move(...format);
        object::obj_stop(...format);
        object::obj_edit(...format);
        object::obj_cancel(...format);
        object::obj_select(...format);
    }
#endif

#if !defined object::
    #define object::
    #define obj_create(%0)     CreateObject(%0)
    #define obj_destroy(%0)    DestroyObject(%0)
    #define obj_move(%0)       MoveObject(%0)
    #define obj_stop(%0)       StopObject(%0)
    #define obj_edit(%0)       EditObject(%0)
    #define obj_cancel(%0)     CancelEdit(%0)
    #define obj_select(%0)     SelectObject(%0)
#endif
