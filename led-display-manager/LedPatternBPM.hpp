#pragma once

#include "LedPattern.hpp"

/// @brief Base class for an 
class LedPatternBPM : public LedPattern
{
  protected:
  LedPatternBPM() { }

  public:
  /// @brief Destructor
  virtual ~LedPatternBPM() {}

  LedPatternBPM(led_strip_list strips);

  /// @brief Function to be called to set the pixels
  virtual void DrawFrame() override;
};
