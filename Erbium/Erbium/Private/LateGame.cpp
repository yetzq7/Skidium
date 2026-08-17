#include "pch.h"
#include "../Public/LateGame.h"
#include "../../FortniteGame/Public/FortInventory.h"
#include "../Public/Utils.h"

FLateGameItem LateGame::GetShotgun()
{
    static UEAllocatedVector<FLateGameItem> Shotguns{};

    if (Shotguns.size() == 0)
    {
        {
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_SR_Ore_T03.WID_Shotgun_Standard_Athena_SR_Ore_T03")));
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_VR_Ore_T03.WID_Shotgun_Standard_Athena_VR_Ore_T03")));
            //hotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Charge_Athena_SR_Ore_T03.WID_Shotgun_Charge_Athena_SR_Ore_T03")));
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_UC_Ore_T03.WID_Shotgun_Standard_Athena_UC_Ore_T03")));
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Swing_Athena_R.WID_Shotgun_Swing_Athena_R")));
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_HighSemiAuto_Athena_VR_Ore_T03.WID_Shotgun_HighSemiAuto_Athena_VR_Ore_T03")));
           // Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Charge_Athena_R_Ore_T03.WID_Shotgun_Charge_Athena_R_Ore_T03")));
            Shotguns.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Shotgun_Swing_Athena_VR.WID_Shotgun_Swing_Athena_VR")));
        }
    }

    return Shotguns[rand() % Shotguns.size()];
}

FLateGameItem LateGame::GetAssaultRifle()
{
    static UEAllocatedVector<FLateGameItem> AssaultRifles{};

    if (AssaultRifles.size() == 0)
    {
        {
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_AutoHigh_Athena_SR_Ore_T03.WID_Assault_AutoHigh_Athena_SR_Ore_T03")));
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_AutoHigh_Athena_VR_Ore_T03.WID_Assault_AutoHigh_Athena_VR_Ore_T03")));
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_SemiAuto_Athena_VR_Ore_T03.WID_Assault_SemiAuto_Athena_VR_Ore_T03")));
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_Suppressed_Athena_SR_Ore_T03.WID_Assault_Suppressed_Athena_SR_Ore_T03")));
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_Auto_Athena_R_Ore_T03.WID_Assault_Auto_Athena_R_Ore_T03")));
            //AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/Boss/WID_Boss_Midas.WID_Boss_Midas")));
            AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Assault_SemiAuto_Athena_SR_Ore_T03.WID_Assault_SemiAuto_Athena_SR_Ore_T03")));
            // AssaultRifles.push_back(FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/")));
        }
    }

    return AssaultRifles[rand() % AssaultRifles.size()];
}

FLateGameItem LateGame::GetUtility()
{
    static UEAllocatedVector<FLateGameItem> Utilities{
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Sniper_BoltAction_Scope_Athena_SR_Ore_T03.WID_Sniper_BoltAction_Scope_Athena_SR_Ore_T03")), // bolt
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Pistol_Scavenger_Athena_VR_Ore_T03.WID_Pistol_Scavenger_Athena_VR_Ore_T03")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Pistol_AutoHeavyPDW_Athena_SR_Ore_T03.WID_Pistol_AutoHeavyPDW_Athena_SR_Ore_T03")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/LTM/WID_Sniper_NoScope_Athena_VR_Ore_T03.WID_Sniper_NoScope_Athena_VR_Ore_T03")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Sniper_BoltAction_Scope_Athena_R_Ore_T03.WID_Sniper_BoltAction_Scope_Athena_R_Ore_T03")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Hook_Gun_VR_Ore_T03.WID_Hook_Gun_VR_Ore_T03")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/Boss/WID_Boss_GrapplingHoot.WID_Boss_GrapplingHoot")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Launcher_Shockwave_Athena_UR_Ore_T03.WID_Launcher_Shockwave_Athena_UR_Ore_T03")),
        FLateGameItem(6, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/ShockwaveGrenade/Athena_ShockGrenade.Athena_ShockGrenade")),
        FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WaffleTruck/WID_WaffleTruck_Sniper_DragonBreath.WID_WaffleTruck_Sniper_DragonBreath"))
    };

    static bool bAdded = false;
    if (!bAdded)
    {
        bAdded = true;

        if (VersionInfo.FortniteVersion >= 24.20 && VersionInfo.FortniteVersion < 25)
        {
            auto ODMGear = FLateGameItem(3, FindObject<UFortWeaponRangedItemDefinition>(L"/DryBox/Items/NyxGlass/AGID_NyxGlass.AGID_NyxGlass"));
            Utilities.push_back(ODMGear);
        }
    }

    return Utilities[rand() % Utilities.size()];
}

FLateGameItem LateGame::GetHeal()
{
    static UEAllocatedVector<FLateGameItem> Heals{ FLateGameItem(3, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/Shields/Athena_Shields.Athena_Shields")),             // big pots
                                                   FLateGameItem(6, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/ShieldSmall/Athena_ShieldSmall.Athena_ShieldSmall")) // minis
                                                  // FLateGameItem(3, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/Flopper/WID_Athena_Flopper.WID_Athena_Flopper")),     // flopper
                                                  // FLateGameItem(3, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/Medkit/Athena_Medkit.Athena_Medkit")),
                                                  // FLateGameItem(1, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/BottomlessChugJug/WID_Athena_BottomlessChugJug.WID_Athena_BottomlessChugJug"))

    };

    static bool bAdded = false;
    if (!bAdded)
    {
        bAdded = true;

        auto ChugSplash = FLateGameItem(6, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/ChillBronco/Athena_ChillBronco_VR.Athena_ChillBronco_VR"));
        // auto SlurpJuice = FLateGameItem(2, FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Consumables/PurpleStuff/Athena_PurpleStuff.Athena_PurpleStuff"));

        if (ChugSplash.Item)
            Heals.push_back(ChugSplash);

        // if (SlurpJuice.Item)
        //    Heals.push_back(SlurpJuice);

        if (VersionInfo.FortniteVersion >= 19 && VersionInfo.FortniteVersion < 27)
        {
            auto MedMist = FLateGameItem(2, FindObject<UFortItemDefinition>(L"/FlipperGameplay/Items/HealSpray/WID_Athena_HealSpray.WID_Athena_HealSpray"));

            Heals.push_back(MedMist);
        }
    }

    return Heals[rand() % Heals.size()];
}

const UFortItemDefinition* LateGame::GetAmmo(EAmmoType AmmoType)
{
    static UEAllocatedVector<const UFortItemDefinition*> Ammos{ FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Ammo/AthenaAmmoDataBulletsLight.AthenaAmmoDataBulletsLight"),
                                                                FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Ammo/AthenaAmmoDataShells.AthenaAmmoDataShells"),
                                                                FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Ammo/AthenaAmmoDataBulletsMedium.AthenaAmmoDataBulletsMedium"),
                                                                FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Ammo/AmmoDataRockets.AmmoDataRockets"),
                                                                FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Ammo/AthenaAmmoDataBulletsHeavy.AthenaAmmoDataBulletsHeavy") };

    return Ammos[(uint8)AmmoType];
}

const UFortItemDefinition* LateGame::GetResource(EFortResourceType ResourceType)
{
    static UEAllocatedVector<const UFortItemDefinition*> Resources{ FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/WoodItemData.WoodItemData"),
                                                                    FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/StoneItemData.StoneItemData"),
                                                                    FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/MetalItemData.MetalItemData") };

    return Resources[(uint8)ResourceType];
}
