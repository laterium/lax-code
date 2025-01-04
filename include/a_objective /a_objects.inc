/// <summary>
/// This section defines a set of macros for object management in the game. 
/// Each macro is a simplified version of the corresponding object-related function, 
/// allowing for easier interaction with objects in the game.
/// 
/// Macros:
/// - obj_create(%0)     : Creates an object based on the given parameters.
/// - obj_destroy(%0)    : Destroys the specified object.
/// - obj_move(%0)       : Moves the object to a new position with specified parameters.
/// - obj_stop(%0)       : Stops the movement of the object if it's in motion.
/// - obj_edit(%0)       : Edits the properties of the specified object.
/// - obj_cancel(%0)     : Cancels the editing mode for the object.
/// - obj_select(%0)     : Selects the specified object for interaction.
/// </summary>

#if !defined objects::
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
