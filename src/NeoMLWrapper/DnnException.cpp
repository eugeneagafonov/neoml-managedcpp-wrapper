#include "DnnException.h"

namespace NeoMLWrapper
{
    /// <summary>
    /// Creates DnnException instance from unmanaged error info reported by NeoML unmanaged code
    /// </summary>
    /// <param name="errorInfo">error info reported by NeoML unmanaged code</param>
    DnnException::DnnException(CDnnErrorInfo* errorInfo) : System::Exception(gcnew System::String(errorInfo->Description))
    {
        this->ErrorType = static_cast<DnnErrorType>(errorInfo->Type);
    }
}