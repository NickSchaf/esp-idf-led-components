#include "LedPatternPulse.hpp"
#include <algorithm>

LedPatternPulse::LedPatternPulse(led_strip_list strips, uint8_t brightnessStep, uint8_t minBrightness, uint8_t maxBrightness)
: LedPattern(strips, "Pulse")
{
  _step = std::min(std::max(brightnessStep, (uint8_t)1), (uint8_t)255);
  _min = minBrightness;
  _max = maxBrightness;
}

void LedPatternPulse::PatternStart()
{
  // On the first time through the loop after chaning patterns, we need to set the direction
  _increasing = false;
  _scaleVal = _max;
}

/// @brief Function to be called to set the pixels
void LedPatternPulse::DrawFrame()
{
  led_strip_list::iterator iter = _led_strips.begin();
  while (iter != _led_strips.end())
  {
    (*iter)->pixels[0] = GetCurrentColor();
    (*iter)->pixels[0].nscale8_video(_scaleVal);

    for (int i = 1; i < (*iter)->pixel_count; i++)
      (*iter)->pixels[i] = (*iter)->pixels[0];

    iter++;
  }

  if (_increasing)
  {
    _scaleVal = (uint8_t)(std::min((int)_scaleVal + (int)_step, (int)_max));  // Casts to avoid rolling-over

    if (_max == _scaleVal) _increasing = false;  // Reverse the scaling direction for next iteration
  }
  else
  {
    _scaleVal = (uint8_t)(std::max((int)_scaleVal - (int)_step, (int)_min));  // Casts to avoid rolling-over

    if (_min == _scaleVal)
    {
      _increasing = true;  // Reverse the scaling direction for next iteration
      IncrementColor();    // Use next color on the next pulse
    }
  }
}
