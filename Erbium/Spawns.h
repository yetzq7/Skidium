// Spawns.h
#pragma once

#include "pch.h"

class AFortPlayerControllerAthena;
struct FVector;

void SpawnBots(AFortPlayerControllerAthena* CallerController, int32 Count, const TArray<FVector>& SpawnLocations = TArray<FVector>());
void UpdateBotMovement();