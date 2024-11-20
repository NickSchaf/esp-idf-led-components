#pragma once

#include "LedPattern.hpp"

/// @brief Base class for an 
class LedPatternGlitter : public LedPattern
{
  protected:
  uint16_t _chanceOfGlitter;
  uint8_t _fadeRate;
  LedPatternGlitter() { }

  public:
  /// @brief Destructor
  virtual ~LedPatternGlitter() {}

  LedPatternGlitter(led_strip_list strips, uint16_t chanceOfGlitter = 80, uint8_t fadeRate = 0);

  /// @brief Function to be called to set the pixels
  virtual void DrawFrame() override;
};
