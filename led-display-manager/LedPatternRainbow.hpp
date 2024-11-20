#pragma once

#include "LedPattern.hpp"

/// @brief Base class for an 
class LedPatternRainbow : public LedPattern
{
  protected:
  LedPatternRainbow() { }

  public:
  /// @brief Destructor
  virtual ~LedPatternRainbow() {}

  LedPatternRainbow(led_strip_list strips);

  /// @brief Function to be called to set the pixels
  virtual void DrawFrame() override;
};
