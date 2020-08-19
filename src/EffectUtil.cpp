#include "EffectUtil.h"

namespace EffectUtil {
    uint32_t GetArea(Effect* effect) {
        if (!effect)
            return 0;
        return effect->effectItem.area;
    }

    float GetCost(Effect* effect) {
        if (!effect)
            return 0;
        return effect->cost;
    }

    uint32_t GetDuration(Effect* effect) {
        if (!effect)
            return 0;
        return effect->effectItem.duration;
    }

    float GetMagnitude(Effect* effect) {
        if (!effect)
            return 0;
        return effect->effectItem.magnitude;
    }

    bool Equals(Effect* effect1, Effect* effect2) {
        if (GetArea(effect1) != GetArea(effect2))
            return false;
        if (GetDuration(effect1) != GetDuration(effect2))
            return false;
        if (!FloatUtil::AlmostEqual(GetCost(effect1), GetCost(effect2)))
            return false;
        if (!FloatUtil::AlmostEqual(GetMagnitude(effect1), GetMagnitude(effect2)))
            return false;
        return effect1->baseEffect->formID == effect2->baseEffect->formID;
    }

    double SquaredError(Effect* effect1, Effect* effect2) {
        double sqErr = 0;
        sqErr += std::pow(GetArea(effect1) - GetArea(effect2), 2);
        sqErr += std::pow(GetCost(effect1) - GetCost(effect2), 2);
        sqErr += std::pow(GetDuration(effect1) - GetDuration(effect2), 2);
        sqErr += std::pow(GetMagnitude(effect1) - GetMagnitude(effect2), 2);
        return sqErr;
    }
}

namespace FloatUtil {
    bool AlmostEqual(float a, float b) {
        float difference = fabs(a - b);
        return difference <= std::max(fabs(a), fabs(b)) * FLT_EPSILON;
    }
}