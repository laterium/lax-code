#if !defined example
//    #include "System"

//    main() {}

//    public OnGameModeInit() {
//        objects::obj_create(....format);
//        objects::obj_destroy(...format);
//        objects::obj_move(......format);
//        objects::obj_stop(......format);
//        objects::obj_edit(......format);
//        objects::obj_cancel(....format);
//        objects::obj_select(....format);
//    }
#endif

#if !defined object::
    #define object->
    #define objects::
    #define obj_create(%0)     CreateObject(%0)
    #define obj_destroy(%0)    DestroyObject(%0)
    #define obj_move(%0)       MoveObject(%0)
    #define obj_stop(%0)       StopObject(%0)
    #define obj_edit(%0)       EditObject(%0)
    #define obj_cancel(%0)     CancelEdit(%0)
    #define obj_select(%0)     SelectObject(%0)
#endif
