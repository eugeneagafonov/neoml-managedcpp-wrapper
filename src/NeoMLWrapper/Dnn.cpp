#include "DnnException.h"
#include "DnnBlob.h"
#include "Dnn.h"

namespace NeoMLWrapper
{
    Dnn::Dnn(const CDnnDesc* p) : UnmanagedResourceHandle<CDnnDesc>(p)
    {
    };

    void Dnn::RunOnce()
    {
        CDnnErrorInfo errorInfo;

        const CDnnDesc* p = Ptr();
        bool success = DnnRunOnce(p, &errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(&errorInfo);
            throw ex;
        };      
    }

    void Dnn::SetInputBlob(int index, DnnBlob^ blob)
    {
        CDnnErrorInfo errorInfo;

        const CDnnDesc* p = Ptr();
        const CDnnBlobDesc* blobPointer = blob->Ptr();

        bool success = ::SetInputBlob(p, index, blobPointer, &errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(&errorInfo);
            throw ex;
        };        
    }

    DnnBlob^ Dnn::GetOutputBlob(int index)
    {
        CDnnErrorInfo errorInfo;

        const CDnnDesc* dnn = Ptr();
        const CDnnBlobDesc* p = ::GetOutputBlob(dnn, index, &errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(&errorInfo);
            throw ex;
        };
        
        DnnBlob^ blob = gcnew DnnBlob(p);
        return blob;
    }

    System::String^ Dnn::GetInputName(int index)
    {
        CDnnErrorInfo errorInfo;

        const CDnnDesc* dnn = Ptr();
        const char* p = ::GetInputName(dnn, index, &errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(&errorInfo);
            throw ex;
        };
        
        System::String^ result = gcnew System::String(p);
        return result;
    }

    System::String^ Dnn::GetOutputName(int index)
    {
        CDnnErrorInfo errorInfo;

        const CDnnDesc* dnn = Ptr();
        const char* p = ::GetInputName(dnn, index, &errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(&errorInfo);
            throw ex;
        };

        System::String^ result = gcnew System::String(p);
        return result;
    }

    int Dnn::InputCount::get()
    {
        const CDnnDesc* p = Ptr();
        return p->InputCount;
    }

    int Dnn::OutputCount::get()
    {
        const CDnnDesc* p = Ptr();
        return p->OutputCount;
    }

    void Dnn::DeleteHandle()
    {
        const CDnnDesc* p = Ptr();
        DestroyDnn(p);
    }
}