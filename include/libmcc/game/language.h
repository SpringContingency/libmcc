#pragma once

namespace libmcc {
	enum e_language {
		_language_en_A,
		_language_fr_B,
		_language_pt_B,
		_language_en_C,
		_language_fr_C,
		_language_zh_C,
		_language_fr_F,
		_language_de_D,
		_language_zh_H,
		_language_en_H,
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

	struct s_language_settings {
		wchar_t audio[85];
		wchar_t text_1[85];
		wchar_t text_2[85];
	};
}
