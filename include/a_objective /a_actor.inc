/// <summary>
/// This section defines a set of macros for actor management in the game. 
/// Each macro serves as a simplified version of the corresponding actor-related function, 
/// providing a more readable and convenient way to interact with the actors in the game.
/// 
/// Macros:
/// - actor_create(%0)          : Creates an actor using the given parameters.
/// - actor_destroy(%0)         : Destroys an actor based on the given parameters.
/// - actor_pos(%0)             : Sets the position of an actor using the given parameters.
/// - actor_angle(%0)           : Sets the facing angle of an actor using the given parameters.
/// - actor_health(%0)          : Sets the health of an actor using the given parameters.
/// - actor_invulnerable(%0)    : Sets the invulnerability status of an actor using the given parameters.
/// </summary>

#if !defined actors::
    #define actor->
    #define actors::
    #define actor_create(%0)          CreateActor(%0)
    #define actor_destroy(%0)         DestroyActor(%0)
    #define actor_pos(%0)             SetActorPos(%0)
    #define actor_angle(%0)           SetActorFacingAngle(%0)
    #define actor_health(%0)          SetActorHealth(%0)
    #define actor_invulnerable(%0)    SetActorInvulnerable(%0)
#endif
