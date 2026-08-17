#pragma once

struct FConfiguration
{
    //static inline auto Playlist = L"/Game/Athena/Playlists/Showdown/Playlist_ShowdownAlt_Solo.Playlist_ShowdownAlt_Solo";
   // static inline auto Playlist = L"/Game/Plugins/GameFeatures/LTM/Melt/Content/Playlists/Playlist_Melt_Solo.Playlist_Melt_Solo";
   // static inline auto Playlist = L"/Game/Athena/Playlists/Showdown/Tournament/Playlist_ShowdownTournament_Solo.Playlist_ShowdownTournament_Solo";
   // static inline auto Playlist = L"/Game/Athena/Playlists/Showdown/Playlist_ShowdownAlt_Duos.Playlist_ShowdownAlt_Duos";
    //static inline auto Playlist = L"/Game/Athena/Playlists/Creative/Playlist_PlaygroundV2.Playlist_PlaygroundV2";
    static inline auto Playlist = L"/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo";

    static inline auto MaxTickRate = 120;

    static inline auto bLateGame = false;
    static inline auto LateGameZone = 3;  
    static inline auto bLateGameLongZone = false; 

    // Creative Stuff
    // check Game/Content/Playgrounds/Items/Plots/ for more plots
    // can also be your own!
    static inline auto CreativeTerrain = L"/Game/Playgrounds/Items/Plots/Tropical_Medium.Tropical_Medium";
    

    static inline auto bCustomTerrain = false; // if u have a custom map with its paks inserted and correct terrain path
    static inline auto CustomTerrainPath = L"open /Game/Path/Goes/Here";

    // gaycoded / they have no brain & cosmetics
    static inline auto bEnablePawnSpawns = false;
    static inline auto PawnAmount = 10; // amount of pawns or "bots" to spawn
    static inline auto PawnName = "projectboss"; // will be switched to a list if i ever give them a brain

    static inline auto bEnableAPI = false;
    static inline auto MatchmakerURL = "127.0.0.1:PORT/endpoint";
    // Example: For phoenix mm the default is port 1111 and it get from /started so it would be 127.0.0.1:1111/started unless you change the port or endpoint
    
    // Reviving (Ill commit it again when its fixed)
    // dosent do nth for now
    // static inline auto bRevives = 3; 
    // 3 = trios, 2 = duos, 4 = squads, 0 = off

    static inline auto bEnableCheats = false;
    static inline auto SiphonAmount = 50; // set to 0 to disable
    static inline auto bInfiniteMats = true;
    static inline auto bInfiniteAmmo = false;
    static inline auto bForceRespawns = false;
    static inline auto bJoinInProgress = false;
    static inline auto bAutoRestart = true;
    static inline auto bKeepInventory = false;
    static inline auto Port = 7777;
    static inline auto bEnableIris = true;
    static inline constexpr auto bGUI = false;
    static inline constexpr auto bCustomCrashReporter = true;
    static inline constexpr auto bUseStdoutLog = true;
    static inline constexpr auto WebhookURL = ""; // broken bc im sped and smh broke it while making the embed more simple
    static inline auto PlaylistName = L""; // for webhook but its broke nfor now so
};
        
