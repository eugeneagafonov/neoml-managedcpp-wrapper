#pragma once
#include <NeoProxy/NeoProxy.h>

namespace NeoMLWrapper
{
	/// <summary>
	/// Error type that is returned from NeoML library unmanaged code
	/// </summary>
	public enum class DnnErrorType
	{
		/// <summary>
		/// no error
		/// </summary>
		DET_OK = 0,

		/// <summary>
		/// internal error, details in error description
		/// </summary>
		DET_InternalError,

		/// <summary>
		/// no GPU available
		/// </summary>
		DET_NoAvailableGPU,

		/// <summary>
		/// no CPU available
		/// </summary>
		DET_NoAvailableCPU,

		/// <summary>
		/// parameter value is invalid
		/// </summary>
		DET_InvalidParameter, 

		/// <summary>
		/// error when running the network, details in error description
		/// </summary>
		DET_RunDnnError,

		/// <summary>
		/// error when loading the network, details in error description
		/// </summary>
		DET_LoadDnnError
	};

	/// <summary>
	/// Exception that is thrown in case of NeoML library unmanaged code reports an error
	/// </summary>
	public ref class DnnException : public System::Exception
	{
	public:
		/// <summary>
		/// NeoML error type
		/// </summary>
		DnnErrorType ErrorType;

	internal:
		DnnException(CDnnErrorInfo* errorInfo);
	};
}