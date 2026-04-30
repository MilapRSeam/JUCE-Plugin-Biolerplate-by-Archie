#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    ThresholdSlider.setSliderStyle (juce::Slider::LinearBarVertical);
    ThresholdSlider.setRange (-40, 0, 1.0);
    ThresholdSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    ThresholdSlider.setPopupDisplayEnabled (true, false, this);
    ThresholdSlider.setTextValueSuffix (" Threshold");
    ThresholdSlider.setValue (-25);

    addAndMakeVisible (&ThresholdSlider);
    ThresholdSlider.addListener(this);

    RatioSlider.setSliderStyle (juce::Slider::LinearBarVertical);   
    RatioSlider.setRange (1, 5, 0.1);
    RatioSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    RatioSlider.setPopupDisplayEnabled (true, false, this);
    RatioSlider.setTextValueSuffix (" Ratio");
    RatioSlider.setValue (2.0);

    addAndMakeVisible (&RatioSlider);
    RatioSlider.addListener(this);
   
    setSize(200,300);

   
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
   
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Threshold", getLocalBounds(), juce::Justification::centred, 1);
    g.drawFittedText ("Ratio", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
     ThresholdSlider.setBounds (40, 30, 20, getHeight() - 60);
         RatioSlider.setBounds (80, 30, 20, getHeight() - 60);   
}

void AudioPluginAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &ThresholdSlider)
    {
        processorRef.threshold = ThresholdSlider.getValue();
    }
    else if (slider == &RatioSlider)
    {
        processorRef.ratio = RatioSlider.getValue();
    }

}