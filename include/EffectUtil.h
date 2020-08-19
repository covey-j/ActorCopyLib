#pragma once

using namespace RE;

namespace EffectUtil {
    uint32_t GetArea(Effect* effect);
    float GetCost(Effect* effect);
    uint32_t GetDuration(Effect* effect);
    float GetMagnitude(Effect* effect);
    bool Equals(Effect* effect1, Effect* effect2);
    double SquaredError(Effect* effect1, Effect* effect2);
}

namespace FloatUtil {
    bool AlmostEqual(float a, float b);
}