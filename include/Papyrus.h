#pragma once

#include "ActorUtil.h"
#include "PlayerUtil.h"
#include "SpellUtil.h"

using namespace RE;

namespace Papyrus {
    void AddTeachableSpellsToPlayer(StaticFunctionTag*, Actor* source);
	void CopyAppearanceToPlayer(StaticFunctionTag*, Actor* actor);
    void CopySkillPerks(StaticFunctionTag*, Actor* destination, Actor* source);
    void CopyOutfit(StaticFunctionTag*, Actor* destination, Actor* source);
    bool RegisterFuncs(BSScript::IVirtualMachine* vm);
}

namespace PapyrusTest {
    void CopySex(StaticFunctionTag*, Actor* actor);
    void CopyGenderAnimations(StaticFunctionTag*, Actor* actor);
    void CopyFaceData(StaticFunctionTag*, Actor* actor);
    void CopyHeadParts(StaticFunctionTag*, Actor* actor);
    void CopyHeadRelatedData(StaticFunctionTag*, Actor* actor);
    void CopyHeight(StaticFunctionTag*, Actor* actor);
    void CopyWeight(StaticFunctionTag*, Actor* actor);
    void CopyRace(StaticFunctionTag*, Actor* actor);
    void UpdateAppearance(StaticFunctionTag*);
    void CopyBodyTintColor(StaticFunctionTag*, Actor* actor);
    void ResetRaceSexTintMasks(StaticFunctionTag*);
    void DoReset3D(StaticFunctionTag*);
    void RunTestSuite(StaticFunctionTag*);
    bool RegisterFuncs(BSScript::IVirtualMachine* vm);
}