#include "Papyrus.h"
#include "PlayerUtil.h"
#include "Test.h"
#include "BSTArrayUtil.h"

namespace Papyrus {
    // TODO : Investigate weirdness with stunted magicka, slightly off faces, strange height when switching to child race

    void AddTeachableSpellsToPlayer(StaticFunctionTag*, Actor* source) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        auto copier = PlayerUtil::ActorToPlayerCopier(player, source);
        copier.AddTeachableSpells();
    }

    void CopyAppearanceToPlayer(StaticFunctionTag*, Actor* source) {
        auto task = SKSE::GetTaskInterface();
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        auto copier = PlayerUtil::ActorToPlayerCopier(player, source);
        copier.CopyAppearance();
    }

    void CopySkillPerks(StaticFunctionTag*, Actor* destination, Actor* source) {
        auto copier = ActorUtil::ActorCopier(destination, source);
        ActorUtil::RemoveSkillPerks(destination);
        copier.AddSkillPerks();
    }

    void CopyOutfit(StaticFunctionTag*, Actor* destination, Actor* source) {
        // TODO
    }

    bool RegisterFuncs(BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("AddTeachableSpellsToPlayer", "ActorCopyLib", AddTeachableSpellsToPlayer);
        vm->RegisterFunction("CopyAppearanceToPlayer", "ActorCopyLib", CopyAppearanceToPlayer);
        vm->RegisterFunction("CopySkillPerks", "ActorCopyLib", CopySkillPerks);
        vm->RegisterFunction("CopyOutfit", "ActorCopyLib", CopyOutfit);

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

    void UpdateAppearance(StaticFunctionTag*) {
        PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
        ActorUtil::UpdateAppearance(player);
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

    bool RegisterFuncs(BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("CopySex", "ActorCopyLibTestSuite", CopySex);
        vm->RegisterFunction("CopyGenderAnimations", "ActorCopyLibTestSuite", CopyGenderAnimations);
        vm->RegisterFunction("CopyFaceData", "ActorCopyLibTestSuite", CopyFaceData);
        vm->RegisterFunction("CopyHeadParts", "ActorCopyLibTestSuite", CopyHeadParts);
        vm->RegisterFunction("CopyHeadRelatedData", "ActorCopyLibTestSuite", CopyHeadRelatedData);
        vm->RegisterFunction("CopyHeight", "ActorCopyLibTestSuite", CopyHeight);
        vm->RegisterFunction("CopyWeight", "ActorCopyLibTestSuite", CopyWeight);
        vm->RegisterFunction("CopyRace", "ActorCopyLibTestSuite", CopyRace);
        vm->RegisterFunction("UpdateAppearance", "ActorCopyLibTestSuite", UpdateAppearance);
        vm->RegisterFunction("CopyBodyTintColor", "ActorCopyLibTestSuite", CopyBodyTintColor);
        vm->RegisterFunction("ResetPlayerTintMasks", "ActorCopyLibTestSuite", ResetPlayerTintMasks);
        vm->RegisterFunction("DoReset3D", "ActorCopyLib", DoReset3D);
        vm->RegisterFunction("RunTestSuite", "ActorCopyLibTestSuite", RunTestSuite);
        
        return true;
    }
}