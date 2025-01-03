/// <summary>
/// actor defined
/// </summary>
#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        actor::actor_create(...do here);
        actor::actor_destroy(...do here);
        actor::actor_pos(...do here);
        actor::actor_health(...do here);
        actor::actor_invulnerable(...do here);
    }
#endif

#if !defined actor::
    #define actor::
    #define actor_create(%0)          CreateActor(%0)
    #define actor_destroy(%0)         DestroyActor(%0)
    #define actor_pos(%0)             SetActorPos(%0)
    #define actor_health(%0)          SetActorHealth(%0)
    #define actor_invulnerable(%0)    SetActorInvulnerable(%0)
#endif
