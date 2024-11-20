#include "LedPatternGlitter.hpp"

LedPatternGlitter::LedPatternGlitter(led_strip_list strips, uint16_t chanceOfGlitter, uint8_t fadeRate)
: LedPattern(strips, "Glitter")
{
  _chanceOfGlitter = chanceOfGlitter;
  _fadeRate = fadeRate;
}

/// @brief Function to be called to set the pixels
void LedPatternGlitter::DrawFrame()
{
  led_strip_list::iterator iter = _led_strips.begin();
  while (iter != _led_strips.end())
  {
    if (_fadeRate == 0)
    {
      fill_solid( (*iter)->pixels, (*iter)->pixel_count, CRGB::Black);
    }
    else
    {
      fadeToBlackBy((*iter)->pixels, (*iter)->pixel_count, _fadeRate);
    }

    if( random8() < _chanceOfGlitter) {
      (*iter)->pixels[ random16((*iter)->pixel_count  ) ] += GetCurrentColor();
    }
    iter++;
  }

  IncrementColor();
}
