#include "Papyrus.h"
#include "PlayerUtil.h"
#include "Test.h"
#include "BSTArrayUtil.h"

namespace Papyrus {
    void AddTeachableSpellsToPlayer(StaticFunctionTag*, Actor* source) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        auto copier = PlayerUtil::ActorToPlayerCopier(player, source);
        copier.AddTeachableSpells();
    }

    void CopyAppearanceToPlayer(StaticFunctionTag*, Actor* source) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        auto copier = PlayerUtil::ActorToPlayerCopier(player, source);
        copier.CopyAppearance();
    }

    void CopyAttributes(StaticFunctionTag*, Actor* destination, Actor* source) {
        auto copier = ActorUtil::ActorCopier(destination, source);
        copier.CopyAttributes();
    }

    void CopyFactions(StaticFunctionTag*, Actor* destination, Actor* source) {
        auto copier = ActorUtil::ActorCopier(destination, source);
        copier.CopyFactions();
    }

    void CopySkillPerks(StaticFunctionTag*, Actor* destination, Actor* source) {
        auto copier = ActorUtil::ActorCopier(destination, source);
        ActorUtil::RemoveSkillPerks(destination);
        copier.AddSkillPerks();
    }

    void CopySkills(StaticFunctionTag*, Actor* destination, Actor* source) {
        auto copier = ActorUtil::ActorCopier(destination, source);
        copier.CopySkills();
    }

    void CopyOutfit(StaticFunctionTag*, Actor* destination, Actor* source) {
        // TODO
    }

    void SetFaceMorph(StaticFunctionTag*, TESNPC* actorBase, float value, uint32_t index) {
        NPCUtil::SetFaceMorph(actorBase, value, index);
    }

    void SetFacePreset(StaticFunctionTag*, TESNPC* actorBase, uint32_t value, uint32_t index) {
        NPCUtil::SetFacePreset(actorBase, value, index);
    }

    void SetGenderAnimations(StaticFunctionTag*, TESNPC* actorBase, bool useOppositeGenderAnims) {
        NPCUtil::SetOppositeGenderAnimations(actorBase, useOppositeGenderAnims);
    }

    void SexChange(StaticFunctionTag*, TESNPC* actorBase) {
        NPCUtil::SexChange(actorBase);
    }

    bool RegisterFuncs(RE::BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("AddTeachableSpellsToPlayer", "ActorCopyLib", AddTeachableSpellsToPlayer);
        vm->RegisterFunction("CopyAppearanceToPlayer", "ActorCopyLib", CopyAppearanceToPlayer);
        vm->RegisterFunction("CopyAttributes", "ActorCopyLib", CopyAttributes);
        vm->RegisterFunction("CopyFactions", "ActorCopyLib", CopyFactions);
        vm->RegisterFunction("CopySkillPerks", "ActorCopyLib", CopySkillPerks);
        vm->RegisterFunction("CopySkills", "ActorCopyLib", CopySkills);
        vm->RegisterFunction("CopyOutfit", "ActorCopyLib", CopyOutfit);
        vm->RegisterFunction("SetFaceMorph", "ActorCopyLib", SetFaceMorph);
        vm->RegisterFunction("SetFacePreset", "ActorCopyLib", SetFacePreset);
        vm->RegisterFunction("SetGenderAnimations", "ActorCopyLib", SetGenderAnimations);
        vm->RegisterFunction("SexChange", "ActorCopyLib", SexChange);

        return true;
    }
}

namespace PapyrusTest {
    void CopySex(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopySex();
    }

    void CopyGenderAnimations(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyGenderAnimations();
    }

    void CopyFaceData(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyFaceData();
    }

    void CopyHeadParts(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyHeadParts();
    }

    void CopyHeadRelatedData(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyHeadRelatedData();
    }

    void CopyHeight(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyHeight();
    }

    void CopyWeight(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyWeight();
    }

    void CopyRace(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyRace();
    }

    void CopyBodyTintColor(StaticFunctionTag*, Actor* actor) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ActorToPlayerCopier copier = PlayerUtil::ActorToPlayerCopier(player, actor);
        copier.CopyBodyTintColor();
    }

    void ResetPlayerTintMasks(StaticFunctionTag*) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        PlayerUtil::ResetPlayerTintMasks(player);
    }

    void DoReset3D(StaticFunctionTag*) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        player->DoReset3D(true);
    }

    void RunTestSuite(StaticFunctionTag*) {
        auto task = SKSE::GetTaskInterface();
        task->AddTask(Test::RunTestSuite);
    }

    bool RegisterFuncs(RE::BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("CopySex", "ActorCopyLibTestSuite", CopySex);
        vm->RegisterFunction("CopyGenderAnimations", "ActorCopyLibTestSuite", CopyGenderAnimations);
        vm->RegisterFunction("CopyFaceData", "ActorCopyLibTestSuite", CopyFaceData);
        vm->RegisterFunction("CopyHeadParts", "ActorCopyLibTestSuite", CopyHeadParts);
        vm->RegisterFunction("CopyHeadRelatedData", "ActorCopyLibTestSuite", CopyHeadRelatedData);
        vm->RegisterFunction("CopyHeight", "ActorCopyLibTestSuite", CopyHeight);
        vm->RegisterFunction("CopyWeight", "ActorCopyLibTestSuite", CopyWeight);
        vm->RegisterFunction("CopyRace", "ActorCopyLibTestSuite", CopyRace);
        vm->RegisterFunction("CopyBodyTintColor", "ActorCopyLibTestSuite", CopyBodyTintColor);
        vm->RegisterFunction("ResetPlayerTintMasks", "ActorCopyLibTestSuite", ResetPlayerTintMasks);
        vm->RegisterFunction("DoReset3D", "ActorCopyLibTestSuite", DoReset3D);
        vm->RegisterFunction("RunTestSuite", "ActorCopyLibTestSuite", RunTestSuite);
        
        return true;
    }
}