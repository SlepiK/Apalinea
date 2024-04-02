# Stream-Library

[![Build](https://github.com/SlepiK/stream/actions/workflows/build.yml/badge.svg)](https://github.com/SlepiK/stream/actions/workflows/build.yml)

## Note
This Library is work in progress.

## Usage
To use the library you need to include only <code>Core/Plan/Plan.hpp</code> in your file.
With that header you can use the following commands:
<ol>
	<li><code>plan.createLink(Energyleaf::Stream::V1::Link::make_SourceLinkUPtr&lt;YOUR_SOURCE_OPERATOR()>);</code> - Creation of an SourceLink</li>
	<li><code>plan.createLink(Energyleaf::Stream::V1::Link::make_SinkLinkUPtr&lt;YOUR_SINK_OPERATOR>());</code> - Creation of an SinkLink</li>
	<li><code>plan.createLink(Energyleaf::Stream::V1::Link::make_PipeLinkUPtr&lt;YOUR_PIPE_OPERATOR>());</code> - Creation of an PipeLink</li>
	<li><code>plan.connect(SOURCELINK_OBJECT,PIPELINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(PIPELINK_OBJECT,PIPELINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(SOURCELINK_OBJECT,SINKLINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(PIPELINK_OBJECT,SINKLINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.process();</code> - Process one iteration trough the stream</li>
</ol>

NOTE: The order of the creation of the links is important. First create the source, then the pipe and then the sink.
Thats an behaviour which will hopefully get resolved in the future.

## Version
The current informations about the version of this library can be found inside of Core/Constants/Version.hpp.
Without warranty, the current version is V2.0 Iluap.
