#if !defined example
//    #include "a_samp"
//    #include "a_addon"
    
//    main() {}

//    public OnGameModeInit() {
//        actor::actor_create(.........format);
//        actor::actor_destroy(........format);
//        actor::actor_pos(............format);
//        actor::actor_angle(..........format);
//        actor::actor_health(.........format);
//        actor::actor_invulnerable(...format);
//    }
#endif

#if !defined actor::
    #define actor::
    #define actor_create(%0)          CreateActor(%0)
    #define actor_destroy(%0)         DestroyActor(%0)
    #define actor_pos(%0)             SetActorPos(%0)
    #define actor_angle(%0)           SetActorFacingAngle(%0)
    #define actor_health(%0)          SetActorHealth(%0)
    #define actor_invulnerable(%0)    SetActorInvulnerable(%0)
#endif
