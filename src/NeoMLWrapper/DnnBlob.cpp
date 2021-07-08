#include "DnnBlob.h"

namespace NeoMLWrapper
{
    DnnBlob::DnnBlob(const CDnnBlobDesc* p) : UnmanagedResourceHandle<CDnnBlobDesc>(p)
    {
    };

    DnnBlobType DnnBlob::BlobType::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return static_cast<DnnBlobType>(p->Type);
    }

    int DnnBlob::BatchLength::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->BatchLength;
    }

    int DnnBlob::BatchWidth::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->BatchWidth;
    }

    int DnnBlob::Height::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->Height;
    }

    int DnnBlob::Width::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->Width;
    }

    int DnnBlob::Depth::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->Depth;
    }

    int DnnBlob::ChannelCount::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->ChannelCount;
    }

    int DnnBlob::DataSize::get()
    {
        const CDnnBlobDesc* p = Ptr();
        return p->DataSize;
    }

    void DnnBlob::DeleteHandle()
    {
        const CDnnBlobDesc* p = Ptr();
        DestroyDnnBlob(p);
    }

}