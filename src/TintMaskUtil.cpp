#include "DirectXTex.h"
#include "TintMaskUtil.h"
#include <stdlib.h>

namespace TintMaskUtil {
	uint8_t* GetDDSPixels(const wchar_t* path) {
		DirectX::ScratchImage image;
		DirectX::LoadFromDDSFile(path, DirectX::DDS_FLAGS::DDS_FLAGS_NONE, NULL, image);
		image.GetPixelsSize();
		return image.GetPixels();
	}

	uint8_t* GetDDSPixels(std::string path) {
		std::wstring wpath = StringToWString(path);
		return GetDDSPixels(wpath.c_str());
	}

	std::wstring StringToWString(std::string s) {
		std::unique_ptr<wchar_t[]>  wptr(new wchar_t[s.length() + 1]);
		size_t numConverted = 0;
		mbstowcs_s(&numConverted, wptr.get(), s.length() + 1, s.c_str(), (s.length() + 1) * 2);
		return std::wstring(wptr.get());
	}
}