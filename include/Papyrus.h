#pragma once

#include "ActorUtil.h"
#include "PlayerUtil.h"
#include "SpellUtil.h"
using namespace RE;

namespace Papyrus {
    void AddTeachableSpellsToPlayer(StaticFunctionTag*, Actor* source);
	void CopyAppearanceToPlayer(StaticFunctionTag*, Actor* actor);
    void CopyFactions(StaticFunctionTag*, Actor* destination, Actor* source);
    void CopyOutfit(StaticFunctionTag*, Actor* destination, Actor* source);
    void CopySkillPerks(StaticFunctionTag*, Actor* destination, Actor* source);
    void CopySkills(StaticFunctionTag*, Actor* destination, Actor* source);
    void SetFaceMorph(StaticFunctionTag*, TESNPC* actorBase, float value, uint32_t index);
    void SetFacePreset(StaticFunctionTag*, TESNPC* actorBase, uint32_t value, uint32_t index);
    void SetGenderAnimations(StaticFunctionTag*, TESNPC* actorBase, bool useOppositeGenderAnimations);
    void SexChange(StaticFunctionTag*, TESNPC* actorBase);
    
    bool RegisterFuncs(RE::BSScript::IVirtualMachine* vm);
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
    bool RegisterFuncs(RE::BSScript::IVirtualMachine* vm);
}