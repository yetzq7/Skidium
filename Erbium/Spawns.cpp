#include "Spawns.h"
#include "pch.h"
#include "./Erbium/Public/Configuration.h"
#include "./FortniteGame/Public/FortPlayerControllerAthena.h"
#include "./FortniteGame/Public/FortGameMode.h"
#include "./FortniteGame/Public/FortPlayerPawnAthena.h"
#include "./FortniteGame/Public/FortPlayerStateAthena.h"
#include "./FortniteGame/Public/FortGameStateAthena.h"
#include "./FortniteGame/Public/FortInventory.h"
#include "./FortniteGame/Public/FortKismetLibrary.h"
#include "./FortniteGame/Public/FortLootPackage.h"
#include "./FortniteGame/Public/FortWeapon.h"
#include "./FortniteGame/Public/BuildingSMActor.h"
extern uint64_t ApplyCharacterCustomization;
extern uint64_t NotifyGameMemberAdded_;

struct FCustomCharacterParts
{
public:
    USCRIPTSTRUCT_COMMON_MEMBERS(FCustomCharacterParts);
};

static FVector GetRandomSpawnLocation(const FVector& BaseLocation, float Radius = 450.0f)
{
    // Using rand() instead of FMath
    float Angle = ((float)rand() / (float)RAND_MAX) * 2.0f * 3.14159265358979f;
    float Distance = ((float)rand() / (float)RAND_MAX) * Radius;
    FVector Offset(cosf(Angle) * Distance, sinf(Angle) * Distance, 0.0f);
    return BaseLocation + Offset;
}

