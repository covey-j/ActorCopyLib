#include "FormUtilTest.h"
#include "SpellUtilTest.h"
#include "ActorUtil.h"
#include "PlayerUtil.h"

namespace Test {
	void LogTestResult(std::string testName, bool passed) {
		std::string testResult = passed ? "PASS" : "FAIL";
		logger::info("%s - %s\n"sv, testName, testResult);
	}

	void RunTestSuite() {
		RunFormUtilTests();
		RunSpellUtilTests();
	}
}