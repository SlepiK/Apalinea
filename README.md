# Apalinea a stream-library

[![Build](https://github.com/SlepiK/stream/actions/workflows/build.yml/badge.svg)](https://github.com/SlepiK/stream/actions/workflows/build.yml)

## Note
This Library is work in progress.
Most of the functionalities and the architecture were inspired by the DSMS framework Odysseus.

## Usage
To use Apalinea you need to include <code>Core/Plan/Plan.hpp</code>, <code>Core/Log/LogManager.hpp</code>, <code>Core/Executor/STLExecutor.hpp</code>, <code>Core/Log/ConsoleLog.hpp</code>.
You can also create your own Executor and Logger (STLExecutor and ConsoleLog are only pre defined ones). A Executor based on boost
is also part of the library.

First you need to add a Logger to the LogManager by using (as an example with ConsoleLog):
<code>Apalinea::Core::Log::LogManager::addLog(std::make_unique&lt;Apalinea::Core::Log::ConsoleLog>());</code>

After that you need to create the Plan by using (as an example with STLExecutor and 3 threads / worker):
<code>Apalinea::Core::Plan::Plan plan(std::make_shared&lt;Apalinea::Core::Executor::STLExecutor>(3));</code>

After that you can add your operators to the plan by using:
<ol>
	<li><code>plan.createSource&lt;YOUR_SOURCE_OPERATOR>();</code> - Creation of an SourceLink</li>
	<li><code>plan.createPipe&lt;YOUR_PIPE_OPERATOR>();</code> - Creation of an PipeLink</li>
	<li><code>plan.createSink&lt;YOUR_SINK_OPERATOR>();</code> - Creation of an SinkLink</li>
	<li><code>plan.connect(SOURCELINK_OBJECT,PIPELINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(PIPELINK_OBJECT,PIPELINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(SOURCELINK_OBJECT,SINKLINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.connect(PIPELINK_OBJECT,SINKLINK_OBJECT);</code> - Connect two Links</li>
	<li><code>plan.process();</code> - Process one iteration through the stream (unordered)</li>
	<li><code>plan.order();</code> - Ordering of the whole plan</li>
	<li><code>plan.processOrdered();</code> - Process one iteration through the stream (ordered) </li>
</ol>

For a working example look into <code>example/example.cpp</code>.

## Version and Changes
Currently, Apalinea is after a breaking change in the version v1.0.0.Orez available. At that change the full library
has moved into its own namespace and a name change was fulfilled.
