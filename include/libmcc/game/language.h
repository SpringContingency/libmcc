#pragma once

namespace libmcc {
	enum e_language {
		_language_en_AU,
		_language_fr_BE,
		_language_pt_BR,
		_language_en_CA,
		_language_fr_CA,
		_language_zh_CN,
		_language_fr_FR,
		_language_de_DE,
		_language_zh_HK,
		_language_en_HK,
		_language_it_IT,
		_language_ja_JP,
		_language_es_MX,
		_language_pl_PL,
		_language_pt_PT,
		_language_ru_RU,
		_language_zh_SG,
		_language_en_SG,
		_language_ko_KR,
		_language_es_ES,
		_language_zh_TW,
		_language_en_GB,
		_language_en_US,

		k_language_count,
	};

	constexpr const wchar_t* k_languages[] {
		L"en-AU",
		L"fr-BE",
		L"pt-BR",
		L"en-CA",
		L"fr-CA",
		L"zh-CN",
		L"fr-FR",
		L"de-DE",
		L"zh-HK",
		L"en-HK",
		L"it-IT",
		L"ja-JP",
		L"es-MX",
		L"pl-PL",
		L"pt-PT",
		L"ru-RU",
		L"zh-SG",
		L"en-SG",
		L"ko-KR",
		L"es-ES",
		L"zh-TW",
		L"en-GB",
		L"en-US"
	};

	struct s_language_settings {
		wchar_t audio[85];
		wchar_t text_1[85];
		wchar_t text_2[85];
	};
}
