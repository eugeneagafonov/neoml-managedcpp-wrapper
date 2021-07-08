#include "NeoMLWrapper.h"

namespace NeoMLWrapper
{        
    DnnMathEngine^ NeoML::CreateGPUDnnMathEngine()
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();

        const CDnnMathEngineDesc* p = CreateGPUMathEngine(errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        DnnMathEngine^ engine = gcnew DnnMathEngine(p);
        return engine;
    }

    DnnMathEngine^ NeoML::CreateCPUDnnMathEngine()
    {
        return NeoML::CreateCPUDnnMathEngine(0);
    }

    DnnMathEngine^ NeoML::CreateCPUDnnMathEngine(int threadCount)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();

        const CDnnMathEngineDesc* p = CreateCPUMathEngine(threadCount, errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        DnnMathEngine^ engine = gcnew DnnMathEngine(p);        
        return engine;
    }

    DnnBlob^ NeoML::CreateBlob(DnnMathEngine^ dnnMathEngine, DnnBlobType type, int batchLength, int batchWidth, int height, int width, int depth, int channelCount)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
       
        const CDnnMathEngineDesc* engine = dnnMathEngine->Ptr();
        TDnnBlobType nativeType = static_cast<TDnnBlobType>(type);

        const CDnnBlobDesc* p = CreateDnnBlob(engine, nativeType, batchLength, batchWidth, height, width, depth, channelCount, errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        DnnBlob^ blob = gcnew DnnBlob(p);
        return blob;
    }

    void NeoML::SetData(DnnBlob^ blob, array<float>^ buffer)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();
        pin_ptr<float> bufferPointer = &buffer[0];

        bool success = CopyToBlob(p, bufferPointer, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
    }

    void NeoML::SetData(DnnBlob^ blob, array<int>^ buffer)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();
        pin_ptr<int> bufferPointer = &buffer[0];

        bool success = CopyToBlob(p, bufferPointer, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
    }

    void NeoML::SetData(DnnBlob^ blob, array<System::Byte>^ buffer)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();
        pin_ptr<System::Byte> bufferPointer = &buffer[0];

        bool success = CopyToBlob(p, bufferPointer, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
    }

    array<float>^ NeoML::GetFloatData(DnnBlob^ blob)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();

        auto buffer = gcnew array<float>(blob->DataSize / sizeof(float));
        pin_ptr<float> bufferPointer = &buffer[0];

        bool success = CopyFromBlob(bufferPointer, p, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        return buffer;
    }

    array<int>^ NeoML::GetIntData(DnnBlob^ blob)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();

        auto buffer = gcnew array<int>(blob->DataSize / sizeof(int));
        pin_ptr<int> bufferPointer = &buffer[0];

        bool success = CopyFromBlob(bufferPointer, p, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        return buffer;
    }

    array<System::Byte>^ NeoML::GetByteData(DnnBlob^ blob)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnBlobDesc* p = blob->Ptr();

        auto buffer = gcnew array<System::Byte>(blob->DataSize);
        pin_ptr<System::Byte> bufferPointer = &buffer[0];

        bool success = CopyFromBlob(bufferPointer, p, errorInfo);

        if (!success)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        return buffer;
    }

    Dnn^ NeoML::CreateDnnFromBuffer(DnnMathEngine^ dnnMathEngine, array<System::Byte>^ buffer)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnMathEngineDesc* engine = dnnMathEngine->Ptr();
        pin_ptr<System::Byte> bufferPointer = &buffer[0];
        int bufferSize = buffer->Length;

        const CDnnDesc* p = ::CreateDnnFromBuffer(engine, bufferPointer, bufferSize, errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        Dnn^ dnn = gcnew Dnn(p);
        return dnn;
    }

    Dnn^ NeoML::CreateDnnFromOnnxBuffer(DnnMathEngine^ dnnMathEngine, array<System::Byte>^ buffer)
    {
        CDnnErrorInfo* errorInfo = new CDnnErrorInfo();
        const CDnnMathEngineDesc* engine = dnnMathEngine->Ptr();
        pin_ptr<System::Byte> bufferPointer = &buffer[0];
        int bufferSize = buffer->Length;

        const CDnnDesc* p = ::CreateDnnFromOnnxBuffer(engine, bufferPointer, bufferSize, errorInfo);

        if (p == nullptr)
        {
            DnnException^ ex = gcnew DnnException(errorInfo);
            delete errorInfo;
            throw ex;
        };

        delete errorInfo;
        Dnn^ dnn = gcnew Dnn(p);
        return dnn;
    }
}