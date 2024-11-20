#include "LedPatternSolid.hpp"

LedPatternSolid::LedPatternSolid(led_strip_list strips, uint16_t colorIncrementTimeMs, std::string nameOverride)
: LedPattern(strips, nameOverride)
{
  _colorIncrTimeMs = colorIncrementTimeMs;
}

/// @brief Function to be called to set the pixels
void LedPatternSolid::DrawFrame()
{
  led_strip_list::iterator iter = _led_strips.begin();
  while (iter != _led_strips.end())
  {
    fill_solid( (*iter)->pixels, (*iter)->pixel_count, GetCurrentColor());
    iter++;
  }

  EVERY_N_MILLISECONDS(_colorIncrTimeMs)
  {
    IncrementColor();
  }
}
