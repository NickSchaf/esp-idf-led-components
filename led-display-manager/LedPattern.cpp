#include "LedPattern.hpp"

void LedPattern::SetStrips(led_strip_list strips) { _led_strips = strips; }

CRGB LedPattern::GetCurrentColor() { return (GetCurrentColorHandler != NULL) ? GetCurrentColorHandler() : CRGB::Black; }
uint8_t LedPattern::GetCurrentHue() { return (GetCurrentHueHandler != NULL) ? GetCurrentHueHandler() : 0; }
void LedPattern::IncrementColor() { if (IncrementColorHandler != NULL)  IncrementColorHandler(); }

std::string LedPattern::GetName() { return _name; }

GetCurrentColorFunc LedPattern::GetCurrentColorHandler = NULL;
GetCurrentHueFunc LedPattern::GetCurrentHueHandler = NULL;
IncrementColorFunc LedPattern::IncrementColorHandler = NULL;

LedPattern::LedPattern(led_strip_list strips, std::string name)
  : _led_strips(strips), _name(name)
  { }

/// @brief Get the constant speed for this pattern (0 for variable speed)
uint8_t LedPattern::GetConstSpeed() { return 0; }
