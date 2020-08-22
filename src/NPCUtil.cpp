#include "NPCUtil.h"

namespace NPCUtil {
	NPCCopier::NPCCopier() {
		destination = nullptr;
		source = nullptr;
	}

	NPCCopier::NPCCopier(RE::TESNPC* destination, RE::TESNPC* source) {
		this->destination = destination;
		this->source = source;
	}

	void NPCCopier::CopyBodyTintColor() {
		destination->bodyTintColor = source->bodyTintColor;
	}

	void NPCCopier::CopyFaceData() {
		CopyFaceDataMorphs();
		CopyFaceDataParts();
	}

	void NPCCopier::CopyFaceDataMorphs() {
		for (int i = 0; i < TESNPC::FaceData::Morphs::kTotal; i++)
			SetFaceMorph(destination, source->faceData->morphs[i], i);
	}

	void NPCCopier::CopyFaceDataParts() {
		for (int i = 0; i < TESNPC::FaceData::Parts::kTotal; i++)
			SetFacePreset(destination, source->faceData->parts[i], i);
	}

	void NPCCopier::CopyFaceTexture() {
		BGSTextureSet* faceTexture = nullptr;
		if (source->headRelatedData)
			faceTexture = source->headRelatedData->faceDetails;
		else
			faceTexture = GetDefaultFaceTexture(source->race, source->GetSex());
		if (faceTexture)
			destination->SetFaceTexture(faceTexture);
		else
			destination->SetFaceTexture(nullptr);
	}

	void NPCCopier::CopyGenderAnimations() {
		SetOppositeGenderAnimations(destination, source->UsesOppositeGenderAnims());
	}

	void NPCCopier::CopyHairColor() {
		BGSColorForm* hairColor = nullptr;
		if (source->headRelatedData)
			hairColor = source->headRelatedData->hairColor;
		else
			hairColor = GetDefaultHairColor(source->race, source->GetSex());
		if (hairColor)
			destination->SetHairColor(hairColor);
	}

	void NPCCopier::CopyHeadParts() {
		RemoveAllHeadParts(destination);
		for (int i = 0; i < source->numHeadParts; i++)
			if (source->headParts && source->headParts[i])
				destination->ChangeHeadPart(source->headParts[i]);
	}

	void NPCCopier::CopyHeadRelatedData() {
		CopyHairColor();
		CopyFaceTexture();
	}

	void NPCCopier::CopyHeight() {
		destination->height = source->GetHeight();
	}

	void NPCCopier::CopySex() {
		if (destination->GetSex() != source->GetSex())
			SexChange(destination);
	}

	void NPCCopier::CopySkin() {
		destination->skin = source->skin;
		destination->farSkin = source->farSkin;
	}

	void NPCCopier::CopyRace() {
		destination->race = source->race;
		destination->originalRace = source->originalRace;
	}

	void NPCCopier::CopyWeight() {
		destination->weight = source->GetWeight();
	}

	NPCCopier::~NPCCopier() {}

	BGSColorForm* GetDefaultHairColor(TESRace* race, SEX sex) {
		if (race && (race->data.flags & RACE_DATA::Flag::kFaceGenHead))
			return race->faceRelatedData[sex]->defaultHairColor;
	}

	BGSTextureSet* GetDefaultFaceTexture(TESRace* race, SEX sex) {
		if (race && (race->data.flags & RACE_DATA::Flag::kFaceGenHead))
			return race->faceRelatedData[sex]->defaultFaceDetailsTextureSet;
	}

	BSTArray<SpellItem*> GetSpells(TESNPC* npc) {
		BSTArray<SpellItem*> spells;
		if (npc && npc->actorEffects)
			for (int i = 0; i < npc->actorEffects->numSpells; i++)
				spells.push_back(npc->actorEffects->spells[i]);
		return spells;
	}

	void RemoveAllHeadParts(TESNPC* npc) {
		if (npc && npc->headParts)
			while (npc->numHeadParts > 0)
				if (npc->headParts[0])
					RemoveHeadPart(npc, npc->headParts[0]->type.get());
	}

	void RemoveHeadPart(TESNPC* npc, TESNPC::HeadPartType type) {
		using func_t = decltype(&RemoveHeadPart);
		REL::Relocation<func_t> func{ REL::ID(24247) };
		return func(npc, type);
	}

	/*void NPCCopier::SetHairColorNative(BGSColorForm* color) {
		using func_t = decltype(&NPC::SetHairColorNative);
		REL::Relocation<func_t> func{ REL::ID(24198) };
		return func(this, color);
	}
	void NPCCopier::SetFaceTextureNative(BGSTextureSet* texture) {
		using func_t = decltype(&NPC::SetFaceTextureNative);
		REL::Relocation<func_t> func{ REL::ID(24199) };
		return func(this, texture);
	}*/

	void SetActorBaseDataFlag(TESActorBaseData* actorBaseData, ACTOR_BASE_DATA::Flag flag, bool enable) {
		using func_t = decltype(&SetActorBaseDataFlag);
		REL::Relocation<func_t> func{ REL::ID(14261) };
		return func(actorBaseData, flag, enable);
	}

	void SetFaceMorph(TESNPC* npc, float value, uint32_t n) {
		using func_t = void (*)(TESNPC*, uint32_t, float);
		REL::Relocation<func_t> func{ REL::ID(24183) };
		return func(npc, n, value);
	};

	void SetFacePreset(TESNPC* npc, uint32_t value, uint32_t n) {
		using func_t = decltype(&SetFacePreset);
		REL::Relocation<func_t> func{ REL::ID(24185) };
		return func(npc, n, value);
	};

	void SetOppositeGenderAnimations(TESNPC* npc, bool useOppositeGenderAnims) {
		SetActorBaseDataFlag(npc, ACTOR_BASE_DATA::Flag::kOppositeGenderanims, useOppositeGenderAnims);
	}

	void SexChange(TESNPC* npc) {
		SEX sex = npc->GetSex();
		if (sex == SEX::kFemale)
			sex = SEX::kMale;
		else if (sex == SEX::kMale)
			sex = SEX::kFemale;
		SetActorBaseDataFlag(npc, ACTOR_BASE_DATA::Flag::kFemale, sex);
	}
}

