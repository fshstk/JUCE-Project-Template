juce_add_plugin(${CMAKE_PROJECT_NAME}
  FORMATS AU VST3 Standalone
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
  PluginEditor.cpp
  PluginProcessor.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC .)

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
  JUCE_VST3_CAN_REPLACE_VST2=0

  # Disabling the splash screen is only legal if you purchase a JUCE license, or
  # if you license your project using the GNU Public License.
  # - https://www.gnu.org/licenses
  # - https://juce.com/juce-6-licence

  # JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
  juce::juce_audio_utils

  juce::juce_recommended_config_flags
  juce::juce_recommended_lto_flags
  juce::juce_recommended_warning_flags
)
