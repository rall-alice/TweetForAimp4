#pragma once
#include "AimpSDK/apiPlugin.h"
#include "IUnknownInterface.h"

class AimpPlugin : public IUnknownInterface<IAIMPPlugin> {

public:
	AimpPlugin() { AddRef(); }
	~AimpPlugin() { Release(); }

	virtual HRESULT WINAPI Initialize(IAIMPCore* Core) = 0;
	virtual HRESULT WINAPI Finalize(void) = 0;
	virtual PWCHAR WINAPI InfoGet(INT index)  = 0;
	virtual DWORD WINAPI InfoGetCategories() = 0;
	virtual void WINAPI SystemNotification(INT NotifyID, IUnknown* Data) = 0;
};
