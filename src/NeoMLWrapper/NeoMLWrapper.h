#pragma once
#include <NeoProxy/NeoProxy.h>
#include "UnmanagedResourceHandle.h"
#include "DnnException.h"
#include "DnnMathEngine.h"
#include "DnnBlob.h"
#include "Dnn.h"

namespace NeoMLWrapper
{	
	[System::Runtime::CompilerServices::Extension]
	public ref class NeoML
	{
	public:
		static DnnMathEngine^ CreateGPUDnnMathEngine();
		static DnnMathEngine^ CreateCPUDnnMathEngine();
		static DnnMathEngine^ CreateCPUDnnMathEngine(int threadCount);

		[System::Runtime::CompilerServices::Extension]
		static DnnBlob^ CreateBlob(DnnMathEngine^ dnnMathEngine, DnnBlobType type, int batchLength, int batchWidth, int height, int width, int depth, int channelCount);

		[System::Runtime::CompilerServices::Extension]
		static void SetData(DnnBlob^ blob, array<float>^ buffer);
		[System::Runtime::CompilerServices::Extension]
		static void SetData(DnnBlob^ blob, array<int>^ buffer);
		[System::Runtime::CompilerServices::Extension]
		static void SetData(DnnBlob^ blob, array<System::Byte>^ buffer);

		[System::Runtime::CompilerServices::Extension]
		static array<float>^ GetFloatData(DnnBlob^ blob);
		[System::Runtime::CompilerServices::Extension]
		static array<int>^ GetIntData(DnnBlob^ blob);
		[System::Runtime::CompilerServices::Extension]
		static array<System::Byte>^ GetByteData(DnnBlob^ blob);

		[System::Runtime::CompilerServices::Extension]
		static Dnn^ CreateDnnFromBuffer(DnnMathEngine^ dnnMathEngine, array<System::Byte>^ buffer);

		[System::Runtime::CompilerServices::Extension]
		static Dnn^ CreateDnnFromOnnxBuffer(DnnMathEngine^ dnnMathEngine, array<System::Byte>^ buffer);
	};
}