void SpawnBots(AFortPlayerControllerAthena* CallerController, int32 Count, const TArray<FVector>& SpawnLocations)
{
    if (!CallerController || !CallerController->Pawn)
        return;

    UWorld* World = UWorld::GetWorld();
    if (!World)
        return;

    AFortGameMode* GameMode = (AFortGameMode*)World->AuthorityGameMode;
    if (!GameMode)
        return;

    AFortGameStateAthena* GameState = (AFortGameStateAthena*)GameMode->GameState;
    if (!GameState)
        return;

    for (int32 i = 0; i < Count; ++i)
    {
        FTransform SpawnTransform = CallerController->Pawn->GetTransform();

        if (SpawnLocations.IsValidIndex(i))
        {
            FVector NewLoc = SpawnLocations[i];
            SpawnTransform.Translation = NewLoc;
        }
        else if (SpawnLocations.Num() > 0)
        {
            FVector NewLoc = SpawnLocations[SpawnLocations.Num() - 1];
            SpawnTransform.Translation = NewLoc;
        }
        else
        {
            FVector BaseLoc = CallerController->Pawn->K2_GetActorLocation();
            FVector RandomLoc = GetRandomSpawnLocation(BaseLoc);
            SpawnTransform.Translation = RandomLoc;
        }

   
        AFortPlayerPawnAthena* Pawn = World->SpawnActor<AFortPlayerPawnAthena>(GameMode->DefaultPawnClass, SpawnTransform);

        AFortPlayerControllerAthena* NewController = World->SpawnActor<AFortPlayerControllerAthena>(FindObject<UClass>(L"/Game/Athena/Athena_PlayerController.Athena_PlayerController_C"), SpawnTransform);

        if (!Pawn || !NewController)
            continue;

        NewController->Possess(Pawn);
        NewController->MyFortPawn = Pawn;

        AFortPlayerStateAthena* PlayerState = World->SpawnActor<AFortPlayerStateAthena>(AFortPlayerStateAthena::StaticClass(), SpawnTransform);

        if (!PlayerState)
            continue;

        PlayerState->SetOwner(NewController);
        NewController->PlayerState = PlayerState;
        NewController->OnRep_PlayerState();

        Pawn->PlayerState = PlayerState;
        Pawn->OnRep_PlayerState();

        Pawn->SetMaxHealth(100.f);

        
        PlayerState->TeamIndex = AFortGameMode::PickTeam(GameMode, 0, NewController);
        if (PlayerState->HasSquadId())
            PlayerState->SquadId = PlayerState->TeamIndex - 3;
        if (PlayerState->HasbIsABot())
            PlayerState->bIsABot = true;


        if (GameState->HasGameMemberInfoArray())
        {
            FGameMemberInfo* Member = (FGameMemberInfo*)malloc(FGameMemberInfo::Size());
            memset((PBYTE)Member, 0, FGameMemberInfo::Size());

            Member->MostRecentArrayReplicationKey = -1;
            Member->ReplicationID = -1;
            Member->ReplicationKey = -1;
            Member->TeamIndex = PlayerState->TeamIndex;
            Member->SquadId = PlayerState->SquadId;
            Member->MemberUniqueId = PlayerState->UniqueId;

            GameState->GameMemberInfoArray.Members.Add(*Member, FGameMemberInfo::Size());
            GameState->GameMemberInfoArray.MarkItemDirty(*Member);

            if (NotifyGameMemberAdded_)
            {
                ((void (*)(AFortGameStateAthena*, uint8_t, uint8_t, FUniqueNetIdRepl*))NotifyGameMemberAdded_)(GameState, Member->SquadId, Member->TeamIndex, &Member->MemberUniqueId);
            }

            free(Member);
        }


        for (auto& AbilitySet : AFortGameMode::AbilitySets)
            PlayerState->AbilitySystemComponent->GiveAbilitySet(AbilitySet);

        GameState->PlayersLeft++;
        GameState->OnRep_PlayersLeft();
        GameMode->AlivePlayers.Add(NewController);

        static auto Commando = FindObject(L"/Game/Athena/Heroes/HID_001_Athena_Commando_F.HID_001_Athena_Commando_F", nullptr);
        static auto Commando2 = FindObject(L"/Game/Athena/Heroes/HID_Commando_Athena_01.HID_Commando_Athena_01", nullptr);
        PlayerState->HeroType = Commando ? Commando : Commando2;

        static int32 CharacterPartsOffset = PlayerState->GetOffset("CharacterParts", 0x100000);

        if (CharacterPartsOffset == -1)
        {
            static int32 CharacterPartsOff = PlayerState->GetOffset("CharacterParts");
            if (CharacterPartsOff == -1)
                CharacterPartsOff = PlayerState->GetOffset("LocalCharacterParts");
            auto& CharacterParts = GetFromOffset<const UObject* [0x6]>(PlayerState, CharacterPartsOff);

            static auto Head = FindObject<UObject>(L"/Game/Characters/CharacterParts/Female/Medium/Heads/F_Med_Head1.F_Med_Head1");
            static auto Body = FindObject<UObject>(L"/Game/Characters/CharacterParts/Female/Medium/Bodies/F_Med_Soldier_01.F_Med_Soldier_01");
            static auto Backpack = FindObject<UObject>(L"/Game/Characters/CharacterParts/Backpacks/NoBackpack.NoBackpack");

            CharacterParts[0] = Head;
            CharacterParts[1] = Body;
            CharacterParts[3] = Backpack;
        }
        else
        {
            static int32 CharacterPartsOff = PlayerState->GetOffset("CharacterParts");
            auto& CustomCharacterParts = GetFromOffset<FCustomCharacterParts>(PlayerState, CharacterPartsOff);
            static int32 PartsOffset = FCustomCharacterParts::StaticStruct()->GetOffset("Parts");
            auto& CharacterParts = GetFromOffset<const UObject* [0x6]>(&CustomCharacterParts, PartsOffset);

            static auto Head = FindObject<UObject>(L"/Game/Characters/CharacterParts/Female/Medium/Heads/F_Med_Head1.F_Med_Head1");
            static auto Body = FindObject<UObject>(L"/Game/Characters/CharacterParts/Female/Medium/Bodies/F_Med_Soldier_01.F_Med_Soldier_01");
            static auto Backpack = FindObject<UObject>(L"/Game/Characters/CharacterParts/Backpacks/NoBackpack.NoBackpack");

            CharacterParts[0] = Head;
            CharacterParts[1] = Body;
            CharacterParts[3] = Backpack;
        }

        if (ApplyCharacterCustomization)
        {
            ((void (*)(AActor*, AFortPlayerPawnAthena*))ApplyCharacterCustomization)(PlayerState, Pawn);
        }

        std::string Name = FConfiguration::PawnName;
        std::wstring WideName(Name.begin(), Name.end());
        FString BotName = FString(WideName.c_str());

        if (std::floor(VersionInfo.FortniteVersion) < 9)
        {
            NewController->ServerChangeName(BotName);
        }
        else
        {
            GameMode->ChangeName(NewController, BotName, true);
        }

        PlayerState->OnRep_PlayerName();
    }
}