#pragma once

#include <array>

#include "../util/string.inl"

enum e_game_language : int {
    _game_language_en_AU = 0,
    _game_language_fr_BE = 1,
    _game_language_pt_BR = 2,
    _game_language_en_CA = 3,
    _game_language_fr_CA = 4,
    _game_language_zh_CN = 5,
    _game_language_fr_FR = 6,
    _game_language_de_DE = 7,
    _game_language_zh_HK = 8,
    _game_language_en_HK = 9,
    _game_language_it_IT = 10,
    _game_language_ja_JP = 11,
    _game_language_es_MX = 12,
    _game_language_pl_PL = 13,
    _game_language_pt_PT = 14,
    _game_language_ru_RU = 15,
    _game_language_zh_SG = 16,
    _game_language_en_SG = 17,
    _game_language_ko_KR = 18,
    _game_language_es_ES = 19,
    _game_language_zh_TW = 20,
    _game_language_en_GB = 21,
    _game_language_en_US = 22,
};

extern std::array<const char*, 23> g_game_language;
inline std::array<const char*, 23>* game_language() { return &g_game_language; }
inline const char* game_language(e_game_language game) { return g_game_language.at(game); }

struct s_game_language_settings {
    wchar_t language_audio[85];
    wchar_t language_text_1[85];
    wchar_t language_text_2[85];

    inline void set_audio(e_game_language language) {
        str_cpy(language_audio, game_language(language));
    }

    inline void set_text(e_game_language language) {
        str_cpy(language_text_1, game_language(language));
        str_cpy(language_text_2, game_language(language));
    }

    inline void set_language(e_game_language language) {
        set_audio(language);
        set_text(language);
    }
};
