/// <summary>
/// players defined
/// </summary>
#if defined example
    /**
     * example
     */
    #include "a_samp"
    #include "a_addon"
    
    main() {}

    public OnGameModeInit() {
        players::player_pos(...do here);
    }
#endif

#if !defined players::
    #define players::
    #define player_pos(%0)          SetPlayerPos(%0)
#endif
