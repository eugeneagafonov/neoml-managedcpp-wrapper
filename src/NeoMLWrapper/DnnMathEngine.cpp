#include "DnnMathEngine.h"

namespace NeoMLWrapper
{
    /// <summary>
    /// Creates an instance of NeoML library unmanaged math engine wrapper
    /// </summary>
    /// <param name="p">unmanaged pointer to a NeoML math engine</param>
    DnnMathEngine::DnnMathEngine(const CDnnMathEngineDesc* p) : UnmanagedResourceHandle<CDnnMathEngineDesc>(p)
    {
    };

    /// <summary>
    /// Type of the underlying math engine: CPU or GPU
    /// </summary>
    DnnMathEngineType DnnMathEngine::EngineType::get()
    {
        const CDnnMathEngineDesc* p = Ptr();
        return static_cast<DnnMathEngineType>(p->Type);
    }

    void DnnMathEngine::DeleteHandle()
    {
        const CDnnMathEngineDesc* p = Ptr();
        DestroyMathEngine(p);
    }
}