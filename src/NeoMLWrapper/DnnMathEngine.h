#pragma once
#include "DnnException.h"
#include "UnmanagedResourceHandle.h"

namespace NeoMLWrapper
{
	/// <summary>
	/// The type of processing unit used for the math engine
	/// </summary>
	public enum class DnnMathEngineType {
		MET_CPU = 0,
		MET_GPU
	};

	/// <summary>
	/// A wrapper for NeoML library math engine unmanaged code
	/// </summary>
	public ref class DnnMathEngine : public UnmanagedResourceHandle<CDnnMathEngineDesc>
	{
	public:		
		/// <summary>
		/// Type of the underlying math engine: CPU or GPU
		/// </summary>
		property DnnMathEngineType EngineType
		{
			DnnMathEngineType get();
		}

	internal:
		DnnMathEngine(const CDnnMathEngineDesc* p);

	protected:
		void DeleteHandle() override;
	};
}