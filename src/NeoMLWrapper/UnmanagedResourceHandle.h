#pragma once

namespace NeoMLWrapper
{
	using SafeHandle = System::Runtime::InteropServices::SafeHandle;
	using IntPtr = System::IntPtr;

	// XML comments does not work for templates see https://docs.microsoft.com/en-us/cpp/build/reference/xml-documentation-visual-cpp?redirectedfrom=MSDN&view=msvc-160
	// this is a wrapper class for anything that holds unmanaged pointer
	// SafeHandle will take care about implementing Dispose() and Finalizer for the class
	// overriding DeleteHandle will allow to run custom logic for releasing unmanaged resources
	template <typename T>
	public ref class UnmanagedResourceHandle abstract : SafeHandle
	{
	internal:
		const T* Ptr() { return static_cast<const T*>(handle.ToPointer()); }

	protected:
		UnmanagedResourceHandle(const T* p) : SafeHandle(IntPtr::Zero, true)
		{
			SetHandle(IntPtr(const_cast<T*>(p)));
		}

		bool ReleaseHandle() override
		{
			if (!IsInvalid)
			{
				DeleteHandle();
				handle = IntPtr::Zero;
			}
			return true;
		}

		virtual void DeleteHandle() = 0;

	public:
		property bool IsInvalid
		{
			bool get() override
			{
				return (handle == IntPtr::Zero || handle == IntPtr(-1));
			}
		}
	};
}