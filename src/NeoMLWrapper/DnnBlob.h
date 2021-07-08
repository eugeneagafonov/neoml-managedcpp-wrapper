#pragma once
#include <NeoProxy/NeoProxy.h>
#include "UnmanagedResourceHandle.h"

namespace NeoMLWrapper
{
	public enum class DnnBlobType {
		DBT_Float = 1,
		DBT_Int = 2
	};

	public ref class DnnBlob : public UnmanagedResourceHandle<CDnnBlobDesc>
	{
	public:		
		property DnnBlobType BlobType
		{
			DnnBlobType get();
		}

		property int BatchLength
		{
			int get();
		}

		property int BatchWidth
		{
			int get();
		}

		property int Height
		{
			int get();
		}

		property int Width
		{
			int get();
		}

		property int Depth
		{
			int get();
		}

		property int ChannelCount
		{
			int get();
		}

		property int DataSize
		{
			int get();
		}

	internal:
		DnnBlob(const CDnnBlobDesc* p);

	protected:
		void DeleteHandle() override;
	};

}