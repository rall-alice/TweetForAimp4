#pragma once
#include <Unknwn.h>

template <typename T>
class IUnknownInterface : public T{
public:
    IUnknownInterface()
        : m_ref_counter(0)
    {}

    virtual ~IUnknownInterface() {}

    virtual HRESULT WINAPI QueryInterface(REFIID riid, LPVOID* ppvObj) {
        if (!ppvObj) {
            return E_POINTER;
        }

        if (IID_IUnknown == riid) {
            *ppvObj = this;
            AddRef();
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    virtual ULONG WINAPI AddRef(void)
    {
        return ++m_ref_counter;
    }

    virtual ULONG WINAPI Release(void) {

        ULONG ref = --m_ref_counter;
        if (ref == 0) {
            delete this;
        }

        return ref;
    }

private:

    ULONG m_ref_counter;
};
