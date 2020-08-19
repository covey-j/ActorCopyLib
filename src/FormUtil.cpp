#include "FormUtil.h"

namespace FormUtil {
    bool Equals(TESForm* form1, TESForm* form2) {
        return form1->formID == form2->formID;
    }
}