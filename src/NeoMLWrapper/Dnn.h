#pragma once
#include <NeoProxy/NeoProxy.h>
#include "UnmanagedResourceHandle.h"

namespace NeoMLWrapper
{
	public ref class Dnn : public UnmanagedResourceHandle<CDnnDesc>
	{
	public:
		Dnn(const CDnnDesc* p);

		void RunOnce();

		void SetInputBlob(int index, DnnBlob^ blob);

		DnnBlob^ GetOutputBlob(int index);

		System::String^ GetInputName(int index);

		System::String^ GetOutputName(int index);

		property int InputCount
		{
			int get();
		}

		property int OutputCount
		{
			int get();
		}

	protected:
		void DeleteHandle() override;
	};
}
