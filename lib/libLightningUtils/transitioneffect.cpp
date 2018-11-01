#include "transitioneffect.h"

#ifndef UNIT_TEST
    #include <Arduino.h>
#else
    extern "C" uint32_t millis();
#endif

TransitionEffect::TransitionEffect(const HSB& p_hsb,
                                   const uint32_t p_startMillis,
                                   const uint32_t m_duration) : Effect(),
    m_hsb(p_hsb),
    m_startMillis(p_startMillis),
    m_endMillis(p_startMillis + m_duration),
    m_duration(m_duration) {
}

HSB TransitionEffect::handleEffect(const uint32_t p_count,
                                   const uint32_t p_time,
                                   const HSB& _hsb) {
    return calcHSB(p_count, p_time, _hsb);
}

HSB TransitionEffect::finalState(const uint32_t p_count,
                                 const uint32_t p_time,
                                 const HSB& _hsb) const {
    return calcHSB(p_count, m_endMillis, _hsb);
}

bool TransitionEffect::isCompleted(const uint32_t p_count,
                                   const uint32_t p_time,
                                   const HSB& hsb) const {
    return p_time > m_endMillis;
}

HSB TransitionEffect::calcHSB(const uint32_t p_count,
                              const uint32_t p_time,
                              const HSB& _hsb) const {
    const float percent = ((p_time - m_startMillis) * 100) / m_duration;
    const float m_hsbsPath = HSB::hueShortestPath(_hsb.hue(), m_hsb.hue());
    const float newHue = map(percent, 0.f, 100.f, _hsb.hue(), m_hsbsPath);
    return HSB(
               HSB::fixHue(newHue),
               map(percent, 0.f, 100.f, _hsb.saturation(), m_hsb.saturation()),
               map(percent, 0.f, 100.f, _hsb.brightness(), m_hsb.brightness()),
               map(percent, 0.f, 100.f, _hsb.white1(), m_hsb.white1()),
               map(percent, 0.f, 100.f, _hsb.white2(), m_hsb.white2()));
}
