#pragma once

#include "LedPattern.hpp"

/// @brief Base class for an 
class LedPatternPulse : public LedPattern
{
  protected:
  bool _increasing;
  uint8_t _scaleVal;
  uint8_t _step;
  uint8_t _min;
  uint8_t _max;

  LedPatternPulse() { }

  public:
  /// @brief Destructor
  virtual ~LedPatternPulse() {}

  void PatternStart() override;

  LedPatternPulse(led_strip_list strips, uint8_t brightnessStep = 15, uint8_t minBrightness = 10, uint8_t maxBrightness = 255);

  /// @brief Function to be called to set the pixels
  virtual void DrawFrame() override;
};
