// BotSpawner.h
#pragma once

#include "pch.h" // your project's precompiled header (brings in TArray, FVector, etc.)

class AFortPlayerControllerAthena;
struct FVector;

/**
 * Spawns a specified number of bots.
 *
 * @param CallerController   The player controller that initiated the spawn (used as context).
 * @param Count              Number of bots to spawn.
 * @param SpawnLocations     Optional list of world locations. If empty, bots are spawned
 *                           at the caller's location with random offsets.
 */
void SpawnBots(AFortPlayerControllerAthena* CallerController, int32 Count, const TArray<FVector>& SpawnLocations = TArray<FVector>());