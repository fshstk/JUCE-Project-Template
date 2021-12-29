#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginAudioProcessor::AudioPluginAudioProcessor()
  : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                     .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
                     .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    )
{}

AudioPluginAudioProcessor::~AudioPluginAudioProcessor() {}

const juce::String AudioPluginAudioProcessor::getName() const
{
  return JucePlugin_Name;
}

bool AudioPluginAudioProcessor::acceptsMidi() const
{
  return false;
}

bool AudioPluginAudioProcessor::producesMidi() const
{
  return false;
}

bool AudioPluginAudioProcessor::isMidiEffect() const
{
  return false;
}

double AudioPluginAudioProcessor::getTailLengthSeconds() const
{
  return 0.0;
}

int AudioPluginAudioProcessor::getNumPrograms()
{
  // Some hosts don't cope very well if you tell them there are 0 programs, so this should be at
  // least 1, even if you're not really implementing programs:
  return 1;
}

int AudioPluginAudioProcessor::getCurrentProgram()
{
  return 0;
}

void AudioPluginAudioProcessor::setCurrentProgram(int index)
{
  juce::ignoreUnused(index);
}

const juce::String AudioPluginAudioProcessor::getProgramName(int index)
{
  juce::ignoreUnused(index);
  return {};
}

void AudioPluginAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
  juce::ignoreUnused(index, newName);
}

// Use this method as the place to do any pre-playback initialisation that you need:
void AudioPluginAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
  juce::ignoreUnused(sampleRate, samplesPerBlock);
}

// When playback stops, you can use this as an opportunity to free up any spare memory, etc.:
void AudioPluginAudioProcessor::releaseResources() {}

bool AudioPluginAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
  juce::ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported. In this template code we only
  // support mono or stereo. Some plugin hosts, such as certain GarageBand versions, will only load
  // plugins that support stereo bus layouts.
  if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}

void AudioPluginAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                             juce::MidiBuffer& midiMessages)
{
  juce::ignoreUnused(midiMessages);

  juce::ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  // In case we have more outputs than inputs, this code clears any output channels that didn't
  // contain input data, (because these aren't guaranteed to be empty - they may contain garbage).
  // This is here to avoid people getting screaming feedback when they first compile a plugin, but
  // obviously you don't need to keep this code if your algorithm always overwrites all the output
  // channels.
  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());

  // This is the place where you'd normally do the guts of your plugin's audio processing... Make
  // sure to reset the state if your inner loop is processing the samples and the outer loop is
  // handling the channels. Alternatively, you can process the samples with the channels interleaved
  // by keeping the same state.
  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto* channelData = buffer.getWritePointer(channel);
    juce::ignoreUnused(channelData);
    // ...do something to the data...
  }
}

bool AudioPluginAudioProcessor::hasEditor() const
{
  // Change this to false if you choose to not supply an editor:
  return true;
}

juce::AudioProcessorEditor* AudioPluginAudioProcessor::createEditor()
{
  return new AudioPluginAudioProcessorEditor(*this);
}

// You should use this method to store your parameters in the memory block. You could do that either
// as raw data, or use the XML or ValueTree classes as intermediaries to make it easy to save and
// load complex data:
void AudioPluginAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
  juce::ignoreUnused(destData);
}

// You should use this method to restore your parameters from this memory block, whose contents will
// have been created by the getStateInformation() call:
void AudioPluginAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
  juce::ignoreUnused(data, sizeInBytes);
}

// This creates new instances of the plugin:
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
  return new AudioPluginAudioProcessor();
}
