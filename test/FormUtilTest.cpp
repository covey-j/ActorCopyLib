#include "FormUtil.h"
#include "FormUtilTest.h"
#include "Test.h"

#define NUM_BOOKS 1042
#define NUM_PERKS 476
#define NUM_SPELLS 1358

namespace Test {
	bool GetFormArrayTest() {
		BSTArray<SpellItem*> allSpells = FormUtil::GetFormArray<SpellItem>();
		BSTArray<TESObjectBOOK*> allBooks = FormUtil::GetFormArray<TESObjectBOOK>();
		BSTArray<BGSPerk*> allPerks = FormUtil::GetFormArray<BGSPerk>();
		
		if (allPerks.size() != NUM_PERKS)
			return false;
		if (allSpells.size() != NUM_SPELLS)
			return false;
		if (allBooks.size() != NUM_BOOKS)
			return false;

		for (TESObjectBOOK* book : allBooks)
			if (!book->Is(FormType::Book))
				return false;
		for (SpellItem* spell : allSpells)
			if (!spell->Is(FormType::Spell))
				return false;
		for (BGSPerk* perk : allPerks)
			if (!perk->Is(FormType::Perk))
				return false;
		
		return true;
	}
	
	void RunFormUtilTests() {
		LogTestResult("FormUtil::GetFormArray Test", GetFormArrayTest());
	}
}