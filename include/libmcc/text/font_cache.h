#pragma once

namespace libmcc {
	constexpr int k_font_texture_width = 1024;
	constexpr int k_font_texture_height = 1024;
	constexpr float k_pixel_width = 1.0f / k_font_texture_width;
	constexpr float k_pixel_height = 1.0f / k_font_texture_height;


#pragma pack(push, 1)
    struct s_font_character {
        wchar_t unicode;
        char : 8;
        char : 8;
        float scale;

        short left;
        short top;
        short width;
        short height;

        short horiBearingY;
        short horiBearingX;
        short horiAdvance;
        short vertBearingX;

        char texture;
        bool valid;
    };

    static_assert(sizeof(s_font_character) == 26);

#pragma pack(pop)
}