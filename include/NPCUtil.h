#pragma once

using namespace RE;

namespace NPCUtil {
	class NPCCopier {
	public:
		NPCCopier();
		NPCCopier(RE::TESNPC* destination, RE::TESNPC* source);
		
		void CopyBodyTintColor();
		void CopyFaceData();
		void CopyFaceDataMorphs();
		void CopyFaceDataParts();
		void CopyFaceTexture();
		void CopyGenderAnimations();
		void CopyHairColor();
		void CopyHeadParts();
		void CopyHeadRelatedData();
		void CopyHeight();
		void CopyRace();
		void CopySex();
		void CopySkin();
		void CopyWeight();

		~NPCCopier();
	private:
		RE::TESNPC* destination;
		RE::TESNPC* source;
	};

	BSTArray<SpellItem*> GetSpells(TESNPC* npc);
	BGSColorForm* GetDefaultHairColor(TESRace* race, SEX sex);
	BGSTextureSet* GetDefaultFaceTexture(TESRace* race, SEX sex);
	void RemoveAllHeadParts(TESNPC* npc);
	void RemoveHeadPart(TESNPC* npc, TESNPC::HeadPartType type);
	void SetActorBaseDataFlag(TESActorBaseData* actorBaseData, ACTOR_BASE_DATA::Flag flag, bool enable);
	void SetFaceMorph(TESNPC* npc, float value, uint32_t n);
	void SetFacePreset(TESNPC* npc, uint32_t value, uint32_t n);
	void SetOppositeGenderAnimations(TESNPC* npc, bool useOppositeGenderAnims);
	void SexChange(TESNPC* npc);
}