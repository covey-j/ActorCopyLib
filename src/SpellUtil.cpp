#include "PCH.h"
#include "EffectUtil.h"
#include "FormUtil.h"
#include "SpellUtil.h"
#include "BSTArrayUtil.h"
#include <functional>

namespace SpellUtil {

    bool HasEquipSlot(SpellItem* spell, BGSEquipSlot* equipSlot) {
        return FormUtil::Equals(spell->GetEquipSlot(), equipSlot);
    }

    BSTArray<SpellItem*> FilterSimilar(BSTArray<SpellItem*> spells, SpellItem* spell) {
        spells = FilterBySpellType(spells, spell->GetSpellType());
        spells = FilterByAssociatedSkill(spells, spell->GetAssociatedSkill());
        spells = FilterByDelivery(spells, spell->GetDelivery());
        spells = FilterByCastingType(spells, spell->GetCastingType());
        return spells;
    }

    BSTArray<SpellItem*> FilterByAssociatedSkill(BSTArray<SpellItem*> spells, ActorValue skill) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetAssociatedSkill() == skill;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByCastingType(BSTArray<SpellItem*> spells, MagicSystem::CastingType type) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetCastingType() == type;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByCostliestEffect(BSTArray<SpellItem*> spells, EffectSetting* effect) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetCostliestEffectItem()->baseEffect->formID == effect->formID;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByDelivery(BSTArray<SpellItem*> spells, MagicSystem::Delivery delivery) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetDelivery() == delivery;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByEquipSlot(BSTArray<SpellItem*> spells, BGSEquipSlot* equipSlot) {
        auto filter = [=](SpellItem* spell) {
            return HasEquipSlot(spell, equipSlot);
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByKeyword(BSTArray<SpellItem*> spells, BGSKeyword* keyword) {
        auto filter = [=](SpellItem* spell) {
            return spell->HasKeyword(keyword);
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterByName(BSTArray<SpellItem*> spells, const char* name) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetName() == name;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterBySpellType(BSTArray<SpellItem*> spells, MagicSystem::SpellType type) {
        auto filter = [=](SpellItem* spell) {
            return spell->GetSpellType() == type;
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterTeachable(BSTArray<SpellItem*> spells) {
        BSTArray<SpellItem*> teachableSpells = GetAllSpellTomeSpells();
        auto filter = [=](SpellItem* spell) {
            return BSTArrayUtil::IsIn(spell, teachableSpells);
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> FilterNotTeachable(BSTArray<SpellItem*> spells) {
        BSTArray<SpellItem*> teachableSpells = GetAllSpellTomeSpells();
        auto filter = [=](SpellItem* spell) {
            return !BSTArrayUtil::IsIn(spell, teachableSpells);
        };

        return BSTArrayUtil::Filter<SpellItem>(spells, filter);
    }

    BSTArray<SpellItem*> GetTeachableEquivalents(BSTArray<SpellItem*> spells) {
        BSTArray<SpellItem*> teachableSpells = GetAllSpellTomeSpells();

        auto similar = [](SpellItem* A, SpellItem* B) {
            if (A->GetName() != B->GetName())
                return false;
            if (A->GetSpellType() != B->GetSpellType())
                return false;
            if (A->GetAssociatedSkill() != B->GetAssociatedSkill())
                return false;
            if (A->GetDelivery() != B->GetDelivery())
                return false;
            if (A->GetCastingType() != B->GetCastingType())
                return false;
            return true;
        };

        auto filter = [=](SpellItem* teachableSpell) {
            for (SpellItem* spell : spells)
                if (similar(spell, teachableSpell))
                    return true;
            return false;
        };
 
        return BSTArrayUtil::Filter<SpellItem>(teachableSpells, filter);
    }

    BSTArray<SpellItem*> GetAllSpellTomeSpells() {
        BSTArray<TESObjectBOOK*> books = FormUtil::GetFormArray<TESObjectBOOK>();
        BSTArray<SpellItem*> spells;
        for (TESObjectBOOK* book : books)
            if (book->TeachesSpell())
                spells.push_back(book->GetSpell());
        return spells;
    }

    BSTArray<SpellItem*> GetAllSpellsWithEquipSlot(BGSEquipSlot* equipSlot) {
        BSTArray<SpellItem*> allSpells = FormUtil::GetFormArray<SpellItem>();
        return FilterByEquipSlot(allSpells, equipSlot);
    }
}