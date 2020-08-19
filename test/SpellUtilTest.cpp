#include "SpellUtilTest.h"
#include "SpellUtil.h"
#include "Test.h"

namespace Test {
	BSTHashMap<uint32_t, std::string> ReadCSV(std::string path) {
		BSTHashMap<uint32_t, std::string> map;
		
		std::ifstream filestream(path);
		std::string line;
		while (std::getline(filestream, line)) {
			std::string value = line.substr(0, line.find(','));
			uint32_t key = std::stoul(line.substr(line.find(',') + 1, line.length()), nullptr, 16);
			map.insert({ key, value });
		}

		return map;
	}

	bool GetAllSpellTomeSpellsTest() {
		BSTArray<SpellItem*> tomeSpells = SpellUtil::GetAllSpellTomeSpells();
		return true;
	}
	void RunSpellUtilTests() {
		LogTestResult("SpellUtil::GetAllSpellTomeSpells Test", GetAllSpellTomeSpellsTest());
	}
}