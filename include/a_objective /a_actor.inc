#if !defined example
//    #include "System"

//    main() {}

//    public OnGameModeInit() {
//        actors::actor_create(.........format);
//        actors::actor_destroy(........format);
//        actors::actor_pos(............format);
//        actors::actor_angle(..........format);
//        actors::actor_health(.........format);
//        actors::actor_invulnerable(...format);
//    }
#endif

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
