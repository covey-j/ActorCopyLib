#pragma once

using namespace RE;

namespace FormUtil {
    bool Equals(TESForm* form1, TESForm* form2);
    template <class T>
    BSTArray<T*> GetFormArray() {
        return TESDataHandler::GetSingleton()->GetFormArray<T>();
    }
}