#pragma once
#define NOT_FOUND -1

using namespace RE;

namespace SpellUtil {
    BSTArray<SpellItem*> FilterSimilar(BSTArray<SpellItem*> spells, SpellItem* spell);
    BSTArray<SpellItem*> FilterByAssociatedSkill(BSTArray<SpellItem*> spells, ActorValue skill);
    BSTArray<SpellItem*> FilterByCastingType(BSTArray<SpellItem*> spells, MagicSystem::CastingType type);
    BSTArray<SpellItem*> FilterByCostliestEffect(BSTArray<SpellItem*> spells, EffectSetting* effect);
    BSTArray<SpellItem*> FilterByDelivery(BSTArray<SpellItem*> spells, MagicSystem::Delivery delivery);
    BSTArray<SpellItem*> FilterByEquipSlot(BSTArray<SpellItem*> spells, BGSEquipSlot* equipSlot);
    BSTArray<SpellItem*> FilterByKeyword(BSTArray<SpellItem*> spells, BGSKeyword* keyword);
    BSTArray<SpellItem*> FilterByName(BSTArray<SpellItem*> spells, const char* name);
    BSTArray<SpellItem*> FilterBySpellType(BSTArray<SpellItem*> spells, MagicSystem::SpellType type);
    BSTArray<SpellItem*> FilterTeachable(BSTArray<SpellItem*> spells);
    BSTArray<SpellItem*> FilterNotTeachable(BSTArray<SpellItem*> spells);
    BSTArray<SpellItem*> GetTeachableEquivalents(BSTArray<SpellItem*> spells);
    BSTArray<SpellItem*> GetAllSpellTomeSpells();
    BSTArray<SpellItem*> GetAllSpellsWithEquipSlot(BGSEquipSlot* equipSlot);
    bool HasEquipSlot(SpellItem* spell, BGSEquipSlot* equipSlot);
}