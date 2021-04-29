#pragma once
#include "./AimpPlugin.h"
#include "PluginData.h"
class TweetForAimp4 : public AimpPlugin {
public:
	TweetForAimp4()
		: m_aimp_core(nullptr) {}

	HRESULT WINAPI Initialize(IAIMPCore* core) {
		this->m_aimp_core = core;
		return S_OK;
	}

	HRESULT WINAPI Finalize(void) {
		this->m_aimp_core = nullptr;
		return S_OK;
	}

	PWCHAR WINAPI InfoGet(INT index) {
		switch (index)
		{
			case AIMP_PLUGIN_INFO_NAME:
				return const_cast<PWCHAR>(PLUGIN_NAME);
			case AIMP_PLUGIN_INFO_AUTHOR:
				return const_cast<PWCHAR>(PLUGIN_AUTHOR);
			case AIMP_PLUGIN_INFO_SHORT_DESCRIPTION:
				return const_cast<PWCHAR>(PLUGIN_SHORT_DESC);
			case AIMP_PLUGIN_INFO_FULL_DESCRIPTION:
				return const_cast<PWCHAR>(PLUGIN_FULL_DESC);
		}
		return nullptr;
	}
	DWORD WINAPI InfoGetCategories() {
		return AIMP_PLUGIN_CATEGORY_ADDONS;
	}

	void WINAPI SystemNotification(INT NotifyID, IUnknown* Data)
	{
	}

private:
	IAIMPCore* m_aimp_core;
};

